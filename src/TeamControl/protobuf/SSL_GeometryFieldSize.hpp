#ifndef SSL_GEOMETRYFIELDSSIZE_HPP__
#define SSL_GEOMETRYFIELDSSIZE_HPP__

#include "SSL_FieldLineSegment.hpp"
#include "SSL_FieldCircularArc.hpp"
#include <vector>

namespace tc {
namespace protobuf {
namespace geometry {

class SSL_GeometryFieldSize {
    private:
        int32_t                 field_length;
        int32_t                 field_width;
        int32_t                 goal_width;
        int32_t                 goal_depth;
        int32_t                 boundary_width;
        SSL_FieldLineSegment *  field_lines;
        SSL_FieldCircularArc *  field_arcs;
        int32_t                 penalty_area_depth;
        int32_t                 penalty_area_width;;
    public:
        SSL_GeometryFieldSize();
        ~SSL_GeometryFieldSize();
};

} // namespace geometry
} // namespace protobuf
} // namespace tc

#endif // SSL_GEOMETRYFIELDSSIZE_HPP__