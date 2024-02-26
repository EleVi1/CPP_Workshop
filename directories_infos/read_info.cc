#include "read_info.hh"

DirectoryInfo read_info(std::istream& input_file)
{
    std::string name;
    size_t size;
    uint16_t rights;
    std::string owner;

    std::string line;

    std::getline(input_file, line);
    std::istringstream input(line);

    if (!(input >> name))
    {
        return DirectoryInfo();
    }
    if (!(input >> size))
    {
        return DirectoryInfo();
    }
    if (!(input >> std::oct >> rights))
    {
        return DirectoryInfo();
    }
    if (!(input >> owner))
    {
        return DirectoryInfo();
    }
    return DirectoryInfo(name, size, rights, owner);
}
