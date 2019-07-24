//
// Created by asem on 01/04/18.
//

#ifndef SBE201_WORDCOUNT_MAPS_BST_HPP
#define SBE201_WORDCOUNT_MAPS_BST_HPP

#include <iostream>
#include <string>
#include <queue>

namespace bst
{
struct BSTNode
{
    std::string item;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
    bool visited = false;
};

using Tree = BSTNode* ;

struct Node
{
    Tree data;
    Node* next = nullptr;
};
struct Queue
{
    //parameters here (using Linked List)
    Node *rear = nullptr;
    Node *front = nullptr;
    int size = 0;
    //methods
    void enqueue(const Tree data)
    {
        Node *newNode = new Node;
        if (rear != nullptr)
            rear->next = newNode;
        rear = newNode;
        newNode->data = data;
        newNode->next = nullptr;
        size++;
        if (front == nullptr)
        {
            front = rear;
        }
    }

    Tree dequeue()
    {

        if (isEmpty() == false)
        {
            Node *current;
            current = front;
            Tree removedData = current->data;
            front = front->next;
            if (front == nullptr)
                rear = nullptr;
            size--;
            delete current;
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
            exit(1);
        }
    }

    bool isEmpty() const
    {
        return size == 0;
    }
};


Tree create()
{
    return nullptr;
}

bool isEmpty( Tree const node )
{
    return node == nullptr;
}

bool isLeaf( Tree const node )
{
    return node->left == nullptr && node->right == nullptr;
}

int size( Tree const node )
{
    if (node)
        return 1 + size(node->left) + size(node->right);
    else
        return 0;
}

bool find( Tree const tree, std::string const item )
{
    if (isEmpty(tree))
        return false;
    else
    {
        int compare = tree->item.compare( item );
        if ( tree->item == item )
        return true;
        else if ( compare < 0 )
        return find( tree->right, item );
        else if ( compare > 0 )
        return find( tree->left, item ); 
    }
}

Tree findParent( Tree tree, std::string item )
{
    if (isEmpty(tree))
        exit(1);
    else
    {
        int compare = tree->item.compare( item );
        if ( tree->left->item == item || tree->right->item == item )
        return tree; 
        else if ( compare < 0 )
        return findParent( tree->left, item );
        else 
        return findParent( tree->right, item ); 
    }
}

Tree nodeParent(Tree root, Tree node)
{
    Tree auxillary = root;
    while( auxillary->left->item != node->item && auxillary->right->item != node->item )
    {
        int compare = node->item.compare( auxillary->item );
        if( compare > 0 )
        auxillary = auxillary->right;
        else 
        auxillary = auxillary->left; 
    }
    return auxillary;
}

void insert( Tree &tree, std::string const item )
{
    if (isEmpty(tree))
    {
        Tree newNode = new BSTNode;
        tree = newNode;
        tree->item = item;
    }
    else
    {
        int compare = tree->item.compare( item );
        if ( compare < 0 )
        insert( tree->right, item );
        else if( compare > 0 )
        insert( tree->left, item );
    }
}

Tree minNode(Tree tree)
{
    if( isEmpty( tree ) )
    exit(1);
    else if ( isLeaf( tree ) )
    {  return tree;}
    else 
    return minNode( tree->left );
}

Tree maxNode(Tree tree)
{
    if( isEmpty( tree ) )
    exit(1);
    else if ( isLeaf( tree ) )
    return tree;
    else 
    return maxNode( tree->right );
}

void remove( Tree &tree, std::string item )
{
    Tree toDiscard;
    Tree parent = findParent( tree, item );
    if( parent->right->item == item ) 
    {
        toDiscard = parent->right;
        if (isLeaf(toDiscard)) //case 1: thhe node to remove is leaf
        {
            parent->right = nullptr;
            delete toDiscard;
        }
        else if (toDiscard->right == nullptr) //case 2: the node to remove has one child
        {
            parent->right = toDiscard->left;
            delete toDiscard;
        }
        else if (toDiscard->left == nullptr)
        {
            parent->right = toDiscard->right;
            delete toDiscard;
        }
        else //case 3:the node to remove has 2 children
        {
            Tree minimum = minNode( toDiscard->right );
            Tree parentOfMin = nodeParent( tree, minimum );
            toDiscard->item = minimum->item;
            if( parentOfMin->right == minimum )
            parentOfMin->right = nullptr;
            else
            parentOfMin->left = nullptr;
            delete minimum;            
        }
    }
    else if (parent->left->item == item)
    {
        toDiscard = parent->left;
        if (isLeaf(toDiscard))
        {
            parent->left = nullptr;
            delete toDiscard;
        }
        else if (toDiscard->right == nullptr) //case 2: the node to remove has one child
        {
            parent->left = toDiscard->left;
            delete toDiscard;
        }
        else if (toDiscard->left == nullptr)
        {
            parent->left = toDiscard->right;
            delete toDiscard;
        }
        else //case 3:the node to remove has 2 children
        {
            Tree minimum = minNode( toDiscard->right );
            Tree parentOfMin = nodeParent( tree, minimum );
            toDiscard->item = minimum->item;
            if( parentOfMin->right == minimum )
            parentOfMin->right = nullptr;
            else
            parentOfMin->left = nullptr;
            delete minimum;            
        }
    }
}

void clear(Tree &tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
    tree = nullptr;
}

void preorder(const Tree tree)
{
    if (!tree)
        return;
    std::cout << tree->item << std::endl;
    preorder(tree->left);
    preorder(tree->right);
}

void postorder(Tree tree)
{
    if (!tree)
        return;
    postorder(tree->left);
    postorder(tree->right);
    std::cout << tree->item << std::endl;
}

void inorder(Tree tree)
{
    if (!tree)
        return;
    inorder(tree->left);
    std::cout << tree->item << std::endl;
    inorder(tree->right);
}

void reset( Tree tree )
{
    if( !tree ) return;
    reset( tree->left );
    tree->visited = false;
    reset( tree->right );
}

void breadthFirst( Tree tree )
{
    Queue q;
    Tree auxillary = tree;
    q.enqueue(tree);
    while (!q.isEmpty())
    {
        auxillary = q.dequeue();
        if (auxillary->visited == false)
        {
            std::cout << auxillary->item << std::endl;
            auxillary->visited = true;
        }
        if( auxillary->left != nullptr )
        {
            q.enqueue( auxillary->left );
            std::cout<<auxillary->left->item<<std::endl;
            auxillary->left->visited = true;
        }
        if( auxillary->right != nullptr )
        {
            auxillary = auxillary->right;
            if( auxillary->visited == false )
            {
                std::cout << auxillary->item << std::endl;
                auxillary->visited = true;
            }
            q.enqueue(auxillary);
        }
    }
    reset(tree);
}
}

#endif //SBE201_WORDCOUNT_MAPS_BST_HPP_HPP
