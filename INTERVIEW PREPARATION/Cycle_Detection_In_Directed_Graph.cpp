#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;  //constant int will help in memory allocation

bool detect_cycle(int src,vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack)
{
    visited[src]=true; //mark that the current node is vasited
    stack[src]=true;  //push the current node in the stack(it is basically a vector)

    for(int i:adj[src])  //visit every neighboring node of current node
    {
        if(stack[i])  //if neighboring node is already present in the stack, then there is a cycle
        {
            return true;  //return treu on this case
        }
        if(!visited[i] and detect_cycle(i,adj,visited,stack))  //if the neigboring node is not visited then call
                                                               //call the function again for this node. If this 
                                                               //function true then there is a cycle present. 
        {
            return true;  //hence return true
        }
    }
stack[src]=false; 
return false;// if program reaches here then there will be no cycle, hence return false
}
int main()
{
    int nodes,edges; //number of nodes and edges
    cin>>nodes>>edges;
    vector<vector<int>> adj(nodes);  //adjecency matrix
    vector<int> stack(nodes,0);  //stack to keep track of which node is already visited
    vector<bool> visited(nodes,false);  //indicator which will indicate if nodes is visited or not
    for(int i=0;i<nodes;i++)  //traverse every node
    {
        int edge_from,edge_to;  
        cin>>edge_from>>edge_to;
        adj[edge_from].push_back(edge_to);  //update the adjcency matrix
    }
    bool is_cycle=false; //flag for indicating whether cycle present or not
    for(int i=0;i<nodes;i++)  //visit every node of graph and check for cycle
    {
        if(!visited[i] and detect_cycle(i,adj,visited,stack))  //if node is not visited and if function detects cycle
        {
            is_cycle=true;  //set the flag to 1
        }
    }

    if(is_cycle)  //if cycle is present 
    {
        cout<<"Cycle is present";  //print cycle is present
    }
    else
    {
        cout<<"Cycle is not present";  //print cycle is not present
    }
}
