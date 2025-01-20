class Solution {
public:
    bool canBeValid(string s, string locked) {
        int l=s.length();
        if(l&1)
        {
            return false;
        }
        int  wildcard=0;
        int open=0;
        int close=0;
        for(int i=0;i<l;i++)
        {
            if(locked[i]=='0')
            {
                wildcard++;
            }
           else if(s[i]==')')
            {
                close++;
            }
            else
            {
                open++;
            }
            if(wildcard<(close-open))
            {
                return false;
            }
        }
        open=close=wildcard=0;
            for(int i=l-1;i>=0;i--)
            {
                if(locked[i]=='0')
            {
                wildcard++;
            }
             else if(s[i]==')')
            {
                close++;
            }
            else
            {
                open++;
            }
                if(wildcard<(open-close))
                {
                    return false;
                }
        }

            
            return true;
        
    }
};