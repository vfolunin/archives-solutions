class Solution {
public:
    int minDeletion(vector<int> &a) {
        int res = 0;
        
        for (int i = 0, j; i < a.size(); i = j + 1) {
            j = i + 1;
            while (j < a.size() && a[i] == a[j])
                j++;
            
            res += j - i - (j < a.size());
        }
        
        return res;
    }
};