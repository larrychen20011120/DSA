#include <iostream>
#include <list>
#include <queue>
#define TOTAL 2756

using namespace std;

struct Cocktail{
    int count;
    string name;
    bool operator< (const Cocktail &c) const {
        if (count == c.count) {
            return name.compare(c.name) < 0;
        }
        return count < c.count;
    }
};
inline int char2value(char ch) {
    if (ch >= 'a') {
        return ch - 'a' + 27;
    } else if (ch >= 'A') {
        return ch - 'A' + 1;
    } else {
        return 0; // '\0'
    }
}
inline int char2idx(char ch1, char ch2) {
    return 53 * (char2value(ch1) - 1) + char2value(ch2);
}

Cocktail* inBucket(list <Cocktail*>, string);

int main(){
    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue <Cocktail> top_k;
    list <Cocktail*> buckets[TOTAL];
    int N, K;
    cin >> N >> K;
    cin.ignore();
    string name;
    for (int i = 0; i < N; i++){
        getline(cin, name);
        int b = char2idx(name[0], name[1]);
        Cocktail* c = inBucket(buckets[b], name);
        if (!c){
            c = new Cocktail();
            c->count = 0; c->name = name;
            buckets[b].push_back(c);
        } else {
            c->count--;
        }
    }
    int count_to_k = 0;
    for (int i = 0; i < TOTAL; i++){
        list <Cocktail*>::iterator iter;
        for (iter = buckets[i].begin(); iter != buckets[i].end(); iter++){
            if (count_to_k < K){
                top_k.push(*(*iter));
            } else {
                if (*(*iter) < top_k.top()){
                    top_k.pop(); top_k.push(*(*iter));
                }
            }
            count_to_k++;
        }
    }
    cout << top_k.top().name << endl;
    return 0;
}
Cocktail* inBucket(list <Cocktail*> c, string name){
    list <Cocktail*>::iterator iter;
    for (iter = c.begin(); iter != c.end() && !c.empty(); iter++){
        if ((*(iter))->name == name){
            return *(iter);
        }
    }
    return NULL;
}
