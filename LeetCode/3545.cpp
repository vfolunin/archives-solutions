class Solution {
public:
    int minDeletion(string &s, int limit) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;

        sort(count.rbegin(), count.rend());
        return accumulate(count.begin() + limit, count.end(), 0);
    }
};