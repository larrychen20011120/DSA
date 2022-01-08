#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

struct Edge{
    int v1, v2;
    int cost;
};

class MySet{
    private:
        list <int> elements;
    public:
        void add(int value){
            this->elements.push_back(value);
        }
    friend class MySets;
};

class MySets{
    private:
        int numOfSets;
        MySet* sets;
    public:
        MySets(int numOfSets){
            this->numOfSets = numOfSets;
            this->sets = new MySet[numOfSets];

            for (int i = 0; i < numOfSets; i++){
                this->sets[i].add(i);
            }
        }
        int Find(int);
        void Union(int, int);
};

int main(){

    ifstream ifs;
    ofstream ofs;

    string inputpath;
    cout << "FILEPATH: ";
    getline(cin, inputpath);
    ifs.open(inputpath);

    if (!ifs.is_open()){
        cout << "Failed to open file." << endl;
        return 1;
    }

    int found = inputpath.find("in");
    string outputpath = inputpath.replace(found, 2, "out");
    ofs.open(outputpath);

    int numOfVertex, numOfEdge;
    ifs >> numOfVertex >> numOfEdge;

    int v1, v2, cost;
    long long int totalCost = 0;
    int totalEdges = 0;
    Edge* edgeSet = new Edge[numOfEdge];
    MySets vertexSet(numOfVertex);

    for (int i = 0; i < numOfEdge; i++){
        ifs >> v1 >> v2 >> cost;
        edgeSet[i] = {v1, v2, cost};
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

    for (int i = 0; i < numOfEdge && totalEdges < numOfVertex - 1; i++){
        int setIdx1 = vertexSet.Find(edgeSet[i].v1);
        int setIdx2 = vertexSet.Find(edgeSet[i].v2);

        if (setIdx1 == setIdx2){
            // form a cycle and discard this edge
            continue;
        }else{
            totalEdges += 1;
            totalCost += edgeSet[i].cost;
            vertexSet.Union(setIdx1, setIdx2);
        }
    }

    if (totalEdges != numOfVertex - 1){
        ofs << "No Spanning Tree\n";
    }else{
        ofs << totalCost << endl;
    }

    return 0;
}

int MySets::Find(int value){
    for (int i = 0; i < this->numOfSets; i++){
        for (list<int>::iterator it = this->sets[i].elements.begin(); it != this->sets[i].elements.end(); it++){
            if (value == *it){
                return i;
            }
        }
    }
    return -1; // discard the warning because finding function must find
}

void MySets::Union(int setIndex1, int setIndex2){
    bool formerMax = (setIndex1 >= setIndex2);

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
