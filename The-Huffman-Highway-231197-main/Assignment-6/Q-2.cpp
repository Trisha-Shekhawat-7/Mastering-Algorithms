#include <bits/stdc++.h>
using namespace std;

bool HamiltonianPath(vector<vector<int>>& adjacencyMatrix, int numNodes) {
    int dp[numNodes][(1 << numNodes)];
    memset(dp, 0, sizeof dp);

    for (int node = 0; node < numNodes; node++)
        dp[node][(1 << node)] = true;

    for (int subset = 0; subset < (1 << numNodes); subset++) {
        for (int node = 0; node < numNodes; node++) {
            if (subset & (1 << node)) {
                for (int neighbor = 0; neighbor < numNodes; neighbor++) {
                    if (subset & (1 << neighbor) && adjacencyMatrix[neighbor][node] && node != neighbor && dp[neighbor][subset ^ (1 << node)]) {
                        dp[node][subset] = true;
                        break;
                    }
                }
            }
        }
    }

    for (int node = 0; node < numNodes; node++) {
        if (dp[node][(1 << numNodes) - 1])
            return true;
    }
    return false;
}

bool isSafe(int vertex, vector<vector<int>>& graph, vector<int>& path, int position) {
    if (graph[path[position - 1]][vertex] == 0)
        return false;

    for (int i = 0; i < position; i++)
        if (path[i] == vertex)
            return false;

    return true;
}

bool checkHamiltonianCycle(vector<vector<int>>& graph, vector<int>& path, int position) {
    int numNodes = graph.size();
    if (position == numNodes) {
        if (graph[path[position - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int vertex = 1; vertex < numNodes; vertex++) {
        if (isSafe(vertex, graph, path, position)) {
            path[position] = vertex;

            if (checkHamiltonianCycle(graph, path, position + 1))
                return true;

            path[position] = -1;
        }
    }

    return false;
}

bool HamiltonianCycle(vector<vector<int>>& graph) {
    int numNodes = graph.size();
    vector<int> path(numNodes, -1);
    path[0] = 0;

    if (checkHamiltonianCycle(graph, path, 1) == false)
        return false;

    return true;
}

int main() {
    int numNodes;
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;
    cout << endl;

    vector<vector<int>> adjacencyMatrix(numNodes, vector<int>(numNodes));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numNodes; i++)
        for (int j = 0; j < numNodes; j++)
            cin >> adjacencyMatrix[i][j];

    bool hasHamiltonianPath = HamiltonianPath(adjacencyMatrix, numNodes);
    bool hasHamiltonianCycle = HamiltonianCycle(adjacencyMatrix);

    cout << "Hamiltonian Path: " << (hasHamiltonianPath ? "YES" : "NO") << endl;
    cout << "Hamiltonian Cycle: " << (hasHamiltonianCycle ? "YES" : "NO") << endl;

    return 0;
}
