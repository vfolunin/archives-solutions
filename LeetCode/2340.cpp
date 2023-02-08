class Solution {
public:
    int minimumSwaps(vector<int> &a) {
        int minIndex = min_element(a.begin(), a.end()) - a.begin();
        int maxIndex = a.rend() - max_element(a.rbegin(), a.rend()) - 1;
        return minIndex + (a.size() - 1 - maxIndex) - (maxIndex < minIndex);
    }
};