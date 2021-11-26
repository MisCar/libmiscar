// Copyright (c) MisCar 1574

#pragma once

#include <wpi/sendable/Sendable.h>

#include <string>
#include <vector>

namespace miscar::network {

/** Get a value from the Network Tables. */
template <typename T>
T Get(const std::string& path) = delete;

template <>
bool Get(const std::string& path);

template <>
int Get(const std::string& path);

template <>
double Get(const std::string& path);

template <>
std::vector<bool> Get(const std::string& path);

template <>
std::vector<int> Get(const std::string& path);

template <>
std::vector<double> Get(const std::string& path);

template <>
std::vector<std::string> Get(const std::string& path);

template <>
std::string Get(const std::string& path);

/** Set a value in the Network Tables. */
template <typename T>
void Set(const std::string& path, T value) = delete;

template <>
void Set(const std::string& path, bool value);

template <>
void Set(const std::string& path, int value);

template <>
void Set(const std::string& path, double value);

template <>
void Set(const std::string& path, std::string value);

template <>
void Set(const std::string& path, std::vector<bool> value);

template <>
void Set(const std::string& path, std::vector<int> value);

template <>
void Set(const std::string& path, std::vector<double> value);

template <>
void Set(const std::string& path, std::vector<std::string> value);

/** Set a value in the Network Tables if it isn't set. */
template <typename T>
void SetDefault(const std::string& path, T value) = delete;

template <>
void SetDefault(const std::string& path, bool value);

template <>
void SetDefault(const std::string& path, int value);

template <>
void SetDefault(const std::string& path, double value);

template <>
void SetDefault(const std::string& path, std::string value);

template <>
void SetDefault(const std::string& path, std::vector<bool> value);

template <>
void SetDefault(const std::string& path, std::vector<int> value);

template <>
void SetDefault(const std::string& path, std::vector<double> value);

template <>
void SetDefault(const std::string& path, std::vector<std::string> value);

/** Add a sendable to Network Tables. */
void Add(const std::string& path, wpi::Sendable& sendable);

}  // namespace miscar::network
