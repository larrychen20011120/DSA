#include <iostream>
using namespace std;

class MinHeap{
private:
    int* arr;
    int length;
public:
    MinHeap(int* arr, int length){
        this->arr = arr;
        // start at index 1
        // parent => / 2
        // child => 2n or 2n + 1
        this->length = length;
    }

    void heapify(int idx){
        int largest = idx;
        if ((2 * idx <= length) && (arr[2 * idx] < arr[largest]))
            largest = 2 * idx;
        if ((2 * idx + 1 <= length) && (arr[2 * idx + 1] < arr[largest]))
            largest = 2 * idx + 1;

        if (largest != idx){
            int temp = arr[idx];
            arr[idx] = arr[largest];
            arr[largest] = temp;
            heapify(largest);
        }
    }

    void printAll(){
        for (int i = 1; i <= length; i++)
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
    MinHeap min_heap = MinHeap(arr, N);

    int heap_i = N / 2;
    while (heap_i >= 1){
        min_heap.heapify(heap_i);
        heap_i--;
    }

    min_heap.printAll();
    return 0;
}
