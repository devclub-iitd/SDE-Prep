#include <bits/stdc++.h>
using namespace std;

int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, 1, -1};
char directions[] = {'U', 'D', 'R', 'L'};
int nextMove[1005][1005];

// Because the monsters move optimally, if a monster can reach a location in the
// maze before A, then A may never move to that spot. Thus, for A to enter a spot,
// the distance from that location to A must be less than the distance from that
// location to the nearest monster. Knowing this, we may BFS to find all locations
// that are visitable by A. This will run in $N^2$ time because each location will
// be visited a constant amount of times.

// While conducting the bfs, store the previous location of every location ("from"
// array in code below). This way, once A reaches the edge, we can retrace A's
// path, following the path of previous locations and storing the direction
// traveled.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &row : grid)
        cin >> row;
    
    queue<pair<int, int>> q;
    int startX, startY;
    
    // Finding positions of monsters and starting point
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M')
                q.push({i, j});
            else if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            }
        }
    }
    
    q.push({startX, startY});
    nextMove[startX][startY] = -1;
    
    // BFS to calculate distances
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (grid[x][y] == 'A' && (x == 0 || x == n-1 || y == 0 || y == m-1)) {
            cout << "YES" << endl;
            string path;
            int move = nextMove[x][y];
            while (move != -1) {
                path += directions[move];
                x -= fx[move];
                y -= fy[move];
                move = nextMove[x][y];
            }
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            cout << path;
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            int newX = x + fx[i], newY = y + fy[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= m || grid[newX][newY] != '.')
                continue;
            grid[newX][newY] = grid[x][y];
            if (grid[newX][newY] == 'A')
                nextMove[newX][newY] = i;
            q.push({newX, newY});
        }
    }
    
    cout << "NO";
    return 0;
}
