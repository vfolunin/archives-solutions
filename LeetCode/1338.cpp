class Solution {
public:
    int minSetSize(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        vector<int> groups;
        for (auto &[value, count] : count)
            groups.push_back(count);
        sort(groups.rbegin(), groups.rend());
        
        int sum = 0;
        for (int i = 0; i < groups.size(); i++) {
            sum += groups[i];
            if (sum * 2 >= a.size())
                return i + 1;
        }
        
        return -1;
    }
};