#include "replace.hh"

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::ifstream input_file;
    input_file.open(input_filename);
    if (!input_file.is_open())
    {
        std::cerr << "Cannot open input file\n";
        return;
    }

    std::ofstream output_file;
    output_file.open(output_filename);
    if (!output_file.is_open())
    {
        std::cerr << "Cannot write output file\n";
        return;
    }

    std::string line;
    while (std::getline(input_file, line))
    {
        size_t index = line.find(src_token);
        while (index != std::string::npos)
        {
            line.replace(index, src_token.length(), dst_token);
            index = line.find(src_token, index + dst_token.length());
        }
        output_file << line << '\n';
    }
}
