#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

struct Vertex {
    short number;
    int dist;
    inline bool operator> (const Vertex& a) const {
        return dist > a.dist;
    }
};

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    int dist[N][N];
    bool visited[N];
    Vertex v[N];
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> min_heap;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            cin >> dist[i][j];
            dist[j][i] = dist[i][j];
        }
    }
    for (int i = 1; i < N; i++) {
        v[i].number = i;
        v[i].dist = dist[0][i];
        visited[i] = false;
        min_heap.push(v[i]);
    }
    v[0].dist = 0;


    while (!min_heap.empty()) {
        while (visited[min_heap.top().number])
            min_heap.pop();
        int curr = min_heap.top().number;
        min_heap.pop();

        for (int i = 0; i < N; i++) {
            if (i == curr) continue;

            if (dist[curr][i] + v[curr].dist < v[i].dist) {
                v[i].dist = dist[curr][i] + v[curr].dist;
                if (!visited[i])
                    min_heap.push(v[i]);
            }
        }
    }
    int result = 0;
    for (auto el : v) {
        result = max(result, el.dist);
    }
    cout << result << endl;
}
