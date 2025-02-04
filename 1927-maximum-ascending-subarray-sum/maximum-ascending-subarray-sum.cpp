class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
         int ans=0,save=0;
         for(int i=0;i<n;i++)
         {
           save+=nums[i];
           if(i+1<n&&nums[i]>=nums[i+1])
           {
            ans=max(ans,save);
            save=0;
           }
         }
         return max(ans,save);
    }
};