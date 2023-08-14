/*Question: You will be given an undirected graph as input. Now count its connected components and print it. Then print All the nodes in a connected component. See the sample output for more clarification.

Sample Input
Sample Output
6
4
1 2
2 3
3 4
5 6
2
Component 1 : 1 2 3 4
Component 2 : 5 6
8
4
1 2
2 3
3 4
5 6
4
Component 1 : 1 2 3 4
Component 2 : 5 6
Component 3 : 7
Component 4 : 8

*/
#include <bits/stdc++.h>
using namespace std;

const int BN=1e3+5;
vector<int> adjlist[BN];
bool visited[BN];

vector<int> components[BN];

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
            // cout<<v<<" ";
            components[root].push_back(v);
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
    // cout<<"Component "<<i<<" : ";
    bfs(i);
    // cout<<endl;
    cc++;
}

cout<<cc<<endl;
int cmpcnt=1;
for (size_t i = 1; i <= n; i++)
{
    if(components[i].size() <1)continue;
    cout<<"Component "<<cmpcnt<<" : "<<i<<" ";
    cmpcnt++;
    for (int j:components[i])
    {
        cout<<j<<" ";
    }
    cout<<endl;
}

    return 0;
}