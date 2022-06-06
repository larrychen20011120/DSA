#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

struct Vertex {
    int dfn, low;
    int importance;
};

bool comp(const std::pair<int, char>& a, const std::pair<int, char>& b)
{
  if (a.first > b.first) {
    return true;
  } else if (a.first == b.first && a.second < b.second) {
    return true;
  }
  return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M, u, v;
    cin >> N >> M;

    stack <int> src;
    vector <int> adj_list[N];
    Vertex villages[N];
    bool visited[N];
    int parent[N];
    pair <int, int> dfn_seq [N];

    while (true) {
        cin >> u >> v;
        if (u == -1 && v == -1)
            break;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i = 0; i < N; i++) {
        villages[i].importance = 1;
        visited[i] = false;
    }

    // dfs
    src.push(0);
    int count = 0;
    while (!src.empty()) {
        int curr = src.top();
        src.pop();
        if (!visited[curr]) {
            visited[curr] = true;
            villages[curr].dfn = count++;
            villages[curr].low = villages[curr].dfn;
            for (auto adj_v : adj_list[curr]) {
                if (!visited[adj_v]) {
                    parent[adj_v] = curr;
                    src.push(adj_v);
                } else if (villages[adj_v].dfn < villages[curr].dfn - 1) {
                    villages[curr].low = min(
                        villages[curr].low, villages[adj_v].dfn
                    );
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        dfn_seq[i] = make_pair(villages[i].dfn, i);
    }
    sort(dfn_seq, dfn_seq+N, greater<pair<int, int>>());

    for (auto s : dfn_seq) {
        for (auto adj_v : adj_list[s.second]) {
            if (parent[adj_v] == s.second) {
                villages[s.second].low = min (
                    villages[s.second].low, villages[adj_v].low
                );
            }
        }
        for (auto adj_v : adj_list[s.second]) {
            if (parent[adj_v] == s.second) {
                if (villages[s.second].dfn <= villages[adj_v].low)
                    villages[s.second].importance++;
            }
        }
    }
    villages[0].importance--;

    for (int i = 0; i < N; i++) {
        dfn_seq[i] = make_pair(villages[i].importance, i);
    }
    sort(dfn_seq, dfn_seq+N, comp);
    for (int i = 0; i < M; i++) {
        cout << dfn_seq[i].second << " " << dfn_seq[i].first << endl;
    }

    return 0;
}
