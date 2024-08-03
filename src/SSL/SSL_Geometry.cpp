#include "ssl_geometry.h"

using namespace ssl::protobuf::geometry;

std::string 
SSL_GeometryData::to_string(const SSL_FieldShapeType& t) noexcept {
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wc++11-extensions"
    switch(t) {
        case SSL_FieldShapeType::Undefined:
        default: {
            return "UNDEFINED";
        };
    };
    #pragma clang diagnostic pop
}

SSL_GeometryData::SSL_GeometryData() {

}

SSL_GeometryData::~SSL_GeometryData() {
    
}