#pragma once

namespace miscar::utilities
{
  template <typename T> class ValueWrapper
  {
  public:
    ValueWrapper(T value);
    virtual T Get() const;
    virtual void Set(T value);

  protected:
    T m_value;
  };
} // namespace miscar::utilities

template <typename T> miscar::utilities::ValueWrapper<T>::ValueWrapper(T value) : m_value(value) {}
template <typename T> T miscar::utilities::ValueWrapper<T>::Get() const { return m_value; }
template <typename T> void miscar::utilities::ValueWrapper<T>::Set(T value) { m_value = value; }
