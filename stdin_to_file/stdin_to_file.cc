#include "stdin_to_file.hh"

ssize_t stdin_to_file(const std::string& filename)
{
    auto nb = 0;
    std::ofstream file_out;
    file_out.open(filename);

    std::string word;
    while (std::cin >> word)
    {
        file_out << word << '\n';
        nb++;
    }
    return nb;
}
