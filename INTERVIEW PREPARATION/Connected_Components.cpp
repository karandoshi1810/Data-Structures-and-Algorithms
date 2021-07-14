#include<bits/stdc++.h>
using namespace std;

int get_comp(int src,vector<vector<int>> &adj,vector<bool> &visited, vector<int> &components)
{
    if(visited[src])
        return 0;
    visited[src]=true;
    int ans=1;
    for(auto i: adj[src])
    {
        if(!visited[i])
        {
            ans+=get_comp(i,adj,visited,components);
            visited[i]=true;
        }
        /*if(visited[i]==1)
        {
            return 0;
        }*/
    }
    return ans;
}
int main()
{
    int nodes=5,edges=6;

    vector<vector<int>> adj(nodes);
    vector<bool> visited(nodes);
    vector<int> components(nodes);

    for(int i=0;i<nodes;i++)
    {
        int edge_from,edge_to;
        cin>>edge_from>>edge_to;
    }

    for(int i=0;i<nodes;i++)
    {
        if(!visited[i])
        {
            components.push_back(get_comp(i,adj,visited,components));
        }
    }
    cout<<"Number of components and their respective size";
    for(auto i:components)
    {
        cout<< i << " ";
    }
}