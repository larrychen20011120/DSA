# HW1 Problems
There are three problems in this homework with different difficulties.
## Arashi's Craft
### Description
Arashi87 is addicted to a game called "arashi's craft" recently. All the items in this game are made of blocks. The first thing to do while being a newbie in the game is definitely building a beautiful house, but arashi87 doesn't have too much blocks to use. To cost down, arashi87 hopes that you can write a program to help him see the result of the house after several operations.

We made the problem simple. Now we have number  to  blocks put on  slots in order, with the following operations:

* `move a onto b`: put the blocks stacked on **No. a** block and **No. b** block back to the top of their original slots, then put **No. a** block onto **No. b**block.
* `move a over b`: put the blocks stacked on **No. a** block back to the top of their original slots, then put **No. a** block on top of the pile that contains **No. b** block.
* `pile a onto b`: put the blocks stacked on **No. b** block back to the top of their original slots, then put the whole pile of blocks above **No. a** block (including a) onto **No. b** block.
* `pile a over b`: put the whole pile of blocks above **No. a** block (including a) on top of the pile that contains **No. b** block.

Please note that when the block  and the block  are in the same pile, the operation get skipped. The final result should be printed after all the operations are done.
### Testing Data

## Stack Simulator
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
### Testing Data
## Test Prediction 
### Description
### Testing Data
