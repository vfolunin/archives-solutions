class Solution {
public:
    int getWinner(vector<int> &a, int k) {
        if (k >= a.size())
            return *max_element(a.begin(), a.end());
        
        int res = a[0];
        
        for (int wins = 0; wins < k; ) {
            vector<int> b;
            
            for (int i = 1; wins < k && i < a.size(); i++) {
                if (res > a[i]) {
                    wins++;
                    b.push_back(a[i]);
                } else {
                    wins = 1;
                    b.push_back(res);
                    res = a[i];
                }
            }
            
            a = { res };
            a.insert(a.end(), b.begin(), b.end());
        }
        
        return res;
    }
};