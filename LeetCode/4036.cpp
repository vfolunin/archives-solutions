class Solution {
public:
    vector<string> largestString(vector<int> &a) {
        vector<string> res;

        for (int value : a) {
            res.push_back(string(value / (1 << 25), 'z'));
            value %= 1 << 25;

            for (int bit = 24; bit >= 0; bit--)
                if (value & (1 << bit))
                    res.back() += 'a' + bit;
        }

        return res;
    }
};