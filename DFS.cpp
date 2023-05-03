#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list; // danh sách các đỉnh kề của đồ thị
bool visited[100]; // lưu trạng thái đã duyệt trong DFS

void dfs(int node) {
    cout << node << " "; // In ra đỉnh đang được duyệt theo thứ tự DFS
    visited[node] = true; // Đánh dấu đã ghé thăm đỉnh này

    for (int i = 0; i < adj_list[node].size(); i++) { // Duyệt qua các đỉnh kề của node
        int neighbor = adj_list[node][i];

        if (!visited[neighbor]) { // Nếu đỉnh chưa được thăm thì ta tiến hành thăm nó
            dfs(neighbor); // Gọi đệ quy đến từng đỉnh kề
        }
    }
}

int main() {
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    adj_list.resize(num_nodes + 1); // Tạo danh sách các đỉnh kề với kích thước của số lượng các node trong đồ thị

    for (int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v); // Thêm đỉnh kề vào danh sách
        adj_list[v].push_back(u); // Cập nhật lại danh sách ở cả 2 đỉnh (vì là đồ thị vô hướng)
    }

    dfs(1); // Bắt đầu duyệt DFS từ node 1

    return 0;
}
