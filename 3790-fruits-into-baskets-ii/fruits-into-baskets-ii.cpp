class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
         int count=0;
        for(auto x:fruits)
        {
            bool b1=true;
            for(int i=0;i<baskets.size();i++)
            {
                
                if(baskets[i]!=-1&&x<=baskets[i])
                {
                     baskets[i]=-1; b1=false; break;
                }
            }
            if(b1) count++;
        }
        return count;
    }
};