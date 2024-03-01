#include "auction.hh"

Auction::Auction(Person& organizer, NFT nft, uint initial_bid)
    : organizer_(organizer)
{
    if (nft->empty() || nft == nullptr)
    {
        throw std::exception();
    }
    nft_ = std::move(nft);
    highest_bidder_ = nullptr;
    highest_bid_ = initial_bid;
}

Auction::~Auction()
{
    if (highest_bidder_ != nullptr)
    {
        highest_bidder_->add_nft(std::move(nft_));
        organizer_.add_money(highest_bid_);
    }
    else
    {
        organizer_.add_nft(std::move(nft_));
    }
}

bool Auction::bid(Person& person, uint money)
{
    if (money > highest_bid_)
    {
        if (highest_bidder_ != nullptr)
        {
            highest_bidder_->add_money(highest_bid_);
        }
        highest_bid_ = money;
        highest_bidder_ = &person;
        highest_bidder_->remove_money(money);
        return true;
    }
    return false;
}

const std::string& Auction::get_nft_name() const
{
    return *nft_;
}

uint Auction::get_highest_bid() const
{
    return highest_bid_;
}
