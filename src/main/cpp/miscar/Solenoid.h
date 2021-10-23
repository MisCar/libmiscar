// Copyright (c) MisCar 1574

#pragma once

#include <frc/Solenoid.h>

#include <vector>

namespace miscar {

/** A pneumatic solenoid */
class Solenoid : public frc::Solenoid {
 public:
  explicit Solenoid(int port);

  static std::vector<Solenoid *> &GetInstances();

 private:
  static std::vector<Solenoid *> m_instances;
};

}  // namespace miscar
