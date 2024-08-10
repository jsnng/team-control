#ifndef SSL_RECEIVER_H_
#define SSL_RECEIVER_H_

#include "UDP.h"

/**
 * base multicast receiver for ssl
 */
class SSLReceiverBase : public UDP {
    public:
        SSLReceiverBase(const std::string x, const uint32_t y);
    private:
};

class SSLVisionReceiver : public SSLReceiverBase {
    public:
        SSLVisionReceiver(const std::string x = "225.5.23.2", const uint32_t y = 10006) : 
            SSLReceiverBase(x, y) {};
    private:
};

class SSLAutoRefReceiver : public SSLReceiverBase {
    public:
        SSLAutoRefReceiver(const std::string x = "224.5.23.1", const uint32_t y = 10003) : 
            SSLReceiverBase(x, y) {};
    private:
};

class grSimVisionReceiver : public SSLReceiverBase {
    public:
        grSimVisionReceiver(const std::string x = "224.5.23.2", const uint32_t y = 10020) : 
            SSLReceiverBase(x, y) {};
    private:   
};

#endif //SSL_RECEIVER_H_