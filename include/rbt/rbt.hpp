#pragma once
#include <vector>
#include <iostream>

namespace rbt
{
    char const NODE_BLACK = 'B';
    char const NODE_RED = 'R';

    class Node
    {
        private:
        Node * m_parent;
        char m_color;
        Node * m_lower;
        Node * m_higher;
        int m_value;
        inline bool is_lower_child(void);
        inline bool has_uncle(void);
        inline bool has_red_child(void);
        //
        // WARNING: This method does NOT check for NULL pointers!
        inline Node * get_uncle(void);

        void recursive_inorder_export(std::vector<int> & vect);
        int check_rbt_pathlength(void);
        Node * get_leftmost(void);
        public:
        Node(Node * parent, int value);
        Node(Node & orig);
        Node(Node * parent, Node * orig);
        void recursively_delete(void);

        void dot_edges(std::ostream & stream);
        void dot_node_descrs(std::ostream & stream);

        friend class RBTree;
        friend class RBTIterator;
    };

    class RBTree
    {
        private:
        Node * m_root;
        size_t m_count;
        Node * do_insert(int value);
        inline void delete_this_node(Node * c_node);
        void repair_after_insert(Node * causing_node);
        inline void left_rotate(Node * B);
        inline void right_rotate(Node * B);
        public:
        void insert(int value);
        void delete_value(int value);
        bool has_value(int value);
        void export_inorder_recursive(std::vector<int> & vect);
        void export_inorder_iterative(std::vector<int> & vect);
        void to_dot(std::ostream & stream);
        int rbt_pathlength(void);
        RBTree(void);
        RBTree(RBTree & orig);
        RBTree(RBTree const & orig);
        ~RBTree(void);
        size_t size(void);
        // WARNING: This method does not check whether
        // the operation is possible.
        int get_element_excluding(int exclude);

        class RBTIterator
        {
            private:
            RBTree * m_tree;
            Node * m_cnode;
            public:
            RBTIterator(RBTree * tree, Node * cnode);
            RBTIterator operator++(int);
            RBTIterator & operator++(void);
            bool operator==(const RBTIterator & b);
            bool operator!=(const RBTIterator & b);
            int operator*(void);
        };
        RBTIterator begin(void);
        RBTIterator end(void);

        friend class RBTIterator;
    };

}
