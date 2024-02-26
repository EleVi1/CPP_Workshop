#pragma once

#include <cstdint>
#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

#include "directory_info.hh"

DirectoryInfo read_info(std::istream& input_file);
