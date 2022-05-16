#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    int start, end;
    int start_global, end_global;
    long long max_global, max_local ;
    int test;

    // initial
    start = 1; end = 0;
    start_global = 1; end_global = 1;
    max_local = 0; max_global = 0;

    for (int i = 1; i <= N; i++) {
        cin >> test;
        if (test >= 0) {
            max_local += test;
            end++;
        } else {
            if (max_global <= max_local) {
                max_global = max_local;
                start_global = start;
                end_global = end;
            }
            if (max_local + test >= 0) {
                max_local += test;
                end++;
            } else {
                max_local = 0;
                start = i + 1;
                end = i;
            }
        }
    }
    if (max_global <= max_local) {
        max_global = max_local;
        start_global = start;
        end_global = end;
    }

    cout << max_global << " " << start_global << " " << end_global << endl;

    return 0;
}
