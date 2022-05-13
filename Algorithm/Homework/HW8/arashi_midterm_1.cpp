#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    int start, end;
    long long maximum = 0;
    int test[N+1];
    long long difficuty[N+1];

    for (int i = 1; i <= N; i++) {
        cin >> test[i];
        if (test[i] < 0)
            maximum += test[i];
    }

    for (int i = N; i >= 1; i--) {
        difficuty[i] = test[i];
        for (int j = N; j > i; j--) {
            difficuty[j] = difficuty[j] + test[i];
            if (difficuty[j] > maximum) {
                maximum = difficuty[j];
                start = i; end = j;
            }
        }
    }
    cout << maximum << " " << start << " " << end << endl;

    return 0;
}
