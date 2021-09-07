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
        char m_marker;
        inline bool is_lower_child(void);
        inline bool has_uncle(void);
        inline bool has_red_child(void);
        // WARNING: This method does NOT check for NULL pointers!
        inline Node * get_uncle(void);
        void recursive_inorder_export(std::vector<int> & vect);
        int check_rbt_pathlength(void);
        void repair_markers(char marker);
        public:
        Node(Node * parent, int value, char marker);
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
        char m_marker_mask;
        char m_marker_sanity;
        size_t m_count;
        Node * do_insert(int value);
        inline void delete_this_node(Node * c_node);
        void repair_after_insert(Node * causing_node);
        inline void left_rotate(Node * B);
        inline void right_rotate(Node * B);
        inline void repair_markers_if_needed(void);
        public:
        void insert(int value);
        void delete_value(int value);
        bool has_value(int value);
        void export_inorder_recursive(std::vector<int> & vect);
        void export_inorder_iterative(std::vector<int> & vect);
        void to_dot(std::ostream & stream);
        int rbt_pathlength(void);
        RBTree(void);
        ~RBTree(void);
        size_t size(void);

        class RBTIterator
        {
            private:
            RBTree * m_tree;
            Node * m_cnode;
            bool m_finished;
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
