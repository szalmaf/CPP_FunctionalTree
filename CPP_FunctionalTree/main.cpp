//
//  main.cpp
//  CPP_FunctionalTree
//
//  Created by Ferenc Szalma on 1/20/17.
//  Copyright © 2017 Ferenc Szalma. All rights reserved.
//
// https://bartoszmilewski.com/2013/11/25/functional-data-structures-in-c-trees/

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
public:
    Tree(){}
    Tree(Tree const & lft, T val, Tree const & rgt)
    : _root(std::make_shared<const Node>(lft._root, val, rgt._root))
    {
    }

    bool isEmpty() const { return !_root; }
    T root() const
    {
        return _root->val;
    }
    Tree left() const
    {
        return Tree(_root->_lft);
    }
    Tree right() const
    {
        return Tree(_root->_rgt);
    }
private:
    std::shared_ptr<const Node> _root;
};


int main(int argc, const char * argv[]) {
    
    Tree<double> t;
    Tree<double> t2(Tree<double>(Tree<double>(), 1.0, Tree<double>()), 2.0, Tree<double>(Tree<double>(), 3.0, Tree<double>()));

    
    return 0;
}
