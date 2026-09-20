class Solution {
public:
    vector<int> largestPower(vector<int> &a) {
        vector<vector<int>> groups = { a };
        vector<int> res;

        for (int bit = 14; bit >= 0; bit--) {
            vector<vector<int>> nextGroups;
            res.push_back(0);

            bool processSubgroups = 1;
            for (vector<int> &group : groups) {
                if (processSubgroups) {
                    vector<vector<int>> subgroups(2);
                    for (int value : group)
                        subgroups[(value >> bit) & 1].push_back(value);
                    
                    if (!subgroups[1].empty()) {
                        nextGroups.push_back(subgroups[1]);
                        res.back() += subgroups[1].size();
                    }
                    if (!subgroups[0].empty()) {
                        nextGroups.push_back(subgroups[0]);
                        processSubgroups = 0;
                    }
                } else {
                    nextGroups.push_back(group);
                }
            }

            groups.swap(nextGroups);
        }

        return res;
    }
};