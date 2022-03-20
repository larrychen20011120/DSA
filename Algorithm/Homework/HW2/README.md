# HW2 Problems
There are three problems in this homework with different difficulties.

# Inversion Number
[Reference solution](inversion_number.cpp)
## Description
Inversion number is the number of pairs of inverted numbers is a series. It's often used to indicate the extend of unsortedness. We define a pair of number is a pair of inverted numbers if **i < j** and **a <sub>i</sub> > a <sub>j</sub>**.
## I/O Format
### input
First line is the size of a. Second line contains the n numbers in a.
* ![](https://latex.codecogs.com/svg.image?2&space;\leq&space;n&space;\leq&space;10^{6})
* ![](https://latex.codecogs.com/svg.image?-10^{8}&space;\leq&space;M&space;\leq&space;10^{8})

### output
Output the inversion number of a. The number maybe be big. Please `mod` it with `524287` before output.
## Testing Data
### sample 1
* input

    ```
    4
    4 3 2 1
    ```
* output

    ```
    6
    ```
### sample 2
* input

    ```
    6
    4 5 10 4 7 1
    ```
* output

    ```
    8
    ```

# Arashi's Lottery
[Reference solution](arashi_lottery.py)
## Description
Arashi87 picked up a red envelope on the street during the Lunar New Year. He decides to use the money inside it to buy lottery.
Here we need six numbers for the lottery.
Arashi87 have a strange habit for picking numbers.
He will lists all combinations on a big white paper and hang it on a wall.
He then shoots it with darts randomly to pick which combination of numbers he will buy for the lottery.
However, there are just too many combinations to pick 6 numbers out of 49 numbers.
Therefore, Arashi87 `picks 7~12 numbers from 1~49` first.
Your job here is to `list all the combinations` from the numbers Arashi87 picked.
## I/O Format
### input
You will be given an integer k ( 6 < k < 13 ) first.
The integers following k is the number Arashi87 picked, and they are listed in ascending order.
* ![](https://latex.codecogs.com/svg.image?1&space;\leq&space;N&space;\leq&space;2\times10^{5})
* ![](https://latex.codecogs.com/svg.image?-10^{8}&space;\leq&space;a_{i}&space;\leq&space;10^{8})
### output
Print all the possible combinations. (One combination for each line)
Each combination should be in ascending order.
There should be a space between each number.
All combination must be printed in dictionary order a.k.a Lexicographic order.
This means sorting the combination according to the smallest number first.
If the smallest number are the same, use the second smallest number to sort, and so on.

## Testing Data
### sample 1
* input

    ```
    7 1 2 3 4 5 6 7
    ```
* output

    ```
    1 2 3 4 5 6
    1 2 3 4 5 7
    1 2 3 4 6 7
    1 2 3 5 6 7
    1 2 4 5 6 7
    1 3 4 5 6 7
    2 3 4 5 6 7
    ```
### sample 2
* input

    ```
    8 1 2 3 5 8 13 21 34
    ```
* output

    ```
    1 2 3 5 8 13
    1 2 3 5 8 21
    1 2 3 5 8 34
    1 2 3 5 13 21
    1 2 3 5 13 34
    1 2 3 5 21 34
    1 2 3 8 13 21
    1 2 3 8 13 34
    1 2 3 8 21 34
    1 2 3 13 21 34
    1 2 5 8 13 21
    1 2 5 8 13 34
    1 2 5 8 21 34
    1 2 5 13 21 34
    1 2 8 13 21 34
    1 3 5 8 13 21
    1 3 5 8 13 34
    1 3 5 8 21 34
    1 3 5 13 21 34
    1 3 8 13 21 34
    1 5 8 13 21 34
    2 3 5 8 13 21
    2 3 5 8 13 34
    2 3 5 8 21 34
    2 3 5 13 21 34
    2 3 8 13 21 34
    2 5 8 13 21 34
    3 5 8 13 21 34
    ```

# 2D Rank Finding
[Reference solution](2d_rank_finding.cpp)
## Description
In the XY-plane, we say a point ![](https://latex.codecogs.com/svg.image?(x_{i},&space;y_{i})) `dominates` another point ![](https://latex.codecogs.com/svg.image?(x_{j},&space;y_{j})) if and only if ![](https://latex.codecogs.com/svg.image?x_{i}&space;\geq&space;x_{j}) and ![](https://latex.codecogs.com/svg.image?y_{i}&space;\geq&space;y_{j}) .
The `rank` of a point is the number of points which are dominated by the point.
Given a set of points in the XY-plane, find the `rank` of each point.
No two points share the same coordinates.

## I/O Format

### input
Input starts with an integer n, where n denotes the number of points.
Each of the next n lines gives two integers which are the x and y coordinates of a point.
* ![](https://latex.codecogs.com/svg.image?5&space;\leq&space;n&space;\leq&space;3\times10^{5})

* ![](https://latex.codecogs.com/svg.image?-2^{31}&space;\leq&space;x,y&space;\leq&space;2^{31})
### output
Output the rank of each point in sequence.

## Testing Data
### sample 1
* input

    ```
    5
    1 2
    3 4
    5 6
    7 8
    9 10
    ```
* output

    ```
    0 1 2 3 4
    ```
### sample 2
* input

    ```
    7
    3 1
    4 1
    5 9
    2 6
    5 3
    5 8
    9 7
    ```
* output

    ```
    0 1 5 0 2 4 4
    ```
