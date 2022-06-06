#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, score_max = 0;
    cin >> N;
    int point[N], due[N], time[N];

    for (int i = 0; i < N; i++)
        cin >> point[i] >> due[i] >> time[i];
    // sort the due array
    sort(due, due+N);

    // initialize
    int score[due[N-1]+1];
    for (auto& s : score) s = 0;

    for (int i = 0; i < N; i++) {
        for (int end = due[i]; end >= time[i]; end--) {
            score[end] = max (
                score[end], // Not doing it
                score[end-time[i]] + point[i] // before done & do it
            );
        }
    }

    for (auto s : score)
        if (score_max < s) score_max = s;

    cout << score_max << endl;
    return 0;
}
