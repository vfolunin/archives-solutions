class VideoSharingPlatform {
    unordered_map<int, string> video;
    unordered_map<int, int> likes, dislikes, views;
    set<int> unusedIds;

public:    
    int upload(const string &s) {
        int id = video.size();
        if (!unusedIds.empty()) {
            id = *unusedIds.begin();
            unusedIds.erase(unusedIds.begin());
        }
        video[id] = s;
        return id;
    }
    
    void remove(int id) {
        if (video.count(id)) {
            video.erase(id);
            likes.erase(id);
            dislikes.erase(id);
            views.erase(id);
            unusedIds.insert(id);
        }
    }
    
    string watch(int id, int l, int r) {
        if (video.count(id)) {
            views[id]++;
            return video[id].substr(l, r - l + 1);
        }
        return "-1";
    }
    
    void like(int id) {
        if (video.count(id))
            likes[id]++;
    }
    
    void dislike(int id) {
        if (video.count(id))
            dislikes[id]++;
    }
    
    vector<int> getLikesAndDislikes(int id) {
        if (video.count(id))
            return { likes[id], dislikes[id] };
        return { -1 };
    }
    
    int getViews(int id) {
        if (video.count(id))
            return views[id];
        return -1;
    }
};