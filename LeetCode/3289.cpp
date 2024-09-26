class Solution {
public:
    vector<int> getSneakyNumbers(vector<int> &a) {
        vector<int> count(a.size() - 2);
        for (int value : a)
            count[value]++;
        
        vector<int> res;
        for (int value = 0; value < count.size(); value++)
            if (count[value] == 2)
                res.push_back(value);
        return res;
    }
};