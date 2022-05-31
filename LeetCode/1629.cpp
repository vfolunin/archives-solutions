class Solution {
public:
    char slowestKey(vector<int> &times, string keys) {
        char res = keys[0];
        int resTime = times[0];
        
        for (int i = 1; i < times.size(); i++) {
            if (resTime < times[i] - times[i - 1] ||
                resTime == times[i] - times[i - 1] && res < keys[i]) {
                resTime = times[i] - times[i - 1];
                res = keys[i];
            }
        }
        
        return res;
    }
};