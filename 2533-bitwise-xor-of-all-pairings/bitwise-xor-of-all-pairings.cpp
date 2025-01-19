class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int l=nums2.size();
       int result;
       if(n%2==0&&l%2==0)
       {
        return 0;
       }
       else if(n%2==0&&l%2!=0)
       {
        result=nums1[0];
        for(int i=1;i<n;i++)
        {
            result^=nums1[i];
        }
        return result;
       }
       else if(n%2!=0&&l%2==0)
       {
        result=nums2[0];
        for(int i=1;i<l;i++)
        {
            result^=nums2[i];
        }
        return result;
       }
       else
       {
        result=nums1[0];
        for(int i=1;i<n;i++)
        {
            result^=nums1[i];
        }
        for(int i=0;i<l;i++)
        {
            result^=nums2[i];
        }
        
       }
        return result;
    }
};