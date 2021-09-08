#pragma once
#include <iostream>
#include <vector>

namespace ll
{
    class Node
    {
        private:
        Node * m_next;
        int m_value;
        public:
        Node(int value);
        Node(int value, Node * next);
        Node(Node & orig);
        void print(void);
        friend class SortedList;

    };
    class SortedList
    {
        private:
        Node * m_first;
        size_t m_count;
        public:
        void insert(int value);
        bool has_value(int value);
        void print(void);
        void delete_value(int value);
        SortedList(void);
        SortedList(SortedList & orig);
        ~SortedList(void);
        void export_vector(std::vector<int> & vect);
        size_t size(void);

        class Iterator
        {
            private: 
            Node * m_cnode;
            public:
            Iterator(Node * cnode);
            Iterator operator++(int);
            Iterator & operator++(void);
            bool operator==(const Iterator & b);
            bool operator!=(const Iterator & b);
            int operator*(void);

        };

        Iterator begin(void);
        Iterator end(void);

    };
}
