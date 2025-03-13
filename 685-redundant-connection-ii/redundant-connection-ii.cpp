class Solution {
public:
  vector<int>parent;
  vector<int>rank;
   int find(int x)
   {
    if(parent[x]==-1)
    {
        return x;
    }
    return parent[x]=find(parent[x]);
   }
   bool union_do(int u,int v)
   {
       int U=find(u);
       int V=find(v);
       if(U==V)
       {
        return true;
       }
       if(rank[U]>rank[V])
       {
        parent[V]=U;
       }
       else if(rank[V]>rank[U])
       {
        parent[U]=V;
       }
       else
        {
            parent[U]=V;
            rank[V]++;
        }
  return false;

   }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1,-1);
        rank.resize(n+1,0);
        vector<int>ind(n+1,-1);
        int b1=-1,b2=-1;
        for(int i=0;i<n;i++)
        {
          // int u=edges[i][0];
           int v=edges[i][1];
           if(ind[v]!=-1)
           {
            b1=i;
            b2=ind[v];
           }
           else
           {
            ind[v]=i;
           }
        }
   for(int i=0;i<n;i++)
   {
    if(i==b1)
    {
        continue;
    }
    int u=edges[i][0];
    int v=edges[i][1];
    if(union_do(u,v))
    {
        if(b1==-1)
        {
            return edges[i];
        }
        else
        {
            return edges[b2];
        }

    }

   }
  return edges[b1];
    }
};