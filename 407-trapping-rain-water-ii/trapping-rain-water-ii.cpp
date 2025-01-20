class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int water=0;
        int row=heightMap.size();
        int coloum=heightMap[0].size();
        typedef pair<int,pair<int,int>> pp;
        priority_queue<pp,vector<pp>,greater<>> b_cell;
        vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
        vector<vector<bool>>visited(row,vector<bool>(coloum,false));
         for(int i=0;i<row;i++)
         {
            for(int col:{0,coloum-1})
            {
                b_cell.push({heightMap[i][col],{i,col}});
                visited[i][col]=true;
            }
         }
          for(int i=0;i<coloum;i++)
         {
            for(int col:{0,row-1})
            {
                b_cell.push({heightMap[col][i],{col,i}});
                visited[col][i]=true;
            }
         }
         while(!b_cell.empty())
         {
            auto x=b_cell.top();
            b_cell.pop();
            int height=x.first;
            int i=x.second.first;
            int j=x.second.second;
            for(vector<int>&di:dir)
            {
                int i_=i+di[0];
                int j_=j+di[1];
                if(i_>=0 && i_<row&&j_>=0&&j_<coloum&&!visited[i_][j_])
                {
                    water+=max((height - heightMap[i_][j_]),0);
                    b_cell.push({max(height,heightMap[i_][j_]),{i_,j_}});
                    visited[i_][j_]=true;
                }
            }


         }
         return water;
    }
};