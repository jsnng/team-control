#ifndef POINT_H_
#define POINT_H_

template <typename T> class Point {
    public:
    Point() =default;    
    ~Point() =default;

    inline void set_x(T x) {
        this->x = x;
    };
    inline void set_y(T y) {
        this->y = y;
    };
    inline void set_z(T z) {
        this->z = z;
    };
    inline T get_x() const {
        return this->x;
    };
    inline T get_y() const {
        return this->y;
    };
    inline T get_z() const {
        return this->z;
    };

    Point<T> transform_to_world_model(Point target);
    Point<T> transform_point_to_world_model(Point target);
    // T[2][2] constexpr get_transformation_matrx(Point<T> point);
    private:
    T x, y, z;
};

#endif //POINT_H_