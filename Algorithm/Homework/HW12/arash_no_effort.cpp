#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M, N;
    int D1, D2;

    while (cin >> N >> M) {
        stack <int> src;
        vector <int> easier_than[N+1];
        bool visited[N+1];
        bool printed[N+1];
        for (int i = 1; i <= N; i++){
            visited[i] = false;
            printed[i] = false;
        }

        for (int i = 0; i < M; i++) {
            cin >> D1 >> D2;
            easier_than[D2].push_back(D1);
        }

        for (int i = N; i >= 1; i--) {
            src.push(i); // for the stack iteration use reverse
            if (!easier_than[i].empty())
                sort(easier_than[i].begin(), easier_than[i].end(),
                     greater<int>());
        }

        while (!src.empty()) {
            int curr = src.top();
            if (visited[curr]) {
                if (!printed[curr]) {
                    cout << curr << " ";
                    printed[curr] = true;
                }
                src.pop();
            } else {
                visited[curr] = true;
                for (auto easier : easier_than[curr])
                    if (!visited[easier])
                        src.push(easier);
            }
        }
        cout << endl;
    }
    return 0;
}
