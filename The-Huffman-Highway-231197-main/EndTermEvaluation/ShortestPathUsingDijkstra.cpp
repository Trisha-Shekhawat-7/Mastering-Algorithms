#include <bits/stdc++.h>
using namespace std;

struct Node {
    int node_num;
    string name;
};

class Graph {
public:
    vector<vector<pair<int, int>>> adj_list;
    vector<Node> nodes;
    map<string, int> node_map;

    Graph(int n) {
        adj_list = vector<vector<pair<int, int>>>(n);
        nodes = vector<Node>(n);
    }

    void add_node(int node_num, const string& name) {
        nodes[node_num] = {node_num, name};
        if (name[0] != 'P') {
            node_map[name] = node_num;
        }
    }

    void add_edge(int u, int v, int wt) {
        adj_list[u].push_back({v, wt});
        adj_list[v].push_back({u, wt});
    }

    void print_graph() {
        for (int i = 0; i < adj_list.size(); ++i) {
            cout << "Node " << i << " (" << nodes[i].name << "): ";
            for (auto& edge : adj_list[i]) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << endl;
        }
    }

    vector<int> dijkstra(int start, int end) {
        int n = adj_list.size();
        vector<int> dist(n, numeric_limits<int>::max());
        vector<int> parent(n, -1);
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [current_dist, u] = pq.top();
            pq.pop();

            if (current_dist > dist[u])
                continue;

            for (auto& [v, weight] : adj_list[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<int> path;
        for (int at = end; at != -1; at = parent[at])
            path.push_back(at);
        reverse(path.begin(), path.end());

        if (path[0] == start) {
            return path;
        } else {
            return {}; 
        }
    }
};

void create_graph(Graph& IITK) {
    vector<Node> initial_nodes = {
        {0, "Hall-11"},
        {1, "Events-Ground"},
        {2, "Pronite-Ground"},
        {3, "New-Shopping-Complex"},
        {4, "Health-Centre"},
        {5, "Hall-6"},
        {6, "Hall-10"},
        {7, "Hall-9"},
        {8, "Hall-13"},
        {9, "Hall-12"},
        {10, "Hall-8"},
        {11, "Hall-7"},
        {12, "Counselling-Service"},
        {13, "Kargil-Chowk"},
        {14, "Hall-2"},
        {15, "Girls-Hostel-1"},
        {16, "Open-Air-Theatre"},
        {17, "Hall-4"},
        {18, "Hall-3"},
        {19, "Hall-1"},
        {20, "Hall-5"},
        {21, "P1"},
        {22, "P2"},
        {23, "P3"},
        {24, "P4"},
        {25, "P5"},
        {26, "P6"},
        {27, "P7"},
        {28, "P8"},
        {29, "P9"},
        {30, "P10"}
    };

    for (const auto& node : initial_nodes) {
        IITK.add_node(node.node_num, node.name);
    }

    vector<tuple<int, int, int>> edges = {
        {0, 1, 160}, {1, 16, 80}, {16, 10, 80}, {10, 11, 50},
        {11, 6, 100}, {6, 7, 180}, {7, 8, 180}, {8, 9, 150},
        {9, 14, 280}, {14, 19, 170}, {19, 18, 75}, {18, 17, 100},
        {17, 3, 140}, {3, 2, 80}, {2, 1, 160}, {19, 20, 89},
        {20, 18, 88}, {14, 13, 250}, {13, 15, 250}, {15, 14, 250},
        {15, 12, 345}, {12, 4, 140}, {4, 5, 100}, {9, 21, 180},
        {8, 22, 100}, {22, 7, 180}, {22, 23, 170}, {23, 24, 245},
        {24, 6, 170}, {24, 25, 30}, {25, 11, 50}, {2, 26, 160},
        {26, 3, 80}, {15, 27, 250}, {27, 13, 250}, {27, 28, 250},
        {28, 19, 75}, {28, 18, 100}, {13, 29, 250}, {15, 29, 250},
        {4, 30, 200}, {5, 30, 100}
    };

    for (const auto& [u, v, wt] : edges) {
        IITK.add_edge(u, v, wt);
    }
}

void print_menu(const Graph& IITK) {
    cout << "Node numbers and names:\n";
    vector<pair<int, string>> sorted_nodes;

    for (const auto& [name, num] : IITK.node_map) {
        sorted_nodes.push_back({num, name});
    }

    sort(sorted_nodes.begin(), sorted_nodes.end());

    for (const auto& [num, name] : sorted_nodes) {
        cout << num << ": " << name << "\n";
    }
}

int main() {
    /*
    Note : New points named P-1,P-2 ... etc have been added and the modified image is uploaded along with this code. 
           These points were not named in the initial image but they're crucial for finding the shortest path in the map. 
    */
    int N = 31; // Number of nodes
    Graph IITK(N);

    create_graph(IITK);

    print_menu(IITK);

    int start_node, end_node;
    cout << "\nEnter the number of the source node: ";
    cin >> start_node;
    cout << "Enter the number of the destination node: ";
    cin >> end_node;

    vector<int> path = IITK.dijkstra(start_node, end_node);

    if (path.empty()) {
        cout << "\nNo path exists from node " << start_node << " to node " << end_node << ".\n";
    } else {
        cout << "\nShortest path from node " << start_node << " to node " << end_node << ":\n";
        for (int node : path) {
            cout << " (" << IITK.nodes[node].name << ") ";
            if (node != end_node) cout << "-> ";
        }
        cout << endl;
    }

    return 0;
}
