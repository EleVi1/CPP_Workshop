#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <array>

#include "path.hh"

class WindowsPath : public Path {
public:
    WindowsPath(char prefix);
    std::string to_string() const;
    WindowsPath& join(const std::string& tail, bool is_file = false) override;
private:
};