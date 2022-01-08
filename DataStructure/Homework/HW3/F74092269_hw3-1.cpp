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

    ifstream ifs;
    ofstream ofs;

    string inputpath;
    cout << "FILEPATH: ";
    getline(cin, inputpath);
    ifs.open(inputpath);

    if (!ifs.is_open()){
        cout << "Failed to open file." << endl;
        return 1;
    }

    int found = inputpath.find("in");
    string outputpath = inputpath.replace(found, 2, "out");
    ofs.open(outputpath);

    int m;
    ifs >> m;

    for (int i = 0; i < m; i++){
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
            bt.preToIn(a, b, n, NULL, 0);
            bt.postorder(bt.getRoot(), ofs);
            ofs << endl;
        }else if (type.compare("postorder-inorder") == 0){
            bt.postToIn(a, b, n, NULL, 0);
            bt.preorder(bt.getRoot(), ofs);
            ofs << endl;
        }else{
            ofs << "ERROR" << endl;
        }
    }

    return 0;
}

void BinaryTree::preToIn(int* pre, int* in, int size, TreeNode* curr, int type){

    if (size == 0)
        return;

    int visit = pre[0];
    int position;

    if (!this->root){
        this->root = new TreeNode(visit, NULL, NULL);
        curr = this->root;
    }else if (type == 1){
        // left
        curr->leftChild = new TreeNode(visit, NULL, NULL);
        curr = curr->leftChild;
    }else{
        // right
        curr->rightChild = new TreeNode(visit, NULL, NULL);
        curr = curr->rightChild;
    }

    for (int i = 0; i < size; i++){
        if (in[i] == visit){
            position = i;
            break;
        }
    }

    preToIn(&pre[1], in, position, curr, 1);
    preToIn(&pre[1 + position], &in[1 + position], size - position - 1, curr, -1);
}

void BinaryTree::postToIn(int* post, int* in, int size, TreeNode* curr, int type){

    if (size == 0)
        return;

    int visit = post[size - 1];
    int position;

    if (!this->root){
        this->root = new TreeNode(visit, NULL, NULL);
        curr = this->root;
    }else if (type == 1){
        // left
        curr->leftChild = new TreeNode(visit, NULL, NULL);
        curr = curr->leftChild;
    }else{
        // right
        curr->rightChild = new TreeNode(visit, NULL, NULL);
        curr = curr->rightChild;
    }

    for (int i = 0; i < size; i++){
        if (*(in + i) == visit){
            position = i;
            break;
        }
    }

    postToIn(post, in, position, curr, 1);
    postToIn(post + position, in + position + 1, size - position - 1, curr, -1);
}

void BinaryTree::preorder(TreeNode* curr, ofstream &ofs){
    if (!curr)
        return;

    ofs << curr->value << " ";
    this->preorder(curr->leftChild, ofs);
    this->preorder(curr->rightChild, ofs);
}
void BinaryTree::postorder(TreeNode* curr, ofstream &ofs){
    if (!curr)
        return;

    this->postorder(curr->leftChild, ofs);
    this->postorder(curr->rightChild, ofs);
    ofs << curr->value << " ";
}
