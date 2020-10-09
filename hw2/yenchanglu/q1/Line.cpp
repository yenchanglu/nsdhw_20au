#include "Line.hpp"

Line::Line(Line const &other) {
    m_coord.clear();
    copy(other.m_coord.begin(), other.m_coord.end(), back_inserter(m_coord));
}

Line::Line(Line &&other) {
    std::swap(other.m_coord, m_coord);
}

Line &Line::operator=(Line const &other) {
    if (this == &other) {
        return *this;
    }
    m_coord.clear();
    copy(other.m_coord.begin(), other.m_coord.end(), back_inserter(m_coord));

    return *this;
}

Line &Line::operator=(Line &&other) {
   if (this == &other) {
       return *this;
   }
   std::swap(other.m_coord, m_coord);

   return *this;
}

int main(int, char **)
{
    Line line(3);
    line.x(0) = 0; line.y(0) = 1;
    line.x(1) = 1; line.y(1) = 3;
    line.x(2) = 2; line.y(2) = 5;

    Line line2(line);
    line2.x(0) = 9;

    std::cout << "line: number of points = " << line.size() << std::endl;
    for (size_t it=0; it<line.size(); ++it)
    {
        std::cout << "point " << it << ":"
                  << " x = " << line.x(it)
                  << " y = " << line.y(it) << std::endl;
    }

    std::cout << "line2: number of points = " << line.size() << std::endl;
    for (size_t it=0; it<line.size(); ++it)
    {
        std::cout << "point " << it << ":"
                  << " x = " << line2.x(it)
                  << " y = " << line2.y(it) << std::endl;
    }

    return 0;
}
