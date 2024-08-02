#ifndef SSL_FIELDLINESEGMENT_HPP__
#define SSL_FIELDLINESEGMENT_HPP__

#include "Vector2f.hpp"
#include "SSL_FieldShapeType.hpp"

#include <string>

namespace tc {
namespace protobuf {
namespace geometry {

class SSL_FieldLineSegment {
    private:
        std::string         name;
        Vector2f *          p1;
        Vector2f *          p2;
        float               thickness;
        SSL_FieldShapeType  type;
    public:
        SSL_FieldLineSegment();
        ~SSL_FieldLineSegment();
};

} // namespace geometry
} // namespace protobuf
} // namespace tc
#endif // SSL_FIELDLINESEGMENT_HPP__