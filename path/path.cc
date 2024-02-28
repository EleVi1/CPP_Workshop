#include <iostream>
#include <sstream>
#include <array>

#include "path.hh"

Path& Path::join(const std::string& tail, bool is_file)
{
    if (this->final_)
    {
        return *this;
    }
    this->path_.emplace_back(tail);
    if (is_file)
    {
        final_ = true;
    }
    return *this;
}