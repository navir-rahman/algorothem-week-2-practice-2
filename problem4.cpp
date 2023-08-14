/*
Question: You will be given an undirected graph as input. Now count its connected components and print it.

Sample Input
Sample Output
6
4
1 2
2 3
3 4
5 6
2
7
4
1 2
2 3
3 4
5 6
3

*/

#include <bits/stdc++.h>
using namespace std;

const int BN=1e3+5;
vector<int> adjlist[BN];
bool visited[BN];


void bfs(int root){
    queue<int> q;
    q.push(root);
    visited[root]=true;
 
    while (!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v:adjlist[u])
        {
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
            
        }
    }
    
}

int main(){

int n,e;
cin>>n>>e;
for (size_t i = 0; i < e; i++)
{
    int a,b;
    cin>>a>>b;
    adjlist[a].push_back(b);
}

int cc=0;
for (size_t i = 1; i <= n; i++)
{
    if(visited[i] == true) continue;
    bfs(i);
    cc++;
}

cout<<cc;

    return 0;
}