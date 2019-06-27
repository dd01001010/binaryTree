#include "interface.h"

int main()
{
    BST bsTree;
    bsTree.usrOptions();

    // int treeKeys[9] = {23,45,34,7,56,9,56,43,97}; //{95,3,11,25,74,81,99,14,42};

    // //prompt to ask user weither to use existing set, or create set
    // char usrChoice = 0;
    // cout << "would you like to use existing set, or create a set? (Y)es create, (N)o use existing" << endl;
    // cin >> usrChoice;
    // if(usrChoice == 0){
    //     cout << "You did not enter a choice";
    // }else
    // {
    //     switch (usrChoice)
    //     {
    //     case 'y' | 'Y':
    //         cout << " you picked yes" << endl;
    //         system("pause");
    //         break;
    //     case 'n' | 'N':
    //         cout << " you picked no" << endl;
    //         system("pause");
    //         break;
    //     }
    // }

    //system("clear");

    // cout << "Print in order, before adding numbers" << endl;
    // bsTree.printInOrder();

    // for(int i = 0; i < 9; i++){
    //     bsTree.addLeaf(treeKeys[i]);
    // }

    // cout << "Print in order, after adding numbers" << endl;

    // bsTree.printInOrder();

    return 0;
}

void BST::usrOptions()
{

    //prompt to ask user weither to use existing set, or create set
    char usrChoice = 0;
    cout << "would you like to use existing set, or create a set? (Y)es create, (N)o use existing" << endl;
    cin >> usrChoice;
    if (usrChoice == 0)
    {
        cout << "You did not enter a choice";
    }
    else
    {
        switch (usrChoice)
        {
        case 'y' | 'Y':
            //must use ptr's if user is picking set size, and set items
            int *array;
            
            cout << "How large is number set ?" << endl;
            int uSize;
            cin >> uSize;
            system("clear");

            cout << "Enter your number set" << endl;
            array = new int[uSize];
            
            for (int i = 0; i < uSize; i++)
            {
                cin >> array[i];
            }

            cout << "print numbers in order ? enter for 'Y' for yes" << endl;
            char organizeNums;
            cin >> organizeNums;

            if(organizeNums = 'Y' | 'y'){
                for (int i = 0; i < 9; i++){addLeaf(array[i]);
                cout << "Print in order, after adding numbers" << endl;
                printInOrder();
                }    
            }else
            {
                cout << "Your tree" << endl;
                
            }
            


            // cout << " values in set " << endl;
            // for (int k = 0; k < uSize; k++)
            // {
            //     cout << array[k] << endl;
            // }
            
            break;
        case 'n' | 'N':
            int treeKeys[9] = {23, 45, 34, 7, 56, 9, 56, 43, 97}; //{95,3,11,25,74,81,99,14,42};

            cout << "Print in order, before adding numbers" << endl;
            printInOrder();

            for (int i = 0; i < 9; i++){addLeaf(treeKeys[i]);}

            cout << "Print in order, after adding numbers" << endl;
            printInOrder();
            break;
        }
    }
}

BST::BST() { root = nullptr; }

//node pointer, defined in constructor
BST::node *BST::CreateLeaf(int key)
{
    node *n = new node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void BST::addLeaf(int key) { addLeafPriv(key, root); }

void BST::addLeafPriv(int key, node *ptr)
{
    if (root == nullptr)
    {
        root = CreateLeaf(key);
    } //end if
    else if (key < ptr->key)
    {
        if (ptr->left != nullptr)
        {
            //recursively moving down the left
            addLeafPriv(key, ptr->left);
        } //end if inside elif
        else
        {
            ptr->left = CreateLeaf(key);
        }
    } //end elif
    else if (key > ptr->key)
    {
        if (ptr->right != nullptr)
        {
            //recursively moving down the left
            addLeafPriv(key, ptr->right);
        } //end if inside elif
        else
        {
            ptr->right = CreateLeaf(key);
        }
    } //end elif
    else
    {

        cout << " The key " << key << " has already been"
             << " added to tree " << endl;
    }

} //end addLeaf

void BST::printInOrder()
{
    printInOrderPriv(root);
} //end print in order

void BST::printInOrderPriv(node *ptr)
{
    if (root != nullptr)
    { //tree NOT empty
        if (ptr->left != nullptr)
        {                                //possible to go left? check
            printInOrderPriv(ptr->left); //recursive call to go left if possible
        }                                //end nested if
        cout << ptr->key << " ";         //print current key value ^ after directions above
        if (ptr->right != nullptr)
        {                                 //go right if possible, check
            printInOrderPriv(ptr->right); // going right long as possible
        }
    }
    else
    {
        cout << " The Tree is empty " << endl;
    } //end else

} // end inordPriv