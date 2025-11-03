class Solution {
public:
    vector<int> findMissingElements(vector<int> &a) {
        sort(a.begin(), a.end());
        vector<int> res;
        for (int i = 0, value = a[0]; i < a.size(); i++) {
            while (value < a[i])
                res.push_back(value++);
            value++;
        }
        return res;
    }
};