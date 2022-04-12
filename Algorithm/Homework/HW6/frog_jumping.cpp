#include <iostream>
#include <vector>
using namespace std;

struct TwoBigStone {
    int max_dist = -1;
    vector <int> small_stones;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, N, W;
    char stone;
    int pos, now;
    cin >> T;
    for (int i = 0; i < T; i++) {
        vector <TwoBigStone> range;
        range.push_back(TwoBigStone());
        range[0].small_stones.push_back(0);
        now = 0;

        cin >> N >> W;
        // read the input data and initialize it
        for (int j = 0; j < N; j++) {
            cin.ignore();
            cin >> stone >> pos;
            if (stone == 'b') {
                range[now++].small_stones.push_back(pos);
                range.push_back(TwoBigStone());
                range[now].small_stones.push_back(pos);
            } else {
                range[now].small_stones.push_back(pos);
            }
        }
        // add the end (thought of as a big stone)
        range[now].small_stones.push_back(W);

        // processing all TwoBigStone
        for (int i = 0; i < (int)range.size(); i++) {
            int s = range[i].small_stones.size();
            if (s >= 4) {
                for (int j = 0; j < s-2; j++) {
                    if (range[i].small_stones[j+2] - range[i].small_stones[j]
                        > range[i].max_dist){
                        range[i].max_dist = range[i].small_stones[j+2] - range[i].small_stones[j];
                    }
                }
            } else {
                range[i].max_dist = range[i].small_stones[s - 1] - range[i].small_stones[0];
            }
        }
        int max = -1;
        for (int i = 0; i < (int)range.size(); i++) {
            if (range[i].max_dist > max) {
                max = range[i].max_dist;
            }
        }
        cout << max << endl;
    }
    return 0;
}
