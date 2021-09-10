#include <rbt/rbt.hpp>

namespace rbt
{
    RBTree::RBTIterator::RBTIterator(RBTree * tree, Node * cnode):
        m_tree(tree), m_cnode(cnode)
    {
    }
    RBTree::RBTIterator RBTree::RBTIterator::operator++(int)
    {
        RBTIterator tmp = *this;
        ++(*this);
        return tmp;
    }
    
    RBTree::RBTIterator & RBTree::RBTIterator::operator++(void)
    {
        // From https://stackoverflow.com/a/2942598.
        if(m_cnode == NULL)
        {
            return *this;
        }

        if(m_cnode->m_higher != NULL)
        {
            m_cnode = m_cnode->m_higher->get_leftmost();
            return *this;
        }
        while(m_cnode->m_parent != NULL && m_cnode->m_parent->m_higher == m_cnode)
        {
            m_cnode = m_cnode->m_parent;
        }
        m_cnode = m_cnode->m_parent;
        return *this;
    }
    bool RBTree::RBTIterator::operator==(const RBTIterator & b)
    {
        return b.m_cnode == m_cnode;
    }
    bool RBTree::RBTIterator::operator!=(const RBTIterator & b)
    {
        return b.m_cnode != m_cnode;
    }

    int RBTree::RBTIterator::operator*(void)
    {
        return m_cnode->m_value;
    }
}
