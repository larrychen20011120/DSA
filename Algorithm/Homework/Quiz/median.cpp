#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(vector<int>);
int select(vector<int>, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector <int> arr(N);
    for (auto& a : arr)
        cin >> a;
    int answer = select(arr, (N+1)/2);
    cout << "answer: " << answer << endl;
    return 0;
}
// including start but excluding end
int select(vector<int> arr, int src){
    if (arr.size() == 1)
        return arr[0];
    int pivot = partition(arr);
    vector <int> small, big;
    for (auto a : arr) {
        if (a < pivot)
            small.push_back(a);
        if (a > pivot)
            big.push_back(a);
    }
    int k = (int)small.size() + 1;
    if (k == src)
        return pivot;
    else if (src > k)
        return select(big, src - k);
    else
        return select(small, src);
}

int partition(vector<int> arr) {
    int i = 0, s = arr.size();
    int temp[5];
    vector <int> medians;
    while (i + 5 <= s) {
        int start = i;
        temp[0] = arr[i++];
        for (; i < 5 + start; i++) {
            int key = arr[i];
            int j = i - start - 1;
            while (j >= 0 && temp[j] > key) {
                temp[j+1] = temp[j];
                j--;
            }
            temp[j+1] = key;
        }
        medians.push_back(temp[2]);
    }
    if (i != s) {
        int start = i;
        temp[0] = arr[i++];
        for (; i < s; i++) {
            int key = arr[i];
            int j = i - start - 1;
            while (j >= 0 && temp[j] > key) {
                temp[j+1] = temp[j];
                j--;
            }
            temp[j+1] = key;
        }
        medians.push_back(temp[(s - start - 1) / 2]);
    }

    int result = select(medians, ((int)medians.size() + 1)/2);
    cout << "pivot: " << result << endl;
    return result;
}
