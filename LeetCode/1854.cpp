class Solution {
public:
    int maximumPopulation(vector<vector<int>> &logs) {
        vector<pair<int, int>> events;
        for (vector<int> &record : logs) {
            events.push_back({ record[0], +1 });
            events.push_back({ record[1], -1 });
        }
        sort(events.begin(), events.end());
        
        int sum = 0, maxSum = 0, maxYear;
        for (auto &[year, delta] : events) {
            sum += delta;
            if (maxSum < sum) {
                maxSum = sum;
                maxYear = year;
            }
        }
        
        return maxYear;
    }
};