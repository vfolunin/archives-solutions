class Solution {
public:
    int smallestAbsent(vector<int> &a) {
        sort(a.begin(), a.end());

        int value = accumulate(a.begin(), a.end(), 0);
        value = value / (int)a.size() + 1;
        value = max(value, 1);
        
        while (binary_search(a.begin(), a.end(), value))
            value++;

        return value;
    }
};