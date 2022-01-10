#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void dfs(short**, bool*, int, int, ofstream&);

int main() {

    ifstream ifs;
    ofstream ofs;

    string inputpath;

    int n; // number of dataset
    int m, t; // how many vertices and start point
    short** adjMatrix;

    cout << "FILEPATH: ";
    getline(cin, inputpath);
    ifs.open(inputpath);
    if (!ifs.is_open()){
        cout << "Failed to open file." << endl;
        return 1;
    }else{
        ifs >> n;
    }

    int found = inputpath.find("in");
    string outputpath = inputpath.replace(found, 2, "out");
    ofs.open(outputpath);

    for (int times = 0; times < n; times++){
        ifs >> m >> t;

        bool visited[m]; // record the vertex is visited or not
        adjMatrix = new short* [m];

        for (int i = 0; i < m; i++){
            adjMatrix[i] = new short[m];
            visited[i] = false;
        }

        // read the adjacency matrix
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                ifs >> adjMatrix[i][j];
            }
        }

        dfs(adjMatrix, visited, m, t, ofs);
        ofs << endl; // match the output
    }
    ifs.close();
    ofs.close();
    return 0;
}

void dfs(short** adj, bool* visited, int num_v, int index_v, ofstream& ofs){
    // output the vertex and record it to visited
    ofs << index_v << " ";
    visited[index_v] = true;
    for (int v = 0; v < num_v; v++){
        if (adj[v][index_v] == 1){
            // if they are adjacent
            if (!visited[v]){
                // check it has visited or not
                // if not do dfs recursively
                dfs(adj, visited, num_v, v, ofs);
            }
        }
    }
}
