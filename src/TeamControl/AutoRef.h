#ifndef AUTOREF_H_
#define AUTOREF_H_

#include <ssl/ssl_referee.h>
#include <forward_list>

class AutoRef {
    public:
        AutoRef();
        ~AutoRef();
    private:
        std::forward_list<ssl::protobuf::Referee>* ssl_gc_autoref_messages;
};

#endif // AUTOREF_H_