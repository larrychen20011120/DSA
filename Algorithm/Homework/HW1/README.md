# HW1 Problems
There are three problems in this homework with different difficulties.

## Arashi's Craft
[Reference solution](arashi_craft.py)
### Description
Arashi87 is addicted to a game called "arashi's craft" recently. All the items in this game are made of blocks. The first thing to do while being a newbie in the game is definitely building a beautiful house, but arashi87 doesn't have too much blocks to use. To cost down, arashi87 hopes that you can write a program to help him see the result of the house after several operations.

We made the problem simple. Now we have number  to  blocks put on  slots in order, with the following operations:

* `move a onto b`: put the blocks stacked on **No. a** block and **No. b** block back to the top of their original slots, then put **No. a** block onto **No. b**block.
* `move a over b`: put the blocks stacked on **No. a** block back to the top of their original slots, then put **No. a** block on top of the pile that contains **No. b** block.
* `pile a onto b`: put the blocks stacked on **No. b** block back to the top of their original slots, then put the whole pile of blocks above **No. a** block (including a) onto **No. b** block.
* `pile a over b`: put the whole pile of blocks above **No. a** block (including a) on top of the pile that contains **No. b** block.

Please note that when the block  and the block  are in the same pile, the operation get skipped. The final result should be printed after all the operations are done.
### I/O Format
#### input
First line contains 2 integers N and M, for N blocks and M operations.
For the next M line commands, every line is a valid operation according to the description.
* ![](https://latex.codecogs.com/svg.image?1&space;\leq&space;N&space;\leq&space;10^{3})
* ![](https://latex.codecogs.com/svg.image?1&space;\leq&space;M&space;\leq&space;2\times10^{5})
* ![](https://latex.codecogs.com/svg.image?1&space;\leq&space;a,b&space;\leq&space;N)
#### output
Output how blocks are distributed on  slots in order. The beginning of every line comes with the number of the slot, and a semi colon right after. If there's at least a block on that slot, please output the number of the block in order. All the number should be separated with a space, with a new line character at the end. If there's no blocks in the slot output new line right away.

### Testing Data
#### sample
* input
    ```
    10 8
    pile 1 onto 1
    pile 8 over 6
    move 3 onto 5
    move 8 over 8
    move 4 onto 9
    pile 10 over 10
    move 9 onto 2
    pile 3 onto 7
    ```
* output
    ```
    1: 1
    2: 2 9
    3:
    4: 4
    5: 5
    6: 6 8
    7: 7 3
    8:
    9:
    10: 10
    ```

## Stack Simulator
[Reference solution](stack_simulator.py)
### Description
After the intense practice of data structure at the first semester of sophomore, you must be very familiar with compiling data structure with your brain. This problem asks you to become a cold-blood stack machine. You are an empty stack and asked to do the following operations:

* `PUSH`: put the empty set `{}` into stack
* `DUP`: duplicate the top element of the stack and put it in stack
* `UNION`: pop out two elements, put the union of them back to stack
* `INTERSECT`: pop out two elements, put the intersection of them back to stack
* `ADD`: pop out two elements, add the first as the element of the later, and put the result back to the stack.

For example, if the first element taken out from the stack is `X={{}, {{}}}`, the second one is `Y={{}, {{{}}}}`. The result of several operations is:
* `UNION` operation gets `{{}, {{}}, {{{}}}}`. The number of elements in the set is **3**.
* `INTERSECT` operation gets `{{}}`. The number of elements in the set is **1**.
* `ADD` operation gets `{{}, {{{}}}, {{}, {{}}} }`，The number of elements in the set is **3**.
### I/O Format
#### input
The first line has an integer N, with following lines of N inputs. Each line contains a string as a valid operation
* ![](https://latex.codecogs.com/svg.image?1&space;\leq&space;N&space;\leq&space;2\times10^{5})
#### output
For each operation, output the number of elements in the `top set of stack` and make a new line.

### Testing Data
#### sample 1
* input
    ```
    10
    PUSH
    PUSH
    PUSH
    ADD
    DUP
    DUP
    DUP
    ADD
    INTERSECT
    ADD
    ```
* output
    ```
    0
    0
    0
    1
    1
    1
    1
    2
    1
    2
    ```
#### sample 2
* input
    ```
    9
    PUSH
    DUP
    ADD
    PUSH
    ADD
    DUP
    ADD
    DUP
    UNION
    ```
* output
    ```
    0
    0
    1
    0
    1
    1
    2
    2
    2
    ```
#### sample 3
* input
    ```
    7
    PUSH
    DUP
    ADD
    PUSH
    ADD
    PUSH
    INTERSECT
    ```
* output
    ```
    0
    0
    1
    0
    1
    0
    0
    ```
## Test Prediction
[Reference solution](test.prediction.cpp)
### Description
A new semester has started! It is well known that professors in the Arashi87's course like to have pop quiz. However, Arashi87 is a quite lazy student. He invented a "Test Prediction Algorithm" according to an unscientific theory. This allows him to prepare less stuff and get more to time to slack off. The algorithm he invented is described down below:

According to the theory, we can know that professors like to have quiz for the chapter they have mentioned lately. And, Arashi87 can memorize at most N. If professor teach more chapter than N, Arashi87 will forget the earliest chapter that the professor taught and memorize the new chapter. Here we need you to provide two operations like down below:

* `set a b`: means that professor teaches chapter  and the content of it is . If there are duplicated chapter, `update its content and the time of mentioning it`.
* `get a`: means that the pop quiz have chapter . You need to look for it in the content you memorize. If it exists, you need to `update time of mentioning it` because you have recall it in your mind.
### I/O Format

#### input
First line contains two integers `N and M`. This means that Arashi87 can memorize `N chapters` at most. And, there are totally `M operations`.
For the `next M line commands`, every line is a valid operation according to the description. All commands will be given in time order.
* ![](https://latex.codecogs.com/svg.image?1&space;\leq&space;N&space;\leq&space;10^{5})
* ![](https://latex.codecogs.com/svg.image?1&space;\leq&space;M&space;\leq&space;10^{6})
* ![](https://latex.codecogs.com/svg.image?1&space;\leq&space;a,b&space;\leq&space;5\times10^{5})
#### output
For each `get` operation, if there exist chapter a, output its content b. Otherwise, output -1. At last, make a new line.

### Testing Data
#### sample
* input
    ```
    10 10
    get 4
    set 4 4
    set 2 1
    get 4
    get 5
    set 2 3
    set 2 2
    get 3
    set 4 3
    get 2
    ```
* output
    ```
    -1
    4
    -1
    -1
    2
    ```
