#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <fstream>

using namespace std;

// Left Child Right Siblings Expression
class Node {

    // constructor to initialize the new node
    Node(int value, Node* lft, Node* rgt){
        this->value = value;
        this->leftChild = lft;
        this->rightChild = rgt;
    }

    // Tree Node of BST, BST can ascess the node private data
    friend class BST;
    private:
        int value;  // the int value of node
        Node* leftChild; // left child node
        Node* rightChild; // right child node
};

class BST {

    // operations of BST
    public:
        // insertion of tree node and return insert successfully or not
        bool add(int);
        // deletion of tree Node
        void del(int);
        // print out structure of BST (4-Order)
        void print();
        // search the value in the BST
        Node* search(int);

        // delete the node with trap
        void clearTrap(int);
        // print the route to save meaty
        void printRoute(int, int);

    private:
        // the root of the BST, initialize as null
        Node* root = NULL;
        // the route to sword
        stack <int> swordRoute;
        // the route to meaty
        list <int> saveRoute;

        // four kinds of printing (they will be called in public print method)
        void preorder(Node*);
        void inorder(Node*);
        void postorder(Node*);
        void levelorder();

        void findTrap(Node*, int);
        // find the meaty and save the route (saveRoute)
        void findMeaty(int);
        // find the sword and save the route (swordRoute)
        void findSword(int);
};

/*
  check whether the first integer consist of the second integer or not
    hasValue(1234, 4) => true
    hasValue(1234, 5) => false
*/
bool hasValue(int, int);

int main() {

    int choice; // User input value to choose demo type (0, 1, 2)
    char operation;  // User input the operation of bst (I, D, S, P, R)

    ifstream ifs; // for input
    string filename; // input file's name

    while (true) {

        // output for choosing demo type (0, 1, 2)
        cout << "(1) Binary Searching Tree." << endl;
        cout << "(2) Finding Meaty." << endl;
        cout << "(0) Escape and face to music next year." << endl;
        cin >> choice;

        switch (choice) {
            case 0:
            // when choice is zero, end the program
                return 0;
                break;
            case 1:
            // when choice is one,
            // construct the binary search tree with their own operations
                { // this block is used to define the bst
                    BST bst; // the binary search tree
                    while(true){

                        cout << "(I)nsert a number." << endl;
                        cout << "(D)elete a number." << endl;
                        cout << "(S)earch a number." << endl;
                        cout << "(P)rint 4 kinds of orders." << endl;
                        cout << "(R)eturn" << endl;
                        cin >> operation;

                        if (operation == 'R' || operation == 'r'){
                            // break the loop in which choice is one
                            // continue to choose the demo type
                            break;
                        }

                        if (operation == 'I' || operation == 'i'){
                            cout << "Enter numbers: ";
                            int num;
                            // input the value until -1
                            while (cin >> num && num != -1) {
                                // add the number to the binary search tree
                                // get successfully insert or not
                                bool success = bst.add(num);
                                if (success){
                                    cout << "Number " << num << " is inserted." << endl;
                                } else{
                                    cout << "Error. Number " << num << " exists." << endl;
                                }
                            }
                        }else if (operation == 'D' || operation == 'd'){
                            cout << "Enter numbers to deleted: ";
                            int num;
                            // input the value until -1
                            while (cin >> num && num != -1) {
                                // delete the corresponding number in bst
                                bst.del(num);
                            }
                        }else if (operation == 'S' || operation == 's'){
                            cout << "Enter elements to searching: ";
                            int num;
                            // input the value until -1
                            while (cin >> num && num != -1) {

                                if (bst.search(num)){
                                    // if search method return the node
                                    // then ouput bingo
                                    cout << "Bingo! " << num << " is found." << endl;
                                }else{
                                    // if search method return NULL
                                    // then ouput Sorry
                                    cout << "Sorry. " << num << " is not found." << endl;
                                }
                            }
                        }else if (operation == 'p' || operation == 'P'){
                            bst.print(); // call the print
                        }else{
                            // error command detection
                            cout << "No Such Commands!" << endl;
                        }
                    }
                }

                break;
            case 2:
                cout << "Please input the map file: ";
                cin.ignore(); // clear the input buffer's enter key
                getline(cin, filename); // user input the filename
                ifs.open(filename); // open the file with filename

                if (!ifs.is_open()){
                    // error detection
                    cout << "Error to load the file or no such file!" << endl;
                    ifs.close();
                }else{
                    // success to open the file
                    cout << "Load file success." << endl;
                    cout << endl;

                    BST map; // the map
                    int num; // number for constructing the map
                    int sword, meaty, trap; // special location in map

                    // load number from the file and add it to the map
                    while (ifs >> num){
                        map.add(num);
                    }
                    ifs.close(); // close file

                    cout << "Please input the sword location: ";
                    cin >> sword;
                    cout << "Please input the meaty's location: ";
                    cin >> meaty;
                    cout << "Please input the broccoli traps' index (0~9): ";
                    cin >> trap;
                    cout << endl;

                    // first clear the trap
                    map.clearTrap(trap);

                    // output some messages to meet the spec
                    cout << endl;
                    cout << "Capoo successfully found his favorite meaty<3." << endl;
                    cout << endl;
                    cout << "Shortest path to find the meaty : " << endl;

                    // print out the way to save meaty
                    map.printRoute(sword, meaty);

                }
                break;
            default:
                // error input
                cout << "Error input. I don't want to deal with it." << endl;
                continue;
        }
    }

}

// Implementation of those operations of BST

// Add the value to BST
bool BST::add(int value) {

    if (!this->root){
        /*  root is NULL => empty tree
            set the root's value to value
            and left and right child to NULL */
        this->root = new Node(value, NULL, NULL);
    } else {
        // root is exist
        Node* current = this->root; // first current point to the root

        while (true) { // loop for putting the value to correct position in BST

            if (value > current->value){
                // value is bigger than current's value
                // if current's rightChild exists, go to rightChild
                // if it doesn't exist, the rightChild is the corresponding position
                if (current->rightChild == NULL){
                    current->rightChild = new Node(value, NULL, NULL);
                    break;
                }
                current = current->rightChild;

            }else if (value < current-> value){
                // value is smaller than current's value
                // if current's leftChild exists, go to leftChild
                // if it doesn't exist, the leftChild is the corresponding position
                if (current->leftChild == NULL){
                    current->leftChild = new Node(value, NULL, NULL);
                    break;
                }
                current = current->leftChild;

            }else{
                // That value is the same as current's value
                // means the value have been in the BST.
                // return false, fail to insert
                return false;
            }
        }
    }
    return true; // insert successfully
}

// Search the value in BST
Node* BST::search(int value){
    Node* current = this->root; // set current to the root
    while(current){
        if (value > current->value){
            // bigger => go right
            current = current->rightChild;
        }else if (value < current->value){
            // smaller => go left
            current = current->leftChild;
        }else{
            // find it
            return current;
        }
    }
    return current; // return NULL
}

// delete the value in BST
void BST::del(int value){

    Node* current = this->search(value); // search the node and return it
    Node* replace; // replace node
    Node* replaceParent; // replace node's parent

    if (!this->root){
        // empty detection
        cout << "It's empty. You can not delete anything." << endl;
        return;
    }

    if (current){
        // find the value to be deleted
        if (current->rightChild){
            // has rightChild => replace with the smallest element in right subtree
            if (!current->rightChild->leftChild){
                // replace node is current's rightChild
                // set current's value as its rightChild's value
                // set current's rightChild as its rightChild's rightChild
                // delete the original current's rightChild
                Node* d = current->rightChild;
                current->value = d->value;
                current->rightChild = d->rightChild;
                delete d;

            }else{
                // traverse begin at current's rightChild
                replace = current->rightChild;
                replaceParent = current;

                // traverse the leftChild until the element before NULL
                // keep tracking it's parent
                while (replace->leftChild) {
                    replaceParent = replace;
                    replace = replace->leftChild;
                }
                // set the value to replace node's value
                current->value = replace->value;
                // set replace node's parent's  leftChild to replace's righChild
                replaceParent->leftChild = replace->rightChild;
                delete replace; // free replace
            }

        }else if (current->leftChild){
            // has leftChild => replace with the biggest element in left subtree
            if (!current->leftChild->rightChild){
                // replace node is current's leftChild
                // set current's value as its leftChild's value
                // set current's leftChild as its leftChild's leftChild
                // delete the original current's leftChild
                Node* d = current->leftChild;
                current->value = d->value;
                current->leftChild = d->leftChild;
                delete d;
            }else{
                // traverse begin at current's leftChild
                replace = current->leftChild;
                replaceParent = current;

                // traverse the rightChild until the element before NULL
                // keep tracking it's parent
                while (replace->rightChild) {
                    replaceParent = replace;
                    replace = replace->rightChild;
                }
                // set the value to replace node's value
                current->value = replace->value;
                // set replace node's parent's  rightChild to replace's leftChild
                replaceParent->rightChild = replace->leftChild;
                delete replace; // free replace
            }

        }else{
            // it's leaf so we need to search again to find the parent of it
            replace = replaceParent = this->root;
            bool left; // determine replace is replaceParent's left or right child

            // search
            while(true){
                if (value > replace->value){
                    // bigger => go right
                    replaceParent = replace;
                    replace = replace->rightChild;
                    left = false; // false means rightChild
                }else if (value < replace->value){
                    // smaller => go left
                    replaceParent = replace;
                    replace = replace->leftChild;
                    left = true; // true means leftChild
                }else{
                    // find it
                    if (replace->value == this->root->value){
                        // if the leaf node is root
                        // delete it and set root to NULL
                        delete replace;
                        this->root = NULL;
                    }else{
                        // it's not the root
                        delete replace;
                        if (left){
                            replaceParent->leftChild = NULL;
                        }else{
                            replaceParent->rightChild = NULL;
                        }
                    }
                    break;
                }
            }
        }

        cout << "Number " << value << " is deleted." << endl;

    } else {
        // not in BST
        cout << "Number " << value << " is not exist." << endl;
    }
}

// call four kinds of printing way
void BST::print(){
    cout << "The tree in prefix order : ";
    this->preorder(this->root);
    cout << endl; // end line
    cout << "The tree in infix order : ";
    this->inorder(this->root);
    cout << endl; // end line
    cout << "The tree in post order : ";
    this->postorder(this->root);
    cout << endl; // end line
    cout << "The tree in level order : ";
    this->levelorder();
}

void BST::levelorder(){
    // visit is the queue recording the visited node
    queue <Node*> visit;
    if (!this->root){
        // error detection and return the function
        cout << "NULL" << endl;
        return;
    }
    visit.push(this->root); // first push into the first element

    while (!visit.empty()) { // looping until queue is empty
        // first current point to the front in queue, and pop front out
        Node* current = visit.front();
        visit.pop();

        if (!current){
            // if the front is NULL, go to next iteration
            continue;
        }
        // output the vale and push children in
        cout << current->value << " ";
        visit.push(current->leftChild);
        visit.push(current->rightChild);
    }
    cout << endl; // meet output spec
}

void BST::preorder(Node* current){
    if (!this->root){
        // null detection
        cout << "NULL";
        return;
    }
    if (!current){
        // current is NULL => return
        return;
    }
    // recursive by VLR
    cout << current->value << " ";
    this->preorder(current->leftChild);
    this->preorder(current->rightChild);
}

void BST::inorder(Node* current) {
    if (!this->root){
        // null detection
        cout << "NULL";
        return;
    }
    if (!current){
        // current is NULL => return
        return;
    }
    // recursive by LVR
    this->inorder(current->leftChild);
    cout << current->value << " ";
    this->inorder(current->rightChild);
}

void BST::postorder(Node* current) {
    if (!this->root){
        // null detection
        cout << "NULL";
        return;
    }
    if (!current){
        // current is NULL => return
        return;
    }
    // recursive by LRV
    this->postorder(current->leftChild);
    this->postorder(current->rightChild);
    cout << current->value << " ";
}

// delete the trap node
void BST::clearTrap(int value){
    if (!this->root){
        // error detection
        cout << "The map is empty." << endl;
        return;
    }

    this->findTrap(this->root, value); // call findTrap
}

// recursively find the trap by postorder
void BST::findTrap(Node* current, int value){
    if (!current){
        // end condition
        return;
    }
    // LRV traverse
    this->findTrap(current->leftChild, value);
    this->findTrap(current->rightChild, value);

    if (hasValue(current->value, value)){
        // here is the trap. Delete the node.
        this->del(current->value);
    }
}

// will called in clearTrap function
bool hasValue(int number, int value){
    int divide = number;
    int remainder;
    // pick out all number of digits
    while (divide) {
        remainder = divide % 10;
        divide /= 10;
        if (remainder == value){
            // return true when the digit is the same as the value
            return true;
        }
    }
    // all digits are different from the value => false
    return false;
}

// find the meaty's location and save the route
void BST::findMeaty(int meaty){
    Node* current = this->root;

    // just like the search function but it will save route
    while(current){
        // add the visited node to the back of the list (saveRoute)
        this->saveRoute.push_back(current->value);
        if (meaty > current->value){
            current = current->rightChild;
        }else if (meaty < current->value){
            current = current->leftChild;
        }else{
            // find it and break the loop
            current = NULL;
        }
    }
}

// find the sword's location and save the route
void BST::findSword(int sword){
    Node* current = this->root;

    // just like the search function but it will save route and print route
    while(current){
        // add the visited node to the back of the list (swordRoute)
        this->swordRoute.push(current->value);
        if (sword > current->value){
            cout << current->value << "->";
            current = current->rightChild;
        }else if (sword < current->value){
            cout << current->value << "->";
            current = current->leftChild;
        }else{
            // find it and break the loop
            current = NULL;
        }
    }
}

void BST::printRoute(int sword, int meaty){
    // call find meaty (saveRoute will save the route to meaty)
    this->findMeaty(meaty);
    // call find sword (swordRoute will save the route to sword)
    this->findSword(sword);

    bool match = false; // match the value in stack (swordRoute) and list (saveRoute)

    while (!match) { // looping until match the value
        // let current first point to the top in swordRoute
        // pop it out and print it out
        int current = this->swordRoute.top();
        this->swordRoute.pop();
        cout << current << "->";

        // go through all the elements in saveRoute (by iterator)
        for (list<int>::iterator it = this->saveRoute.begin(); it != this->saveRoute.end(); it++){
            if (match){
                // if match is true, then output the value in saveRoute
                cout << *it;
                if (*it == meaty){
                    cout << endl;
                }else{
                     cout << "->";
                }
            }
            // if current's value is same as the value at saveRoute
            // then match is true
            // note that when match it won't output
            // because it's also in swordRoute
            if (current == *it) {
                match = true;
            }
        }

    }
}
