class Solution {
public:
    bool dfs(int src , vector<vector<int>>&graph , vector<int>&vis , int clr , vector<int>&colors)
    {
        vis[src] = 1 ;
        colors[src] = clr ;
        for(auto x : graph[src])
        {
            if(vis[x] == 0)
            {
               bool temp =  dfs(x,graph,vis,1-clr,colors);
               if(temp == false)
               {
                return false;
               }
            }
            else if(vis[x] == 1 && colors[x] == clr)
            {
                return false ;
            }
        } 
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>colors(n,-1);
        bool ans = true;
        for(int i = 0 ; i<n ; i++)
        {
            if(vis[i] == 0)
            {
                ans = ans & dfs(i,graph,vis,0,colors);
            }
        }
        return ans;
        
    }
};