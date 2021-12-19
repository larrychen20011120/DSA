#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TreeNode{
    private:
        int value;
        TreeNode* leftChild;
        TreeNode* rightChild;
    friend class BinaryTree;
};

class BinaryTree{
    public:
        void add(int);
        void preorder(TreeNode*);
        void postorder(TreeNode*);
    private:
        TreeNode* root;

};

void preToIn(int*, int*, int);
void postToIn(int*, int*, int);

int main() {
    int m;
    cin >> m;

    for (int i = 0; i < m; i++){
        int n;
        string type;

        cin.ignore();
        getline(cin, type);
        cin >> n;
        int a[n], b[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        if (type.compare("preorder-inorder") == 0){

        }else if (type.compare("postorder-inorder") == 0){

        }else{
            cout << "ERROR" << endl;
        }
    }




    return 0;
}

void preToIn(int* pre, int* in, int size){
    int visit = *pre;
    int position;

    for (int i = 0; i < size; i++){
        if (*(in + i) == visit){
            position = i;
            break;
        }
    }

    preToIn(pre + 1, in, position);
    preToIn(pre + 1 + position, in + position + 1, size - position - 1);
}
