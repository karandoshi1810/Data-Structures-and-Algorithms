#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool visited[20];
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<nodes;i++)
    {
        visited[i]=0;
    }
    vector<int> adj[20];

    int edge_from,edge_to;
    for(int i=0;i<nodes;i++)
    {
        cin>>edge_from>>edge_to;
        adj[edge_from].push_back(edge_to);
        adj[edge_to].push_back(edge_from);
    }
    queue<int> q;
    q.push(1);
    visited[1]=true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<endl;

        vector<int>::iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++)
        {
            if (!visited[*it] )
            {
                visited[*it]=true;
                q.push(*it);
            }
        }
    }
    

}