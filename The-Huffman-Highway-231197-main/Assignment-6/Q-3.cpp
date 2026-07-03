#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int inf = 1e9;

struct Cell {
    int x, y, z;
};

Cell dir[] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1} };

bool isValid(int x, int y, int z, int maxX, int maxY, int maxZ, vector<vector<vector<int>>>& grid, vector<vector<vector<bool>>>& visited) {
    return (x >= 0 && x < maxX && y >= 0 && y < maxY && z >= 0 && z < maxZ && grid[x][y][z] == 0 && !visited[x][y][z]);
}

vector<Cell> bfs(Cell src, Cell dest, int x, int y, int z, vector<vector<vector<int>>>& grid) {
    vector<Cell> shortest_path; // Vector containing the shortest path

    vector<vector<vector<bool>>> visited(x, vector<vector<bool>>(y, vector<bool>(z, false)));
    vector<vector<vector<Cell>>> parent(x, vector<vector<Cell>>(y, vector<Cell>(z, {-1, -1, -1})));
    vector<vector<vector<int>>> min_distance(x, vector<vector<int>>(y, vector<int>(z, inf)));

    queue<Cell> q;
    q.push(src);
    visited[src.x][src.y][src.z] = true;
    min_distance[src.x][src.y][src.z] = 0;

    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        for (Cell d : dir) {
            int newx = curr.x + d.x, newy = curr.y + d.y, newz = curr.z + d.z;
            if (isValid(newx, newy, newz, x, y, z, grid, visited)) {
                q.push({newx, newy, newz});
                visited[newx][newy][newz] = true;
                if (min_distance[newx][newy][newz] > 1 + min_distance[curr.x][curr.y][curr.z]) {
                    min_distance[newx][newy][newz] = 1 + min_distance[curr.x][curr.y][curr.z];
                    parent[newx][newy][newz] = curr;
                }
            }
        }
    }

    // Generate the shortest path
    if (min_distance[dest.x][dest.y][dest.z] == inf) return {}; // If the destination is not reachable

    Cell curr = dest;
    while (curr.x != -1) {
        shortest_path.push_back(curr);
        curr = parent[curr.x][curr.y][curr.z];
    }
    reverse(shortest_path.begin(), shortest_path.end());
    return shortest_path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Grid Dimensions
    int x, y, z;
    cin >> x >> y >> z;

    // Source and target cells
    Cell source, destination;
    cin >> source.x >> source.y >> source.z;
    cin >> destination.x >> destination.y >> destination.z;

    // 3D Grid with obstacles
    vector<vector<vector<int>>> grid(x, vector<vector<int>>(y, vector<int>(z)));
    for (int xx = 0; xx < x; xx++)
        for (int yy = 0; yy < y; yy++)
            for (int zz = 0; zz < z; zz++)
                cin >> grid[xx][yy][zz];

    vector<Cell> shortest_path = bfs(source, destination, x, y, z, grid);

    if (!shortest_path.empty()) {
        cout << "Shortest path length is " << shortest_path.size() - 1 << "\n";
        cout << "The shortest path is: ";
        for (auto& cell : shortest_path)
            cout << "(" << cell.x << "," << cell.y << "," << cell.z << ") ";
    } else {
        cout << "Destination is not reachable\n";
    }

    return 0;
}
