#include <rbt/rbt.hpp>
#include <time_m.hpp>
#include <iostream>

#ifndef NTEST
#define NTEST 10000
#endif

int
main(int argc, char ** argv)
{
    //std::vector<int> orig;
    //rbt::RBTree tree;

    //for(auto i = 0; i < NTEST; i++)
    //{
    //    orig.push_back(i);
    //    tree.insert(i);
    //}

    //std::vector<int> export_iter, export_rec;

    //
    //CLOG_TIMEIT_START;
    //tree.export_inorder_recursive(export_rec);
    //CLOG_TIMEIT_END("recursive export");
    //CLOG_TIMEIT_START;
    //tree.export_inorder_iterative(export_iter);
    //CLOG_TIMEIT_END("iterative export");

    //for(auto i: orig)
    //{
    //    if(export_iter[i] != export_rec[i])
    //    {
    //        std::cerr << "mismatch at #" << i << std::endl;
    //        return -1;
    //    }
    //}
    //
    
    rbt::RBTree tree;
    std::vector<int> data = {1, 2, 3};
    for(auto i: data)
    {
        tree.insert(i);
    }

    for(auto i: tree)
    {
        for(auto j: tree)
        {
            std::cout << i << ", " << j << std::endl;
        }
    }
    

    return 0;
}
