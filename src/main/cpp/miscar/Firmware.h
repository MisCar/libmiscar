// Copyright (c) MisCar 1574

#pragma once

namespace firmware {

/**
 * The latest Talon firmware version, currently 21.0.0.0.
 * https://www.ctr-electronics.com/talon-fx.html#product_tabs_technical_resources
 */
constexpr int FALCON = 21 * 16 * 16;

/**
 * The latest Spark firmware version, currently 1.5.4.
 * https://docs.revrobotics.com/sparkmax/software-resources/spark-max-api-information
 */
constexpr int SPARK = 0;

/**
 * The latest Talon firmware version, currently 21.0.
 * https://www.ctr-electronics.com/talon-srx.html#product_tabs_technical_resources
 */
constexpr int TALON = 5376;

/**
 * The latest Victor firmware version, currently 21.0.
 * http://www.ctr-electronics.com/victor-spx.html#product_tabs_technical_resources
 */
constexpr int VICTOR = 0;

}  // namespace firmware
