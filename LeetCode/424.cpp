struct Counter {
    vector<int> count;
    multiset<int> countSet;
    int countSum = 0;

    Counter() : count(26) {
        for (int i = 0; i < 26; i++)
            countSet.insert(0);
    }

    void add(int i, int delta) {
        countSet.erase(countSet.find(count[i]));
        countSum -= count[i];
        count[i] += delta;
        countSet.insert(count[i]);
        countSum += count[i];
    }

    bool isOk(int k) {
        return countSum - (countSet.empty() ? 0 : *--countSet.end()) <= k;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        Counter counter;
        int res = 0;
        
        for (int l = 0, r = 0; r < s.size(); r++) {
            counter.add(s[r] - 'A', 1);
            
            while (!counter.isOk(k)) {
                counter.add(s[l] - 'A', -1);
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};