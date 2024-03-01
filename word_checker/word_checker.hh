#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

class WordChecker
{
public:
    WordChecker(std::string filename);
    bool operator()(std::string word);

private:
    std::string filename_;
    std::set<std::string> language_;
};