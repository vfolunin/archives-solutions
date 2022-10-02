class Solution {
public:
    bool equalFrequency(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;      
        
        count.erase(remove(count.begin(), count.end(), 0), count.end());
        
        for (int &value : count) {
            value--;
            
            unordered_set<int> countSet(count.begin(), count.end());
            countSet.erase(0);
            
            if (countSet.size() == 1)
                return 1;
            
            value++;
        }
        
        return 0;
    }
};