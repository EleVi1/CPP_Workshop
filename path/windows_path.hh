#pragma once

#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "path.hh"

class WindowsPath : public Path
{
public:
    WindowsPath(char prefix);
    std::string to_string() const override;
    WindowsPath& join(const std::string& tail, bool is_file = false) override;

private:
};