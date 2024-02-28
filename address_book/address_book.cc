#include "address_book.hh"

bool AddressBook::add(const std::string& full_name, const std::string& email,
                      const std::string& number)
{
    if (full_name.empty()
        || ContactDetails::makeDetails(number, email) == std::nullopt)
    {
        return false;
    }
    book_.insert(
        { full_name, ContactDetails::makeDetails(number, email).value() });
    return true;
}

std::vector<ContactDetails> AddressBook::find(const std::string& full_name)
{
    std::vector<ContactDetails> list;
    auto beg = book_.begin();
    auto fin = book_.end();
    for (; beg != fin; beg++)
    {
        if (beg->first == full_name)
        {
            list.push_back(beg->second);
        }
    }
    return list;
}

std::size_t AddressBook::count(const std::string& full_name)
{
    size_t count = 0;
    auto beg = book_.begin();
    auto fin = book_.end();
    for (; beg != fin; beg++)
    {
        if (beg->first == full_name)
        {
            count++;
        }
    }
    return count;
}

bool AddressBook::remove(const std::string& full_name, std::size_t index)
{
    bool removed = false;
    size_t i = 0;
    auto beg = book_.begin();
    auto fin = book_.end();
    for (; beg != fin; beg++)
    {
        if (beg->first == full_name)
        {
            if (i == index)
            {
                book_.erase(beg);
                removed = true;
                break;
            }
            else
            {
                i++;
            }
        }
    }
    return removed;
}

void AddressBook::remove_all(const std::string& full_name)
{
    auto beg = book_.begin();
    auto fin = book_.end();
    for (; beg != fin; beg++)
    {
        if (beg->first == full_name)
        {
            book_.erase(beg);
        }
    }
}

std::ostream& operator<<(std::ostream& os, const AddressBook& b)
{
    os << b.book_.size() << " contact(s) in the address book.\n";
    auto beg = b.book_.begin();
    auto fin = b.book_.end();
    for (; beg != fin; beg++)
    {
        os << "- " << beg->first << ": " << beg->second;
    }
    return os;
}
