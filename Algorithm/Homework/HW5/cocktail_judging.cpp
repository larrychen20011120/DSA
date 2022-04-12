#include <iostream>
#include <queue>

using namespace std;

struct Cocktail {
    int number, concentration;
    bool operator< (const Cocktail &c) const {
        if (concentration == c.concentration) {
            return number > c.number;
        }
        return concentration < c.concentration;
    }
};

class MaxHeap {
private:
    int end;
    int* where_is; // number to index in heap
    Cocktail* heap;
public:
    MaxHeap(int K, int N) {
        end = 1; where_is = new int[N]; heap = new Cocktail[K + 1];
        for (int i = 0; i < N; i++) { where_is[i] = 0; }
    }
    inline void insert_(int, int);
    inline void delete_(int);
    inline void pop_();
    inline Cocktail top_() { return heap[1]; }
    inline bool in_heap(int number) {
        return where_is[number] != 0;
    }
    inline int size() { return end - 1; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    MaxHeap max_heap = MaxHeap(K, N);
    priority_queue <Cocktail> cocktails;
    int value;
    for (int i = 0; i < K; i++) {
        cin >> value;
        max_heap.insert_(i, value);
    }
    for (int i = K; i < M; i++) {
        cin >> value;
        if (max_heap.top_().concentration > value) {
            cocktails.push(Cocktail {max_heap.top_().number, -max_heap.top_().concentration});
            max_heap.pop_();
            max_heap.insert_(i, value);
        } else {
            cocktails.push(Cocktail {i, -value});
        }
    }
    cout << max_heap.top_().concentration << " ";
    for (int i = M; i < N; i++) {
        cin >> value;
        if (max_heap.in_heap(i - M)) {
            max_heap.delete_(i - M);
            max_heap.insert_(i, value);
        } else {
            cocktails.push(Cocktail {i, -value});
        }
        while (max_heap.top_().concentration > -cocktails.top().concentration){
            if (cocktails.top().number <= i - M) {
                cocktails.pop();
            } else {
                cocktails.push(Cocktail {max_heap.top_().number, -max_heap.top_().concentration});
                max_heap.pop_();
                max_heap.insert_(cocktails.top().number, -cocktails.top().concentration);
                cocktails.pop();
            }
        }
        cout << max_heap.top_().concentration << " ";
    } cout << endl;
    return 0;
}
inline void MaxHeap::insert_(int number, int concentration){
    heap[end].number = number; heap[end].concentration = concentration;
    where_is[number] = end;
    int curr = end;
    while (curr > 1 && heap[curr / 2] < heap[curr]) {
        // swap them
        int parent = curr / 2;
        where_is[heap[curr].number] = parent;
        where_is[heap[parent].number] = curr;
        int temp = heap[curr].number;
        heap[curr].number = heap[parent].number;
        heap[parent].number = temp;
        temp = heap[curr].concentration;
        heap[curr].concentration = heap[parent].concentration;
        heap[parent].concentration = temp;
        curr = parent; // next iter
    }
    end++;
}
inline void MaxHeap::delete_(int number){
    int curr = where_is[number]; end--;
    where_is[number] = 0; where_is[heap[end].number] = curr;
    heap[curr].concentration = heap[end].concentration;
    heap[curr].number = heap[end].number;
    while (curr < end) {
        int next = curr;
        if (2 * curr < end && heap[curr] < heap[2 * curr])
            next = 2 * curr;
        if (2 * curr + 1 < end && heap[next] < heap[2 * curr + 1])
            next = 2 * curr + 1;
        // swap them
        if (next == curr) {
            break;
        } else {
            where_is[heap[curr].number] = next;
            where_is[heap[next].number] = curr;
            int temp = heap[curr].number;
            heap[curr].number = heap[next].number;
            heap[next].number = temp;
            temp = heap[curr].concentration;
            heap[curr].concentration = heap[next].concentration;
            heap[next].concentration = temp;
            curr = next; // next iter
        }
    }
}
inline void MaxHeap::pop_() {
    // end - 1 cover the index 1
    end--;
    where_is[heap[1].number] = 0; where_is[heap[end].number] = 1;
    heap[1].concentration = heap[end].concentration;
    heap[1].number = heap[end].number;
    int curr = 1;
    while (curr < end) {
        int next = curr;
        if (2 * curr < end && heap[curr] < heap[2 * curr])
            next = 2 * curr;
        if (2 * curr + 1 < end && heap[next] < heap[2 * curr + 1])
            next = 2 * curr + 1;
        // swap them
        if (next == curr) {
            break;
        } else {
            where_is[heap[curr].number] = next;
            where_is[heap[next].number] = curr;
            int temp = heap[curr].number;
            heap[curr].number = heap[next].number;
            heap[next].number = temp;
            temp = heap[curr].concentration;
            heap[curr].concentration = heap[next].concentration;
            heap[next].concentration = temp;
            curr = next; // next iter
        }
    }
}
