class Solution {
public:
    int findSmallestInteger(vector<int> &a, int delta) {
        vector<int> count(delta);
        for (int value : a)
            count[(value % delta + delta) % delta]++;
        
        int minIndex = min_element(count.begin(), count.end()) - count.begin();
        return delta * count[minIndex] + minIndex;
    }
};