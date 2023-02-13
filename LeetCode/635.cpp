long long getTime(const string &s, const string &type, bool add) {
    static const vector<string> TYPES = { "Year", "Month", "Day", "Hour", "Minute", "Second" };
    stringstream ss(s);
    long long weight = 1e10, res = 0;

    for (int i = 0; 1; i++) {
        int value;
        char colon;
        ss >> value >> colon;

        res += value * weight;

        if (type == TYPES[i]) {
            if (add)
                res += weight - 1;
            return res;
        }
        
        weight /= 100;
    }
}

class LogSystem {
    map<long long, int> ids;

public:
    void put(int id, const string &time) {
        ids.emplace(getTime(time, "Second", 0), id);
    }
    
    vector<int> retrieve(const string &lTime, const string &rTime, const string &type) {
        auto lIt = ids.lower_bound(getTime(lTime, type, 0));
        auto rIt = ids.upper_bound(getTime(rTime, type, 1));

        vector<int> res;
        for (auto it = lIt; it != rIt; it++)
            res.push_back(it->second);
        return res;
    }
};