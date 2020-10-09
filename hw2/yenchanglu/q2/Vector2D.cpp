#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>
#include <cmath>
#include <vector>

namespace py = pybind11;

float getAngle(const std::vector<float> v1, const std::vector<float> v2) {
    if(v1.size() != 2 || v2.size() !=2) {
        throw std::invalid_argument("Invalid arguments of each vector");
    }

    double dot = (v1[0] * v2[0] + v1[1] * v2[1]);
    double len = ((v1[0] * v1[0] + v1[1] * v1[1]) * (v2[0] * v2[0] + v2[1] * v2[1]));
    double res = dot / sqrt(len);

    if (res >= 1.0f) {
        return 0.0f;
    } else if (res <= -1.0f) {
        return M_PI;
    }

    return std::acos(dot / len);
}

PYBIND11_MODULE(Vector2D, m) {
    m.doc() = "Vector2D plugin";
    m.def("getAngle", &getAngle, "a function that calculates the angle (in radians) between two vectors in the 2-dimensional Cartesian coordinate system");
}
