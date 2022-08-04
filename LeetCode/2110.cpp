class Solution {
public:
    long long getDescentPeriods(vector<int> &a) {
        long long res = 0;
        
        int row = 0;
        for (int i = 0; i < a.size(); i++) {
            if (i && a[i - 1] - 1 == a[i])
                row++;
            else 
                row = 1;            
            res += row;
        }
        
        return res;
    }
};