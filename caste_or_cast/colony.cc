#include "colony.hh"

#include <iostream>

#include "nurturer.hh"
#include "provider.hh"

Colony::Colony(uint32_t passport)
    : passport_pheromone_(passport)
    , workers_()
{}

void Colony::manageQueen()
{
    if (queen_ == nullptr)
        throw std::runtime_error("Cannot manage a colony without a Queen.");
    // check if the queen should lose health points
    if (queen_->food_level_ < 0)
        queen_->hp_ -= 1;
    if (queen_->hp_ <= 0)
    {
        queen_ = nullptr;
        throw std::runtime_error("The Queen died.");
    }
    // Append to workers_ all the new workers contained in the queen's
    // eggs_queue_
    while (!queen_->eggs_queue_.empty())
    {
        //! we insert eggs that were laid by the queen
        workers_.emplace_back(queen_->eggs_queue_.front());
        queen_->eggs_queue_.pop();
    }
}

void Colony::removeDeadWorkers()
{
    auto dead_count = std::erase_if(
        workers_, [](const std::shared_ptr<Worker> w) { return w->hp_ <= 0; });
    if (dead_count > 0)
    {
        std::cout << dead_count << " workers_ died.\n";
        // each dead worker decrease the cleanliness of the colony
        cleanliness -= 0.5 * dead_count;
    }
}

// this method can be considered as one round of management
void Colony::manageAnts()
{
    // We first manage the queen
    manageQueen();
    // We remove all dead workers contained in workers_
    removeDeadWorkers();
    std::cout << "-- THERE IS " << workers_.size() << " WORKERS --\n";
    // We iterate over all workers
    for (auto worker : workers_)
    {
        if (worker->stage_ == DevelopmentStage::ADULT)
        {
            /*
             * Because work() is a virtual method, dynamic dispatch will be
             * used. Which means that the overridden work method of the true
             * type (either Nurturer or Provider) will actually be called
             * instead of Worker::work().
             */
            worker->work();
        }
        else
        {
            /*
             * We increment their food_level_ as if it is a ticking time,
             * EXCEPT for the larvae, as they are fed by nurturers.
             */
            if (worker->stage_ != DevelopmentStage::LARVA)
                worker->food_level_ += 1;
            if (worker->food_level_ >= 4.0)
            {
                int state = static_cast<int>(worker->stage_);
                state++;
                worker->stage_ = static_cast<DevelopmentStage>(state);
                worker->food_level_ = 0;
                /* FIXME : Make the worker change stage_ and reset their
                 * food_level_ to 0. HINT : This can take only 2/3 lines if you
                 * use a certain C++ cast instead of a switch.
                 */
            }
        }
    }
    queen_->food_level_ -= 0.2;
}

// FIXME : Implements addAnt() static method.
bool Colony::addAnt(const Ant& ant, std::shared_ptr<Colony> colony)
{
    Ant* tmp = const_cast<Ant*>(&ant);
    bool added = false;
    if (dynamic_cast<Queen*>(tmp) != nullptr)
    {
        auto q = dynamic_cast<Queen*>(tmp);
        if (q != nullptr)
        {
            if (!colony->queen_ && q->stage_ == DevelopmentStage::ADULT)
            {
                colony->queen_ = std::make_unique<Queen>(*q);
                added = true;
            }
        }
    }
    else if (dynamic_cast<Provider*>(tmp) != nullptr)
    {
        auto q = dynamic_cast<Provider*>(tmp);
        colony->workers_.emplace_back(std::make_shared<Provider>(*q));
        added = true;
    }
    else if (dynamic_cast<Nurturer*>(tmp) != nullptr)
    {
        auto q = dynamic_cast<Nurturer*>(tmp);
        colony->workers_.emplace_back(std::make_shared<Nurturer>(*q));
        added = true;
    }
    return added;
}
