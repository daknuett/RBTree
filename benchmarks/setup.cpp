#include "setup.hpp"
#include <vector>
#include <random>
#include <algorithm>

rbt::RBTree * random_tree(const size_t n_elements)
{
    rbt::RBTree * tree = new rbt::RBTree();
    std::vector<int> orig;
    for(auto i = 0; i < n_elements; i++)
    {
        orig.push_back(i);
    }


    std::mt19937 rne;
    std::shuffle(orig.begin(), orig.end(), rne);

    for(auto i: orig)
    {
        tree->insert(i);
    }
    return tree;
}
ll::SortedList * random_list(const size_t n_elements)
{
    ll::SortedList * list = new ll::SortedList();
    for(auto i = n_elements; i > 0; --i)
    {
        list->insert(i - 1);
    }

    return list;
}


