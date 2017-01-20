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
public:
    Tree(){}
    Tree(Tree const & l, T val, Tree const & r){}
};


int main(int argc, const char * argv[]) {
    
    Tree<double> t;

    
    return 0;
}
