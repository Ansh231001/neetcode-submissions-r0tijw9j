class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);
        queue<pair<int,int>> q;

        q.push({0,-1}); // node, parent
        vis[0] = 1;

        while(!q.empty()){
            auto [node,parent] = q.front();
            q.pop();

            for(auto nbr : adj[node]){
                if(nbr == parent)
                    continue;

                if(vis[nbr])
                    return false;

                vis[nbr] = 1;
                q.push({nbr,node});
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i])
                return false;
        }

        return true;
    }
};