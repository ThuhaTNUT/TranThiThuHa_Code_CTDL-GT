#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// lop bieu dien do thi duoi dang danh sach ke
class Graph {
private:
    int V; // So luong dinh
    vector<vector<int> > adjList; //Danh sach ke

public:
    // Khoi tao do thi voi so luong dinh V
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Ham them canh vao do thi
    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Them v vao danh sach ke cua u
        adjList[v].push_back(u); // Do thi vo huong nen them u vao danh sach ke cua v
    }

    // Ham duyet theo chieu sau DFS
    void DFS(int start) {
        vector<bool> visited(V, false); // Khoi tao mang danh dau cac dinh chua duoc tham
        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // Ham tien ich cho DFS (DFS su dung de quy)
    void DFSUtil(int u, vector<bool>& visited) {
        visited[u] = true; // Danh dau dinh u la da tham
        cout << u << " "; // In dinh u

        for (size_t i = 0; i < adjList[u].size(); ++i) { // Su dung vong lap thong thuong
            int v = adjList[u][i];
            if (!visited[v]) { // Neu v chua duoc tham
                DFSUtil(v, visited); // Goi de quy DFS tren dinh v
            }
        }
    }

    // Ham duyet theo chieu rong BFS
    void BFS(int start) {
        vector<bool> visited(V, false); // Khoi tao mang danh dau cac dinh chua duoc tham
        queue<int> q; // Khoi tao hang doi duyet BFS

        visited[start] = true; // Ðanh dau dinh bat dau la da tham
        q.push(start); // Dua dinh bat dau vao hang doi 

        cout << "BFS: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " "; // In dinh u

            for (size_t i = 0; i < adjList[u].size(); ++i) { // Su dung vong lap thong thuong
                int v = adjList[u][i];
                if (!visited[v]) { // Neu v chua duoc tham
                    visited[v] = true; // Ðanh dau v la da tham
                    q.push(v); // Ðua v vao hang doi
                }
            }
        }
        cout << endl;
    }
};

// Ham main
int main() {
    int V, E, u, v, start;
    cout << "Nhap so luong dinh va canh cua do thi: ";
    cin >> V >> E;

    Graph g(V); // Tao do thi voi dinh v

    cout << "Nhap cac canh cua do thi (u v):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g.addEdge(u, v); // Them canh vao do thi
    }

    cout << "Nhap dinh bat dau duyet: ";
    cin >> start;

    // Thuc hien duyet theo chieu sau DFS và dyet theo chieu rong BFS
    g.DFS(start);
    g.BFS(start);

    return 0;
}

