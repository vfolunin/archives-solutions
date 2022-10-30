class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creator, vector<string> &id, vector<int> &view) {
        unordered_map<string, long long> views;
        long long maxViews = -1;
        unordered_map<string, int> bestId;
        
        for (int i = 0; i < creator.size(); i++) {
            views[creator[i]] += view[i];
            maxViews = max(maxViews, views[creator[i]]);
            if (!bestId.count(creator[i]) || view[bestId[creator[i]]] < view[i] ||
                view[bestId[creator[i]]] == view[i] && id[bestId[creator[i]]] > id[i])
                bestId[creator[i]] = i;
        }

        unordered_map<string, string> bestVideos;
        for (int i = 0; i < creator.size(); i++)
            if (views[creator[i]] == maxViews)
                bestVideos[creator[i]] = id[bestId[creator[i]]];
        
        vector<vector<string>> res;
        for (auto &[editor, id] : bestVideos)
            res.push_back({ editor, id });
        return res;
    }
};