#include "singleton.hh"

void Logger::open_log_file(const std::string& file)
{
    std::cout << "LOG: Open file " << file << "\n";
}

void Logger::write_to_log_file()
{
    std::cout << "LOG: Writing into log file ...\n";
}

void Logger::close_log_file()
{
    std::cout << "LOG: Closing log file ...\n";
}
