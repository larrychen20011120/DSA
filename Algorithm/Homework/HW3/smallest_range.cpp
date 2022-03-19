#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int value, type;
};

class MinHeap{
private:
    Node** arr = new Node* [25000];
    int length = 1;
    Node* delete_();
public:
    void insert_(Node*);
    int* find_range(int);
    void printAll(){
        for (int i = 1; i < length; i++)
            cout << arr[i]->value << " ";
        cout << endl;
    }
};

int main(int argc, char const *argv[]) {
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, len;
    int value;
    MinHeap minHeap = MinHeap();
    cin >> k;

    for (int i = 0; i < k; i++){
        // load the data
        cin >> len;
        for (int j = 0; j < len; j++){
            cin >> value;
            Node* node = new Node{.value = value, .type = i};
            minHeap.insert_(node);
        }
    }
    int* output = minHeap.find_range(k);
    cout << output[0] << " " << output[1] << endl;
    return 0;
}

void MinHeap::insert_(Node* node){
    arr[length] = node;
    int child = length;
    int parent = length / 2;
    while (parent >= 1 && arr[parent]->value > arr[child]->value){
        Node* temp = arr[parent];
        arr[parent] = arr[child];
        arr[child] = temp;
        child = parent;
        parent /= 2;
    }
    length++;
}

Node* MinHeap::delete_(){
    Node* returnNode = arr[1];
    arr[1] = arr[--length];
    int curr = 1;

    while (true) {
        int smallest = curr;
        if (2 * curr < length - 1 && arr[2 * curr]->value < arr[smallest]->value)
            smallest = 2 * curr;
        if (2 * curr < length - 2 && arr[2 * curr + 1]->value < arr[smallest]->value)
            smallest = 2 * curr + 1;

        if (smallest == curr)
            break;

        Node* temp = arr[curr];
        arr[curr] = arr[smallest];
        arr[smallest] = temp;
        curr = smallest;
    }

    return returnNode;
}

int* MinHeap::find_range(int k){
    bool finded[k];
    queue <Node*> q;
    int* returnArr = new int[3];
    returnArr[2] = 200001;
    for (int i = 0; i < k; i++)
        finded[i] = false;

    while (length != 1) {
        Node* out = delete_();
        if (!finded[out->type]){
            q.push(out);
            finded[out->type] = true;
            if ((int)q.size() == k){
                if (returnArr[2] > q.back()->value - q.front()->value){
                    returnArr[2] = q.back()->value - q.front()->value;
                    returnArr[0] = q.front()->value;
                    returnArr[1] = q.back()->value;
                }
            }
        } else {
            while (!q.empty()) {
                if (q.front()->type == out->type){
                    q.pop();
                    q.push(out);
                    break;
                } else {
                    finded[q.front()->type] = false;
                    q.pop();
                }
            }
        }
    }
    return returnArr;
}
