class Solution {
public:
    vector<int> recoverOrder(vector<int> &order, vector<int> &friends) {
        vector<int> res;
        for (int value : order)
            if (binary_search(friends.begin(), friends.end(), value))
                res.push_back(value);
        return res;
    }
};