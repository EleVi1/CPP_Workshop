#include "contact_details.hh"

std::optional<ContactDetails>
ContactDetails::makeDetails(const std::string& telephone_number,
                            const std::string& personal_email)
{
    if (personal_email.find('@') == std::string::npos
        || telephone_number.find_first_not_of("0123456789")
            != std::string::npos)
    {
        return std::nullopt;
    }
    return ContactDetails(telephone_number, personal_email);
}

std::ostream& operator<<(std::ostream& os, const ContactDetails& c)
{
    os << c.number_ << ", " << c.email_ << '\n';
    return os;
}
