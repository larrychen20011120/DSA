#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int point[n], time[n];
    int pnt_table[m+1];

    for (int i = 0; i < n; i++)
        cin >> point[i] >> time[i];
    for (int i = 0; i <= m; i++)
        pnt_table[i] = 0;

    for (int hw = 0; hw < n; hw++) {
        for (int spent = m; spent >= time[hw]; spent--) {
            pnt_table[spent] = max (
                pnt_table[spent],
                pnt_table[spent - time[hw]] + point[hw]
            );
        }
    }
    cout << pnt_table[m] << endl;
    return 0;
}
