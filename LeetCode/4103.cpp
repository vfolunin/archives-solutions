struct Group {
    int type, color, size;
};

class Solution {
public:
    bool canRemoveAll(vector<int> &type, vector<int> &color, vector<int> &groupSize) {
        vector<Group> groups;
        for (int i = 0; i < type.size(); i++) {
            if (!groups.empty() && groups.back().type == type[i] && groups.back().color == color[i])
                groups.back().size++;
            else
                groups.push_back({ type[i], color[i], 1 });

            if (!groups.empty() && groups.back().size == groupSize[groups.back().type])
                groups.pop_back();
        }
        return groups.empty();
    }
};