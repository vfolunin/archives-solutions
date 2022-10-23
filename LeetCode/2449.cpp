class Solution {
    long long solve(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        long long res = 0;
        
        for (int i = 0; i < a.size(); i++)
            if (a[i] < b[i])
                res += (b[i] - a[i]) / 2;
        
        return res;
    }
    
public:
    long long makeSimilar(vector<int> &a, vector<int> &b) {
        vector<vector<int>> aParts(2);
        for (int value : a)
            aParts[value % 2].push_back(value);
        
        vector<vector<int>> bParts(2);
        for (int value : b)
            bParts[value % 2].push_back(value);
        
        return solve(aParts[0], bParts[0]) + solve(aParts[1], bParts[1]);
    }
};