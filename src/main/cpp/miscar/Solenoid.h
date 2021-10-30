// Copyright (c) MisCar 1574

#pragma once

#include <frc/Solenoid.h>

#include <vector>

namespace miscar {

/** A pneumatic solenoid */
class Solenoid : public frc::Solenoid {
 public:
  explicit Solenoid(std::string_view name, int port);

  static std::vector<Solenoid *> &GetInstances();

  std::string_view GetName();

 private:
  static std::vector<Solenoid *> m_instances;

  std::string_view m_name;
};

}  // namespace miscar
