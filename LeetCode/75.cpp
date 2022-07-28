class Solution {
public:
    void sortColors(vector<int> &a) {
        vector<int> count(3);
        for (int value : a)
            count[value]++;
        
        for (int i = 0, from = 0; i < count.size(); from += count[i++])
            fill(a.begin() + from, a.begin() + from + count[i], i);
    }
};