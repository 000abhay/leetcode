class Solution {
public:
   int fun(unordered_map<int,int>&hash)
   {
    int sum=0;
    for(auto x:hash)
    {
      sum+=x.second;
    }
    return sum;

   }
    int totalFruit(vector<int>& fruits) {
        int right=0,left=0,sum=0;
        unordered_map<int,int>hash;
        int l=fruits.size();
        if(l==1) return 1;
        while(right<l)
        {
            hash[fruits[right]]++;
            while(hash.size()>2)
            {

                hash[fruits[left]]--;
                if(hash[fruits[left]]==0) hash.erase(fruits[left]);
                left++;
            }
            if(hash.size()<3)
            {
              sum=max(sum,fun(hash));
            }
            right++;
            
        }
        return sum;
    }
};