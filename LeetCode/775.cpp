class Solution {
public:
    bool isIdealPermutation(vector<int> &a) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == i)
                continue;
            
            if (i + 1 < a.size() && a[i] == i + 1 && a[i + 1] == i) {
                i++;
                continue;
            }
            
            return 0;
        }
        return 1;
    }
};