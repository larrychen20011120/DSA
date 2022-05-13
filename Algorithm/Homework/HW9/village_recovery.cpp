#include <iostream>
#include <vector>
#include <queue>
#define INF 176000000000

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    const int OIL = 1000, RECOVER = 870000;
    int M, N, v1, v2, num_ruin, min_start;
    long long min_cost;
    cin >> N >> M;
    bool ruin[N];
    long long cost[N];
    vector <int> graph[N];

    for (int i = 0; i < N - 1; i++) {
        cin >> v1 >> v2;
        ruin[i] = false;
        cost[i] = 0;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    ruin[N-1] = false; cost[N-1] = 0;
    for (int i = 0; i < M; i++) {
        cin >> v1;
        ruin[v1] = true;
    }
    min_cost = INF;
    for (int i = 0; i < N; i++) {
        num_ruin = M;
        queue <int> next_src;
        next_src.push(i);
        while (num_ruin != 0) {
            int curr = next_src.front();
            if (ruin[curr])
            for (auto v : graph[i])
        }
    }
    return 0;
}
