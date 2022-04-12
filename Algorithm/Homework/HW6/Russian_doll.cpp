#include <iostream>
#include <list>

using namespace std;

struct Item {
    int count;
    int number;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    int count[101];
    list <Item> tolls;
    for (int i = 1; i < 101; i++) {
        count[i] = 0;
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M;
        count[M]++;
    }
    for (int i = 1; i < 101; i++) {
        if (count[i])
            tolls.push_back(Item{.count=count[i], .number=i});
    }
    while (tolls.size()) {
        list<Item>::iterator it = tolls.begin();
        while (it != tolls.end()) {
            cout << (*it).number << " ";
            if ((*it).count == 1) {
                it = tolls.erase(it);
            } else {
                (*it).count--; it++;
            }
        } cout << endl;
    }
    return 0;
}
