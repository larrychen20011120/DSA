#include <iostream>
using namespace std;

int main(){
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    long long int table[N+1];
    table[0] = 0; table[1] = 1; table[2] = 2;
    for (int i = 3; i <= N; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
    cout << table[N] << endl;
    return 0;
}
