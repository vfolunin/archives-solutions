class Solution {
public:
    int mostFrequent(vector<int> &a, int targetValue) {
        vector<int> count(1001);
        for (int i = 0; i + 1 < a.size(); i++)
            if (a[i] == targetValue)
                count[a[i + 1]]++;
        return max_element(count.begin(), count.end()) - count.begin();
    }
};