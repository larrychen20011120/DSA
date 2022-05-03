#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int start, end;
};
bool comp(Job j1, Job j2) {
    return (j1.end < j2.end);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        Job job[N];
        for (int j = 0; j < N; j++) {
            cin >> job[j].start >> job[j].end;
        }
        int sum = 1;
        sort(job, job + N, comp);
        int pre = 0;
        for (int j = 1; j < N; j++) {
            if (job[j].start >= job[pre].end) {
                sum++;
                pre = j;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
