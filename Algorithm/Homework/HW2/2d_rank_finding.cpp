#include <iostream>
using namespace std;

struct Point{
    int x, y;
    int index; // index: the index of rank array
};

void merge_sort(Point*, int, int);
void merge(Point*, int, int, int);
void rank_finding(Point* arr, int*, int, int);

int main(int argc, char const *argv[]) {
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, x, y;
    cin >> N;

    Point* arr;
    arr = new Point[N];
    int rank[N]; // record the rank

    for (int i = 0; i < N; i++){
        cin >> x >> y;
        arr[i] = Point{.x = x, .y = y, .index = i};
    }
    merge_sort(arr, 0, N);
    // already sorted by x's value
    rank_finding(arr, rank, 0, N);

    for (int i = 0; i < N; i++){
        cout << rank[i] << " ";
    } cout << endl;
    return 0;
}

void merge_sort(Point* arr, int start, int end){
    if (end - start <= 1)
        return;

    int middle = (end + start) / 2;
    merge_sort(arr, start, middle);
    merge_sort(arr, middle, end);
    merge(arr, start, middle, end);
}

void merge(Point* arr, int start, int middle, int end){
    int len_l = middle - start, len_r = end - middle;
    Point left_arr[len_l], right_arr[len_r];
    // initialize the left part of the array
    for (int i = 0; i < len_l; i++){
        left_arr[i].x = arr[start + i].x;
        left_arr[i].y = arr[start + i].y;
        left_arr[i].index = arr[start + i].index;
    }
    // initialize the right part of the array
    for (int i = 0; i < len_r; i++){
        right_arr[i].x = arr[middle + i].x;
        right_arr[i].y = arr[middle + i].y;
        right_arr[i].index = arr[middle + i].index;
    }

    // two iterator go through left / right part of array
    int iter_l = 0, iter_r = 0;
    // idx from start to end
    int idx = start;

    while (iter_l != len_l && iter_r != len_r){
        if (left_arr[iter_l].x > right_arr[iter_r].x){
            // right x is smaller => put into array
            arr[idx].x = right_arr[iter_r].x;
            arr[idx].y = right_arr[iter_r].y;
            arr[idx].index = right_arr[iter_r].index;
            iter_r++; // for next right iteration
        } else if (left_arr[iter_l].x < right_arr[iter_r].x){
            // left x is smaller => put into array
            arr[idx].x = left_arr[iter_l].x;
            arr[idx].y = left_arr[iter_l].y;
            arr[idx].index = left_arr[iter_l].index;
            iter_l++; // for next left iteration
        } else {
            // if x is the same, y is smaller go first
            if (left_arr[iter_l].y > right_arr[iter_r].y){
                arr[idx].x = right_arr[iter_r].x;
                arr[idx].y = right_arr[iter_r].y;
                arr[idx].index = right_arr[iter_r].index;
                iter_r++;
            } else {
                arr[idx].x = left_arr[iter_l].x;
                arr[idx].y = left_arr[iter_l].y;
                arr[idx].index = left_arr[iter_l].index;
                iter_l++;
            }
        }
        idx++; // update next array element
    }
    // put into array the remaining elements
    for (; iter_l < len_l; iter_l++){
        arr[idx].x = left_arr[iter_l].x;
        arr[idx].y = left_arr[iter_l].y;
        arr[idx].index = left_arr[iter_l].index;
        idx++;
    }
    for (; iter_r < len_r; iter_r++){
        arr[idx].x = right_arr[iter_r].x;
        arr[idx].y = right_arr[iter_r].y;
        arr[idx].index = right_arr[iter_r].index;
        idx++;
    }

}

void rank_finding(Point* arr, int *rank, int start, int end){
    if (end - start <= 1){
        rank[arr[start].index] = 0;
        return;
    }
    int middle = (start + end) / 2;
    rank_finding(arr, rank, start, middle);
    rank_finding(arr, rank, middle, end);

    int len_l = middle - start, len_r = end - middle;
    Point left_arr[len_l], right_arr[len_r];
    for (int i = 0; i < len_l; i++){
        left_arr[i].x = arr[start + i].x;
        left_arr[i].y = arr[start + i].y;
        left_arr[i].index = arr[start + i].index;
    }
    for (int i = 0; i < len_r; i++){
        right_arr[i].x = arr[middle + i].x;
        right_arr[i].y = arr[middle + i].y;
        right_arr[i].index = arr[middle + i].index;
    }

    int iter_l = 0, iter_r = 0;
    int idx = start;

    while (iter_l != len_l && iter_r != len_r){
        if (left_arr[iter_l].y > right_arr[iter_r].y){
            arr[idx].x = right_arr[iter_r].x;
            arr[idx].y = right_arr[iter_r].y;
            arr[idx].index = right_arr[iter_r].index;
            // any right one's x is bigger than all left one's x
            // justify how many point's y in left is smaller than the right one
            rank[right_arr[iter_r].index] += iter_l;
            iter_r++;
        } else {
            arr[idx].x = left_arr[iter_l].x;
            arr[idx].y = left_arr[iter_l].y;
            arr[idx].index = left_arr[iter_l].index;
            iter_l++;
        }
        idx++;
    }

    for (; iter_l < len_l; iter_l++){
        arr[idx].x = left_arr[iter_l].x;
        arr[idx].y = left_arr[iter_l].y;
        arr[idx].index = left_arr[iter_l].index;
        idx++;
    }
    for (; iter_r < len_r; iter_r++){
        arr[idx].x = right_arr[iter_r].x;
        arr[idx].y = right_arr[iter_r].y;
        arr[idx].index = right_arr[iter_r].index;
        rank[right_arr[iter_r].index] += iter_l;
        idx++;
    }
}
