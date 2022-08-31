class TweetCounts {
    unordered_map<string, vector<int>> times;
    
public:    
    void recordTweet(const string &name, int time) {
        times[name].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(const string &type, const string &name, int l, int r) {
        int size = 60;
        if (type == "hour")
            size = 3600;
        if (type == "day")
            size = 86400;
        
        vector<int> res((r - l + size) / size);
        for (int time : times[name])
            if (l <= time && time <= r)
                res[(time - l) / size]++;
        return res;
    }
};