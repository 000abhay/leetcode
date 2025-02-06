class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>adj;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int product=nums[i]*nums[j];
               adj[product]++;
            }
        }
        int ans=0;
        for(auto &x:adj)
        {
            int save=(x.second*(x.second-1))/2;
            ans+=(save*8);
        }
return ans;
    }
};