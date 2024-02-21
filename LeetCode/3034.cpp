class Solution {
public:
    int countMatchingSubarrays(vector<int> &values, vector<int> &pattern) {
        string sValues;
        for (int i = 0; i + 1 < values.size(); i++) {
            if (values[i] < values[i + 1])
                sValues += 'a';
            else if (values[i] == values[i + 1])
                sValues += 'b';
            else
                sValues += 'c';
        }
        
        string sPattern;
        for (int value : pattern) {
            if (value == 1)
                sPattern += 'a';
            else if (value == 0)
                sPattern += 'b';
            else
                sPattern += 'c';
        }

        int res = 0;
        for (int from = 0; from + sPattern.size() <= sValues.size(); from++)
            res += sValues.substr(from, sPattern.size()) == sPattern;
        return res;
    }
};