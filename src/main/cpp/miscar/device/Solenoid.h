// Copyright (c) MisCar 1574

#pragma once

#include <string>
#include <vector>

#include <frc/Solenoid.h>

namespace miscar {

/** A pneumatic solenoid */
class Solenoid : public frc::Solenoid {
 public:
  explicit Solenoid(std::string name, int port);

  static std::vector<Solenoid *> &GetInstances();

  const std::string &GetName();

 private:
  static std::vector<Solenoid *> m_instances;

  std::string m_name;
};

}  // namespace miscar
