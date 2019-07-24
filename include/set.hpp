//
// Created by asem on 01/04/18.
//

#ifndef SBE201_WORDCOUNT_MAPS_SET_HPP
#define SBE201_WORDCOUNT_MAPS_SET_HPP

#include "bst.hpp"

namespace set
{

using WordSet = bst::BSTNode *;

WordSet create()
{
    return nullptr;
}

bool isEmpty( WordSet &wset )
{
    bst::isEmpty( wset );
}

int size( WordSet &wset )
{
    bst::size( wset );
}

bool contains( WordSet &wset, std::string item )
{
    bst::find( wset, item );
}

void remove(WordSet &wset, std::string to_remove)
{
    bst::remove( wset, to_remove );
}

void insert(WordSet &wset, std::string new_item)
{
    if (!bst::find(wset, new_item))
        bst::insert(wset, new_item);
}

void printAll(WordSet &wset)
{
    if (wset)
    {
        printAll(wset->left);
        std::cout << wset->item << std::endl;
        printAll(wset->right);
    }
}

void insertBF( WordSet &set3, WordSet set )
{
    bst::Queue q;
    WordSet auxillary = set;
    q.enqueue( set );
    while( !q.isEmpty() )
    {
        auxillary = q.dequeue();
        if( auxillary->left != nullptr )
        q.enqueue( auxillary );
        if( auxillary->right != nullptr )
        q.enqueue( auxillary );
        set::insert( set3, auxillary->item );
    }
}

void insertBFCommon( WordSet &set3, WordSet set1, WordSet set2 )
{
    bst::Queue q;
    WordSet auxillary = set1;
    q.enqueue( set1 );
    while( !q.isEmpty() )
    {
        auxillary = q.dequeue();
        if( auxillary->left != nullptr )
        q.enqueue( auxillary );
        if( auxillary->right != nullptr )
        q.enqueue( auxillary );
        if( contains( set2, auxillary->item ) )
        {
            set::insert( set3, auxillary->item );
        }
    }
}
void union_(WordSet &set1, WordSet &set2)
{
    WordSet set3 = create();
    insertBF( set3, set1 );
    insertBF( set3, set2 );
}

void intersect(WordSet &set1, WordSet &set2)
{
    WordSet set3 = create();
    insertBFCommon( set3, set1, set2 );
}

bool inOrderEqual( WordSet set1, WordSet set2 )
{
    if( !set1 ) return true; 
    return inOrderEqual( set1->left, set2->left );
    if( set1->item != set2->item ) 
    return false;
    return inOrderEqual( set1->right, set2->right );
}
bool equals(WordSet &set1, WordSet &set2)
{
    if( set::size( set1 ) != set::size( set2 ))
    return false;
    else
    return inOrderEqual( set1, set2 );

}
}
#endif //SBE201_WORDCOUNT_MAPS_SET_HPP
