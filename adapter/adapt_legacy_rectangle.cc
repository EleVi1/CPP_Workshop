#include "adapt_legacy_rectangle.hh"

#include <cmath>
#include <iostream>

AdaptLegacyRectangle::AdaptLegacyRectangle(LegacyRectangle& rect)
    : rect_(rect)
{}

void AdaptLegacyRectangle::print() const
{
    std::cout << "x: " << rect_.get_x1() << " y: " << rect_.get_y1() << '\n'
              << "height: " << abs(rect_.get_y2() - rect_.get_y1()) << '\n'
              << "width: " << abs(rect_.get_x2() - rect_.get_x1()) << '\n';
}

unsigned AdaptLegacyRectangle::area() const
{
    return abs(rect_.get_y2() - rect_.get_y1())
        * abs(rect_.get_x2() - rect_.get_x1());
}

AdaptLegacyRectangle::~AdaptLegacyRectangle() = default;
