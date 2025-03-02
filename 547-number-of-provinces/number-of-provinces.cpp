class Solution {
public:
void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node)
{
    vis[node]=true;
    for(auto &x:adj[node])
    {
        if(!vis[x])
        {
            dfs(adj,vis,x);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adj;
        int r=isConnected.size();
        int c=isConnected[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i!=j&&isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<bool>vis(r,false);
        for(int i=0;i<r;i++)
        {
           if(!vis[i])
           {
            count++;
            dfs(adj,vis,i);
           }
        }
        return count;
    }
};