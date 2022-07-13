class Twitter {
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followees;
    int timer = 0;
    
    struct Item {
        int user, index, timer;
        
        bool operator < (const Item &that) const {
            return timer > that.timer;
        }
    };
    
public:
    void postTweet(int user, int tweet) {
        tweets[user].push_back({ timer++, tweet });
    }
    
    vector<int> getNewsFeed(int user) {
        set<Item> q;
        
        for (int followee : followees[user])
            if (!tweets[followee].empty())
                q.insert({ followee, (int)tweets[followee].size() - 1, tweets[followee].back().first });
        
        if (!tweets[user].empty())
            q.insert({ user, (int)tweets[user].size() - 1, tweets[user].back().first });
        
        vector<int> res;
        while (res.size() < 10 && !q.empty()) {
            auto [user, index, timer] = *q.begin();
            q.erase(q.begin());
            
            res.push_back(tweets[user][index].second);
            if (index)
                q.insert({ user, index - 1, tweets[user][index - 1].first });
        }
        return res;
    }
    
    void follow(int follower, int followee) {
        followees[follower].insert(followee);
    }
    
    void unfollow(int follower, int followee) {
        followees[follower].erase(followee);
    }
};