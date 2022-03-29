#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Obj{
    int position, concentration;
};
bool compare(Obj a, Obj b){
    return a.position < b.position;
}
int binary_src(Obj*, int, int, int);

int main(){
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    int max_con = 0;
    cin >> N >> Q;
    Obj* cocktails = new Obj[N];
    Obj* judges = new Obj[Q];
    for (int i = 0; i < N; i++){
        cin >> cocktails[i].position >> cocktails[i].concentration;
        max_con = (max_con < cocktails[i].concentration) ? cocktails[i].concentration : max_con;
    }
    for (int i = 0; i < Q; i++)
        cin >> judges[i].position >> judges[i].concentration;
    sort(cocktails, cocktails + N, compare);
    for (int i = 0; i < Q; i++){
        int now = binary_src(cocktails, 0, N, judges[i].position);
        int min_dis = abs(cocktails[now].position - judges[i].position);
        int min_idx = now;
        if (now - 1 >= 0){
            if (abs(cocktails[now - 1].position - judges[i].position) < min_dis){
                min_idx = now - 1;
                min_dis = (cocktails[now - 1].position - judges[i].position);
            }
        }
        if (now + 1 < N){
            if (abs(cocktails[now + 1].position - judges[i].position) < min_dis){
                min_idx = now + 1;
                min_dis = (cocktails[now + 1].position - judges[i].position);
            }
        }
        now = min_idx;
        int left = now - 1;
        int right = now + 1;
        while (cocktails[now].concentration < judges[i].concentration) {
            int center = judges[i].position;
            if (left >= 0 && right < N){
                if (abs(cocktails[right].position - center) <
                    abs(center - cocktails[left].position)){
                    now = right++;
                } else {
                    now = left--;
                }
            } else if (left < 0 && right < N){
                now = right++;
            } else if (left >= 0 && right >= N){
                now = left--;
            } else {
                break;
            }
        }
        if (max_con < judges[i].concentration){
            cout << -1 << endl;
        } else {
            cout << cocktails[now].position << endl;
        }
    }
    return 0;
}

int binary_src(Obj* arr, int start, int end, int value){
    int middle = (start + end) / 2;
    if (value == arr[middle].position)
        return middle;
    if (end - start <= 1){
        return start;
    }

    if (value < arr[middle].position){
        return binary_src(arr, start, middle, value);
    } else {
        return binary_src(arr, middle, end, value);
    }
}
