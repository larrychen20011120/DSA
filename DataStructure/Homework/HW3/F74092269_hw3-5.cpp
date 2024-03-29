#include <iostream>
#include <string>
#include <fstream>
#include <queue>

#define INF 500000001 // max distance may be 500000000

using namespace std;

// class adjNode is like the linked list
// it will record the adjacent vertex,
// cost of the path and next adjacent vertex
class adjNode{
    private:
        // attribute to record the information
        adjNode* next;
        int adjVertex;
        int cost;
    public:
        // constructor for initialize the attribute
        adjNode(int adjVertex, int cost, adjNode* next){
            this->adjVertex = adjVertex;
            this->cost = cost;
            this->next = next;
        }
        adjNode(){
            // initialize the head
            // it will be called in Graph class
            this->next = NULL;
            this->cost = -1;
            this->adjVertex = -1;
        }
    friend class Graph;
};

// record the number of vertices
// and each vertex's adjacent vertices
class Graph{
    private:
        adjNode* adjHead; // adjNode array
        int numOfVertex;
    public:
        Graph(int num){
            // generate the adjNode array and the index
            // means the vertex we focus on.
            // the array consist of linked list
            this->adjHead = new adjNode[num];
            this->numOfVertex = num;
        }
        // based on two vertex, we insert them into
        //the front of their linked list
        void add(int v1, int v2, int cost){
            // minus one => let the index is correct for our array
            // the question is start at 1
            // however my array is start at 0
            v1--; v2--;
            this->adjHead[v1].next = new adjNode(v2, cost, this->adjHead[v1].next);
            this->adjHead[v2].next = new adjNode(v1, cost, this->adjHead[v2].next);
        }
        void findShortestPath(int start, ofstream&);
};

int main(){

    ifstream ifs; // for input file
    ofstream ofs; // for output file

    // fill in the input path and read it
    string inputpath;
    cout << "FILEPATH: ";
    getline(cin, inputpath);
    ifs.open(inputpath);

    if (!ifs.is_open()){
        // Error for no such file
        cout << "Failed to open file." << endl;
        return 1;
    }

    // find the 'in' string and replace it to 'out'
    // and then create the file
    int found = inputpath.find("in");
    string outputpath = inputpath.replace(found, 2, "out");
    ofs.open(outputpath);

    int numOfVertex;
    int v1, v2, cost;
    int startVertex;
    ifs >> numOfVertex;
    Graph myGraph(numOfVertex); // initialize the graph

    // based on input fill the Graph
    for (int i = 0; i < numOfVertex - 1; i++){
        ifs >> v1 >> v2 >> cost;
        myGraph.add(v1, v2, cost);
    }
    ifs >> startVertex;

    myGraph.findShortestPath(startVertex, ofs);

    return 0;
}

void Graph::findShortestPath(int start, ofstream& ofs){
    start--; // correct the vertex number to vertex index
    int* distance = new int[this->numOfVertex]; // record distance from start to others
    bool* visit = new bool[this->numOfVertex]; // record the vertex visited or not
    queue <int> handleIndexes; // the index of vertex to be handled

    // initialize the visit to false and distance to infinity
    for (int i = 0; i < this->numOfVertex; i++){
        visit[i] = false;
        distance[i] = INF;
    }

    distance[start] = 0; // distance from start to start is 0
    handleIndexes.push(start); // push start into handle queue

    // go through all vertex
    while(!handleIndexes.empty()){
        // get the front and pop it out
        int searchIdx = handleIndexes.front();
        handleIndexes.pop();

        if (visit[searchIdx]){
            // has visited and then next looping
            continue;
        }else{
            // not visited mark it to visited
            visit[searchIdx] = true;
        }

        // go through all adjacent vertices to searchIdx
        for (adjNode* iter = this->adjHead[searchIdx].next; iter != NULL; iter = iter->next){
            handleIndexes.push(iter->adjVertex); // push it into handleQueue
            if (distance[iter->adjVertex] > distance[searchIdx] + iter->cost){
                // if the distance from start to searchIdx +
                // distance from searchIdx to adjacent vertex
                // is smaller than the distance from start to adjacent vertex,
                // change the distance
                distance[iter->adjVertex] = distance[searchIdx] + iter->cost;
            }
        }
    }

    // print out the result
    for (int i = 0; i < this->numOfVertex; i++){
        ofs << i + 1 << " " << distance[i] << endl;
    }
}
