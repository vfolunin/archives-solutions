class Solution {
public:
    bool checkValidCuts(int size, vector<vector<int>> &rectangles) {
        for (int coord = 0; coord < 2; coord++) {
            set<int> values;
            for (vector<int> &rectangle : rectangles)
                values.insert(rectangle[coord]);
            values.erase(0);

            for (vector<int> &rectangle : rectangles) {
                auto it = values.upper_bound(rectangle[coord]);
                while (it != values.end() && *it < rectangle[2 + coord])
                    it = values.erase(it);
            }

            if (values.size() >= 2)
                return 1;
        }
        return 0;
    }
};