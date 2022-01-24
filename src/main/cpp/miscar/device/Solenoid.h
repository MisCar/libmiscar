// Copyright (c) MisCar 1574

#pragma once

#include <vector>

#include "miscar/Named.h"

namespace miscar {

class Solenoid : public Named {
 public:
  Solenoid(std::string name);

  virtual bool Get() = 0;
  virtual void Set(bool value);
  void Flip();

  static std::vector<Solenoid *> &GetInstances();

 private:
  static std::vector<Solenoid *> m_instances;
};

}  // namespace miscar
