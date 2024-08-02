#ifndef SSL_FIELDSHAPETYPE_HPP
#define SSL_FIELDSHAPETYPE_HPP

namespace tc {
namespace protobuf {
namespace geometry {

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

} // namespace geometry
} // namespace protobuf
} // namespace tc
#endif // SSL_FIELDSHAPETYPE_HPP__