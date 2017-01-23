//
//  main.cpp
//  CPP_FunctionalTree
//
//  Created by Ferenc Szalma on 1/20/17.
//  Copyright © 2017 Ferenc Szalma. All rights reserved.
//
// https://bartoszmilewski.com/2013/11/25/functional-data-structures-in-c-trees/
// Binary search code without rebalancing

#include <iostream>

template <class T>
class Tree
{
    struct Node
    {
        Node(std::shared_ptr<const Node> lft,
             T val,
             std::shared_ptr<const Node> rgt)
        : _lft(lft), _val(val), _rgt(rgt)
        {}
        
        std::shared_ptr<const Node> _lft;
        T _val;
        std::shared_ptr<const Node> _rgt;
    };
    explicit Tree(std::shared_ptr<const Node> const & node) : _root(node){}
public:
    Tree(){}
    Tree(Tree const & lft, T val, Tree const & rgt)
    : _root(std::make_shared<const Node>(lft._root, val, rgt._root)){}
    Tree(std::initializer_list<T> init)
    {
        Tree t;
        for (T v : init)
        {
            t = t.insert(v);
        }
        _root = t._root;
    }

    bool isEmpty() const { return !_root; }
    T root() const
    {
        return _root->_val;
    }
    Tree left() const
    {
        return Tree(_root->_lft);
    }
    Tree right() const
    {
        return Tree(_root->_rgt);
    }
    Tree insert(T x) const
    {
        if(isEmpty())
            return Tree(Tree(), x, Tree());
        T y = root();
        if (x < y)
            return Tree(left().insert(x), y, right());
        else if (y < x)
            return Tree(left(), y, right().insert(x));
        else
            return *this;
    }
    bool member(T x) const
    {
        if (isEmpty())
            return false;
        T y = root();
        if (x < y)
            return left().member(x);
        else if (y < x)
            return right().member(x);
        else
            return true;
    }
private:
    std::shared_ptr<const Node> _root;
};


int main(int argc, const char * argv[]) {
    
    Tree<double> t;
    Tree<double> t2(Tree<double>(Tree<double>(), 1.0, Tree<double>()), 2.0, Tree<double>(Tree<double>(), 3.0, Tree<double>()));

    // Initializer_list constructor
    Tree<double> t3{10,20,30,40,100,90,80,70};
    
    return 0;
}
