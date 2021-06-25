/**
 * WPI Compliant motor controller class.
 * WPILIB's object model requires many interfaces to be implemented to use
 * the various features.
 * This includes...
 * - Software PID loops running in the robot controller
 * - LiveWindow/Test mode features
 * - Motor Safety (auto-turn off of motor if Set stops getting called)
 * - Single Parameter set that assumes a simple motor controller.
 */
#pragma once

#include "ctre/phoenix/motorcontrol/can/TalonFX.h"
#include "ctre/phoenix/motorcontrol/can/WPI_BaseMotorController.h"

//Need to disable certain warnings for WPI headers.
#if __GNUC__
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wconversion"
#elif _MSC_VER
	#pragma warning(push)
	#pragma warning(disable : 4522 4458 4522 4250)
#endif

#include "frc/smartdashboard/SendableBase.h"
#include "frc/smartdashboard/SendableBuilder.h"
#include "frc/SpeedController.h"
#include "frc/MotorSafety.h"
#include "wpi/raw_ostream.h"
#include <mutex>

//Put the warning settings back to normal
#if __GNUC__
	#pragma GCC diagnostic pop
#elif _MSC_VER
	#pragma warning(pop)
#endif


//Turn off dominance warning
#if _MSC_VER
	#pragma warning(push)
	#pragma warning(disable : 4250)
#endif

namespace ctre {
namespace phoenix {
namespace motorcontrol {
namespace can {

/**
 * CTRE Talon SRX Motor Controller when used on CAN Bus.
 */
class WPI_TalonFX : public virtual TalonFX,
					 public virtual WPI_BaseMotorController
{
public:
	/**
	 * Constructor for a WPI_TalonFX
	 * @param deviceNumber Device ID of TalonFX
	 */
	WPI_TalonFX(int deviceNumber);
	virtual ~WPI_TalonFX();

	WPI_TalonFX() = delete;
	WPI_TalonFX(WPI_TalonFX const &) = delete;
	WPI_TalonFX &operator=(WPI_TalonFX const &) = delete;

	/* ----- virtual re-directs ------- */
	virtual void Set(double value);
	virtual void Set(ControlMode mode, double value);
	virtual void Set(ControlMode mode, double demand0, DemandType demand1Type, double demand1);
	virtual void Set(TalonFXControlMode mode, double value);
	virtual void Set(TalonFXControlMode mode, double demand0, DemandType demand1Type, double demand1);
	virtual void SetVoltage(units::volt_t output);
	virtual void SetInverted(TalonFXInvertType invertType);
	virtual void SetInverted(InvertType invertType);
	virtual void SetInverted(bool bInvert);
	virtual ctre::phoenix::ErrorCode ConfigSelectedFeedbackSensor(FeedbackDevice feedbackDevice, int pidIdx = 0, int timeoutMs = 0);
	virtual ctre::phoenix::ErrorCode ConfigSelectedFeedbackSensor(RemoteFeedbackDevice feedbackDevice, int pidIdx = 0, int timeoutMs = 0);

protected:
	
private:

};

} // namespace can
} // namespace motorcontrol
} // namespace phoenix
} // namespace ctre

#if _MSC_VER
	#pragma warning(pop)
#endif