#ifndef Interface_Header
#define Interface_Header

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int SIZE = 9;

class BST{
    private:

        struct node
        {
            /* data */
            int key;
            node* left;
            node* right;
        };
        
        node* root;
        void addLeafPriv(int key, node* ptr);
        void printInOrderPriv(node* ptr);
        //void usrChoicePriv(char uc);
    public:
        void tstPrint();
        BST();
        node* CreateLeaf(int key);
        void addLeaf(int key);
        void printInOrder();
        void usrOptions();
        void usrChoice(char uchoice);
};
#endif