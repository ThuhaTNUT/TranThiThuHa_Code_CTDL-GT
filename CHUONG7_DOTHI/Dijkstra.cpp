#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int node;
    int weight;
    Edge(int node, int weight) : node(node), weight(weight) {}
};

void dijkstra(const vector<vector<Edge> >& graph, int start) {
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    vector<bool> visited(n, false);
    // Su dung priority_queue de luu tru cap (khoang cach, dinh)
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    distances[start] = 0;
    pq.push(make_pair(0, start)); // Su dung make_pair thay cho khoi tao danh sach

    while (!pq.empty()) {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;

        for (size_t i = 0; i < graph[node].size(); ++i) { // Su dung vong lap thong thuong
            const Edge& neighbor = graph[node][i];
            int newDist = dist + neighbor.weight;
            if (newDist < distances[neighbor.node]) {
                distances[neighbor.node] = newDist;
                pq.push(make_pair(newDist, neighbor.node)); // Su dung make_pair
            }
        }
    }

    // Hien thi ket qua
    cout << "Do dai duong di ngan nhat tu dinh " << start << ":\n";
    for (int i = 0; i < n; i++) {
        if (distances[i] == INT_MAX) {
            cout << "Dinh " << i << ": Khong the di toi\n";
        } else {
            cout << "Dinh " << i << ": " << distances[i] << endl;
        }
    }
}

int main() {
    int n;
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;
    
    vector<vector<Edge> > graph(n);

    cout << "Nhap do thi duoi dang ma tran trong so:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                graph[i].push_back(Edge(j, weight));
            }
        }
    }

    int startVertex;
    cout << "Nhap dinh bat dau: ";
    cin >> startVertex;

    dijkstra(graph, startVertex);

    return 0;
}

