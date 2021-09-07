#include <vector>
#include <set>
#include <random>
#include <algorithm>

#include <rbt/rbt.hpp>
#include <time_m.hpp>

#ifndef NBENCH
#define NBENCH 10000
#endif

int
main(int argc, char ** argv)
{
    std::clog << "using nbench = " << NBENCH << std::endl;
    std::vector<int> orig;
    for(auto i = 0; i < NBENCH; i++)
    {
        orig.push_back(i);
    }

    std::mt19937_64 rne;
    std::shuffle(orig.begin(), orig.end(), rne);

    std::set<int> set;
    rbt::RBTree tree;

    CLOG_TIMEIT_START;
    for(auto i: orig)
    {
        set.insert(i);
    }
    CLOG_TIMEIT_END("insert into set");
    CLOG_TIMEIT_START;
    for(auto i: orig)
    {
        tree.insert(i);
    }
    CLOG_TIMEIT_END("insert into tree");

    CLOG_TIMEIT_START;
    for(auto i: orig)
    {
        if(set.find(i) != set.end())
        {
            continue;
        }
    }
    CLOG_TIMEIT_END("lookup in set");
    CLOG_TIMEIT_START;
    for(auto i: orig)
    {
        if(tree.has_value(i))
        {
            continue;
        }
    }
    CLOG_TIMEIT_END("lookup in tree");

    std::vector<int> export_set;
    export_set.reserve(NBENCH);
    std::vector<int> export_tree;
    export_tree.reserve(NBENCH);

    CLOG_TIMEIT_START;
    for(auto i: set)
    {
        export_set.push_back(i);
    }
    CLOG_TIMEIT_END("set iterate into vect");
    CLOG_TIMEIT_START;
    for(auto i: tree)
    {
        export_tree.push_back(i);
    }
    CLOG_TIMEIT_END("tree iterate into vect");

    CLOG_TIMEIT_START;
    for(auto i: orig)
    {
        set.erase(i);
    }
    CLOG_TIMEIT_END("delete from set");
    CLOG_TIMEIT_START;
    for(auto i: orig)
    {
        tree.delete_value(i);
    }
    CLOG_TIMEIT_END("delete from tree");
    
    return 0;
}
