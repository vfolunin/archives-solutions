class Solution {
public:
    string kthDistinct(vector<string> &a, int k) {
        unordered_map<string, int> count;
        for (string &value : a)
            count[value]++;
        
        for (string &value : a)
            if (count[value] == 1 && !--k)
                return value;
        
        return "";
    }
};