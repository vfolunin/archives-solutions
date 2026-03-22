class Solution {
public:
    bool uniformArray(vector<int> &a) {
        return *min_element(a.begin(), a.end()) % 2 || all_of(a.begin(), a.end(), [](int value) {
            return value % 2 == 0;
        });
    }
};