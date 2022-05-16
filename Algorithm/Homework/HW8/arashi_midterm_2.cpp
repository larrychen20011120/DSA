#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    long long max_local ;
    vector <long long> max_global;
    int test;
    bool update;

    // initialization
    max_local = 0;
    update = false;

    for (int i = 0; i < N; i++) {
        cin >> test;
        if (test >= 0) {
            max_local += test;
        } else {
            if (update) {
                if (max_local > *max_global.rbegin()) {
                    max_global.pop_back();
                    max_global.push_back(max_local);
                }
            } else {
                max_global.push_back(max_local);
            }

            if (max_local + test >= 0) {
                update = true;
                max_local += test;
            } else {
                update = false;
                max_local = 0;
            }
        }
    }
    // for last element
    if (update) {
        if (max_local > *max_global.rbegin()) {
            max_global.pop_back();
            max_global.push_back(max_local);
        }
    } else {
        max_global.push_back(max_local);
    }

    // output
    if (max_global.size() == 1) {
        cout << max_global[0] << endl;
    } else {
        sort(max_global.begin(), max_global.end(), greater<int>());
        cout << max_global[0] + max_global[1] << endl;
    }

    return 0;
}
