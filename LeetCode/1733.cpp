class Solution {
public:
    int minimumTeachings(int languageCount, vector<vector<int>> &languages, vector<vector<int>> &edges) {
        for (vector<int> &languages : languages)
            sort(languages.begin(), languages.end());
        
        vector<pair<int, int>> edgesWithoutCommonLanguage;
        for (vector<int> &edge : edges) {
            int a = edge[0] - 1, b = edge[1] - 1;
            if (languages[a].size() > languages[b].size())
                swap(a, b);

            bool languageFound = 0;
            for (int language : languages[a]) {
                if (binary_search(languages[b].begin(), languages[b].end(), language)) {
                    languageFound = 1;
                    break;
                }
            }

            if (!languageFound)
                edgesWithoutCommonLanguage.push_back({a, b});
        }
        
        int res = languages.size();
        
        for (int language = 1; language <= languageCount; language++) {
            unordered_set<int> taught;
            
            for (auto &[a, b] : edgesWithoutCommonLanguage) {
                if (!binary_search(languages[a].begin(), languages[a].end(), language))
                    taught.insert(a);
                if (!binary_search(languages[b].begin(), languages[b].end(), language))
                    taught.insert(b);

                if (res <= taught.size())
                    break;
            }
            
            res = min<int>(res, taught.size());
        }
        
        return res;
    }
};