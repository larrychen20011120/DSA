#include <iostream>
using namespace std;

void merge(int* arr, int start, int middle, int end){
    int len_l = middle - start, len_r = end - middle;
    int left_arr[len_l], right_arr[len_r];
    // initialize the left part of the array
    for (int i = 0; i < len_l; i++)
        left_arr[i] = arr[start + i];
    // initialize the right part of the array
    for (int i = 0; i < len_r; i++)
        right_arr[i] = arr[middle + i];

    // two iterator go through left / right part of array
    int iter_l = 0, iter_r = 0;
    // idx from start to end
    int idx = start;

    while (iter_l != len_l && iter_r != len_r){
        if (left_arr[iter_l] > right_arr[iter_r]){
            arr[idx] = right_arr[iter_r];
            iter_r++; // for next right iteration
        } else {
            arr[idx] = left_arr[iter_l];
            iter_l++; // for next left iteration
        }
        idx++; // update next array element
    }
    // put into array the remaining elements
    for (; iter_l < len_l; iter_l++){
        arr[idx] = left_arr[iter_l];
        idx++;
    }
    for (; iter_r < len_r; iter_r++){
        arr[idx] = right_arr[iter_r];
        idx++;
    }

}

void merge_sort(int* arr, int start, int end){
    if (end - start <= 1)
        return;

    int middle = (end + start) / 2;
    merge_sort(arr, start, middle);
    merge_sort(arr, middle, end);
    merge(arr, start, middle, end);
}

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
    merge_sort(arr, 0, N);
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
