#include <iostream>
#include <cmath>
#define MAX_SUM 1000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    bool dist[2][MAX_SUM+1];
    int a, use = 0;
    for (int i = 0; i <= MAX_SUM; i++) {
        dist[0][i] = false;
        dist[1][i] = false;
    }
    dist[1][0] = true; // setting unuse to true
    for (int i = 0; i < N; i++) {
        cin >> a;
        for (int j = 0; j <= MAX_SUM; j++) {
            if (dist[1-use][j]) {
                dist[use][abs(a - j)] = true;
                if (a + j <= MAX_SUM)
                    dist[use][a + j] = true;
            }
        }
        // clear unuse
        for (int j = 0; j <= MAX_SUM; j++) {
            dist[1-use][j] = false;
        }
        use = 1 - use; // unuse = 1 - use
    }
    use = 1 - use;
    int src = 0;
    while (!dist[use][src])
        src++;
    cout << src << endl;
    return 0;
}
