#include "unix_path.hh"

std::string UnixPath::to_string() const
{
    std::ostringstream out;
    if (path_.size() == 0)
    {
        return "/";
    }
    size_t i = 0;
    for (i = 0; i < path_.size() - 1; ++i)
    {
        out << "/" << path_[i];
    }
    out << "/" << path_[i];
    if (!this->final_)
    {
        out << "/";
    }
    return out.str();
}