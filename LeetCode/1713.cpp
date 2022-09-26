class Solution {
    int lisSize(vector<int> &a) {
        vector<int> lisLast;
        for (int i = 0; i < a.size(); i++) {
            int pos = lower_bound(lisLast.begin(), lisLast.end(), a[i]) - lisLast.begin();
            if (pos == lisLast.size())
                lisLast.emplace_back();
            lisLast[pos] = a[i];
        }
        return lisLast.size();
    }
    
public:
    int minOperations(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]] = i;
        
        vector<int> c;
        for (int &value : b)
            if (pos.count(value))
                c.push_back(pos[value]);
        
        return a.size() - lisSize(c);
    }
};