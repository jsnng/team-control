#ifndef SSL_GEOMETRYDATA_HPP
#define SSL_GEOMETRYDATA_HPP

#include "SSL_GeometryFieldSize.hpp"
#include "SSL_GeometryModels.hpp"

namespace tc {
namespace protobuf {
namespace geometry {

struct SSL_GeometryCameraCalibration {
    uint32_t    camera_id; 
    float       focal_length; 
    float       principal_point_x; 
    float       principal_point_y; 
    float       distortion; 
    float       q0; 
    float       q1; 
    float       q2; 
    float       q3; 
    float       tx; 
    float       ty; 
    float       tz; 
    float       derived_camera_world_tx; 
    float       derived_camera_world_ty; 
    float       derived_camera_world_tz; 
    uint32_t    pixel_image_width; 
    uint32_t    pixel_image_height; 
};

class SSL_GeometryData {
    private:
        SSL_GeometryFieldSize *             field;
        SSL_GeometryCameraCalibration *     cali;
        SSL_GeometryModels *                models;
    public:
        SSL_GeometryData();
        ~SSL_GeometryData();
};

} // namespace geometry
} // namespace protobuf
} // namespace tc
#endif // SSL_GEOMETRYDATA_HPP__