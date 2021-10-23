// Copyright (c) MisCar 1574

#include "Robot.h"

#include <frc/DriverStation.h>

#include "frc2/command/Command.h"
#include "miscar/Log.h"
#include "miscar/Network.h"
#include "miscar/motor/Motor.h"

constexpr std::string_view GEVARIM[] = {"Zaks",  "Szpiler", "Sheffi", "Toto",
                                        "Mayan", "Hadas",   "Barak"};
constexpr auto GEVARIM_COUNT = sizeof(GEVARIM) / sizeof(GEVARIM[0]);

miscar::Robot::Robot() {
  int index = (static_cast<double>(std::rand()) / RAND_MAX) * GEVARIM_COUNT;
  network::Set("Gever", std::string(GEVARIM[index]));
}

miscar::Robot::~Robot() {}

void miscar::Robot::RobotInit() {
  m_mode_chooser.SetDefaultOption("Percent Output",
                                  miscar::Motor::PercentOutput);
  m_mode_chooser.AddOption("Position", miscar::Motor::Position);
  m_mode_chooser.AddOption("Velocity", miscar::Motor::Velocity);

  m_graph_chooser.SetDefaultOption("Position", miscar::Motor::Position);
  m_graph_chooser.AddOption("Velocity", miscar::Motor::Velocity);

  for (const auto& motor : Motor::GetInstances()) {
    m_motor_chooser.AddOption(motor->GetName(), motor);
  }

  network::Add("Mode", m_mode_chooser);
  network::Add("Motor", m_motor_chooser);
  network::Add("Autonomous", m_autonomous_chooser);
  network::Add("Graph", m_graph_chooser);

  network::Set("Test/Enabled", false);
  network::Set("Test/Output", 0);
  network::Set("Test/SetPID", false);
  network::Set("Test/P", 0);
  network::Set("Test/I", 0);
  network::Set("Test/D", 0);
  network::Set("Test/F", 0);
  network::Set("Test/I Zone", 0);
  network::Set("Test/Slot", 0);
}

void miscar::Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
  network::Set("Battery",
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
  auto motor = m_motor_chooser.GetSelected();
  if (motor != nullptr) {
    if (network::Get<bool>("Test/Enabled")) {
      motor->SetOutput(network::Get<double>("Test/Output"),
                       m_mode_chooser.GetSelected());
    }

    if (network::Get<bool>("Test/SetPID")) {
      motor->SetPID(
          {network::Get<double>("Test/P"), network::Get<double>("Test/I"),
           network::Get<double>("Test/D"), network::Get<double>("Test/F"),
           network::Get<double>("Test/I Zone"),
           network::Get<int>("Test/Slot")});
    }

    if (m_graph_chooser.GetSelected() == Motor::Position) {
      network::Set("Test/Value", motor->GetPosition());
    } else {
      network::Set("Test/Value", motor->GetVelocity());
    }
  }
}

void miscar::Robot::AddAutonomous(std::string_view name,
                                  frc2::Command* command) {
  m_autonomous_chooser.AddOption(name, command);
}
