// Copyright (c) MisCar 1574

#pragma once

#include <string>

namespace miscar {

class Named {
 public:
  explicit Named(std::string name);
  std::string &GetName();

 private:
  std::string m_name;
};

}  // namespace miscar
