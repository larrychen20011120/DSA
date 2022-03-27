# include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node (int data, Node* next): data(data), next(next) {}
};
class LinkedNode{
private:
    Node* head;
    Node* tail;
public:
    LinkedNode(){ head = tail = NULL; }
    void add(Node*);
    void radix_sort(int digit);
    Node* getHead(){ return this->head; }
};

int main(){
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, data;
    int max = 0, digit = 0;
    cin >> N;
    LinkedNode llist = LinkedNode();
    for (int i = 0; i < N; i++){
        cin >> data;
        Node *node = new Node(data, NULL);
        llist.add(node);
        max = (data > max) ? data : max;
    }

    while (max != 0){
        digit++;
        max /= 10;
    }

    if (N < 2){
        cout << 0 << endl;
    } else {
        for (int i = 0; i < digit; i++)
            llist.radix_sort(i);
        int max_diff = 0;
        for (Node *current = llist.getHead()->next, *before = llist.getHead();
             current != NULL; before = current, current = current->next ){
             if (current->data - before->data > max_diff)
                max_diff = current->data - before->data;
        }
        cout << max_diff << endl;
    }
    return 0;
}
void LinkedNode::add(Node* node){
    if (!this->head){
        head = tail = node;
    } else {
        this->tail->next = node;
        this->tail = node;
    }
}

void LinkedNode::radix_sort(int digit){
    LinkedNode bucket[10];
    int radix = 1;
    for (int i = 0; i < digit; i++)
        radix *= 10;

    for (Node *current = head; current != NULL; ){
        Node* n = current->next;
        current->next = NULL;
        bucket[current->data / radix % 10].add(current);
        current = n;
    }
    head = NULL; tail = NULL;
    for (int i = 0; i < 10; i++){
        if (bucket[i].head){
            if (!head){
                head = bucket[i].head;
                tail = bucket[i].tail;
            } else {
                tail->next = bucket[i].head;
                tail = bucket[i].tail;
            }
        }
    }
}
