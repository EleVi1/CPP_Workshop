#include <iostream>
#include <ios>
#include <iomanip>

#include "format_numerical_data.hh"

FormatNumericalData::FormatNumericalData(const std::string &prefix,
                                         const std::string &suffix, int precision,
                                         bool scientific_notation, bool display_plus) {
    this->prefix = prefix;
    this->suffix = suffix;
    this->precision = precision;
    this->scientific_notation = scientific_notation;
    this->display_plus = display_plus;
}

std::ostream &FormatNumericalData::formatOs(std::ostream &os) const {
    if (precision >= 0)
    {
        os << std::setprecision(precision);
    }
    if (scientific_notation)
    {
        os << std::scientific;
    }
    if (display_plus)
    {
        os << std::showpos;
    }
    return os;
}
