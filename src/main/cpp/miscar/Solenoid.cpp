#include "Solenoid.h"
#include "frc/Solenoid.h"

miscar::Solenoid::Solenoid(std::string&& name, int id)
    : frc::Solenoid(id), m_name(name) {}

const std::string& miscar::Solenoid::GetName() { return m_name; }