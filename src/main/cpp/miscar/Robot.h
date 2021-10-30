// Copyright (c) MisCar 1574

#pragma once

#include <frc/Compressor.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>

#include "miscar/Solenoid.h"
#include "miscar/motor/Motor.h"

namespace miscar {

/**
 * A base robot class with built in test mode and other utilities.
 */
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

 protected:
  void AddAutonomous(std::string_view name, frc2::Command *command);

 private:
  frc::SendableChooser<frc2::Command *> m_autonomous_chooser;
  frc::SendableChooser<miscar::Motor::Mode> m_mode_chooser;
  frc::SendableChooser<miscar::Motor::Mode> m_graph_chooser;
  frc::SendableChooser<miscar::Motor *> m_motor_chooser;
  frc::SendableChooser<miscar::Solenoid *> m_solenoid_chooser;
};

}  // namespace miscar
