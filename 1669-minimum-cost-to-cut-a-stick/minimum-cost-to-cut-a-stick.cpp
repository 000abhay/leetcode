class Solution {
public:
vector<vector<int>>memo;
int solve(vector<int>&cuts,int l,int r)
{
    if((r-l)<2)
    {
     return 0;
    }
    if(memo[l][r]!=-1)
    {
        return memo[l][r];
    }
    int res=INT_MAX;
    for(int i=l+1;i<=r-1;i++)
    {
       int cost=(cuts[r]-cuts[l])+solve(cuts,l,i)+solve(cuts,i,r);
       res=min(res,cost);
    }
    return memo[l][r]=res;

}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(begin(cuts),0);
        cuts.push_back(n);
        memo.assign(103,vector<int>(103,-1));
        return solve(cuts,0,cuts.size()-1);

    }
};