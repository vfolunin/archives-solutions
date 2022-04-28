class Solution {
public:
    vector<int> frequencySort(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        sort(a.begin(), a.end(), [&](int a, int b) {
            if (count[a] != count[b])
                return count[a] < count[b];
            return a > b;
        });
        return a;
    }
};