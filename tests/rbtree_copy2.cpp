#include <vector>
#include <random>
#include <algorithm>
#include <rbt/rbt.hpp>

#ifndef NTEST
#define NTEST 10000
#endif

int
main(int argc, char ** argv)
{
    std::vector<int> orig;
    for(auto i = 0; i < NTEST; i++)
    {
        orig.push_back(i);
    }

    std::vector<int> copy = orig;

    std::mt19937 rne;
    std::shuffle(copy.begin(), copy.end(), rne);

    rbt::RBTree * tree = new rbt::RBTree();
    for(auto i: copy)
    {
        tree->insert(i);
    }

    rbt::RBTree * tree2 = new rbt::RBTree(*tree);
    if(tree2->size() != orig.size())
    {
        return -1;
    }
    std::vector<int> exported;
    tree2->export_inorder_recursive(exported);
    if(exported.size() != orig.size())
    {
        return -1;
    }
    for(int i = 0; i < exported.size(); i++)
    {
        if(exported[i] != orig[i])
        {
            return -1;
        }
    }

    delete tree;
    delete tree2;
}
