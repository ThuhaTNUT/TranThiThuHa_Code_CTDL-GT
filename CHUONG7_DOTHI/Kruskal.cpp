#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// So sanh hai canh theo trong so
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Tim cha cua mot dinh (voi path compression)
int findParent(int u, vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = findParent(parent[u], parent);
    return parent[u];
}

// Hop nhat hai tap hop cua hai dinh u va v
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskal(int n, vector<Edge>& edges) {
    // Sap xep cac canh theo trong so tang dan
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    // Khoi tao parent cua moi dinh la chinh no
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    vector<Edge> mst;
    int mstWeight = 0;

    // Duyet cac canh theo trong so tang dan
    for (size_t i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // Kiem tra xem co tao chu trinh hay khong
        if (findParent(u, parent) != findParent(v, parent)) {
            mst.push_back(edges[i]);
            mstWeight += weight;
            unionSets(u, v, parent, rank);
        }
    }

    // In ra ket qua
    cout << "Canh trong cay khung toi thieu: \n";
    for (size_t i = 0; i < mst.size(); i++) {
        cout << mst[i].u << " - " << mst[i].v << " : " << mst[i].weight << endl;
    }
    cout << "Tong trong so cay khung toi thieu: " << mstWeight << endl;
}

int main() {
    int n = 10, m = 5;  // so dinh va so canh

    vector<Edge> edges;
    edges.push_back(Edge(3, 5, 3));
    edges.push_back(Edge(3, 10, 2));
    edges.push_back(Edge(3, 9, 1));
    edges.push_back(Edge(5, 9, 18));
    edges.push_back(Edge(9, 10, 9));

    kruskal(n, edges);

    return 0;
}

