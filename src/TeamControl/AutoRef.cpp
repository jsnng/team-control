#include "AutoRef.h"
#include "SSL_Receiver.h"

AutoRef::AutoRef() {

}
AutoRef::~AutoRef() {

}

/**
 * for testing purposes
 */
int
main(int argc, char * argv[]) {
    auto ssl_autoref_addr = SSLAutoRefReceiver::get_default_addr();
    SSLAutoRefReceiver ssl_autoref_recv(std::get<0>(ssl_autoref_addr), std::get<1>(ssl_autoref_addr));
    return EXIT_SUCCESS;
}