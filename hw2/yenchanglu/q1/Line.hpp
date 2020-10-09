#pragma once

#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <iterator>

class Line {
public:
    Line() = default;
    Line(Line const &);
    Line(Line &&);
    Line &operator=(Line const&);
    Line &operator=(Line &&);
    Line(size_t size) { m_coord.resize(size*2); }
    ~Line() { m_coord.clear(); }
    size_t size() const { return m_coord.size() / 2; }
    float const &x(size_t it) const { bounds_check(it); return m_coord[it*2]; }
    float &x(size_t it) { bounds_check(it); return m_coord[it*2]; }
    float const &y(size_t it) const { bounds_check(it); return m_coord[it*2+1]; }
    float &y(size_t it) { bounds_check(it); return m_coord[it*2+1]; }

private:
    std::vector<float> m_coord;
    void bounds_check(size_t it) const
    { if (it >= m_coord.size()) { throw std::out_of_range("Line index out of range"); } }
};
