#include<bits/stdc++.h>
using namespace std;

const int N=10;
bool visited[N];
vector<int> adj[N];

void dfs(int node)
{
    visited[1]=1;
    cout<<node<<endl;

    vector<int>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(visited[*it]!=1)
        {
            dfs(*it);

        }
    }
    
}
int main()
{
    for(int i=0;i<N;i++)
    {
        visited[i]=false;
    }
    int nodes,edges;

    cin>>nodes>>edges;

    for(int i=0;i<nodes;i++)
    {
        int edge_from,edge_to;
        cin>>edge_from>>edge_to;
        adj[edge_from].push_back(edge_to);
        adj[edge_to].push_back(edge_from);
    }

    queue<int> q;
    q.push(1);
}