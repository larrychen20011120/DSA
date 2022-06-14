#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> adj;

// function to add edge to the graph
void addEdge(int x,int y)
{
	adj[x].push_back(y);
}

// Function to print the required topological
// sort of the given graph
void topologicalSort()
{
	int V = adj.size();
	vector<int> in_degree(V, 0);

	for (int u = 0; u < V; u++) {
		for (auto x: adj[u])
			in_degree[x]++;
	}

	multiset<int> s;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			s.insert(i);

	int cnt = 0;
	vector<int> top_order;

	while (!s.empty()) {
		int u = *s.begin();
		s.erase(s.begin());
		top_order.push_back(u);

		for (auto x:adj[u])

			// If in-degree becomes zero, add it to queue
			if (--in_degree[x] == 0)
				s.insert(x);

		cnt++;
	}

	// Check if there was a cycle
	if (cnt != V) {
		cout << -1;
		return;
	}

	// Print topological order
	for (int i = 0; i < top_order.size(); i++)
		cout << top_order[i]+1 << " ";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    int s, e;
    while (cin >> N >> M) {
        // adjacency matrix
        adj = vector<vector<int>>(N);
        for (int i = 0; i < M; i++) {
            cin >> s >> e;
            addEdge(s-1, e-1);
        }

        // find required topological order
        topologicalSort();
        cout << endl;
    }

    return 0;
}
