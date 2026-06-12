add_executable(tc_tests SSL_Receiver_test.cpp)
target_link_libraries(tc_tests PRIVATE ssl_tc_model GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tc_tests
    PROPERTIES
    LABELS "unit"
)