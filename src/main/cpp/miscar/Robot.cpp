// Copyright (c) MisCar 1574

#include "Robot.h"

#include <frc/DriverStation.h>

#include <string>

#include "frc2/command/Command.h"
#include "miscar/Log.h"
#include "miscar/Network.h"
#include "miscar/motor/Motor.h"

constexpr std::array STARS = {"Zaks",  "Szpiler", "Sheffi", "Toto",
                              "Mayan", "Hadas",   "Barak"};

miscar::Robot::Robot() {
  int index = (static_cast<double>(std::rand()) / RAND_MAX) * STARS.size();
  network::Set("Gever", std::string(STARS[index]));
}

miscar::Robot::~Robot() {}

void miscar::Robot::RobotInit() {
  m_mode_chooser.SetDefaultOption("Percent Output",
                                  miscar::Motor::PercentOutput);
  m_mode_chooser.AddOption("Position", miscar::Motor::Position);
  m_mode_chooser.AddOption("Velocity", miscar::Motor::Velocity);

  m_graph_mode_chooser.SetDefaultOption("Position", miscar::Motor::Position);
  m_graph_mode_chooser.AddOption("Velocity", miscar::Motor::Velocity);

  for (const auto& motor : Motor::GetInstances()) {
    m_activate_motor_chooser.AddOption(std::string(motor->GetName()), motor);
    m_sensor_motor_chooser.AddOption(std::string(motor->GetName()), motor);
  }

  for (const auto& solenoid : Solenoid::GetInstances()) {
    m_solenoid_chooser.AddOption(std::string(solenoid->GetName()), solenoid);
  }

  network::Add("Mode", m_mode_chooser);
  network::Add("Activate Motor", m_activate_motor_chooser);
  network::Add("Sensor Motor", m_sensor_motor_chooser);
  network::Add("Autonomous", m_autonomous_chooser);
  network::Add("Graph", m_graph_mode_chooser);

  network::SetDefault("Test/Motors/Enabled", false);
  network::SetDefault("Test/Motors/Output", 0);
  network::SetDefault("Test/Motors/SetPID", false);
  network::SetDefault("Test/Motors/P", 0);
  network::SetDefault("Test/Motors/I", 0);
  network::SetDefault("Test/Motors/D", 0);
  network::SetDefault("Test/Motors/F", 0);
  network::SetDefault("Test/Motors/I Zone", 0);
  network::SetDefault("Test/Motors/Slot", 0);
  network::SetDefault("Test/Motors/Value", 0);

  network::SetDefault("Test/Solenoids/Enabled", false);
  network::SetDefault("Test/Solenoids/Output", false);
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
  auto activate_motor = m_activate_motor_chooser.GetSelected();
  if (activate_motor != nullptr) {
    if (network::Get<bool>("Test/Motors/Enabled")) {
      activate_motor->SetOutput(network::Get<double>("Test/Motors/Output"),
                                m_mode_chooser.GetSelected());
    }

    if (network::Get<bool>("Test/Motors/SetPID")) {
      activate_motor->SetPID(PID(network::Get<double>("Test/Motors/P"),
                                 network::Get<double>("Test/Motors/I"),
                                 network::Get<double>("Test/Motors/D"),
                                 network::Get<double>("Test/Motors/F"),
                                 network::Get<double>("Test/Motors/I Zone"),
                                 network::Get<int>("Test/Motors/Slot")));
    }
  }

  auto sensor_motor = m_sensor_motor_chooser.GetSelected();
  if (sensor_motor != nullptr) {
    if (m_graph_mode_chooser.GetSelected() == Motor::Position) {
      network::Set("Test/Motors/Value", sensor_motor->GetPosition());
    } else {
      network::Set("Test/Motors/Value", sensor_motor->GetVelocity());
    }
  }

  auto solenoid = m_solenoid_chooser.GetSelected();
  if (solenoid != nullptr) {
    if (network::Get<bool>("Test/Solenoids/Enabled")) {
      solenoid->Set(network::Get<bool>("Test/Solenoids/Output"));
    }
  }
}

void miscar::Robot::AddAutonomous(std::string_view name,
                                  frc2::Command* command) {
  m_autonomous_chooser.AddOption(std::string(name), command);
}
