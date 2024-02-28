#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <array>
#include "path.hh"

class UnixPath : public Path {
public:
    std::string to_string() const;
private:
};