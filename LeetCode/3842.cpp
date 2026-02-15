class Solution {
public:
    vector<int> toggleLightBulbs(vector<int> &indexes) {
        vector<int> isOn(101);
        for (int i : indexes)
            isOn[i] ^= 1;
        
        vector<int> res;
        for (int i = 1; i < isOn.size(); i++)
            if (isOn[i])
                res.push_back(i);
        return res;
    }
};