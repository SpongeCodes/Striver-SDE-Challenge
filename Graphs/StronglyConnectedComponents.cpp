// problem link: https://www.codingninjas.com/studio/problems/strongly-connected-components-tarjan-s-algorithm_8230789?challengeSlug=striver-sde-challenge

#include<bits/stdc++.h>
void dfs(int node, vector<int> adj[],bool *vis,vector<int> &times) {
      if(vis[node]) return;
        vis[node] = true;
        for(auto adjacentNode: adj[node]) {
            dfs(adjacentNode,adj,vis,times);
        }
        
        times.push_back(node);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // found using kosaraju's algorithm
    // Tarjan's algorithm of time will be used in separate solution
    vector<int> adj[n];
    for(auto &e: edges) {
        adj[e[0]].push_back(e[1]);
    }
    
    bool vis[n];
    memset(vis,false,n);

    vector<int> times;
     // do dfs of the graph and reverse the array to get timeTaken by nodes in descending order 
        for(int i=0;i<n;i++) {
            if(!vis[i]) dfs(i,adj,vis,times);
        }
        // now have the nodes ordered by time taken highest to lowest
        reverse(times.begin(),times.end()); 
        // reverse the graph
        vector<int> adj_reverse[n];
        for(int i=0;i<n;i++) {
            for(auto e: adj[i])
                adj_reverse[e].push_back(i);
        }
        memset(vis,false,n);
        vector<vector<int>> components;
        for(int i=0;i<n;i++) {
            if(vis[times[i]]) continue;
            vector<int> scc; // strongly connected component
            dfs(times[i],adj_reverse,vis,scc);
            //cout<<"SCC found is: ";
            //for(auto x: scc) cout<<x<<" ";
            //cout<<endl;
            components.push_back(scc);
        }
        return components;
}
