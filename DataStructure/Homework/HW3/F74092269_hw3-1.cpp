#include <iostream>
#include <string>

using namespace std;

class TreeNode{

    public:
        TreeNode(int value, TreeNode* lft, TreeNode* rgt){
            this->value = value;
            this->leftChild = lft;
            this->rightChild = rgt;
        }

    private:
        int value;
        TreeNode* leftChild;
        TreeNode* rightChild;

    friend class BinaryTree;
};

class BinaryTree{

    public:
        void add(int, TreeNode*);
        void preorder(TreeNode*);
        void postorder(TreeNode*);
        void preToIn(int*, int*, int, TreeNode*);
        void postToIn(int*, int*, int, TreeNode*);
        TreeNode* getRoot(){
            return this->root;
        }
    private:
        TreeNode* root = NULL;
};


int main() {
    int m;
    cin >> m;

    for (int i = 0; i < m; i++){
        int n;
        string type;
        BinaryTree bt;

        cin.ignore();
        getline(cin, type);
        cin >> n;
        int a[n], b[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        if (type.compare("preorder-inorder") == 0){
            bt.preToIn(a, b, n, bt.getRoot());
            bt.postorder(bt.getRoot());
        }else if (type.compare("postorder-inorder") == 0){
            bt.postToIn(a, b, n, bt.getRoot());
            bt.preorder(bt.getRoot());
        }else{
            cout << "ERROR" << endl;
        }
    }

    return 0;
}

void BinaryTree::add(int value, TreeNode* addedNode){
    addedNode = new TreeNode(value, NULL, NULL);
}

void BinaryTree::preToIn(int* pre, int* in, int size, TreeNode* curr){

    if (size == 0){
        cout << "Zero\n";
        return;
    }

    int visit = pre[0];
    int position;
    this->add(visit, curr);

    if (size == 1){
        cout << "One\n";
        return;
    }

    for (int i = 0; i < size; i++){
        if (in[i] == visit){
            position = i;
            break;
        }
    }

    preToIn(&pre[1], in, position, curr->leftChild);
    preToIn(&pre[1 + position], &in[1 + position], size - position - 1, curr->rightChild);
}

void BinaryTree::postToIn(int* post, int* in, int size, TreeNode* curr){

    int visit = *(post + size - 1);
    int position;
    this->add(visit, curr);

    if (size == 1)
        return;


    for (int i = 0; i < size; i++){
        if (*(in + i) == visit){
            position = i;
            break;
        }
    }

    postToIn(post, in, position, curr->leftChild);
    postToIn(post + position, in + position + 1, size - position - 1, curr->rightChild);
}

void BinaryTree::preorder(TreeNode* curr){
    if (!curr)
        return;

    cout << curr->value << " ";
    this->preorder(curr->leftChild);
    this->preorder(curr->rightChild);
}
void BinaryTree::postorder(TreeNode* curr){
    if (!curr)
        return;

    this->postorder(curr->leftChild);
    this->postorder(curr->rightChild);
    cout << curr->value << " ";
}
