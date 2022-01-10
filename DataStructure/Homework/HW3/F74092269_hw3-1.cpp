#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// node of the tree structure
class TreeNode{

    public:
        // constructor of the TreeNode class
        TreeNode(int value, TreeNode* lft, TreeNode* rgt){
            this->value = value;
            this->leftChild = lft;
            this->rightChild = rgt;
        }

    private:
        int value; // the value of it
        TreeNode* leftChild; // its left child
        TreeNode* rightChild; // its right sibling

    friend class BinaryTree; // setting friend class
};

// the binary structure
class BinaryTree{

    public:
        // operations of BinaryTree
        void preorder(TreeNode*, ofstream&);
        void postorder(TreeNode*, ofstream&);
        void preToIn(int*, int*, int, TreeNode*, int);
        void postToIn(int*, int*, int, TreeNode*, int);

        // get the root node out of the class
        TreeNode* getRoot(){
            return this->root;
        }
    private:
        TreeNode* root = NULL;
};


int main() {

    ifstream ifs; // for input file
    ofstream ofs; // for output file

    // fill in the input path and read it
    string inputpath;
    cout << "FILEPATH: ";
    getline(cin, inputpath);
    ifs.open(inputpath);

    if (!ifs.is_open()){
        // is open in error => output error message and termiate
        cout << "Failed to open file." << endl;
        return 1;
    }

    // find the 'in' string and replace it to 'out'
    // and then create the file
    int found = inputpath.find("in");
    string outputpath = inputpath.replace(found, 2, "out");
    ofs.open(outputpath);

    int m;
    ifs >> m;

    for (int i = 0; i < m; i++){
        // reading from the input file
        int n;
        string type;
        BinaryTree bt;
        ifs >> type;
        ifs >> n;
        int a[n], b[n];

        for (int i = 0; i < n; i++)
            ifs >> a[i];
        for (int i = 0; i < n; i++)
            ifs >> b[i];

        if (type.compare("preorder-inorder") == 0){
            // string is preorder-inorder
            // do the corresponding function
            bt.preToIn(a, b, n, NULL, 0);
            bt.postorder(bt.getRoot(), ofs);
            ofs << endl; // match the output format
        }else if (type.compare("postorder-inorder") == 0){
            // string is postorder-inorder
            // do the corresponding function
            bt.postToIn(a, b, n, NULL, 0);
            bt.preorder(bt.getRoot(), ofs);
            ofs << endl; // match the output format
        }else{
            // No matching string
            ofs << "ERROR" << endl;
        }
    }

    return 0;
}

// based on preorder-inoder, create the tree
void BinaryTree::preToIn(int* pre, int* in, int size, TreeNode* curr, int type){
    // when size is NULL => terminate recursive
    if (size == 0)
        return;

    int visit = pre[0]; // the first element in preorder is the root to subtrees
    int position; // record the position visit in inorder array

    if (!this->root){
        // when tree has no root create it
        this->root = new TreeNode(visit, NULL, NULL);
        curr = this->root;
    }else if (type == 1){
        // when type is 1 means to
        // set the leftChild as next recusive's curr
        curr->leftChild = new TreeNode(visit, NULL, NULL);
        curr = curr->leftChild;
    }else{
        // when type is -1 means to
        // set the rightChild as next recusive's curr
        curr->rightChild = new TreeNode(visit, NULL, NULL);
        curr = curr->rightChild;
    }

    for (int i = 0; i < size; i++){
        if (in[i] == visit){
            // find the position and break out
            position = i;
            break;
        }
    }
    // recursive to construct the left subtree and right subtree
    preToIn(&pre[1], in, position, curr, 1);
    preToIn(&pre[1 + position], &in[1 + position], size - position - 1, curr, -1);
}

// based on postorder-inoder, create the tree
void BinaryTree::postToIn(int* post, int* in, int size, TreeNode* curr, int type){
    // when size is NULL => terminate recursive
    if (size == 0)
        return;

    int visit = post[size - 1]; // the last element in postorder is the root to subtrees
    int position;  // record the position visit in inorder array

    if (!this->root){
        // when tree has no root create it
        this->root = new TreeNode(visit, NULL, NULL);
        curr = this->root;
    }else if (type == 1){
        // when type is 1 means to
        // set the rightChild as next recusive's curr
        curr->leftChild = new TreeNode(visit, NULL, NULL);
        curr = curr->leftChild;
    }else{
        // when type is -1 means to
        // set the rightChild as next recusive's curr
        curr->rightChild = new TreeNode(visit, NULL, NULL);
        curr = curr->rightChild;
    }

    for (int i = 0; i < size; i++){
        if (*(in + i) == visit){
            // find the position and break out
            position = i;
            break;
        }
    }
    // recursive to construct the left subtree and right subtree
    postToIn(post, in, position, curr, 1);
    postToIn(post + position, in + position + 1, size - position - 1, curr, -1);
}

// use recursive to do preorder traversal
void BinaryTree::preorder(TreeNode* curr, ofstream &ofs){
    // when it is NULL => terminate recursive
    if (!curr)
        return;

    // VLR
    ofs << curr->value << " ";
    this->preorder(curr->leftChild, ofs);
    this->preorder(curr->rightChild, ofs);
}
// use recursive to do postorder traversal
void BinaryTree::postorder(TreeNode* curr, ofstream &ofs){
    // when it is NULL => terminate recursive
    if (!curr)
        return;
    // LRV
    this->postorder(curr->leftChild, ofs);
    this->postorder(curr->rightChild, ofs);
    ofs << curr->value << " ";
}
