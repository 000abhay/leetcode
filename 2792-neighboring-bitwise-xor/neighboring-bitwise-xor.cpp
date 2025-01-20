class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int l=derived.size();
        vector<int>ans(l,-1);
        ans[0]=0;
        for(int i=0;i<l;i++)
        {
            if(ans[(i+1)%l]==-1)
            {
                if(derived[i]==0)
                {
                    ans[i+1]=ans[i];
                }
                else
                {
                    ans[i+1]=~ans[i];
                }

            }
            else
            {
             if(derived[i]==0&&(ans[(i+1)%l]!=ans[i]))
                {
                    return false;
                }
            if(derived[i]==1&&(ans[(i+1)%l]==ans[i]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};