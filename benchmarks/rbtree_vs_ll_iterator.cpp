#include <rbt/rbt.hpp>
#include <ll/ll.hpp>
#include <time_m.hpp>
#include <iostream>
#include "setup.hpp"

#ifndef NBENCH
#define NBENCH 10000
#endif

int
main(int argc, char ** argv)
{
    std::clog << "using nbench = " << NBENCH << std::endl;

    rbt::RBTree * tree = random_tree(NBENCH);
    ll::SortedList * list = random_list(NBENCH);

    std::vector<int> export_tree;
    export_tree.reserve(NBENCH);
    std::vector<int> export_list;
    export_list.reserve(NBENCH);

    CLOG_TIMEIT_START;
    for(auto i: *tree)
    {
        export_tree.push_back(i);
    }
    CLOG_TIMEIT_END("iterate over tree into vector");
    CLOG_TIMEIT_START;
    for(auto i: *list)
    {
        export_list.push_back(i);
    }
    CLOG_TIMEIT_END("iterate over list into vector");

    return 0;
}
