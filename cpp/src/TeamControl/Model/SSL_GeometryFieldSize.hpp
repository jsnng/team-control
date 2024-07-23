#ifndef SSL_GEOMETRYFIELDSSIZE_H
#define SSL_GEOMETRYFIELDSSIZE_H 

#include "SSL_FieldLineSegment.hpp"
#include "SSL_FieldCircularArc.hpp"
#include <vector>

class SSL_GeometryFieldSize {
    private:
        int32_t field_length;
        int32_t field_width;
        int32_t goal_width;
        int32_t goal_depth;
        int32_t boundary_width;
        SSL_FieldLineSegment * field_lines;
        SSL_FieldCircularArc * field_arcs;
        int32_t penalty_area_depth;
        int32_t penalty_area_width;
    public:
        SSL_GeometryFieldSize();
        ~SSL_GeometryFieldSize();
};

#endif