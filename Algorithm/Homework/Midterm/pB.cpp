#include <iostream>
#define INFINITY 10001

using namespace std;

struct Item{
    int value;
    int idx;
};

void merge_sort(Item*, int, int, int*);
void merge(Item*, int, int, int, int*);

int main(){
    int N;
    cin >> N;
    Item arr[N];
    int ans[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i].value;
        arr[i].idx = i;
        ans[i] = 0;
    }
    merge_sort(arr, 0, N, ans);

    for (int i = 0; i < N; i++){
        cout << ans[i] << " ";
    } cout << endl;

    return 0;
}

void merge_sort(Item* arr, int start, int end, int* ans){
    if (end - start <= 1)
        return;

    int middle = (end + start) / 2;
    merge_sort(arr, middle, end, ans);
    merge_sort(arr, start, middle, ans);
    merge(arr, start, middle, end, ans);
}

void merge(Item* arr, int start, int middle, int end, int* ans){
    int len_l = middle - start, len_r = end - middle;
    Item left_arr[len_l + 1], right_arr[len_r + 1];
    for (int i = 0; i < len_l; i++){
        left_arr[i].value = arr[start + i].value;
        left_arr[i].idx = arr[start + i].idx;
    }
    for (int i = 0; i < len_r; i++){
        right_arr[i].value = arr[middle + i].value;
        right_arr[i].idx = arr[middle + i].idx;
    }

    left_arr[len_l] = Item{.value = INFINITY, .idx = 0};
    right_arr[len_r] = Item{.value = INFINITY, .idx = 0};

    int iter_l = 0, iter_r = 0;
    int idx = start;

    while (iter_l != len_l || iter_r != len_r){
        if (left_arr[iter_l].value > right_arr[iter_r].value){
            arr[idx].value = right_arr[iter_r].value;
            arr[idx].idx = right_arr[iter_r].idx;
            iter_r++;
        } else{
            arr[idx].value = left_arr[iter_l].value;
            arr[idx].idx = left_arr[iter_l].idx;
            ans[left_arr[iter_l].idx] += iter_r;
            iter_l++;
        }
        idx++;
    }
}
