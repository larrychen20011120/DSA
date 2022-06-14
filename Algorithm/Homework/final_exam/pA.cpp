#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

struct Edge {
    int s, d;
    int weight;
    inline bool operator> (const Edge& a) const {
        return weight > a.weight;
    }
};

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
    int N, M; cin >> N >> M;
    long long int max_cost;
    int s, d, w;
    Edge edges[M];
    MySet set(N);
    for (int i = 0; i < M; i++) {
        cin >> s >> d >> w;
        edges[i] = Edge {
            .s=s, .d=d, .weight=w
        };
    }
    sort (edges, edges+M, greater<Edge>());
    max_cost = 0;
    for (auto e : edges) {
        int s1 = set.find(e.s);
        int s2 = set.find(e.d);
        if (s1 != s2) {
            set.combine(s1, s2);
            max_cost += e.weight;
        }
    }
    cout << max_cost << endl;

    return 0;
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
