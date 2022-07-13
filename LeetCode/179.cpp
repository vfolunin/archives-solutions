class Solution {
public:
    string largestNumber(vector<int> &parts) {
        vector<string> stringParts(parts.size());
        for (int i = 0; i < parts.size(); i++)
            stringParts[i] = to_string(parts[i]);
        
        vector<int> indexes(parts.size());
        iota(indexes.begin(), indexes.end(), 0);
        sort(indexes.begin(), indexes.end(), [&](int a, int b) {
            return stringParts[a] + stringParts[b] > stringParts[b] + stringParts[a];
        });
        
        string res;
        for (int index : indexes)
            res += stringParts[index];
        return res[0] != '0' ? res : "0";
    }
};