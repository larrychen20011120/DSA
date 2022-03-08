#include <iostream>
using namespace std;

struct MemBlock{
    int content;
    int toChapter;
    MemBlock* next;
    MemBlock* before;
};

class Memory {
private:
    int capacity;
    MemBlock* forget = NULL;
    MemBlock** chapter2Mem;

public:
    Memory(int capacity){
        this->capacity = capacity;
        chapter2Mem = new MemBlock* [500000];
        for (int i = 0; i < 500000; i++)
            chapter2Mem[i] = NULL;
    }
    int get(int);
    void set(int, int);
};

int main() {

    // accelerate io time
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    char c;
    Memory memory(N);

    for (int i = 0; i < M; i++){
        c = cin.get();
        int a, b;
        if (c == '\n')
            c = cin.get();
        if (c == 'g'){
            cin.get(); cin.get(); cin.get();
            cin >> a;
            cout << memory.get(a) << endl;
        }else{
            cin.get(); cin.get(); cin.get();
            cin >> a >> b;
            memory.set(a, b);
        }
    }

    return 0;
}

int Memory::get(int chapter){
    if (!chapter2Mem[chapter]){
        return -1;
    }
    MemBlock* block = chapter2Mem[chapter];

    if (forget == block){
        forget = forget->next;
    } else if (block->next == forget){
        ;
    } else {
        block->before->next = block->next;
        block->next->before = block->before;
        forget->before->next = block;
        block->before = forget->before;
        block->next = forget;
        forget->before = block;
    }

    return block->content;
}

void Memory::set(int chapter, int content){
    if (!chapter2Mem[chapter]){
        // not in Memory
        if (!forget){
            MemBlock* block = new MemBlock();
            block->content = content; block->toChapter = chapter;
            block->next = block; block->before = block;

            forget = block;
            chapter2Mem[chapter] = block;
            capacity--;
        } else {
            if (capacity == 0){
                forget->content = content;
                chapter2Mem[forget->toChapter] = NULL;
                chapter2Mem[chapter] = forget;
                forget->toChapter = chapter;
                forget = forget->next;

            } else {
                // add
                MemBlock* block = new MemBlock();
                block->content = content; block->toChapter = chapter;
                block->next = forget; block->before = forget->before;

                forget->before->next = block;
                forget->before = block;
                capacity--;
                chapter2Mem[chapter] = block;
            }
        }
    } else {
        // already in memory
        MemBlock* block = chapter2Mem[chapter];
        block->content = content;
        if (forget == block){
            forget = forget->next;
        } else if (block->next == forget){
            ;
        } else {
            block->before->next = block->next;
            block->next->before = block->before;
            forget->before->next = block;
            block->before = forget->before;
            block->next = forget;
            forget->before = block;
        }
    }
}
