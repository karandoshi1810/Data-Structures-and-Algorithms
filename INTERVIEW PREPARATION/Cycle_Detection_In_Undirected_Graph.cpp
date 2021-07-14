#include<bits/stdc++.h>
using namespace std;
bool cycle_detector(int src, vector<vector<int>> &adj, vector<bool> &visited,int parent)
{
    visited[src]=true;   //change the src node from unvisited to visited
    for(auto i: adj[src])  //visit every adjecent node of current node using for_each loop
    {
        if(i!=parent)  //if the node is not parent. This condition is required as it is an undirected graph and there 
                       //is an edge from A->B and B->A as well. So if a graph with two nodes A and B is available then
                       // also it will detect cycle 
        {
            if(visited[i]) //while traversing the adjcent nodes if we find that a node is visited again
            {
                return true;  //then a cycle is present, hence return true
            }
            if(!visited[i] && cycle_detector(i,adj,visited,src)) //if we find that node is not visited then we will call
                                                                 //this function again and if the function detects a cycle
                                                                 //return true
            {
                return true;
            }
        }
    }
    return false;  //if no cycle is detected then return false
}
int main()
{
    int nodes,edges; 
    cin>>nodes>>edges;   //input number of nodes and edges

    vector<vector<int>> adj(nodes);  //create a adjcency matrix/list
    vector<bool> visited(nodes,false);  //vector to keep record of which nodes are visited

    for(int i=0;i<nodes;i++)  //input the graph
    {
        int edge_from,edge_to;  //graphs from which edge is originated and graph to which it points
        cin>>edge_from>>edge_to;

        adj[edge_from].push_back(edge_to);  //update the matrix by creating an edge from src to dest
        adj[edge_to].push_back(edge_from);  //update the matrix by creating an edge from dest to src as it is 
                                            // undirected graph
    }

    bool is_cycle=false;  //variable to inidcate whether cycle exits or not

    for(int i=0;i<nodes;i++)  //traversing every node of the graph
    {
        if(!visited[i] && cycle_detector(i,adj,visited,-1)) //if the graph is not visited and cycle is detected
        {
            is_cycle=true;  //change the variable to true
        }
    }
    if(is_cycle)
    {
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
}