/*Question: You will be given an undirected graph as input. Now print “YES” if there is a cycle and print “NO” if there isn’t any cycle. Consider root as 1.


Sample Input
Sample Output
4
4
1 2
2 3
3 4
4 2
YES
6
4
1 2
2 3
3 4
5 6
NO

*/

#include <bits/stdc++.h>
using namespace std;

const int BN=1e3+5;
vector<int> adjlist[BN];
bool visited[BN];
int level[BN];

// void bfs(int root, int p=-1){
//     queue<int> q;
//     q.push(root);
//     visited[root]=true;
 
//     while (!q.empty())
//     {
//         int u=q.front();
//         q.pop();
//         p=u;
//         for(int v:adjlist[u])
//         {
//             if(visited[v]==true) continue;
//             q.push(v);
//             visited[v]=true;

//             cout<<"parent "<<u<<" child "<<v<<endl;
            
//         }
//     }
    
// }


bool dfs(int u, int p=-1)
{
    bool cycleExist = false;
    visited[u]=true;

    for(int v:adjlist[u])
    {
        if(v==p) continue;
        if(visited[v]) return true;
        cycleExist = cycleExist | dfs(v, u);
    }
    return  cycleExist;
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

if(dfs(1)){
    cout<<"YES";

}else cout<<"NO";

    return 0;
}