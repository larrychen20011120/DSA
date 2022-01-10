#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

// Edge to record the adjacent vertices and cost between them
struct Edge{
    int v1, v2;
    int cost;
};

// Myset is used to record the connected component
class MySet{
    private:
        list <int> elements; // connected component
    public:
        void add(int value){
            // add to list buttom
            this->elements.push_back(value);
        }
    friend class MySets;
};

// record how many sets are their and each component
class MySets{
    private:
        int numOfSets;
        MySet* sets; // components
    public:
        MySets(int numOfSets){
            // first initialize the set's number to numOfVertex
            this->numOfSets = numOfSets;
            this->sets = new MySet[numOfSets];
            // let all vertex construct one set1
            // therefore totally, there are numOfVertex sets
            for (int i = 0; i < numOfSets; i++){
                this->sets[i].add(i);
            }
        }
        int Find(int);
        void Union(int, int);
};

int main(){

    ifstream ifs; // for input file
    ofstream ofs; // for output file

    // input the file path and read it
    string inputpath;
    cout << "FILEPATH: ";
    getline(cin, inputpath);
    ifs.open(inputpath);

    if (!ifs.is_open()){
        // error to open it
        cout << "Failed to open file." << endl;
        return 1;
    }

    // replace 'in' string to 'out' string
    // and open the output file
    int found = inputpath.find("in");
    string outputpath = inputpath.replace(found, 2, "out");
    ofs.open(outputpath);

    int numOfVertex, numOfEdge;
    ifs >> numOfVertex >> numOfEdge;

    int v1, v2, cost; // two adjacent vertices and the cost between them
    long long int totalCost = 0; // record the total cost (long long int in case overflow)
    int totalEdges = 0; // record how many edges is choosen
    Edge* edgeSet = new Edge[numOfEdge]; // edges' array
    MySets vertexSet(numOfVertex); // initialize

    for (int i = 0; i < numOfEdge; i++){
        ifs >> v1 >> v2 >> cost;
        edgeSet[i] = {v1, v2, cost}; // construct the edges' array
    }

    // bubble sort from smaller one to bigger one
    for (int i = 0; i < numOfEdge; i++){
        for (int j = 0; j < numOfEdge - 1 - i; j++){
            if (edgeSet[j].cost > edgeSet[j + 1].cost){
                // swap j + 1's element and j's element
                // when j is bigger than j + 1
                Edge tempEdge = {edgeSet[j].v1, edgeSet[j].v2, edgeSet[j].cost};
                edgeSet[j] = edgeSet[j + 1];
                edgeSet[j + 1] = tempEdge;
            }
        }
    }

    // now edge array is in non decreasing order

    for (int i = 0; i < numOfEdge && totalEdges < numOfVertex - 1; i++){
        // go through edge array and
        // finding the set the vertices from
        int setIdx1 = vertexSet.Find(edgeSet[i].v1);
        int setIdx2 = vertexSet.Find(edgeSet[i].v2);

        if (setIdx1 == setIdx2){
            // in the same set
            // form a cycle and discard this edge
            continue;
        }else{
            totalEdges += 1;
            totalCost += (long long int)edgeSet[i].cost;
            vertexSet.Union(setIdx1, setIdx2); // Union the two set for next usage
        }
    }

    if (totalEdges != numOfVertex - 1){
        ofs << "No Spanning Tree\n";
    }else{
        ofs << totalCost << endl;
    }

    return 0;
}

// find the set index for specific vertex
int MySets::Find(int value){
    for (int i = 0; i < this->numOfSets; i++){
        // go through the sets
        for (list<int>::iterator it = this->sets[i].elements.begin(); it != this->sets[i].elements.end(); it++){
            // go through set's elements
            if (value == *it){
                // find out and return
                return i;
            }
        }
    }
    return -1; // discard the warning because finding function must find
}

// Union two sets
void MySets::Union(int setIndex1, int setIndex2){
    bool formerMax = (setIndex1 >= setIndex2); // check the former is bigger or not

    if (formerMax){
        // set2 add to set1
        this->sets[setIndex1].elements.merge(this->sets[setIndex2].elements);
        // data movement from set2 to end
        this->numOfSets--;
        for (int i = setIndex2; i < numOfSets; i++){
            this->sets[i] = this->sets[i + 1];
        }
    }else{
        // set1 add to set2
        this->sets[setIndex2].elements.merge(this->sets[setIndex1].elements);
        // data movement from set2 to end
        this->numOfSets--;
        for (int i = setIndex1; i < numOfSets; i++){
            this->sets[i] = this->sets[i + 1];
        }
    }

}
