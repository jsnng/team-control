#ifndef SSL_SENDER_H_
#define SSL_SENDER_H_

#include "UDP.h"

/**
 * base multicast sender for ssl
 */
class SSLSenderBase : public UDP {
    public:
        SSLSenderBase(const std::string x, const uint32_t y) :
            UDP() {};
        ~SSLSenderBase();
    private:

};

class SSLVisionSender : public SSLSenderBase {
    public:
        SSLVisionSender(const std::string x = "225.5.23.255", const uint32_t y = 10006) : 
            SSLSenderBase(x, y) {};
    private:
};

class SSLAutoRefSender : public SSLSenderBase {
    public:
        SSLAutoRefSender(const std::string x = "224.5.23.255", const uint32_t y = 10003) : 
            SSLSenderBase(x, y) {};
    private:
};

class grSimVisionSender : public SSLSenderBase {
    public:
        grSimVisionSender(const std::string x = "224.5.23.255", const uint32_t y = 10020) : 
            SSLSenderBase(x, y) {};
    private:   
};

#endif //SSL_SENDER_H_