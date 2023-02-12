class Solution {
public:
    string findSmallestRegion(vector<vector<string>> &regions, string &a, string &b) {
        unordered_map<string, string> parent;
        for (vector<string> &regions : regions)
            for (int i = 1; i < regions.size(); i++)
                parent[regions[i]] = regions[0];
        
        vector<string> pathA;
        for ( ; a != ""; a = parent[a])
            pathA.push_back(a);
            
        vector<string> pathB;
        for ( ; b != ""; b = parent[b])
            pathB.push_back(b);
        
        string res = pathA.back();
        while (!pathA.empty() && !pathB.empty() && pathA.back() == pathB.back()) {
            res = pathA.back();
            pathA.pop_back();
            pathB.pop_back();
        }
        return res;
    }
};