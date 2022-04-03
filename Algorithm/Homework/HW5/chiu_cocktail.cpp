#include <iostream>
#include <queue>

using namespace std;

struct Cocktail{
    double concentration;
    string name;
    bool operator< (const Cocktail &c) const {
        return concentration < c.concentration;
    }
};

int main(){
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    double lemon, sugar, alcohol;
    cin >> N >> K;
    priority_queue <Cocktail> top_k;
    for (int i = 0; i < K; i++){
        cin >> lemon >> sugar >> alcohol;
        cin.ignore();
        Cocktail* cocktail = new Cocktail();
        cocktail->concentration = -alcohol / (lemon + sugar + alcohol);
        getline(cin, cocktail->name);
        top_k.push(*cocktail);
    }
    for (int i = K; i < N; i++){
        cin >> lemon >> sugar >> alcohol;
        cin.ignore();
        Cocktail* cocktail = new Cocktail();
        cocktail->concentration = -alcohol / (lemon + sugar + alcohol);
        getline(cin, cocktail->name);
        if (*cocktail < top_k.top()){
            top_k.pop(); top_k.push(*cocktail);
        }
    }
    cout << top_k.top().name << endl;

}
