#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

class MySet {
private:
    int* parent;
public:
    MySet(int N) {
        parent = new int [N];
        for (int i = 0; i < N; i++){
            parent[i] = -1;
        }
    } // constructor
    inline int find(int vertex);
    inline void combine(int s1, int s2);
};

inline int diff(char* a, char* b) {
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (a[i] != b[i]) cnt++;
    }
    return cnt;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, Q; cin >> N;
    const int edges = N*(N-1)/2;
    char number[N][7];
    MySet set(N);
    pair <int, pair<int, int>> car[edges];

    cin.ignore();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> number[i][j];
        }
        cin.ignore();
    }
    cin >> Q; // think of as buffer

    // count the edges
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            car[cnt++] = make_pair(
                diff(number[i], number[j]),
                make_pair(i, j)
            );
        }
    }
    sort(car, car+edges);

    Q = 0;
    for (auto c : car) {
        pair <int, int> u_v = c.second;
        int s1 = set.find(u_v.first);
        int s2 = set.find(u_v.second);
        if (s1 != s2) {
            set.combine(s1, s2);
            Q += c.first;
        }
    }
    cout << "The highest possible quality is 1/" << Q << ".\n";
}

inline int MySet::find(int vertex) {
    int curr = vertex;
    while (parent[curr] != -1)
        curr = parent[curr];
    if (curr != vertex)
        parent[vertex] = curr;
    return curr;
}
inline void MySet::combine(int s1, int s2) {
    parent[s1] = s2;
}
