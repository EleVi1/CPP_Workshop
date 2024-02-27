#include <iostream>
#include <ios>
#include <iomanip>
#include <string>

#include "state_saver.hh"
#include "format_numerical_data.hh"
#include "vector.hh"
#include "formatted_vector.hh"

FormattedVector::FormattedVector(double x, double y)
        : FormatNumericalData("[ ", " ]", 12, true, true), Vector(x, y) {}

FormattedVector::FormattedVector(Vector vec)
        : FormatNumericalData("[ ", " ]", 12, true, true) {
    x_ = vec.get_x();
    y_ = vec.get_y();
}

std::ostream& operator<<(std::ostream& os, const FormattedVector& formattedVect)
{
    StateSaver svg(os);
    formattedVect.formatOs(os);
    os << formattedVect.prefix << formattedVect.x_ << " , "
    << formattedVect.y_ << formattedVect.suffix << '\n';
    return os;
}