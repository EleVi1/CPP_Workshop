#include "lookup_table.hh"

#include <optional>
#include <unordered_map>

#include "fibo.hh"

void LookupTable::set(int x, long value) {
    table_.insert({x, value});
}

std::optional<long> LookupTable::get(int x) {
    auto res = table_.find(x);
    if (res == table_.end())
    {
        return std::nullopt;
    }
    return res->second;
}
