#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

int main(){

    int n; // number of dataset
    int m, t; // how many vertices and start point

    string inputpath;
    ifstream ifs;
    ofstream ofs;

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
        short adjMatrix[m][m];
        queue <int> handleQueue;

        for (int i = 0; i < m; i++){
            visited[i] = false;
        }

        // read the adjacency matrix
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                ifs >> adjMatrix[i][j];
            }
        }

        // first push in the first element
        handleQueue.push(t);

        while(!handleQueue.empty()){
            int handle = handleQueue.front();
            handleQueue.pop();

            if (visited[handle]){
                continue;
            }else{
                visited[handle] = true;
                ofs << handle << " ";
            }

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
