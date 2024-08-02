#ifndef SSL_FIELDCIRCULARARC_HPP__
#define SSL_FIELDCIRCULARARC_HPP__

#include "Vector2f.hpp"
#include "SSL_FieldShapeType.hpp"
#include <string>

namespace tc {
namespace protobuf {
namespace geometry {

class SSL_FieldCircularArc {
    private:
        std::string         name;
        Vector2f *          center;
        float               radius;
        float               a1;
        float               a2;
        float               thickness;
        SSL_FieldShapeType  type;
    public:
        SSL_FieldCircularArc();
        ~SSL_FieldCircularArc();
};

} // namespace geometry
} // namespace protobuf
} // namespace tc
#endif // SSL_FIELDCIRCULARARC_HPP__