#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

struct ContactDetails
{
public:
    static std::optional<ContactDetails>
    makeDetails(const std::string& telephone_number,
                const std::string& personal_email);
    friend std::ostream& operator<<(std::ostream& os, const ContactDetails& c);

private:
    ContactDetails(const std::string& telephone_number,
                   const std::string& personal_email)
    {
        number_ = telephone_number;
        email_ = personal_email;
    }
    std::string number_;
    std::string email_;
};