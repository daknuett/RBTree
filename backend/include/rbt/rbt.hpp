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
        bool m_marker;
        inline bool is_lower_child(void);
        inline bool has_uncle(void);
        inline bool has_red_child(void);
        // WARNING: This method does NOT check for NULL pointers!
        inline Node * get_uncle(void);
        void inorder_export(std::vector<int> & vect);
        public:
        Node(Node * parent, Node * lower, Node * higher, int value);
        void recursively_delete(void);

        void dot_edges(std::ostream & stream);
        void dot_node_descrs(std::ostream & stream);

        friend class RBTree;
    };

    class RBTree
    {
        private:
        Node * m_root;
        Node * do_insert(int value);
        inline void delete_this_node(Node * c_node);
        void repair_after_insert(Node * causing_node);
        inline void left_rotate(Node * B);
        inline void right_rotate(Node * B);
        public:
        void insert(int value);
        void delete_value(int value);
        bool has_value(int value);
        void export_inorder(std::vector<int> & vect);
        void to_dot(std::ostream & stream);
        RBTree(void);
        ~RBTree(void);
    };
}
