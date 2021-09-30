add_executable(
        day1_tests
        day1_tests.cc
)
conan_target_link_libraries(day1_tests)
add_test(
        NAME day1_tests
        COMMAND day1_tests)

add_executable(
        day2_tests
        day2_tests.cc
)
conan_target_link_libraries(day2_tests)
add_test(
        NAME day2_tests
        COMMAND day2_tests)

add_executable(
        day3_tests
        day3_tests.cc
)
conan_target_link_libraries(day3_tests)
add_test(
        NAME day3_tests
        COMMAND day3_tests)
