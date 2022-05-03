#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int s[n], t[n];
    int point[n][n], time[n][n];
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
        time[i][i] = (t[i] <= m) ? t[i] : 0;
        point[i][i] = s[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int k = j + i + 1;
            point[j][k] = -1;
        }
    }
    return 0;
}
