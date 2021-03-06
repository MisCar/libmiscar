// Copyright (c) MisCar 1574

#pragma once

#include <frc/GenericHID.h>

/**
 * Handle input from PS4 controllers connected to the Driver Station.
 *
 * <p>This class handles PS4 input that comes from the Driver Station. Each time
 * a value is requested the most recent value is returned. There is a single
 * class instance for each controller and the mapping of ports to hardware
 * buttons depends on the code in the Driver Station.
 */
namespace miscar {

class PS4Controller : public frc::GenericHID {
 public:
  /**
   * Construct an instance of an PS4 controller.
   *
   * The controller index is the USB port on the Driver Station.
   *
   * @param port The port on the Driver Station that the controller is plugged
   *             into (0-5).
   */
  explicit PS4Controller(int port);

  ~PS4Controller() override = default;

  PS4Controller(PS4Controller &&) = default;
  PS4Controller &operator=(PS4Controller &&) = default;

  /**
   * Get the X axis value of left side of the controller.
   *
   * @return the axis value.
   */
  double GetLeftX() const;

  /**
   * Get the X axis value of right side of the controller.
   *
   * @return the axis value.
   */
  double GetRightX() const;

  /**
   * Get the Y axis value of left side of the controller.
   *
   * @return the axis value.
   */
  double GetLeftY() const;

  /**
   * Get the Y axis value of right side of the controller.
   *
   * @return the axis value.
   */
  double GetRightY() const;

  /**
   * Get the L2 axis value of the controller. Note that this axis is bound to
   * the range of [0, 1] as opposed to the usual [-1, 1].
   *
   * @return the axis value.
   */
  double GetL2Axis() const;

  /**
   * Get the R2 axis value of the controller. Note that this axis is bound to
   * the range of [0, 1] as opposed to the usual [-1, 1].
   *
   * @return the axis value.
   */
  double GetR2Axis() const;

  /**
   * Read the value of the Square button on the controller.
   *
   * @return The state of the button.
   */
  bool GetSquareButton() const;

  /**
   * Whether the Square button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetSquareButtonPressed();

  /**
   * Whether the Square button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetSquareButtonReleased();

  /**
   * Read the value of the Cross button on the controller.
   *
   * @return The state of the button.
   */
  bool GetCrossButton() const;

  /**
   * Whether the Cross button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetCrossButtonPressed();

  /**
   * Whether the Cross button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetCrossButtonReleased();

  /**
   * Read the value of the Circle button on the controller.
   *
   * @return The state of the button.
   */
  bool GetCircleButton() const;

  /**
   * Whether the Circle button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetCircleButtonPressed();

  /**
   * Whether the Circle button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetCircleButtonReleased();

  /**
   * Read the value of the Triangle button on the controller.
   *
   * @return The state of the button.
   */
  bool GetTriangleButton() const;

  /**
   * Whether the Triangle button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetTriangleButtonPressed();

  /**
   * Whether the Triangle button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetTriangleButtonReleased();

  /**
   * Read the value of the L1 button on the controller.
   *
   * @return The state of the button.
   */
  bool GetL1Button() const;

  /**
   * Whether the L1 button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetL1ButtonPressed();

  /**
   * Whether the L1 button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetL1ButtonReleased();

  /**
   * Read the value of the R1 button on the controller.
   *
   * @return The state of the button.
   */
  bool GetR1Button() const;

  /**
   * Whether the R1 button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetR1ButtonPressed();

  /**
   * Whether the R1 button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetR1ButtonReleased();

  /**
   * Read the value of the Share button on the controller.
   *
   * @return The state of the button.
   */
  bool GetShareButton() const;

  /**
   * Whether the Share button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetShareButtonPressed();

  /**
   * Whether the Share button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetShareButtonReleased();

  /**
   * Read the value of the Options button on the controller.
   *
   * @return The state of the button.
   */
  bool GetOptionsButton() const;

  /**
   * Whether the Options button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetOptionsButtonPressed();

  /**
   * Whether the Options button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetOptionsButtonReleased();

  /**
   * Read the value of the L3 button (pressing the left analog stick) on the
   * controller.
   *
   * @return The state of the button.
   */
  bool GetL3Button() const;

  /**
   * Whether the L3 (left stick) button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetL3ButtonPressed();

  /**
   * Whether the L3 (left stick) button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetL3ButtonReleased();

  /**
   * Read the value of the R3 button (pressing the right analog stick) on the
   * controller.
   *
   * @return The state of the button.
   */
  bool GetR3Button() const;

  /**
   * Whether the R3 (right stick) button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetR3ButtonPressed();

  /**
   * Whether the R3 (right stick) button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetR3ButtonReleased();

  struct Button {
    static constexpr int kCross = 1;
    static constexpr int kCircle = 2;
    static constexpr int kSquare = 3;
    static constexpr int kTriangle = 4;
    static constexpr int kL1 = 5;
    static constexpr int kR1 = 6;
    static constexpr int kShare = 7;
    static constexpr int kOptions = 8;
    static constexpr int kL3 = 9;
    static constexpr int kR3 = 10;
  };

  struct Axis {
    static constexpr int kLeftX = 0;
    static constexpr int kLeftY = 1;
    static constexpr int kRightX = 4;
    static constexpr int kRightY = 5;
    static constexpr int kL2 = 2;
    static constexpr int kR2 = 3;
  };
};
}  // namespace miscar
