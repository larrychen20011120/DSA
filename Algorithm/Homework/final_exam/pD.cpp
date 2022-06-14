#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <bitset>
#include <cstring>
#include <functional>

using namespace std;

struct Edge{
    int to_vtx;
    long long weight;
    bool operator<(const Edge &other)const{
        return weight > other.weight;
    }
};

// error caption or it can't function
vector<Edge> vtx[100001];
priority_queue<Edge> heap;
bitset<100001> visited;
long long dist[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, F;
    cin >> N >> M >> F;
    int start, end, weight, repair;
    for (int i = 0; i < 100001; i++) dist[i] = -1;

    for(int i = 0; i < M; i++){
        cin >> start >> end >> weight;
        vtx[start].push_back(Edge{.to_vtx = end, .weight=weight});
        vtx[end].push_back(Edge{.to_vtx=start, .weight=weight});
    }
    for(int i = 0; i < F; i++) {
        cin >> repair;
        heap.push(Edge{repair, 0});
    }
    while(!heap.empty()){
        Edge curr = heap.top();
        heap.pop();

        if(visited[curr.to_vtx])
            continue;

        visited[curr.to_vtx] = 1;
        dist[curr.to_vtx] = curr.weight;
        for(auto el : vtx[curr.to_vtx]) {
            if(!visited[el.to_vtx]) {
                heap.push(Edge {el.to_vtx, curr.weight + el.weight});
            }
        }
    }
    for(int i = 1; i <= N; i++)
        cout << dist[i] << " ";

    cout << endl;
}
