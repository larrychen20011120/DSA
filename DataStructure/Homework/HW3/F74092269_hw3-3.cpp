#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

int main(){

    int n; // number of dataset
    int m, t; // how many vertices and start point

    string inputpath;
    ifstream ifs; // for input file
    ofstream ofs; // for output file

    // fill in the input path and read it
    cout << "FILEPATH: ";
    getline(cin, inputpath);
    ifs.open(inputpath);

    if (!ifs.is_open()){
        // error to open the file
        cout << "Failed to open file." << endl;
        return 1;
    }
    ifs >> n;

    // find the 'in' string and replace it to 'out'
    // and then create the file
    int found = inputpath.find("in");
    string outputpath = inputpath.replace(found, 2, "out");
    ofs.open(outputpath);

    for (int times = 0; times < n; times++){
        ifs >> m >> t;
        bool visited[m]; // record the vertex is visited or not
        short adjMatrix[m][m];
        queue <int> handleQueue; // BFS queue

        // initialize all vertex unvisited
        for (int i = 0; i < m; i++){
            visited[i] = false;
        }

        // read the adjacency matrix
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                ifs >> adjMatrix[i][j];
            }
        }

        // first push in the first vertex
        handleQueue.push(t);

        // queue is empty then break out
        while(!handleQueue.empty()){
            // get the first and pop one out
            int handle = handleQueue.front();
            handleQueue.pop();

            if (visited[handle]){
                // has visited => next looping
                continue;
            }else{
                // not visited => mark it visited and output it
                visited[handle] = true;
                ofs << handle << " ";
            }

            // put all adjacency vertex in the handleQueue
            for (int i = 0; i < m; i++){
                if (adjMatrix[handle][i] == 1){
                    handleQueue.push(i);
                }
            }
        }
        ofs << endl;
    }
    return 0;
}
