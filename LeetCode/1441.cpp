class Solution {
public:
    vector<string> buildArray(vector<int> &a, int n) {
        vector<string> res;
        
        for (int x = 1, i = 0; x <= n && i < a.size(); x++) {
            res.push_back("Push");
            
            if (x == a[i])
                i++;
            else
                res.push_back("Pop");
        }
        
        return res;
    }
};