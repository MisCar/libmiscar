#include <frc/Solenoid.h>

namespace miscar {

class Solenoid : public frc::Solenoid {
 public:
  Solenoid(std::string&& name, int id);

  const std::string& GetName();

  // #ifdef RUNNING_SYSTEM_CHECKS
  static std::vector<Solenoid*>& GetInstances() { return m_instances; }
  // #endif

 private:
  const std::string m_name;

  // #ifdef RUNNING_SYSTEM_CHECKS
  static std::vector<Solenoid*> m_instances;
  // #endif
};

}  // namespace miscar