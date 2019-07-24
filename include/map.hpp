//
// Created by asem on 01/04/18.
//

#ifndef SBE201_WORDCOUNT_MAPS_MAP_HPP
#define SBE201_WORDCOUNT_MAPS_MAP_HPP

#include <string>
#include <iostream>

namespace map
{

struct MapNode
{
    std::string key;
    int value;
    MapNode *left;
    MapNode *right;
};

using WordMap = MapNode *;

WordMap create()
{
    return nullptr;
}

bool isEmpty(WordMap wmap)
{
    return wmap == nullptr;
}

bool isLeaf(WordMap wmap)
{
    return wmap->left == nullptr && wmap->right == nullptr;
}

int size(WordMap wmap)
{
    if (wmap == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + size(wmap->right) + size(wmap->left);
    }
}

bool find(WordMap wmap, std::string key)
{
    if (wmap == nullptr)
        return false;
    if (wmap->key == key)
        return true;
    else
    {
        if (key.compare(wmap->key) < 0)
        {
            return find(wmap->left, key);
        }
        else
        {
           return find(wmap->right, key);
        }
    }
}

int &at(WordMap wmap, std::string key)
{
    if (isEmpty(wmap))
    {
        std::cout << "Key not found!" << std::endl;
        exit(1);
    }
    else
    {
        if (wmap->key == key)
            return wmap->value;
        else
        {
            if (key.compare(wmap->key) < 0)
            {
               return at(wmap->left, key);
            }
            else
            {
                return at(wmap->right, key);
            }
        }
    }
}

void insert(WordMap &wmap, std::string key)
{
    if (isEmpty(wmap))
    {
        wmap = new MapNode;
        wmap->left = nullptr;
        wmap->right = nullptr;
        wmap->key = key;
        wmap->value = 0;
    }
    else if (key.compare(wmap->key) < 0) // Ignore when the key is already found
    {
        insert(wmap->left, key);
    }
    else
    {
        insert(wmap->right, key);
    }
}

WordMap minNode(WordMap wmap)
{
    if (wmap->left)
        return minNode(wmap->left);
    else
    {
        return wmap;
    }
}

WordMap &getAt(WordMap &wmap, std::string key)
{
    if (isEmpty(wmap))
    {
        std::cout << "Key not found!" << std::endl;
        exit(1);
    }
    else
    {
        if (wmap->key == key)
            return wmap;
        else
        {
            if (key.compare(wmap->key) < 0)
            {
                getAt(wmap->left, key);
            }
            else
            {
                getAt(wmap->right, key);
            }
        }
    }
}

void remove(WordMap &wmap, std::string key)
{
    WordMap temp = map::getAt(wmap, key) ;
    WordMap minimum = map::minNode(temp->right) ;
    WordMap del = map::getAt(wmap , minimum->key) ;
    temp->key = minimum->key ;
    delete del ;  
}

int &value(WordMap &wmap, std::string key)
{
    if (!find(wmap, key))
    {
        insert(wmap, key);
    }
    return at(wmap, key);
}

void clear(WordMap &wmap)
{
    if (!isEmpty(wmap))
    {
        clear(wmap->left);
        clear(wmap->right);
        delete wmap;
        wmap = nullptr;
    }
}

void printAll(WordMap wmap)
{
    if (wmap)
    {
        printAll(wmap->left);
        std::cout << wmap->key << ":" << wmap->value << std::endl;
        printAll(wmap->right);
    }
}
}

#endif //SBE201_WORDCOUNT_MAPS_MAP_HPP
