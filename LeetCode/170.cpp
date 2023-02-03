class TwoSum {
    multiset<int> values;

public:    
    void add(int value) {
        values.insert(value);
    }
    
    bool find(int sum) {
        if (values.empty())
            return 0;

        auto lIt = values.begin(), rIt = prev(values.end());
        while (1) {
            while (lIt != rIt && *lIt + *rIt < sum)
                lIt++;
            while (lIt != rIt && *lIt + *rIt > sum)
                rIt--;
            if (lIt != rIt && *lIt + *rIt == sum)
                return 1;
            if (lIt == rIt)
                return 0;
        }
    }
};