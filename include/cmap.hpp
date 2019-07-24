//
// Created by asem on 01/04/18.
//

#ifndef SBE201_WORDS_CMAP_HPP
#define SBE201_WORDS_CMAP_HPP
#include <iostream>
#include <cstdlib>
namespace char_map
{
struct MapNode
{
    char key;
    int value;
    MapNode *left;
    MapNode *right;
};

using CharMap = MapNode *;

CharMap create()
{
    return nullptr;
}

bool isEmpty(CharMap cmap)
{
    return (cmap == nullptr);
}

bool isLeaf(CharMap cmap)
{
    return (cmap->left == nullptr && cmap->right == nullptr);
}

int size(CharMap cmap)
{
    if (cmap == nullptr)
        return 0;
    else
        return 1 + size(cmap->left) + size(cmap->right);
}

bool find(CharMap cmap, char key)
{
    if (isEmpty(cmap))
        return false;
    else
    { // COMPLETE THIS
        if (cmap->key == key)
            return true;
        else if (cmap->key > key)
            return find(cmap->left, key);
        else
            return find(cmap->right, key);
    }
}

int &at(CharMap cmap, char key)
{
    if (isEmpty(cmap))
    {
        std::cout << "Key not found!" << std::endl;
        exit(1);
    }
    else
    { // COMPLETE THIS
        if (cmap->key == key)
            return cmap->value;
        else if (cmap->key > key)
            return at(cmap->left, key);
        else
            return at(cmap->right, key);
    }
}

void insert(CharMap &cmap, char key)
{
    if (isEmpty(cmap))
    {
        cmap = new MapNode;
        cmap->left = nullptr;
        cmap->right = nullptr;
        cmap->key = key;
        cmap->value = 0;
    }
    else if (key != cmap->key) // Ignore when the key is already found
    {
        if (key < cmap->key)
            insert(cmap->left, key);
        else
            insert(cmap->right, key);
    }
}

CharMap minNode(CharMap cmap)
{
    if (cmap->left)
        return minNode(cmap->left);
    else
    {
        return cmap;
    }
}

void remove(CharMap &cmap, char key)
{
    if (cmap = nullptr)
        return;
    if (cmap->key == key)
    {
        if (cmap->left == nullptr && cmap->right == nullptr)
        {
            CharMap toDelete = cmap;
            cmap = nullptr;
            delete toDelete;
        }
        else if (cmap->left != nullptr)
        {
            CharMap current = cmap->left;
            CharMap parent = cmap;
            while (current->right != nullptr)
            {
                current = current->right;
                if (parent == cmap)
                    parent = cmap->left;
                else
                    parent = parent->right;
            }
            cmap->key = current->key;
            if (parent->right == current)
                parent->right == nullptr;
            else if (parent->left == current)
                parent->left == nullptr;
            delete current;
        }

        else
        {
            CharMap current = cmap->right;
            CharMap parent = cmap;
            while (current->left != nullptr)
            {
                current = current->left;
                if (parent == cmap)
                    parent = cmap->right;
                else
                    parent = parent->left;
            }
            cmap->key = current->key;
            if (parent->right == current)
                parent->right == nullptr;
            else if (parent->left == current)
                parent->left == nullptr;
            delete current;
        }
    }
    else if (cmap->key > key)
        remove(cmap->left, key);
    else
        remove(cmap->right, key);
}

int &value(CharMap &cmap, char key)
{
    if (!find(cmap, key))
    {
        insert(cmap, key);
    }
    return at(cmap, key);
}

void clear(CharMap &cmap)
{
    if (cmap == nullptr)
        return;
    clear(cmap->left);
    clear(cmap->right);
    delete cmap;
    cmap = nullptr;
}

void printAll(CharMap cmap)
{
    if (cmap)
    {
        printAll(cmap->left);
        std::cout << cmap->key << ":" << cmap->value << std::endl;
        printAll(cmap->right);
    }
}
}

#endif //SBE201_WORDS_CMAP_HPP
