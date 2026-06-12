#include <gtest/gtest.h>
#include "SSL_Receiver.h"

TEST(SSLReceiver, RejectsPortZero) {
    EXPECT_THROW(SSLVisionReceiver("0.0.0.0", "224.5.23.2", 0), std::runtime_error);
}

TEST(SSLReceiver, RejectsPortAbove65535) {
    EXPECT_THROW(SSLVisionReceiver("0.0.0.0", "224.5.23.2", 70000), std::runtime_error);
}
TEST(SSLReceiver, AcceptsValidPort) {
    EXPECT_NO_THROW(SSLVisionReceiver{});
}