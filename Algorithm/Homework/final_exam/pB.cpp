#include<iostream>
#include <list>

using namespace std;

class Graph{
	int V;
	list<int> *adjacent;
public:
	Graph(int V) {
        this->V = V;
    	adjacent = new list<int>[V];
    }
	void add(int v, int w);
	bool is_safe(int s, int d);
};

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    int start, end;
    cin >> start >> end;
    start--; end--; // the start and end

    int edge[M][2], trape;

    for(int i = 0; i < M; i++){
        cin >> edge[i][0] >> edge[i][1];
        edge[i][0]--; // match start at 0
        edge[i][1]--; // match start at 0
    }
    for(int i = 0; i < K; i++){
        cin >> trape; trape--; // start at 0
        for(int j = 0; j < M; j++)
            if(edge[j][0] == trape)
                edge[j][0] = -1; // can cross it
    }
    Graph G(N);
    for(int i = 0; i < M; i++){
        if( edge[i][0] != -1 ){
            G.add(edge[i][0], edge[i][1]);
        }
    }
    bool is_safe = G.is_safe(start, end);
    if (is_safe)
        cout << "SAFE" << endl;
    else
        cout << "UNSAFE" << endl;

}

void Graph::add(int v, int w){
	adjacent[v].push_back(w);
}

bool Graph::is_safe(int s, int d){
	if (s == d)
	return true;

	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue;
	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i;
	while (!queue.empty()) {
		s = queue.front();
		queue.pop_front();
		for (i = adjacent[s].begin(); i != adjacent[s].end(); ++i) {
			if (*i == d)
				return true;
			if (!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	return false;
}
