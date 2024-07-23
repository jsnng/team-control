#ifndef SSL_GEOMETRYMODELS_H
#define SSL_GEOMETRYMODELS_H

struct SSL_BallModelStraightTwoPhase {
    double acc_slide;
    double acc_roll;
    double k_switch;
};

struct SSL_BallModelChipFixedLoss {
    double damping_xy_first_hop;
    double damping_xy_other_hops;
    double damping_z;
};

class SSL_GeometryModels {
    private:
        SSL_BallModelStraightTwoPhase * straight_two_phase;
        SSL_BallModelChipFixedLoss * chip_fixed_loss;
    public:
        SSL_GeometryModels();
        ~SSL_GeometryModels();
};

#endif