#include "word_checker.hh"

WordChecker::WordChecker(std::string filename)
{
    this->filename_ = filename;
}

bool WordChecker::operator()(std::string word)
{
    std::ifstream file;
    file.open(filename_);
    std::string line;
    while (std::getline(file, line))
    {
        language_.insert(line);
    }
    if (word.length() == 1)
    {
        return (language_.count(word));
    }
    std::vector<std::string> pairs;
    std::string subword;
    for (size_t i = 0; i < word.length(); i++)
    {
        subword = word.substr(i, 2);
        pairs.push_back(subword);
    }
    bool belong;
    for (auto sub : pairs)
    {
        // std::cout << "Subword: " << sub << '\n';
        belong = false;
        auto it = language_.begin();
        for (; it != language_.end(); it++)
        {
            if (it->find(sub) != std::string::npos)
            {
                // std::cout << "PASSED\n";
                belong = true;
                break;
            }
        }
        if (!belong)
        {
            return false;
        }
    }
    return true;
}
