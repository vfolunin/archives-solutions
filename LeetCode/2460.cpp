class Solution {
public:
    vector<int> applyOperations(vector<int> &a) {
        for (int i = 0; i + 1 < a.size(); i++) {
            if (a[i] == a[i + 1]) {
                a[i] *= 2;
                a[i + 1] = 0;
            }
        }
        
        fill(remove(a.begin(), a.end(), 0), a.end(), 0);
        
        return a;
    }
};