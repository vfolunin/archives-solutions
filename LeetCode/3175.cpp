class Solution {
public:
    int findWinningPlayer(vector<int> &a, int targetRow) {
        deque<pair<int, int>> values;
        for (int i = 0; i < a.size(); i++)
            values.push_back({ a[i], i });
        int maxValue = *max_element(a.begin(), a.end());
        int row = 0;

        while (1) {
            if (values[0].first == maxValue)
                return values[0].second;
            
            if (values[0].first > values[1].first) {
                values.push_back(values[1]);
                values.erase(values.begin() + 1);
            } else {
                values.push_back(values[0]);
                values.pop_front();
                row = 0;
            }

            if (++row == targetRow)
                return values[0].second;
        }
    }
};