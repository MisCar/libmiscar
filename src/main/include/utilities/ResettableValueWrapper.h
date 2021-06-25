#include "utilities/ValueWrapper.h"

namespace miscar::utilities
{
  template <typename T> class ResettableValueWrapper : public ValueWrapper<T>
  {
  public:
    ResettableValueWrapper(T value);
    void Reset();

  private:
    T m_initial;
  };
} // namespace miscar::utilities

template <typename T>
miscar::utilities::ResettableValueWrapper<T>::ResettableValueWrapper(T value)
    : ValueWrapper<T>(value), m_initial(value)
{
}

template <typename T> void miscar::utilities::ResettableValueWrapper<T>::Reset()
{
  ValueWrapper<T>::Set(m_initial);
}
