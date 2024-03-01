#pragma once
#include <memory>
#include <vector>

using NFT = std::unique_ptr<std::string>;

inline NFT create_empty_nft()
{
    return std::make_unique<std::string>(nullptr);
}

inline NFT create_nft(const std::string& name)
{
    return std::make_unique<std::string>(name);
}