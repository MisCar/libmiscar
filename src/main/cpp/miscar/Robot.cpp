// Copyright (c) MisCar 1574

#include "Robot.h"

#include <frc/DriverStation.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include "miscar/Log.h"
#include "miscar/motor/Motor.h"
#include "miscar/Network.h"

using namespace miscar;

const std::string GEVARIM[] = {"Zaks",  "Szpiler", "Sheffi", "Toto",
                               "Mayan", "Hadas",   "Barak"};
constexpr auto GEVARIM_COUNT = sizeof(GEVARIM) / sizeof(GEVARIM[0]);

Robot::Robot() {
  int index = (static_cast<double>(std::rand()) / RAND_MAX) * GEVARIM_COUNT;
  log::Network("Gever", GEVARIM[index]);
  frc::Shuffleboard::GetTab("MisCar").Add(m_autonomous_chooser);

#ifdef RUNNING_SYSTEM_CHECKS
  m_mode_chooser.SetDefaultOption("Percent Output",
                                  miscar::Motor::PercentOutput);
  m_mode_chooser.AddOption("Position", miscar::Motor::Position);
  m_mode_chooser.AddOption("Velocity", miscar::Motor::Velocity);

  for (const auto& motor : Motor::GetInstances()) {
    m_motor_chooser.AddOption(motor->GetName(), motor);
  }

  frc::Shuffleboard::GetTab("MisCar").Add(m_mode_chooser);
  frc::Shuffleboard::GetTab("MisCar").Add(m_motor_chooser);
#endif
}

Robot::~Robot() {}

void Robot::RobotInit() {}

void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
  log::Network("/MisCar/CompressorEnabled", m_compressor.Enabled());
  log::Network("/MisCar/Battery",
               frc::DriverStation::GetInstance().GetBatteryVoltage());
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit() {
  auto autonomous = m_autonomous_chooser.GetSelected();
  if (autonomous != nullptr) {
    autonomous->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  auto autonomous = m_autonomous_chooser.GetSelected();
  if (autonomous != nullptr) {
    autonomous->Cancel();
  }
}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {
#ifdef RUNNING_SYSTEM_CHECKS
  if (network::GetBool("Tuning/Activate")) {
    m_motor_chooser.GetSelected()->SetOutput(
        network::GetDouble("Tuning/Output"), m_mode_chooser.GetSelected());
  }
#endif
}