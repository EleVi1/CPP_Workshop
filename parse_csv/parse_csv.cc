#include "parse_csv.hh"

std::vector<std::vector<std::string>> parse_csv(const std::string& file_name)
{
    std::vector<std::vector<std::string>> result;

    std::ifstream file;
    file.open(file_name);
    if (!file)
    {
        throw std::ios_base::failure("Error opening file");
    }
    std::string line;
    std::string word;
    size_t elements = 0;
    size_t line_nb = 1;
    while (std::getline(file, line))
    {
        std::stringstream lineStream(line);
        std::vector<std::string> input;
        if (line_nb == 1)
        {
            while (std::getline(lineStream, word, ','))
            {
                elements++;
                input.push_back(word);
            }
        }
        else
        {
            size_t count = 0;
            while (count < elements && std::getline(lineStream, word, ','))
            {
                count++;
                input.push_back(word);
            }
            if (count != elements || std::getline(lineStream, word, ','))
            {
                std::stringstream errMsg;
                errMsg << "Non consistent number of columns at line "
                       << line_nb;
                throw std::ios_base::failure(errMsg.str());
            }
        }
        result.push_back(input);
        line_nb++;
    }
    return result;
}