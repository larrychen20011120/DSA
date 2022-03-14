#include <iostream>
using namespace std;

void insertion_sort(int *arr, int start, int end){
    for (int i = start; i < end; i++){
        int j = i;
        while (j > start){
            if (arr[j] < arr[j - 1]){
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
            else
                break;
        }
    }
}

int median(int a, int b, int c){
    if ((a >= b && b >= c) || (c >= b && b >= a)){
        return b;
    } else if ((b >= a && a >= c) || (c >= a && a >= b)){
        return a;
    } else {
        return c;
    }
}

void quick_sort(int *arr, int start, int end){
    if (end - start > 5){
        int middle = ( start + end ) / 2;
        int med = median(arr[start], arr[middle], arr[end - 1]);
        int iter1 = start, iter2 = end - 1;
        while (iter1 != iter2){
            if (arr[iter1] > med){
                int temp = arr[iter2];
                arr[iter2] = arr[iter1];
                arr[iter1] = temp;
                iter2--;
            } else
                iter1++;
        }

        arr[iter1] = med;
        quick_sort(arr, start, iter1);
        quick_sort(arr, iter1 + 1, end);

    } else
        insertion_sort(arr, start, end);
}

int main(){
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    quick_sort(arr, 0, N);
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
