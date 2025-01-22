class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                     q.push({i,j});
                }
                 if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if(!fresh)
        {
            return 0;
        }
        int min=0,count=0;
        while(!q.empty())
        {
           int l=q.size();
           
           
             
             while(l--)
             {
           auto x=q.front();
           q.pop();
           count++;
           int i=x.first;
           int j=x.second;
                for(auto &x:direction)
                {
                    int i_=i+x[0];
                    int j_=j+x[1];
                    if(i_>=0&&j_>=0&&i_<m&&j_<n&&grid[i_][j_]==1)
                    {
                        grid[i_][j_]=2;
                        q.push({i_,j_});
                        fresh--;
                    }
                
             }
           }
           min++;
        }
    
    
        return  fresh==0? min-1 :-1;

    }
};