#include "player.hh"

#include <iostream>

#include "game.hh"

Player::Player(const std::string& name, size_t nb_presses)
    : name_(name)
    , bomb_(nullptr)
    , nb_presses_(nb_presses)
{}

void Player::pass_bomb(Player& receiver)
{
    if (bomb_ == nullptr || receiver.bomb_ != nullptr)
    {
        throw std::runtime_error("Receiver has a bomb or sender has no bomb");
    }
    else
    {
        std::cout << name_ << " passes the bomb to " << receiver.name_ << ".\n";
    }
    receiver.bomb_ = std::move(bomb_);
}

void Player::press_bomb()
{
    if (bomb_ == nullptr)
    {
        throw std::runtime_error("Doesn't have a bomb");
    }
    auto nb = nb_presses_;
    while (!bomb_->has_exploded() && nb > 0)
    {
        bomb_->tick();
        nb--;
    }
}

bool Player::has_bomb() const
{
    return bomb_ != nullptr;
}

bool Player::is_dead() const
{
    if (bomb_ == nullptr)
    {
        return false;
    }
    return bomb_->has_exploded();
}

void Player::set_bomb(std::unique_ptr<Bomb> bomb)
{
    bomb_ = std::move(bomb);
}

const std::string& Player::get_name() const
{
    return name_;
}
