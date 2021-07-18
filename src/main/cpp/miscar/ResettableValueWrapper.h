#pragma once

#include "miscar/ValueWrapper.h"

namespace miscar {
template <typename T>
class ResettableValueWrapper : public ValueWrapper<T> {
 public:
  ResettableValueWrapper(T value);
  void Reset();

 private:
  T m_initial;
};
}  // namespace miscar

template <typename T>
miscar::ResettableValueWrapper<T>::ResettableValueWrapper(T value)
    : ValueWrapper<T>(value), m_initial(value) {}

template <typename T>
void miscar::ResettableValueWrapper<T>::Reset() {
  ValueWrapper<T>::Set(m_initial);
}
