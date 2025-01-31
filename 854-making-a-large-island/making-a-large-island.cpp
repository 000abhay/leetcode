// class Solution {
// public:
// int group=2;
// vector<pair<int,int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
// void dfs(vector<vector<int>>&grid,int i,int j,int r,int c,int *count)
// {
    
//     *count=(*count)+1;
//     grid[i][j]=group;
//     for(auto x:direction)
//     {
//         int i_=i+x.first;
//         int j_=j+x.second;
//         if(i_<r&&j_<c&&i_>=0&&j_>=0&&grid[i_][j_]==1)
//         {
//             dfs(grid,i_,j_,r,c,count);
//         }
//     }

// }
//     int largestIsland(vector<vector<int>>& grid) {
//         int r=grid.size();
//         int c=grid[0].size();
//         set<int>s;
//        unordered_map<int,int>store;
       
//         for(int i=0;i<r;i++)
//         {
//             for(int j=0;j<c;j++)
//             {
//                 if(grid[i][j]==1)
//                 {
//                     int count=0;
//                     dfs(grid,i,j,r,c,&count);
//                     store[group]=count;
//                     group++;
//                 }
//              //   group++;
//             }
//         }
//       int  count=1;
//         int max_ans=INT_MIN;
//        for(int i=0;i<r;i++)
//        {
//         for(int j=0;j<c;j++)
//         {
//            if(grid[i][j]==0)
//            {
//              for(auto x:direction)
//              {
//                 int i_=i+x.first;
//                int j_=j+x.second;
//                if(i_<r&&j_<c&&i_>=0&&j_>=0)
//                {
//                 s.insert(grid[i_][j_]);
 
//                }
//              }
//              for(auto x:s)
//              {
//                 count+=store[x];
//              }
//            max_ans=max(count,max_ans);
//            }
//         }
//        }
//        return max_ans;
//     }
// };
class Solution {
public:
    int group = 2;
    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& grid, int i, int j, int r, int c, int* count) {
        *count += 1;
        grid[i][j] = group;
        for (auto x : direction) {
            int i_ = i + x.first;
            int j_ = j + x.second;
            if (i_ < r && j_ < c && i_ >= 0 && j_ >= 0 && grid[i_][j_] == 1) {
                dfs(grid, i_, j_, r, c, count);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        unordered_map<int, int> store;
        int max_ans = 0;
        
        // Step 1: Mark all islands and store their sizes
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, i, j, r, c, &count);
                    store[group] = count;
                    max_ans = max(max_ans, count);  // Track the largest island
                    group++;
                }
            }
        }

        // Step 2: Try flipping each 0 to 1 and check the possible island size
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0) {
                    set<int> s;  // Track unique island groups
                    int count = 1;  // If we flip this 0, we count itself as 1
                    
                    for (auto x : direction) {
                        int i_ = i + x.first;
                        int j_ = j + x.second;
                        if (i_ < r && j_ < c && i_ >= 0 && j_ >= 0 && grid[i_][j_] > 1) {
                            s.insert(grid[i_][j_]);
                        }
                    }
                    
                    for (auto x : s) {
                        count += store[x];  // Sum sizes of unique adjacent islands
                    }
                    
                    max_ans = max(max_ans, count);
                }
            }
        }
        
        return max_ans;
    }
};
