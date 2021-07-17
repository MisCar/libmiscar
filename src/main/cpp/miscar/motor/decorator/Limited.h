#include <algorithm>
#include <optional>
#include <type_traits>

#include "miscar/Log.h"
#include "miscar/motor/Motor.h"

namespace miscar {

template <class M, typename = std::enable_if<std::is_base_of<M, Motor>::value>>
class Limited : public M {
 public:
  Limited(const M &m, std::optional<double> minimum = std::optional<double>(),
          std::optional<double> maximum = std::optional<double>())
      : M(m), m_minimum(minimum), m_maximum(maximum) {
    static_assert(!m_minimum.has_value() || !m_maximum.has_value() ||
                      m_minimum.value() < m_maximum.value(),
                  "The minimum should be lower than the maximum");
  }

  void SetOutput(double output, Motor::Mode mode) override {
    if (mode != Motor::Position) {
      log::Warning(
          "Limited motor shouldn't be set with modes other than position");
    } else {
      if (m_minimum.has_value() && output < m_minimum.value())
        output = m_minimum.value();
      if (m_maximum.has_value() && output > m_maximum.value())
        output = m_minimum.value();
    }

    M::SetOutput(output, mode);
  }

 private:
  const std::optional<double> m_minimum;
  const std::optional<double> m_maximum;
};

}  // namespace miscar