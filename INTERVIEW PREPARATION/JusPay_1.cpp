#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;

bool check_reachibility(int follower,int following,vector<vector<int>> &members,vector<bool> &visited)
{
    queue<int> q;
    q.push(follower);
    visited[follower]=true;

    while(!q.empty())
    {
        int node= q.front();
        q.pop();
        vector<int>:: iterator it;
        for(it = members[follower].begin(); it!=members[follower].end();it++)
        {
            if(*it==following)
            {
                return true;
            }
            if(!visited[*it] && check_reachibility(*it,following,members,visited))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int total_members;
    cin>>total_members;

    vector<vector<int>> members(N);
    vector<bool> visited(N,false);

    for(int i=0;i<total_members;i++)
    {
        int id;
        cin>>id;
        members[id].push_back(id);
    }

    int total_edges,edge_from,edge_to;
    cin>>total_edges;
    for(int i=0;i<total_edges;i++)
    {
        cin>>edge_from>>edge_to;
        members[edge_from].push_back(edge_to);
    }

    int follower,following;
    cin>>follower>>following;

    cout<<check_reachibility(follower,following,members,visited)<<endl;

    return 0;
}