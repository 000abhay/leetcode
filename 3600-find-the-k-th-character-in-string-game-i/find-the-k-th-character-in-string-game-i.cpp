class Solution {
public:
    char kthCharacter(int k) {
        int count=0,set=1,div,val;
         while(set<k)
         {
            set*=2;
         }
         while(set>1)
         {
            div=set/2;
            if(k>div)
            {
                count++;
                val=k%div;
                if(val==0)
                {
                  k=div;
                }
                else
                {
                    k=val;
                }
            }

         set/=2;
             
             
    
         }
     return 'a'+count;
    }
};