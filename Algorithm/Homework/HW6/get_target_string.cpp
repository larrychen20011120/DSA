#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, src_idx, count;
    cin >> T; cin.ignore();
    string sample, target;
    for (int i = 0; i < T; i++) {
        vector <int> alphabet_pos[26];
        getline(cin, sample);
        getline(cin, target);
        for (int j = 0; j < (int)sample.length(); j++) {
            alphabet_pos[sample[j] - 'a'].push_back(j);
        }
        src_idx = -1; count = 1;
        for (int j = 0; j < (int)target.length(); j++) {
            if (alphabet_pos[target[j] - 'a'].size() == 0) {
                count = -1; break;
            }
            vector<int>::const_iterator it = upper_bound(
                alphabet_pos[target[j] - 'a'].begin(),
                alphabet_pos[target[j] - 'a'].end(),
                src_idx);
            if (it == alphabet_pos[target[j] - 'a'].end()) {
                src_idx = -1;
                count++;
                j--;  // remember j for next search
            } else {
                src_idx = *it;
            }
        }
        cout << count << endl;
    }
    return 0;
}
