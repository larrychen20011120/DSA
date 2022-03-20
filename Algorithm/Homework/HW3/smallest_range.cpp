#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int value, type;
};

class MinHeap{
private:
    Node** arr;
    int length;
    int max;
public:
    void insert_(Node*);
    Node* delete_();
    MinHeap(int k){
        arr = new Node* [k];
        length = 1; max = -100001;
    }
    int getMax() { return max; }
    int getMin() { return arr[1]->value; }
};

int main(int argc, char const *argv[]) {
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, len, value;
    int result[3];
    cin >> k;
    queue <Node*> q_arr[k];
    MinHeap minHeap = MinHeap(k);

    for (int i = 0; i < k; i++){
        // load the data
        cin >> len;
        for (int j = 0; j < len; j++){
            cin >> value;
            q_arr[i].push(new Node{.value = value, .type = i});
        }
    }
    // initial
    for (int i = 0; i < k; i++){
        minHeap.insert_(q_arr[i].front());
        q_arr[i].pop();
    }
    result[0] = minHeap.getMin(); result[1] = minHeap.getMax();
    result[2] = result[1] - result[0];

    while (true) {
        Node* out = minHeap.delete_();
        if (q_arr[out->type].empty())
            break;

        minHeap.insert_(q_arr[out->type].front());
        q_arr[out->type].pop();

        if (minHeap.getMax() - minHeap.getMin() < result[2]){
            result[0] = minHeap.getMin(); result[1] = minHeap.getMax();
            result[2] = result[1] - result[0];
        }
    }
    cout << result[0] << " " << result[1] << endl;
    return 0;
}

void MinHeap::insert_(Node* node){
    max = (node->value > max) ? node->value : max;
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
        if (2 * curr < length && arr[2 * curr]->value < arr[smallest]->value)
            smallest = 2 * curr;
        if (2 * curr + 1 < length && arr[2 * curr + 1]->value < arr[smallest]->value)
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
