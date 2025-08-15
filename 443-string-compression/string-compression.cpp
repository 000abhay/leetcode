class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0,i=0;
        char curr;
       while(i<n)
       {
        int count=0;
        curr=chars[i];
        while(i<n&&chars[i]==curr)
        {
            count++;
            i++;
        }
        chars[index++]=curr;
   if(count>1)
   {


         string str=to_string(count);
   
         for(auto x:str)
         {
            chars[index++]=x;

         }
   }
       }
         return index;
    }
};