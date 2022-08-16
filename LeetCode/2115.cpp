struct Compressor {
    unordered_map<string, int> ids;

    int getId(string &word) {
        if (!ids.count(word))
            ids[word] = ids.size();
        return ids[word];
    }
};

class Solution {
    bool canCreate(vector<int> &iIds, unordered_set<int> &sIds) {
        for (int id : iIds)
            if (!sIds.count(id))
                return 0;
        return 1;
    }
    
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies) {
        Compressor compressor;
        
        unordered_set<int> rIds;
        for (string &recipe : recipes)
            rIds.insert(compressor.getId(recipe));
        
        vector<vector<int>> iIds(rIds.size());
        for (int i = 0; i < iIds.size(); i++)
            for (string &ingredient : ingredients[i])
                iIds[i].push_back(compressor.getId(ingredient));
        
        unordered_set<int> sIds;
        for (string &supply : supplies)
            sIds.insert(compressor.getId(supply));
        
        vector<int> resIds;
        
        while (1) {
            bool updated = 0;

            for (auto rIt = rIds.begin(); rIt != rIds.end(); ) {
                if (canCreate(iIds[*rIt], sIds)) {
                    sIds.insert(*rIt);
                    resIds.push_back(*rIt);
                    rIt = rIds.erase(rIt);
                    updated = 1;
                } else {
                    rIt++;
                }
            }

            if (!updated)
                break;
        }
        
        vector<string> res;
        for (int id : resIds)
            res.push_back(recipes[id]);
        return res;
    }
};