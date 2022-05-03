#include <iostream>
using namespace std;

class MaxHeap{
private:
    int* arr;
    int length; int size;
public:
    MaxHeap(int* arr, int length){
        this->arr = arr;
        // start at index 1
        // parent => / 2
        // child => 2n or 2n + 1
        this->length = length;
        this->size = length;
    }

    void heapify(int idx){
        int largest = idx;
        if ((2 * idx <= length) && (arr[2 * idx] > arr[largest]))
            largest = 2 * idx;
        if ((2 * idx + 1 <= length) && (arr[2 * idx + 1] > arr[largest]))
            largest = 2 * idx + 1;

        if (largest != idx){
            int temp = arr[idx];
            arr[idx] = arr[largest];
            arr[largest] = temp;
            heapify(largest);
        }
    }
    inline void swap(int i) {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        length--;
    }
    inline void printAll(){
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int arr[N + 1];

    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    MaxHeap max_heap = MaxHeap(arr, N);

    int heap_i = N / 2;
    while (heap_i >= 1){
        max_heap.heapify(heap_i);
        heap_i--;
    }
    max_heap.printAll();
    heap_i = N;
    while (heap_i >= 2) {
        max_heap.swap(heap_i);
        max_heap.heapify(1);
        heap_i--;
    }
    max_heap.printAll();
    return 0;
}
