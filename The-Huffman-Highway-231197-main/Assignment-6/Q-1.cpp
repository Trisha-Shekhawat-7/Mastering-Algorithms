#include <bits/stdc++.h>
using namespace std;

// Helper function to find all possible paths
void find_all_possible_paths(int u, int d, vector<int> adj[], vector<bool>& visited, vector<int>& path) {
    visited[u] = true;
    path.push_back(u);

    if (u == d) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] + 1; // converting back to 1-indexed
            if (i != path.size() - 1)
                cout << " -> ";
        }
        cout << endl;
    } else {
        for (int i : adj[u]) {
            if (!visited[i]) {
                find_all_possible_paths(i, d, adj, visited, path);
            }
        }
    }

    path.pop_back();
    visited[u] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // n is the number of nodes and m is the number of edges 
    int n, m; // nodes : 1, 2, 3, ..., n
    cin >> n >> m;

    vector<int> adj[n]; // Adjacency list 

    // Graph input 
    for (int i = 0; i < m; i++) {
        int x, y; 
        cin >> x >> y; 
        --x; --y; // 0 indexing 

        // x->y, there is an edge from x to y
        adj[x].push_back(y); 
    }

    int u, v; // source and destination 
    cin >> u >> v;
    --u; --v; 

    vector<bool> visited(n, false);
    vector<int> path;

    cout << "Following are all different paths from " << u + 1 << " to " << v + 1 << ":\n";
    find_all_possible_paths(u, v, adj, visited, path);

    return 0;
}
