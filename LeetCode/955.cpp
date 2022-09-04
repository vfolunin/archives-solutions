class Solution {
public:
    int minDeletionSize(vector<string> &a) {
        vector<int> removed(a[0].size());
        
        while (1) {
            bool updated = 0;
            
            for (int i = 1; i < a.size(); i++) {
                for (int j = 0; j < a[0].size(); j++) {
                    if (removed[j])
                        continue;

                    if (a[i - 1][j] < a[i][j])
                        break;

                    if (a[i - 1][j] > a[i][j]) {
                        removed[j] = 1;
                        updated = 1;
                        break;
                    }
                }
            }
            
            if (!updated)
                break;
        }
        
        return count(removed.begin(), removed.end(), 1);
    }
};