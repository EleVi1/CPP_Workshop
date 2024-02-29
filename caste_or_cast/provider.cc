#include "provider.hh"

#include <iostream>
#include <memory>
#include <queue>
#include <vector>

#include "nurturer.hh"

void Provider::work()
{
    if (this->stage_ == DevelopmentStage::ADULT)
    {
        int base = static_cast<int>(food_stock_);
        auto food = food_stock_ - base;
        this->increment_food_level_by(food);
        this->food_stock_ -= food;
        this->harvestFood();
        Worker::work();
    }
}

void Provider::transferFood(Nurturer& nurturer)
{
    if (this->food_stock_ >= 1)
    {
        std::cout << "Transferring food.\n";
        int food = static_cast<int>(food_stock_);
        nurturer.increment_food_stock_by(food);
        this->food_stock_ -= (food);
    }
}

bool Provider::communicate(std::weak_ptr<Ant> wk_receiver)
{
    if (Ant::communicate(wk_receiver))
    {
        std::cout << "Provider initiates communication.\n";
        auto nurturer = std::dynamic_pointer_cast<Nurturer>(
            std::shared_ptr<Ant>(wk_receiver));
        if (nurturer != nullptr)
        {
            this->transferFood(*nurturer);
        }
        return true;
    }
    return false;
}

void Provider::harvestFood()
{
    std::cout << "Harvested " << this->luck_ << " food.\n";
    increment_food_stock_by(this->luck_);
    int entier = static_cast<int>(luck_);
    float decimal = this->luck_ - entier;
    food_level_ -= decimal / 2;
}