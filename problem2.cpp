/*Question: You will be given an undirected graph as input. This graph will contain only one connected component. The edge number will be exactly node-1. Then take a node from the input and print its level. Consider root as 1.

Sample Input
Sample Output
7 
6
1 2
2 4
2 5
1 3
3 6
1 7
7
Level of 7 = 1
8 
7
1 2
2 4
2 5
1 3
3 6
1 7
4 8
8
Level of 8 = 3


*/

//calculate level


#include <bits/stdc++.h>
using namespace std;

const int BN=1e3+5;
vector<int> adjlist[BN];
bool visited[BN];
int level[BN];

void bsf(int root)
{
    queue <int> q;
    q.push(root);
    visited[root]=true;

    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v: adjlist[u])
        {
            if(visited[v]==true) continue;
            level[v]=level[u]+1;
            // cout<<"parent /u "<<u << " child /v "<<v<<" "<<" level "<<level[v]<<endl;
            q.push(v);
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

    bsf(1);
    int x;
    cin>>x;
    cout<<"Level of "<<x<< " = " << level[x];
    return 0;
}