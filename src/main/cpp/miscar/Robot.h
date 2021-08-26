// Copyright (c) MisCar 1574

#pragma once

#include <frc/Compressor.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>

#include "miscar/motor/Motor.h"
#include "miscar/Solenoid.h"

namespace miscar {

class Robot : public frc::TimedRobot {
 public:
  Robot();
  ~Robot() override;
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<frc2::Command *> m_autonomous_chooser;
  frc::Compressor m_compressor;

  // #ifdef RUNNING_SYSTEM_CHECKS

  frc::SendableChooser<miscar::Motor::Mode> m_mode_chooser;
  frc::SendableChooser<miscar::Motor *> m_motor_chooser;
  frc::SendableChooser<miscar::Solenoid *> m_solenoid_chooser;

  // #endif
};

}  // namespace miscar
