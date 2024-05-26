class Solution {
public:
    vector<int> queryResults(int size, vector<vector<int>> &queries) {
        unordered_map<int, int> colorOf, colorCount;
        vector<int> res(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int index = queries[i][0];
            int color = queries[i][1];

            if (colorOf.count(index) && !--colorCount[colorOf[index]])
                colorCount.erase(colorOf[index]);
            colorOf[index] = color;
            colorCount[colorOf[index]]++;

            res[i] = colorCount.size();
        }

        return res;
    }
};