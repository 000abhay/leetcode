class Solution {
public:
bool fun(vector<int>&weights,int n,int mi,int days)
{
    int sum=0,count=1;
    for (int i = 0; i < n; i++) {
            if (sum + weights[i] > mi) { // If adding weight exceeds capacity
                count++;  // Start a new day
                sum = weights[i];  // Carry current weight to new day
                if (count > days) return false;  // More than allowed days
            } else {
                sum += weights[i];
            }
        }
        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int mx=0,mi=0;
        int n=weights.size();
        mx=accumulate(weights.begin(),weights.end(),0);
        for(int i=0;i<n;i++)
        {
            
           mi=max(mi,weights[i]);
        }
        while(mi<mx)
        {
        int mid = mi + (mx - mi) / 2;
            if (fun(weights, n, mid, days)) {
                mx = mid;  // Try a smaller capacity
            } else {
                mi = mid + 1;  // Increase capacity
            }
        }
        return mi;
    }
};