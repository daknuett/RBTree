#include <rbt/rbt.hpp>
#include <time_m.hpp>
#include <iostream>

#ifndef NTEST
#define NTEST 10000
#endif

int
main(int argc, char ** argv)
{
    std::vector<int> orig;
    rbt::RBTree tree;

    for(auto i = 0; i < NTEST; i++)
    {
        orig.push_back(i);
        tree.insert(i);
    }

    std::vector<int> export_iter, export_rec;

    for(auto i: orig)
    {
        if(export_iter[i] != export_rec[i])
        {
            std::cerr << "mismatch at #" << i << std::endl;
            return -1;
        }
    }

    return 0;
}
