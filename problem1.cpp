/*Question: You will be given an undirected graph. Print its BFS traversal in reverse order. Consider root as 1.
Note: In the explanation video there was a mistake, the explanation was for DFS traversal, but you have to do it using BFS traversal.

Sample Input
Sample Output
4 
4
1 2
3 4
1 3
2 4
4 3 2 1
(4 2 3 1 is also valid ans)




*/

#include <bits/stdc++.h>
using namespace std;

const int BN = 1e3 + 1;
vector<int> adjList[BN];
bool visited[BN];
vector<int> bfsNOdes;

void bfs(int root) {
    queue<int> q;
    q.push(root);
    visited[root] = true;
    bfsNOdes.push_back(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adjList[u]) {
            if (!visited[v]) {
                // cout << "root " << root << " u " << u << " v " << v << endl;
                bfsNOdes.push_back(v);
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
    }
    bfs(1);

    for(int v:bfsNOdes)
    {
        cout<<bfsNOdes.back()<<" ";
        bfsNOdes.pop_back();
    }
    return 0;
}
