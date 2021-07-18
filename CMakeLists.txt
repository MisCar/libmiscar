cmake_minimum_required(VERSION 3.5)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
project(2021-cpp)

file(GLOB_RECURSE SOURCES "src/main/cpp/*.*")
file(GLOB_RECURSE TESTS "src/test/cpp/*.*")
add_executable(release ${SOURCES})
set_target_properties(release PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(release PRIVATE src/main/cpp)

set(INCLUDES
	external/api/include
	external/cci/include
	external/core/include
	external/cscore/include
	external/diagnostics/include
	external/hal/include
	external/ntcore/include
	external/platform/include
	external/sparkmax/include
	external/sparkmaxdriver/include
	external/talonsrx/include
	external/victorspx/include
	external/wpiapi/include
	external/wpilibc/include
	external/wpilibnewcommands/include
	external/wpimath/include
	external/wpiutil/include
)

target_include_directories(release SYSTEM PRIVATE
	${INCLUDES}
)

add_executable(test ${TESTS})
set_target_properties(test PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(test PRIVATE src/main/include)

target_include_directories(test PRIVATE
	${INCLUDES}
	external/gtest/include
)
