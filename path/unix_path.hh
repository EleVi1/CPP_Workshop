#pragma once

#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "path.hh"

class UnixPath : public Path
{
public:
    std::string to_string() const override;

private:
};