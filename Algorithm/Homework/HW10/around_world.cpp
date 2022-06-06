#include <iostream>
#include <utility>
#include <functional>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    int u, v, d;

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        int time;
        int finish_time[N];
        vector <int> adj_list[N];
        priority_queue <pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>>> adj_list_T[N];
        bool visited[N];
        bool can_reach;
        stack <int> src;

        for (int i = 0; i < N; i++) {
            finish_time[i] = -1;
            visited[i] = false;
        }

        for (int i = 0; i < M; i++) {
            cin >> u >> v >> d;
            adj_list[u-1].push_back(v-1);
            if (d == 2) {
                adj_list[v-1].push_back(u-1);
            }
        }

        // dfs
        src.push(0);
        time = 0;
        can_reach = true;
        while (!src.empty()) {
            time++;
            if (visited[src.top()]) {
                if (finish_time[src.top()] == -1)
                    finish_time[src.top()] = time;
                src.pop();
            } else {
                visited[src.top()] = true;
                for (auto adj_v : adj_list[src.top()]) {
                    if (!visited[adj_v])
                        src.push(adj_v);
                }
            }
        }

        for (auto v : visited)
            if (!v) { can_reach = false; break; }

        for (int i = 0; i < N; i++) {
            visited[i] = false;
            for (auto v : adj_list[i]) {
                adj_list_T[v].push(make_pair(finish_time[i], i));
            }
        }
        src.push(0);
        while (!src.empty()) {
            if (visited[src.top()]) {
                src.pop();
            } else {
                int curr = src.top();
                visited[curr] = true;
                while (!adj_list_T[curr].empty()) {
                    int el = adj_list_T[curr].top().second;
                    adj_list_T[curr].pop();
                    if (!visited[el]) {
                        src.push(el);
                    }
                }
            }
        }
        for (auto v : visited)
            if (!v) { can_reach = false; break; }

        if (can_reach) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}
