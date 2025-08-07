class Solution {
public:
    void build(int i, int l, int r, vector<int>& b, vector<int>& s) {
        if(l == r) {
            s[i] = b[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*i+1, l, mid, b, s);
        build(2*i+2, mid+1, r, b, s);
        s[i] = max(s[2*i+1], s[2*i+2]);
    }

    bool query(int i, int l, int r, vector<int>& s, int x) {
        if(s[i] < x) return false;
        if(l == r) {
            s[i] = -1;
            return true;
        }
        int mid = (l + r) / 2;
        bool placed = false;
        if(query(2*i+1, l, mid, s, x))
            placed = true;
        else
            placed = query(2*i+2, mid+1, r, s, x);
        s[i] = max(s[2*i+1], s[2*i+2]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size();
        vector<int> seg(4*n, -1);
        build(0, 0, n-1, b, seg);
        int un = 0;
        for(int &x : f) {
            if(!query(0, 0, n-1, seg, x)) un++;
        }
        return un;
    }
};
