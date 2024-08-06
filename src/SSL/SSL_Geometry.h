#ifndef SSL_GEOMETRYDATA_H_
#define SSL_GEOMETRYDATA_H_

#include <vector>
#include <cassert>

namespace ssl {
namespace protobuf {
namespace geometry {

/**
* protobuf message `SSL_GeometryData`
* @see src/TeamControl/protobuf/ssl_vision_geometry.proto
*/
class SSL_GeometryData {
    public:
        enum class SSL_FieldShapeType {
            Undefined,
            CenterCircle,
            TopTouchLine,
            BottomTouchLine,
            LeftGoalLine,
            RightGoalLine,
            HalfwayLine,
            CenterLine,
            LeftPenaltyStretch,
            RightPenaltyStretch,
            LeftFieldLeftPenaltyStretch,
            LeftFieldRightPenaltyStretch,
            RightFieldLeftPenaltyStretch,
            RightFieldRightPenaltyStretch
        };
        
        std::string to_string(const SSL_FieldShapeType&) noexcept;

        SSL_GeometryData();
        ~SSL_GeometryData();

    private:
    
    struct Vector2f {
        float x;
        float y;
    };

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

    struct SSL_BallModelStraightTwoPhase {
        double      acc_slide;
        double      acc_roll;
        double      k_switch;
    };

    struct SSL_BallModelChipFixedLoss {
        double      damping_xy_first_hop;
        double      damping_xy_other_hops;
        double      damping_z;
    };

    struct SSL_GeometryModels {
            SSL_BallModelStraightTwoPhase *     straight_two_phase;
            SSL_BallModelChipFixedLoss *        chip_fixed_loss;
    };

    struct SSL_FieldCircularArc {
        std::string         name;
        Vector2f *          center;
        float               radius;
        float               a1;
        float               a2;
        float               thickness;
        SSL_FieldShapeType  type;
    };

    struct SSL_FieldLineSegment {
        std::string         name;
        Vector2f *          p1;
        Vector2f *          p2;
        float               thickness;
        SSL_FieldShapeType  type;
    };

    struct SSL_FieldCircularArc {
        std::string         name;
        Vector2f *          center;
        float               radius;
        float               a1;
        float               a2;
        float               thickness;
        SSL_FieldShapeType  type;
    };

    struct SSL_GeometryFieldSize {
        int32_t                 field_length;
        int32_t                 field_width;
        int32_t                 goal_width;
        int32_t                 goal_depth;
        int32_t                 boundary_width;
        SSL_FieldLineSegment*   field_lines;
        SSL_FieldCircularArc*   field_arcs;
        int32_t                 penalty_area_depth;
        int32_t                 penalty_area_width;;
    };

    SSL_GeometryFieldSize*             field;
    SSL_GeometryCameraCalibration*     cali;
    SSL_GeometryModels*                models;

};

} // namespace geometry
} // namespace protobuf
} // namespace tc
#endif // SSL_GEOMETRYDATA_H_