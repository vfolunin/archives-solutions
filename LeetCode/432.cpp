class AllOne {
    unordered_map<string, int> count;
    map<int, unordered_set<string>> strings;
    
public:
    void inc(const string &s) {
        if (count.count(s)) {
            if (auto it = strings[count[s]].find(s); it != strings[count[s]].end()) {
                strings[count[s]].erase(it);
                if (strings[count[s]].empty())
                    strings.erase(count[s]);
            }
        }
        
        count[s]++;
        
        strings[count[s]].insert(s);
    }
    
    void dec(const string &s) {
        if (count.count(s)) {
            if (auto it = strings[count[s]].find(s); it != strings[count[s]].end()) {
                strings[count[s]].erase(it);
                if (strings[count[s]].empty())
                    strings.erase(count[s]);
            }
        }
        
        count[s]--;
        
        if (count[s])
            strings[count[s]].insert(s);
        else
            count.erase(s);
    }
    
    string getMinKey() {
        return count.empty() ? "" : *strings.begin()->second.begin();
    }
    
    string getMaxKey() {
        return count.empty() ? "" : *strings.rbegin()->second.begin();
    }
};