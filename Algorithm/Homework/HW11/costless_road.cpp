#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

class MySet {
private:
    int* parent;
public:
    MySet(int N) {
        parent = new int [N];
        for (int i = 0; i < N; i++){
            parent[i] = -1;
        }
    } // constructor
    inline int find(int vertex);
    inline void combine(int s1, int s2);
};

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, min_cost; cin >> N;
    pair <int, int> pos[N];
    const int edges = N*(N-1)/2;
    MySet set(N);
    pair <int, pair<int, int>> route[edges];

    for (int i = 0; i < N; i++)
        cin >> pos[i].first >> pos[i].second;

    // count the edges
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            route[cnt++] = make_pair(
                abs(pos[i].first-pos[j].first) + abs(pos[i].second-pos[j].second),
                make_pair(i, j)
            );
        }
    }
    sort(route, route+edges);

    min_cost = 0;
    for (auto r : route) {
        pair <int, int> u_v = r.second;
        int s1 = set.find(u_v.first);
        int s2 = set.find(u_v.second);
        if (s1 != s2) {
            set.combine(s1, s2);
            min_cost += r.first;
        }
    }
    cout << min_cost << endl;
}

inline int MySet::find(int vertex) {
    int curr = vertex;
    while (parent[curr] != -1)
        curr = parent[curr];
    if (curr != vertex)
        parent[vertex] = curr;
    return curr;
}
inline void MySet::combine(int s1, int s2) {
    parent[s1] = s2;
}
