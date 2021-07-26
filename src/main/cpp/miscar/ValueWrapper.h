// Copyright (c) MisCar 1574

#pragma once

namespace miscar {
template <typename T>
class ValueWrapper {
 public:
  explicit ValueWrapper(T value);
  virtual T Get() const;
  virtual void Set(T value);

 protected:
  T m_value;
};
}  // namespace miscar

template <typename T>
miscar::ValueWrapper<T>::ValueWrapper(T value) : m_value(value) {}
template <typename T>
T miscar::ValueWrapper<T>::Get() const {
  return m_value;
}
template <typename T>
void miscar::ValueWrapper<T>::Set(T value) {
  m_value = value;
}
