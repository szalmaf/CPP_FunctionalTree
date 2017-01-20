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
        Node(std::shared_ptr<Node> lft,
             T val,
             std::shared_ptr<Node> rgt)
        : _lft(lft), _val(val), _rgt(rgt)
        {}
        
        std::shared_ptr<Node> _lft;
        T _val;
        std::shared_ptr<Node> _rgt;
    };
public:
    Tree(){}
    Tree(Tree const & lft, T val, Tree const & rgt){}
};


int main(int argc, const char * argv[]) {
    
    Tree<double> t;

    
    return 0;
}
