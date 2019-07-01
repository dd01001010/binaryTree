#include "interface.h"

int main()
{
    BST bsTree;
    char usr_choice = 'Q' || 'q';
    do
    {
        bsTree.usrOptions();
        cout << "Do you want to continue ?\n " << endl;
        cout << "Enter (Y)es or (Q)uit : ";
        cin >> usr_choice;
        cin.ignore(); //add in class
    }                 // close do
    while ((usr_choice == 'Y') || (usr_choice == 'y'));
    return 0;
}

void BST::usrOptions()
{
    //prompt to ask user weither to use existing set, or create set
    char choice = 0;
    
    cout << "would you like to use existing set, or create a number set?" <<
    "(Y) to create a number set, (N) to use existing number set" << endl;
    
    cin >> choice;
    system("clear");

    usrChoice(choice);
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

        cout << " The key " << key << " exist " << endl;
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


void BST::usrChoice(char uchoice)
{

   // usrChoicePriv(uchoice);

    if (uchoice == 0)
    {
        cout << "You did not enter a choice";
    }
    else
    {
        switch (uchoice)
        {
        case 'y' | 'Y':
            //must use ptr's if user is picking set alocation size, and list of set values
            int *array;
            cout << "How large is number set ?" << endl;
            int uSize;
            cin >> uSize;
            system("clear");

            cout << "Enter your list of values for number set" << endl;
            array = new int[uSize];

            int hldS;
            hldS = uSize;

            //off by 1 bug fixed ;)
            for (int i = 0; i <= uSize - 1; i++)
            {
                cout << hldS << " "
                     << "Remaining inputs: " << endl;
                cin >> array[i];
                hldS--;
            }

            cout << "print numbers in order ? enter 'Y' for yes" << endl;
            char organizeNums;
            cin >> organizeNums;
            system("clear");

            //switch worked better than ifElse's o_O
            switch (organizeNums)
            {
            case 'y' | 'Y':
                for (int k = 0; k < uSize; k++)
                {
                    addLeaf(array[k]);
                }
                cout << "Print in order, after adding numbers" << endl;
                printInOrder();
                cout << " " << endl;
                break;
            default:
                cout << "number set unordered " << endl;
                for (int a = 0; a < uSize; a++)
                {
                    cout << array[a] << endl;
                }
                break;
            }
            break;
        case 'n' | 'N':
            int treeKeys[SIZE] = {23, 45, 34, 7, 56, 9, 56, 43, 987};

            //{95,3,11,25,74,81,99,14,42};
            cout << "Print in order (y) or print as is (n)" << endl;
            char printPref = 'n' | 'N';
            cin >> printPref;
            system("clear");

            switch (printPref)
            {
            case 'y' | 'Y':
                
                cout << "Printing in order" << endl;
                for (int i = 0; i < SIZE; i++)
                {
                    addLeaf(treeKeys[i]);
                }
                printInOrder();
                break;

            case 'n' | 'N':
                cout << "number set unordered " << endl;
                for (int b = 0; b < SIZE; b++)
                {
                    cout << treeKeys[b] << endl;
                }
                break;
            }
            break;
        }
    }
}//end funct

// void BST::usrChoicePriv(char c)
// {
//     if (c == 0)
//     {
//         cout << "You did not enter a choice";
//     }
//     else
//     {
//         switch (c)
//         {
//         case 'y' | 'Y':
//             //must use ptr's if user is picking set alocation size, and list of set values
//             int *array;
//             cout << "How large is number set ?" << endl;
//             int uSize;
//             cin >> uSize;
//             system("clear");

//             cout << "Enter your list of values for number set" << endl;
//             array = new int[uSize];

//             int hldS;
//             hldS = uSize;

//             //off by 1 bug fixed ;)
//             for (int i = 0; i <= uSize - 1; i++)
//             {
//                 cout << hldS << " "
//                      << "Remaining inputs: " << endl;
//                 cin >> array[i];
//                 hldS--;
//             }

//             cout << "print numbers in order ? enter 'Y' for yes" << endl;
//             char organizeNums;
//             cin >> organizeNums;
//             system("clear");

//             //switch worked better than ifElse's o_O
//             switch (organizeNums)
//             {
//             case 'y' | 'Y':
//                 for (int k = 0; k < uSize; k++)
//                 {
//                     addLeaf(array[k]);
//                 }
//                 cout << "Print in order, after adding numbers" << endl;
//                 printInOrder();
//                 cout << " " << endl;
//                 break;
//             default:
//                 cout << "number set unordered " << endl;
//                 for (int a = 0; a < uSize; a++)
//                 {
//                     cout << array[a] << endl;
//                 }
//                 break;
//             }
//             break;
//         case 'n' | 'N':
//             int treeKeys[SIZE] = {23, 45, 34, 7, 56, 9, 56, 43, 987};

//             //{95,3,11,25,74,81,99,14,42};
//             cout << "Print in order (y) or print as is (n)" << endl;
//             char printPref = 'n' | 'N';
//             cin >> printPref;
//             system("clear");

//             switch (printPref)
//             {
//             case 'y' | 'Y':
                
//                 cout << "Printing in order" << endl;
//                 for (int i = 0; i < SIZE; i++)
//                 {
//                     addLeaf(treeKeys[i]);
//                 }
//                 printInOrder();
//                 break;

//             case 'n' | 'N':
//                 cout << "number set unordered " << endl;
//                 for (int b = 0; b < SIZE; b++)
//                 {
//                     cout << treeKeys[b] << endl;
//                 }
//                 break;
//             }
//             break;
//         }
//     }

// }//end funct 