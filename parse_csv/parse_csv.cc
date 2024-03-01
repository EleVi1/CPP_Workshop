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
    std::getline(file, line);
    std::string word;
    size_t elements = 0;
    size_t pos;
    // First line : store and count elements on column
    std::vector<std::string> input;
    while ((pos = line.find(",")) != std::string::npos)
    {
        word = line.substr(0, pos);
        line.erase(0, pos + 1);
        // std::cout << "Word: " << word << '\n';
        elements++;
        input.push_back(word);
    }
    word = line.substr(0, pos);
    line.erase(0, pos + 1);
    // std::cout << "Word: " << word << '\n';
    elements++;
    input.push_back(word);
    result.push_back(input);

    size_t count = 0;
    size_t line_nb = 2;
    std::stringstream errMsg;
    while (std::getline(file, line))
    {
        std::vector<std::string> input;
        while (count < elements - 1
               && (pos = line.find(",")) != std::string::npos)
        {
            word = line.substr(0, pos);
            line.erase(0, pos + 1);
            // std::cout << "Word: " << word << '\n';
            count++;
            input.push_back(word);
        }
        word = line.substr(0, pos);
        line.erase(0, pos + 1);
        // std::cout << "Word: " << word << '\n';
        count++;
        input.push_back(word);

        if (count != elements
            || (pos = line.find(","))
                != std::string::npos) // too few or more than the precedent
                                      // column
        {
            errMsg << "Non consistent number of columns at line " << line_nb;
            throw std::ios_base::failure(errMsg.str());
        }
        result.push_back(input);
        count = 0;
        line_nb++;
    }
    return result;
}
