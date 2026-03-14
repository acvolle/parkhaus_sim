cmake_minimum_required(VERSION 3.10)

project(parkhaus_sim C)

# C-Standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include-folders
include_directories(include)

# --------------------------------------------------
# Merge src files to library "parkhaus_logic"
# --------------------------------------------------

add_library(parkhaus_logic
    src/car.c
    src/queue.c
    src/parking.c
    src/stats.c
    src/simulation.c
    src/ui.c
)


# --------------------------------------------------
# Unit-Test-Executables
# --------------------------------------------------

add_executable(test_car test/test_car.c)
target_link_libraries(test_car parkhaus_logic)

add_executable(test_queue test/test_queue.c)
target_link_libraries(test_queue parkhaus_logic)

add_executable(test_parking test/test_parking.c)
target_link_libraries(test_parking parkhaus_logic)

add_executable(test_stats test/test_stats.c)
target_link_libraries(test_stats parkhaus_logic)

add_executable(test_simulation test/test_simulation.c)
target_link_libraries(test_simulation parkhaus_logic)

add_executable(test_ui test/test_ui.c)
target_link_libraries(test_ui parkhaus_logic)

# --------------------------------------------------
# Activate CTest
# --------------------------------------------------

enable_testing()

add_test(NAME CarTests COMMAND test_car)
add_test(NAME QueueTests COMMAND test_queue)
add_test(NAME ParkingTests COMMAND test_parking)
add_test(NAME StatsTests COMMAND test_stats)
add_test(NAME SimulationTests COMMAND test_simulation)
add_test(NAME UiTests COMMAND test_ui)


# --------------------------------------------------
# Ensure testing before each build
# --------------------------------------------------

add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_car test_queue test_parking test_stats test_simulation test_ui
    COMMENT "Running unit tests before building main app"
)

# --------------------------------------------------
# Main Executable
# --------------------------------------------------

add_executable(parkhaus_sim
    src/main.c
)

# Link library to main app
target_link_libraries(parkhaus_sim
    parkhaus_logic
)

# only build main if tests were successful
add_dependencies(parkhaus_sim run_tests)