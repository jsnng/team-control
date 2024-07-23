#ifndef SSL_FIELDCIRCULARARC_H
#define SSL_FIELDCIRCULARARC_H

#include "Vector2f.hpp"
#include "SSL_FieldShapeType.hpp"
#include <string>

class SSL_FieldCircularArc {
    private:
        std::string name;
        Vector2f * center;
        float radius;
        float a1;
        float a2;
        float thickness;
        SSL_FieldShapeType type;
    public:
        SSL_FieldCircularArc();
        ~SSL_FieldCircularArc();
};

#endif