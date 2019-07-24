//
// Created by asem on 01/04/18.
//

#include <iostream>
#include "bst.hpp"


int main() {
    bst::Tree tree = bst::create();

    bst::insert( tree , "Samy" );
    bst::insert( tree , "Kareem" );
    bst::insert( tree , "Toqa");
    bst::insert( tree , "Ahmed" );
    bst::insert( tree , "Mohamed" );
    bst::insert( tree , "Youmna" );
    bst::insert( tree , "Wessam" );
    bst::insert( tree , "Basma" );
    bst::insert( tree , "Zyad" );

    std::cout << "In-order Traversal" << std::endl;
    std::cout << "==================" << std::endl;
    bst::inorder( tree );
    std::cout << std::endl << std::endl;

    std::cout << "Pre-order Traversal" << std::endl;
    std::cout << "==================" << std::endl;
    bst::preorder( tree );
    std::cout << std::endl << std::endl;

    std::cout << "Post-order Traversal" << std::endl;
    std::cout << "==================" << std::endl;
    bst::postorder( tree );
    std::cout << std::endl << std::endl;

    std::cout << "Breadth first Traversal" << std::endl;
    std::cout << "==================" << std::endl;
    bst::breadthFirst( tree );
    std::cout << std::endl << std::endl;


    std::cout << "Find" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "Find Samy:" << bst::find( tree , "Samy" );
    std::cout << std::endl << std::endl;

    std::cout << "Find" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "Find Sondos:" << bst::find( tree , "Sondos" );
    std::cout << std::endl << std::endl;



    std::cout << "Size" << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << bst::size( tree );
    std::cout << std::endl << std::endl;


    std::cout << "Remove(100)" << std::endl;
    std::cout << "==================" << std::endl;
    bst::remove( tree , "Kareem" );
    std::cout << "Size:"  << bst::size( tree ) << std::endl;
    std::cout << "BFT:"<<std::endl;
    bst::breadthFirst( tree );
    std::cout << std::endl << std::endl;


    std::cout << "Remove(20)" << std::endl;
    std::cout << "==================" << std::endl;
    bst::remove( tree , "Toqa" );
    std::cout << "Size:"  << bst::size( tree ) << std::endl;
    std::cout << "BFT:";
    bst::breadthFirst( tree );
    std::cout << std::endl << std::endl;
    return 0;
}