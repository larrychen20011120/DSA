#include <iostream>
#define INFINITY 100000001

using namespace std;

struct Item{
    int value;
    int inver_num;
};

void merge_sort(Item*, int, int);
void merge(Item*, int, int, int);

int main(){
    int N;
    cin >> N;
    Item arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i].value;
        arr[i].inver_num = 0;
    }
    merge_sort(arr, 0, N);

    int sum = 0;
    for (int i = 0; i < N; i++){
        sum += arr[i].inver_num;
        sum %= 524287;
    }
    cout << sum << endl;

    return 0;
}

void merge_sort(Item* arr, int start, int end){
    if (end - start <= 1)
        return;

    int middle = (end + start) / 2;
    merge_sort(arr, middle, end);
    merge_sort(arr, start, middle);
    merge(arr, start, middle, end);
}

void merge(Item* arr, int start, int middle, int end){
    int len_l = middle - start, len_r = end - middle;
    Item left_arr[len_l + 1], right_arr[len_r + 1];
    for (int i = 0; i < len_l; i++){
        left_arr[i].value = arr[start + i].value;
        left_arr[i].inver_num = arr[start + i].inver_num;
    }
    for (int i = 0; i < len_r; i++){
        right_arr[i].value = arr[middle + i].value;
        right_arr[i].inver_num = arr[middle + i].inver_num;
    }

    left_arr[len_l] = Item{.value = INFINITY, .inver_num = 0};
    right_arr[len_r] = Item{.value = INFINITY, .inver_num = 0};

    int iter_l = 0, iter_r = 0;
    int idx = start;

    while (iter_l != len_l || iter_r != len_r){
        if (left_arr[iter_l].value > right_arr[iter_r].value){
            arr[idx].value = right_arr[iter_r].value;
            arr[idx].inver_num = right_arr[iter_r].inver_num;
            iter_r++;
        } else{
            arr[idx].inver_num = left_arr[iter_l].inver_num + iter_r;
            arr[idx].value = left_arr[iter_l].value;
            iter_l++;
        }
        idx++;
    }
}
