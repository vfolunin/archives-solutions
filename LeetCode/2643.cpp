class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &a) {
        vector<int> oneCount(a.size());
        for (int y = 0; y < a.size(); y++)
            oneCount[y] = count(a[y].begin(), a[y].end(), 1);
        
        int y = max_element(oneCount.begin(), oneCount.end()) - oneCount.begin();
        return { y, oneCount[y] };
    }
};