class Solution {
public:
    vector<int> resultsArray(vector<int> &a, int width) {
        vector<int> res(a.size() - width + 1);
        int sortedWidth = 0;
 
        for (int i = 0; i < a.size(); i++) {
            if (i && a[i - 1] + 1 == a[i])
                sortedWidth++;
            else
                sortedWidth = 1;
            
            if (i >= width - 1)
                res[i - width + 1] = sortedWidth >= width ? a[i] : -1;
        }

        return res;
    }
};