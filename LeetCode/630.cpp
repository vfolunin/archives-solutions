class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(), [](auto &a, auto &b) { return a[1] < b[1]; });
        
        multiset<int> durations;
        int durationSum = 0, res = 0;
        
        for (vector<int> &course : courses) {
            int &duration = course[0], &deadline = course[1];
            
            if (durationSum + duration <= deadline) {
                durations.insert(duration);
                durationSum += duration;
                res++;
            } else if (!durations.empty() && duration < *--durations.end()) {
                durationSum += duration - *--durations.end();
                durations.erase(--durations.end());
                durations.insert(duration);
            }
        }
        
        return res;
    }
};