// Copyright (c) MisCar 1574

#pragma once

#include <functional>

#include "miscar/ResettableValueWrapper.h"

namespace miscar {
template <typename T>
class LazyCallback : public ResettableValueWrapper<T> {
 public:
  LazyCallback<T>(T initial, std::function<void(T)> callback);
  void Set(T value) override;

 private:
  std::function<void(T)> m_callback;
};
}  // namespace miscar

template <typename T>
miscar::LazyCallback<T>::LazyCallback(T initial,
                                      std::function<void(T)> callback)
    : ResettableValueWrapper<T>(initial), m_callback(callback) {}

template <typename T>
void miscar::LazyCallback<T>::Set(T value) {
  T current = ValueWrapper<T>::Get();
  if (current != value) {
    m_callback(value);
    ValueWrapper<T>::Set(value);
  }
}
