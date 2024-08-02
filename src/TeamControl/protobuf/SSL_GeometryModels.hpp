#ifndef SSL_GEOMETRYMODELS_HPP
#define SSL_GEOMETRYMODELS_HPP

namespace tc {
namespace protobuf {
namespace geometry {

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

class SSL_GeometryModels {
    private:
        SSL_BallModelStraightTwoPhase *     straight_two_phase;
        SSL_BallModelChipFixedLoss *        chip_fixed_loss;
    public:
        SSL_GeometryModels();
        ~SSL_GeometryModels();
};

} // namespace geometry
} // namespace protobuf
} // namespace tc

#endif // SSL_GEOMETRYMODELS_HPP__ 