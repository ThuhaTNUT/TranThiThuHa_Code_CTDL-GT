#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V; // So dinh cua do thi
    vector<vector<int> > adjList; // Danh sach ke

public:
    // Ham khoi tao do thi
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    // Ham them canh vao do thi
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Do thi vo huong
    }

    // Ham duyet BFS
    void BFS(int start) {
        vector<bool> visited(V, false); // Khoi tao mang danh dau cac dinh chua duoc tham
        queue<int> q; // Khoi tao hang doi duyet BFS

        visited[start] = true; // Danh dau dinh bat dau la da tham
        q.push(start); // Dua dinh bat dau vao hang doi 

        cout << "BFS bat dau tu dinh " << start << ": ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " "; // In dinh u

            // Duyet cac dinh ke voi u
            for (size_t i = 0; i < adjList[u].size(); ++i) {
                int v = adjList[u][i];
                if (!visited[v]) { // Neu v chua duoc tham
                    visited[v] = true; // Danh dau v la da tham
                    q.push(v); // Dua v vao hang doi
                }
            }
        }
        cout << endl;
    }

    // Ham hien thi danh sach ke
    void printAdjList() {
        cout << "Danh sach ke cua do thi:" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            // Duyet danh sach ke theo kieu thong thuong
            for (size_t j = 0; j < adjList[i].size(); ++j) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Nhap so dinh cua do thi: ";
    cin >> V;
    cout << "Nhap so canh cua do thi: ";
    cin >> E;

    Graph g(V);

    cout << "Nhap danh sach canh (dinh u va dinh v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printAdjList();

    int start;
    cout << "Nhap dinh bat dau de duyet BFS: ";
    cin >> start;

    g.BFS(start);

    return 0;
}

