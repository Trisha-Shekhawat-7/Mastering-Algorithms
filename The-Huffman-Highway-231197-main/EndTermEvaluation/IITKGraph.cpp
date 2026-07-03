#include<bits/stdc++.h>
using namespace std;

struct Node {
    int node_num;
    int x, y;
    string name;
};

class Graph {
    vector<vector<pair<int, long double>>> adj_list;
    vector<Node> nodes;

public:
    Graph(int n) {
        adj_list = vector<vector<pair<int, long double>>>(n);
        nodes = vector<Node>(n);
    }

    void add_node(int node_num, int x, int y, const string& name) {
        nodes[node_num] = {node_num, x, y, name};
    }

    void add_edge(int u, int v, long double wt) {
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
};

int main() {
    vector<Node> initial_nodes = {
        {0, 0, 0, "Hall 11"},
        {1, 160, 0, "Events Ground"},
        {2, 320, 0, "Pronite Ground"},
        {3, 400, 0, "New Shopping Complex"},
        {4, 700, 0, "Health Centre"},
        {5, 800, 0, "Hall 6"},
        {6, 0, 200, "Hall 10"},
        {7, 0, 380, "Hall 9"},
        {8, 0, 660, "Hall 13"},
        {9, 120, 750, "Hall 12"},
        {10, 160, 80, "Hall 8"},
        {11, 160, 160, "Hall 7"},
        {12, 820, 180, "Counselling Service"},
        {13, 820, 570, "Kargil Chowk"},
        {14, 400, 570, "Hall 2"},
        {15, 570, 320, "Girls Hostel 1"},
        {16, 240, 80, "Open Air Theatre"},
        {17, 400, 220, "Hall 4"},
        {18, 400, 320, "Hall 3"},
        {19, 400, 495, "Hall 1"},
        {20, 320, 457, "Hall 5"}
    };

    int N = initial_nodes.size();
    Graph IITK(N);

    for (const auto& node : initial_nodes) {
        IITK.add_node(node.node_num, node.x, node.y, node.name);
    }

    IITK.add_edge(0, 1, 160);
    IITK.add_edge(1, 16, 80);
    IITK.add_edge(16, 10, 80);
    IITK.add_edge(10, 11, 50);
    IITK.add_edge(11, 6, 100);
    IITK.add_edge(6, 7, 180);
    IITK.add_edge(7, 8, 180);
    IITK.add_edge(8, 9, 150);
    IITK.add_edge(9, 14, 280);
    IITK.add_edge(14, 19, 170);
    IITK.add_edge(19, 18, 75);
    IITK.add_edge(18, 17, 100);
    IITK.add_edge(17, 3, 140);
    IITK.add_edge(3, 2, 80);
    IITK.add_edge(2, 1, 160);
    IITK.add_edge(19, 20, 89);
    IITK.add_edge(20, 18, 88);
    IITK.add_edge(14, 13, 250);
    IITK.add_edge(13, 15, 250);
    IITK.add_edge(15, 14, 250);
    IITK.add_edge(15, 12, 345);
    IITK.add_edge(12, 4, 140);
    IITK.add_edge(4, 5, 100);

    IITK.print_graph();

    return 0;
}
