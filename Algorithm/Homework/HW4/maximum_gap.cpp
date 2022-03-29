#include <iostream>

#define MAX 1000000001
#define MIN -1

using namespace std;

int main(){
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int maximum = MIN, minimum = MAX;
    cin >> N;
    int *arr = new int [N];

    for (int i = 0; i < N; i++){
        cin >> arr[i];
        minimum = (arr[i] < minimum) ? arr[i] : minimum;
        maximum = (arr[i] > maximum) ? arr[i] : maximum;
    }
    if (maximum == minimum){
        cout << 0 << endl;
        return 0;
    }
    int diff = (maximum - minimum) / (N - 1);
    int buck_num = (maximum - minimum) / diff + 1;
    int *buck_max = new int [buck_num], *buck_min = new int [buck_num];
    for (int i = 0; i < buck_num; i++){
        buck_max[i] = MIN; // for judging empty or not
        buck_min[i] = MAX;
    }
    for (int i = 0; i < N; i++){
        int idx = (arr[i] - minimum) / diff;
        buck_max[idx] = (arr[i] > buck_max[idx]) ? arr[i] : buck_max[idx];
        buck_min[idx] = (arr[i] < buck_min[idx]) ? arr[i] : buck_min[idx];
    }
    int curr = 1, bef = 0;
    int max_diff = 0;
    while (curr < N) {
        if (buck_max[bef] < 0){
            // before one is empty
            bef = curr++;
        } else if (buck_max[curr] < 0){
            // current one is empty
            curr++;
        } else {
            int d = buck_min[curr] - buck_max[bef];
            bef = curr++;
            max_diff = (d > max_diff) ? d : max_diff;
        }
    }
    cout << max_diff << endl;
    return 0;
}
