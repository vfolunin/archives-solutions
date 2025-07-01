class Solution {
public:
    vector<string> partitionString(string &s) {
        unordered_set<string> partSet;
        vector<string> parts;
        string part;

        for (char c : s) {
            part += c;
            if (!partSet.count(part)) {
                partSet.insert(part);
                parts.push_back(part);
                part.clear();
            }
        }

        return parts;
    }
};