class FrequencyTracker {
    map<int, int> count;
    multiset<int> counts;
    
public:    
    void add(int value) {
        if (count[value])
            counts.erase(counts.find(count[value]));
        count[value]++;
        counts.insert(count[value]);
    }
    
    void deleteOne(int value) {
        if (count[value]) {
            counts.erase(counts.find(count[value]));
            count[value]--;
            if (count[value])
                counts.insert(count[value]);
        }
    }
    
    bool hasFrequency(int count) {
        return counts.find(count) != counts.end();
    }
};