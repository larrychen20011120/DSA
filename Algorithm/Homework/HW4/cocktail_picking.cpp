#include <iostream>
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
    int N, Q;
    cin >> N >> Q;
    Obj* cocktails = new Obj[N];
    Obj* judges = new Obj[Q];
    for (int i = 0; i < N; i++)
        cin >> cocktails[i].position >> cocktails[i].concentration;
    for (int i = 0; i < Q; i++)
        cin >> judges[i].position >> judges[i].concentration;
    sort(cocktails, cocktails + N, compare);
    for (int i = 0; i < Q; i++){
        int idx = binary_src(cocktails, 0, Q, judges[i].position);
        while (true) {
            
        }
    }
    return 0;
}

int binary_src(Obj* arr, int start, int end, int value){
    if (end - start <= 1){
        return start;
    }
    int middle = (start + end) / 2;
    if (value < arr[middle].position){
        return binary_src(arr, start, middle, value);
    } else if (value > arr[middle].position){
        return binary_src(arr, middle + 1, end, value);
    } else {
        return middle;
    }
}
