#include "game.hh"

void Game::add_player(const std::string& name, size_t nb_presses)
{
    players_.push_back(Player(name, nb_presses));
}

void Game::play(int bomb_ticks)
{
    if (players_.size() < 2)
    {
        throw std::runtime_error("Too few players!");
    }
    players_[0].set_bomb(std::make_unique<Bomb>(bomb_ticks));
    players_[0].press_bomb();
    if (players_[0].is_dead())
    {
        std::cout << players_[0].get_name() << " has exploded.\n";
        return;
    }
    for (size_t i = 1; i < players_.size(); i++)
    {
        players_[i - 1].pass_bomb(players_[i]);
        players_[i].press_bomb();
        if (players_[i].is_dead())
        {
            std::cout << players_[i].get_name() << " has exploded.\n";
            return;
        }
    }
}
