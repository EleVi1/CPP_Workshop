#include "person.hh"

#include <memory>
#include <string>
#include <utility>

Person::Person(const std::string& name, uint money)
{
    this->name_ = name;
    this->money_ = money;
}

std::vector<std::string> Person::enumerate_nfts() const
{
    std::vector<std::string> names;
    auto beg = nfts_.begin();
    auto end = nfts_.end();
    for (; beg != end; beg++)
    {
        names.emplace_back(*beg->get());
    }
    return names;
}

void Person::add_nft(NFT nft)
{
    this->nfts_.emplace_back(std::move(nft));
}

NFT Person::remove_nft(const std::string& name)
{
    auto beg = nfts_.begin();
    auto end = nfts_.end();
    NFT ret;
    for (; beg != end; beg++)
    {
        if (*beg->get() == name)
        {
            ret = std::move(*beg);
            nfts_.erase(beg);
        }
    }
    return ret;
}

void Person::add_money(uint money)
{
    this->money_ += money;
}

bool Person::remove_money(uint money)
{
    if (this->money_ >= money)
    {
        this->money_ -= money;
        return true;
    }
    return false;
}

uint Person::get_money() const
{
    return money_;
}

const std::string& Person::get_name() const
{
    return name_;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "Name: " << p.get_name() << '\n'
       << "Money: " << p.get_money() << '\n'
       << "NFTs:";
    for (auto i : p.enumerate_nfts())
    {
        os << " " << i;
    }
    os << '\n';
    return os;
}