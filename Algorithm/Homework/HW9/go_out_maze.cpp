#include <iostream>
#include <queue>

using namespace std;

struct Position {
    short x, y;
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    short M, N;
    Position start, end;
    cin >> M >> N >> start.x >> start.y >> end.x >> end.y;

    short route[M+2][N+2];
    queue <Position> next_visit;

    for (short i = 0; i <= M+1; i++) {
        for (short j = 0; j <= N+1; j++) {
            if (i == 0 || j == 0 || i == M+1 || j == N+1) {
                route[i][j] = 0;
            } else {
                cin >> route[i][j];
            }
        }
    }
    next_visit.push(start);

    while (!next_visit.empty()) {
        Position curr = next_visit.front();
        if (route[curr.x][curr.y]) {
            route[curr.x][curr.y] = 0;
            next_visit.push(Position {.x = curr.x - 1, .y = curr.y});
            next_visit.push(Position {.x = curr.x + 1, .y = curr.y});
            next_visit.push(Position {.x = curr.x, .y = curr.y - 1});
            next_visit.push(Position {.x = curr.x, .y = curr.y + 1});
        }
        next_visit.pop();
    }

    if (route[end.x][end.y] == 0) cout << "Success!\n";
    else cout << "Fail!\n";

    return 0;
}
