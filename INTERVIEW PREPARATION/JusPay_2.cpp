#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;

void minimum_disconnection_nodes(int follower,int following,vector<vector<int>> &members)
{
    sort(members[follower].begin(), members[follower].end());
    sort(members[following].begin(), members[following].end());
    vector<int> v3(members[follower].size() + members[following].size());

    //iterator to store return type
    vector<int>::iterator it, end;

    end = set_intersection(
        members[follower].begin(), members[follower].end(),
        members[following].begin(), members[following].end(),
        v3.begin());
    for (it = v3.begin(); it != end-1; it++)
        cout << *it << " ";
    //cout<<follower;  //can be reason for testcase failure in contest
    
}
int main()
{
    int total_members;
    cin>>total_members;

    vector<vector<int>> members(N);

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
        members[edge_to].push_back(edge_from); //can be reason for testcase failure in contest
    }

    int follower,following;
    cin>>follower>>following;

    minimum_disconnection_nodes(follower,following,members);

    return 0;
}