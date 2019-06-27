#include "interface.h"

int main(){
    BST bsTree;

    int treeKeys[9] = {23,45,34,7,56,9,56,43,97}; //{95,3,11,25,74,81,99,14,42};    
    
    cout << "Print in order, before adding numbers **This is a test**" << endl;
    bsTree.printInOrder();

    for(int i; i < 9; i++){
        bsTree.addLeaf(treeKeys[i]);
    }

    cout << "Print in order, after adding numbers" << endl;
    
    bsTree.printInOrder();

    return 0;
}

void BST::tstPrint()
{cout << " Hello world " << endl;}

BST::BST(){root = nullptr;}

//node pointer, defined in constructor
BST::node* BST::CreateLeaf(int key){ node* n = new node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    return n;}

void BST::addLeaf(int key){addLeafPriv(key, root);}

void BST::addLeafPriv(int key, node* ptr){
    if(root == nullptr){
        root = CreateLeaf(key);
    }//end if
    else if(key < ptr->key){
        if(ptr->left != nullptr){
            //recursively moving down the left 
            addLeafPriv(key, ptr->left);
        }//end if inside elif
        else
        {
            ptr->left = CreateLeaf(key);
        }
    }//end elif
    else if(key > ptr->key){
        if(ptr->right != nullptr){
            //recursively moving down the left 
            addLeafPriv(key, ptr->right);
        }//end if inside elif
        else
        {
            ptr->right = CreateLeaf(key);
        }
    }//end elif
    else
    {
        
        cout << " The key " << key <<" has already been" <<
                                            " added to tree " << endl;

    }
    
}//end addLeaf

void BST::printInOrder(){
    printInOrderPriv(root);
}//end print in order

void BST::printInOrderPriv(node* ptr){
    if(root != nullptr){ //tree NOT empty
        if(ptr->left != nullptr){//possible to go left? check
            printInOrderPriv(ptr->left); //recursive call to go left if possible    
        }//end nested if
        cout << ptr->key << " "; //print current key value ^ after directions above
        if (ptr->right != nullptr) {//go right if possible, check
            printInOrderPriv(ptr->right); // going right long as possible
        }
        
    }else
    {cout << " The Tree is empty " << endl;  }//end else
    
}// end inordPriv