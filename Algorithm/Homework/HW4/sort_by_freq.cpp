#include <iostream>
#include <string>
#include <list>

using namespace std;

int char2idx(char);

int main(){
    int count[62]; // 26 * 2 + 10
    char* output;
    for (int i = 0; i < 62; i++)
        count[i] = 0;
    string line;
    getline(cin, line);
    int len = line.length();
    output = new char[len + 1]; output[len] = '\0';
    list <int> searchIdx;

    for (int i = 0; i < len; i++){
        int idx = char2idx(line[i]);
        if (!count[idx])
            searchIdx.push_back(idx);
        count[idx]++;
    }
    for (list<int>::iterator it = searchIdx.begin();
         it != searchIdx.end(); it++){

    }
    cout << output;
    return 0;
}

int char2idx(char ch){
    if (ch >= 'a' && ch <= 'z'){
        return 36 + ch - 'a';
    } else if (ch >= 'A' && ch <= 'Z'){
        return 10 + ch - 'A';
    } else {
        return ch - '0';
    }
}
