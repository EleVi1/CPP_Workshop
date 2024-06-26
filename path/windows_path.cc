#include "windows_path.hh"

WindowsPath::WindowsPath(char prefix)
{
    path_.emplace_back(std::string(1, prefix));
}

std::string WindowsPath::to_string() const
{
    std::ostringstream output;
    if (path_.empty() || path_[0].length() != 1)
    {
        return "";
    }
    size_t i = 0;
    output << path_[0] << ':';
    for (i = 1; i < path_.size(); ++i)
    {
        output << "\\" << path_[i];
    }
    if (!this->final_)
    {
        output << "\\";
    }
    return output.str();
}

WindowsPath& WindowsPath::join(const std::string& tail, bool is_file)
{
    if (this->final_)
    {
        return *this;
    }
    if (tail.find('"') != std::string::npos
        || tail.find('?') != std::string::npos
        || tail.find('|') != std::string::npos
        || tail.find('*') != std::string::npos
        || tail.find(':') != std::string::npos)
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