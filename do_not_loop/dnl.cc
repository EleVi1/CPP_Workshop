#include "dnl.hh"

size_t min_elt_length(const std::vector<std::string>& req)
{
    return std::min_element(req.begin(), req.end())->length();
}

size_t max_elt_length(const std::vector<std::string>& req)
{
    return std::max_element(req.begin(), req.end(),
                            [] (const std::string a, const std::string b)
    {return a.length() < b.length();})->length();
}

size_t sum_elt_length(const std::vector<std::string>& req)
{
    auto tmp = std::vector<size_t>(req.size());
    std::transform(req.begin(), req.end(), tmp.begin(), [](const std::string s) {return s.length();});
    return std::accumulate(tmp.begin(), tmp.end(), 0);
}

size_t count_elt(const std::vector<std::string>& req, const std::string& elt)
{
    return std::count_if(req.begin(), req.end(), [&] (const std::string s)
    {return s == elt;});
}

size_t count_duplicate(const std::vector<std::string>& req)
{
//    return std::count_if(req.begin(), req.end(),
//                         [&req] (const std::string& s1)
//                         {return std::count_if(req.begin(), req.end(),
//                                               [&s1] (const std::string s2)
//                                               {return s1 == s2;});}) > 1;
}