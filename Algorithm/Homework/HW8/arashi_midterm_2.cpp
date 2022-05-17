#include <iostream>
#define MINIMUM -200000000001
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    int test[N];
    /********************************************************
    ** dp array is from 0~N-1, and dp_reverse is from N-1~0 *
    ** record the max_subarray from start to end            *
    *********************************************************/
    long long dp[N], dp_reverse[N];
    // max_local count the local max, max_global is the result
    long long max_local, max_global;

    // input all data
    for (int i = 0; i < N; i++)
        cin >> test[i];

    // initialization
    max_local = max(0, test[0]);
    dp[0] = test[0];
    dp_reverse[N-1] = test[N-1];

    // looping from 1~N-1 and calculate the value of dp
    for (int i = 1; i < N; i++) {
        if (test[i] >= 0) {
            max_local += test[i];
        } else {
            if (max_local + test[i] >= 0) {
                max_local += test[i];
            } else {
                max_local = 0;
            }
        }
        if (max_local == 0) {
            // if not visit positive number, it should not be zero
            dp[i] = max(dp[i-1], (long long)test[i]);
        } else {
            dp[i] = max(dp[i-1], max_local);
        }
    }

    max_local = max(0, test[N-1]); // reset for next usage

    // looping from N-2~0 and calculate the value of dp_reverse
    for (int i = N - 2; i >= 0; i--) {
        if (test[i] >= 0) {
            max_local += test[i];
        } else {
            if (max_local + test[i] >= 0) {
                max_local += test[i];
            } else {
                max_local = 0;
            }
        }
        if (max_local == 0) {
            // if not visit positive number, it should not be zero
            dp_reverse[i] = max(dp_reverse[i+1], (long long)test[i]);
        } else {
            dp_reverse[i] = max(dp_reverse[i+1], max_local);
        }
    }

    // calculate the result
    max_global = MINIMUM;
    for (int i = 0; i < N-1; i++) {
        max_global = max(
            max_global, dp[i] + dp_reverse[i+1]
        );
    }

    cout << max_global << endl;

    return 0;
}
