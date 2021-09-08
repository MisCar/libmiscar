// Copyright (c) MisCar 1574

#include "Robot.h"

#include <frc/DriverStation.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include "miscar/Log.h"
#include "miscar/Network.h"
#include "miscar/motor/Motor.h"

const std::string GEVARIM[] = {"Zaks",  "Szpiler", "Sheffi", "Toto",
                               "Mayan", "Hadas",   "Barak"};
constexpr auto GEVARIM_COUNT = sizeof(GEVARIM) / sizeof(GEVARIM[0]);

miscar::Robot::Robot() {
  int index = (static_cast<double>(std::rand()) / RAND_MAX) * GEVARIM_COUNT;
  log::Network("Gever", GEVARIM[index]);
  frc::Shuffleboard::GetTab("MisCar").Add(m_autonomous_chooser);

  m_mode_chooser.SetDefaultOption("Percent Output",
                                  miscar::Motor::PercentOutput);
  m_mode_chooser.AddOption("Position", miscar::Motor::Position);
  m_mode_chooser.AddOption("Velocity", miscar::Motor::Velocity);

  for (const auto& motor : Motor::GetInstances()) {
    m_motor_chooser.AddOption(motor->GetName(), motor);
  }

  frc::Shuffleboard::GetTab("MisCar").Add(m_mode_chooser);
  frc::Shuffleboard::GetTab("MisCar").Add(m_motor_chooser);
}

miscar::Robot::~Robot() {}

void miscar::Robot::RobotInit() {}

void miscar::Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
  log::Network("/MisCar/CompressorEnabled", m_compressor.Enabled());
  log::Network("/MisCar/Battery",
               frc::DriverStation::GetInstance().GetBatteryVoltage());
}

void miscar::Robot::DisabledInit() {}

void miscar::Robot::DisabledPeriodic() {}

void miscar::Robot::AutonomousInit() {
  auto autonomous = m_autonomous_chooser.GetSelected();
  if (autonomous != nullptr) {
    // Periodic tasks are run in this command
    autonomous->Schedule();
  }
}

void miscar::Robot::AutonomousPeriodic() {}

void miscar::Robot::TeleopInit() {
  auto autonomous = m_autonomous_chooser.GetSelected();
  if (autonomous != nullptr) {
    autonomous->Cancel();
  }
}

void miscar::Robot::TeleopPeriodic() {
  // Periodic tasks are run through default commands
}

void miscar::Robot::TestPeriodic() {
  if (network::Get<bool>("Tuning/Activate")) {
    m_motor_chooser.GetSelected()->SetOutput(
        network::Get<double>("Tuning/Output"), m_mode_chooser.GetSelected());
  }
}
