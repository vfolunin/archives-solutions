class Solution {
public:
    bool canReorderDoubled(vector<int> &a) {
        multiset<int> positive, negative;
        for (int value : a) {
            if (value > 0)
                positive.insert(value);
            else if (value < 0)
                negative.insert(value);
        }
        
        while (!positive.empty()) {
            int value = *positive.begin();
            positive.erase(positive.begin());
            
            if (auto it = positive.find(2 * value); it != positive.end()) {
                positive.erase(it);
                continue;
            }
            
            return 0;
        }
        
        while (!negative.empty()) {
            int value = *--negative.end();
            negative.erase(--negative.end());
            
            if (auto it = negative.find(2 * value); it != negative.end()) {
                negative.erase(it);
                continue;
            }
            
            return 0;
        }
        
        return 1;
    }
};
