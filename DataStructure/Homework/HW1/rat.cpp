#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

int main() {
    // special type define (struct)
    struct Item{
        int x, y;  // position of x, y
        int direction; // 0 : right ; 1 : down ; 2 : up; 3 : left
    };
    struct Mark{
        int x, y;
    };

    ifstream  ifs;
    string line;  // first used for filename and then for line of input file
    stack <Item> route; // collection of the positions we have visited
    stack <Mark> mark; // mark which position we have visited used for restoring the maze
    int maze[17][17];
    int start[2], exit[2];
    // step is used to mark how many times we walks
    int step;
    // boolean value to check whether we are changing position or direction
    bool changeDir;

    // let user input the filename
    // (file & cpp must under the same folder)
    cout << "enter filename :";
    getline(cin, line);
    ifs.open(line, ifstream::in);

    if (!ifs.is_open()){
        // print out error message of loading file
        cout << "error to open the file or no such file";
        ifs.close();
        return 0;
    }

    // row is used to count the row of maze
    int row = 0;

    // initialize maze array by input file and print out the file content
    while (getline(ifs, line)){
        // print the maze file out
        cout << line << endl;
        // load file content to the maze array
        for (int col = 0; col < line.length(); col++){
            maze[row][col] = line[col] - '0';
        }
        row++;
    }

    // infinite looping until user enters (-1, -1)
    while (true) {
        // input start and exit or break the loop
        cout << "enter start position :";
        cin >> start[0] >> start[1];
        if (start[0] == -1 && start[1] == -1) {
            // break the loop
            cout << "end the code";
            ifs.close();
            return 0;
        }
        cout << "enter exit position :";
        cin >> exit[0] >> exit[1];

        // initialize the tempItem as the start and right(0)
        Item tempItem = {start[1], start[0], 0};

        // initialize the step to 0 and changeDir to false
        step = 0;
        changeDir = false;

        /* two ways to break the searching loop
         * 1. tempItem.direction < 0 : when we go back to start and four direction has been visited,
         *                             we will set tempItem.direction as -1 (now route is empty).
         * 2. tempItem is at exit : However, the exit's x & y won't be shown on console
         * */
        while ( !( (tempItem.direction < 0) || (tempItem.x == exit[1] && tempItem.y == exit[0])) ){

            // if changing direction, then we do nothing but search for next step
            // if changing position, we set the position now into visited (1)
            // then push it into mark and show position now on console
            if (!changeDir){
                maze[tempItem.y][tempItem.x] = 1;
                mark.push({tempItem.x, tempItem.y});
                cout << step++ << ":" << tempItem.y << "," << tempItem.x << endl; // step + 1 : next movement
            }

            // based on different direction value, we look for next movement in different way
            switch (tempItem.direction) {
                case 0:   // right
                    if (maze[tempItem.y][tempItem.x + 1] == 0){
                        // change position for next movement and push position now into route
                        changeDir = false;
                        route.push(tempItem);
                        tempItem.x++;
                        tempItem.direction = 0; // set next position for searching right first
                    }else{
                        // this direction is blocked, change direction
                        changeDir = true;
                        tempItem.direction++;
                    }
                    break;
                case 1:  // down
                    if (maze[tempItem.y + 1][tempItem.x] == 0){
                        // change position for next movement and push position now into route
                        changeDir = false;
                        route.push(tempItem);
                        tempItem.y++;
                        tempItem.direction = 0; // set next position for searching right first
                    }else{
                        // this direction is blocked, change direction
                        changeDir = true;
                        tempItem.direction++;
                    }
                    break;
                case 2:  // up
                    if (maze[tempItem.y - 1][tempItem.x] == 0){
                        // change position and push position now into route
                        changeDir = false;
                        route.push(tempItem);
                        tempItem.y--;
                        tempItem.direction = 0; // set next position for searching right first

                    }else{
                        // this direction is blocked, change direction
                        changeDir = true;
                        tempItem.direction++;
                    }
                    break;
                default:  // left
                    if (maze[tempItem.y][tempItem.x - 1] == 0){
                        // change position for next movement and push position now into route
                        changeDir = false;
                        route.push(tempItem);
                        tempItem.direction = 0;
                        tempItem.x--;

                    } else {
                        // final direction is blocked, go back to the top of route
                        changeDir = false;
                        if (route.empty()) {
                            // break the loop
                            tempItem.direction = -1;
                        } else {
                            tempItem = route.top();
                            route.pop();
                        }
                    }
            }
        }

        // change all elements in maze into origin input value
        while (!mark.empty()){
            maze[mark.top().y][mark.top().x] = 0;
            mark.pop();
        }

        if (route.empty()){
            // Failed to escape
            cout << "Failed to escape." << endl;
        }else{
            // successfully escaped!!
            // remember to print out the tempItem now and clear all route for using it again
            // (break the loop at exit but not show it on the console)
            cout << step << ":" << tempItem.y << "," << tempItem.x << endl;
            cout << "successfully escaped!!" << endl;
            while (!route.empty()){
                route.pop();
            }
        }

    }

}
