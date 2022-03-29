#include <iostream>
#include <string>

using namespace std;

struct Item{
    char ch;
    int count;
};

char idx2char(int);
int char2idx(char);
void merge_sort(Item*, int, int);
void merge(Item*, int, int, int);

int main(){
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int total_char = 62;
    Item items[total_char]; // 26 * 2 + 10
    for (int i = 0; i < total_char; i++){
        items[i].count = 0;
        items[i].ch = idx2char(i);
    }
    string line;
    getline(cin, line);
    for (int i = 0; i < (int)line.length(); i++){
        items[char2idx(line[i])].count++;
    }
    merge_sort(items, 0, total_char);
    for (int i = 0; i < total_char; i++){
        for (int j = 0; j < items[i].count; j++){
            cout << items[i].ch;
        }
    } cout << endl;

    return 0;
}
char idx2char(int idx){
    if (idx >= 36){
        return (idx - 36) + 'a';
    } else if (idx >= 10 && idx <= 35){
        return (idx - 10) + 'A';
    } else {
        return '0' + idx;
    }
}
int char2idx(char ch){
    if (ch >= 'a' && ch <= 'z'){
        return 36 + ch - 'a';
    } else if (ch >= 'A' && ch <= 'Z'){
        return 10 + ch - 'A';
    } else {
        return ch - '0';
    }
}
void merge_sort(Item* arr, int start, int end){
    if (end - start <= 1)
        return;

    int middle = (end + start) / 2;
    merge_sort(arr, start, middle);
    merge_sort(arr, middle, end);
    merge(arr, start, middle, end);
}

void merge(Item* arr, int start, int middle, int end){
    int len_l = middle - start, len_r = end - middle;
    Item left_arr[len_l], right_arr[len_r];
    // initialize the left part of the array
    for (int i = 0; i < len_l; i++){
        left_arr[i].ch = arr[start + i].ch;
        left_arr[i].count = arr[start + i].count;
    }
    // initialize the right part of the array
    for (int i = 0; i < len_r; i++){
        right_arr[i].ch = arr[middle + i].ch;
        right_arr[i].count = arr[middle + i].count;
    }

    // two iterator go through left / right part of array
    int iter_l = 0, iter_r = 0;
    // idx from start to end
    int idx = start;

    while (iter_l != len_l && iter_r != len_r){
        if (left_arr[iter_l].count < right_arr[iter_r].count){
            // right is smaller => put into array
            arr[idx].count = right_arr[iter_r].count;
            arr[idx].ch = right_arr[iter_r].ch;
            iter_r++; // for next right iteration
        } else {
            arr[idx].count = left_arr[iter_l].count;
            arr[idx].ch = left_arr[iter_l].ch;
            iter_l++; // for next left iteration
        }
        idx++; // update next array element
    }
    // put into array the remaining elements
    for (; iter_l < len_l; iter_l++){
        arr[idx].count = left_arr[iter_l].count;
        arr[idx].ch = left_arr[iter_l].ch;
        idx++;
    }
    for (; iter_r < len_r; iter_r++){
        arr[idx].count = right_arr[iter_r].count;
        arr[idx].ch = right_arr[iter_r].ch;
        idx++;
    }
}
