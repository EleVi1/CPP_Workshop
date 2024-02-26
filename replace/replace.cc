#include "replace.hh"

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::ifstream file_in;
    file_in.open(input_filename);
    if (!file_in.is_open())
    {
        std::cerr << "Cannot open input file\n";
        return;
    }

    std::ofstream file_out;
    file_out.open(output_filename);
    if (!file_out.is_open())
    {
        std::cerr << "Cannot write output file\n";
        return;
    }

    std::string line;
    size_t index;
    while (std::getline(file_in, line))
    {
        index = line.find(src_token);
        while (index != std::string::npos)
        {
            line.replace(index, src_token.length(), dst_token);
            index = line.find(src_token, index + dst_token.length());
        }
        file_out << line << '\n';
    }
}
