class Solution {
public:
    vector<string> getFolderNames(vector<string> &names) {
        unordered_set<string> used;
        unordered_map<string, int> suffix;
        vector<string> res(names.size());
        
        for (int i = 0; i < names.size(); i++) {            
            if (!used.count(names[i])) {
                res[i] = names[i];
            } else {
                suffix[names[i]] = max(suffix[names[i]], 1);
                while (used.count(names[i] + "(" + to_string(suffix[names[i]]) + ")"))
                    suffix[names[i]]++;
                res[i] = names[i] + "(" + to_string(suffix[names[i]]) + ")";
            }
            used.insert(res[i]);
        }
        
        return res;
    }
};