#pragma once
#include <cassert>
#include <iostream>
#include <memory>
#include <string>

template <typename U>
class Singleton
{
public:
    Singleton& operator=(const Singleton&) = delete;
    Singleton(const Singleton&) = delete;
    static U& instance();

protected:
    Singleton() = default;
    ~Singleton() = default;
};

class Logger : public Singleton<Logger>
{
public:
    friend class Singleton<Logger>;
    void open_log_file(const std::string& file);
    void write_to_log_file();
    void close_log_file();

private:
    Logger() = default;
};

#include "singleton.hxx"