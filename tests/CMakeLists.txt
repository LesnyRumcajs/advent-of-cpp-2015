add_executable(
        day1_tests
        day1_tests.cc
)

conan_target_link_libraries(day1_tests)

add_test(
        NAME day1_tests
        COMMAND day1_tests)