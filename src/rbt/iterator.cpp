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
        while(m_cnode != NULL)
        {
            if((m_cnode->m_marker ^ m_tree->m_marker_mask) == 0)
            {
                //std::cerr << "found unvisited node " << m_cnode->m_value << " descending" << std::endl;
                // 1st time visiting the node.
                m_cnode->m_marker ^= 0b01;
                if(m_cnode->m_lower != NULL)
                {
                    m_cnode = m_cnode->m_lower;
                }
                continue;
            }
            if((m_cnode->m_marker ^ m_tree->m_marker_mask) == 0b01)
            {
                //std::cerr << "found once-visited node " << m_cnode->m_value << " yielding it" << std::endl;
                // 2nd time visiting the node.
                m_cnode->m_marker ^= 0b10;
                return *this;
            }
            if((m_cnode->m_marker ^ m_tree->m_marker_mask) == 0b11)
            {
                //std::cerr << "found twice-visited node " << m_cnode->m_value << " ascending" << std::endl;
                m_cnode->m_marker ^= 0b100;
                if(m_cnode->m_higher != NULL)
                {
                    m_cnode = m_cnode->m_higher;
                }
                continue;
            }
            m_cnode = m_cnode->m_parent;
        }
        m_tree->m_marker_mask ^= 0b111;
        m_tree->m_marker_sanity = 1;
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
