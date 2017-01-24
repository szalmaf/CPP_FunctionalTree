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
#include <cassert>

template <class T>
class Tree
{
    enum Color { R, B };
    struct Node
    {
        Node(Color c, std::shared_ptr<const Node> lft,
             T val,
             std::shared_ptr<const Node> rgt)
        : _c(c), _lft(lft), _val(val), _rgt(rgt)
        {}
        
        Color _c;
        std::shared_ptr<const Node> _lft;
        T _val;
        std::shared_ptr<const Node> _rgt;
    };
    explicit Tree(std::shared_ptr<const Node> const & node) : _root(node){}
public:
    Tree(){}
    Tree(Color c, Tree const & lft, T val, Tree const & rgt)
        : _root(std::make_shared<const Node>(c, lft._root, val, rgt._root))
    {
        assert(lft.isEmpty() || lft.root() < val);
        assert(rgt.isEmpty() || rgt.root() > val);
    }
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
        assert(!isEmpty());
        return _root->_val;
    }
    Color rootColor() const
    {
        assert(!isEmpty());
        return _root->_c;
    }
    Tree left() const
    {
        assert(!isEmpty());
        return Tree(_root->_lft);
    }
    Tree right() const
    {
        assert(!isEmpty());
        return Tree(_root->_rgt);
    }
    Tree insert (T x) const
    {
        Tree t = ins(x);
        return Tree (B, t.left(), t.root(), t.right());
    }
    Tree ins(T x) const
    {
        if(isEmpty())
            return Tree(R, Tree(), x, Tree());
        T y = root();
        Color c = rootColor();
        if (x < y)
            return balance(c, left().ins(x), y, right()); //Tree(left().insert(x), y, right());
        else if (y < x)
            return balance(c, left(), y, right().ins(x));
        else
            return *this; // no duplicates
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
//    Tree<double> t2(Tree<double>(Tree<double>(), 1.0, Tree<double>()), 2.0, Tree<double>(Tree<double>(), 3.0, Tree<double>()));

    // Initializer_list constructor
    Tree<double> t3{10,20,30,40,100,90,80,70};
    
    return 0;
}
