#ifndef SSL_FIELDLINESEGMENT_H
#define SSL_FIELDLINESEGMENT_H

#include "Vector2f.hpp"
#include "SSL_FieldShapeType.hpp"

#include <string>

class SSL_FieldLineSegment {
    private:
        std::string name;
        Vector2f * p1;
        Vector2f * p2;
        float thickness;
        SSL_FieldShapeType type;
    public:
        SSL_FieldLineSegment();
        ~SSL_FieldLineSegment();
};

#endif