class Solution {
    int getTime(const string &s) {
        stringstream ss(s);
        int h, m;
        char colon;
        ss >> h >> colon >> m;
        return h * 60 + m;
    }
    
public:
    int findMinDifference(vector<string> &timeStrings) {
        vector<int> times(timeStrings.size());
        for (int i = 0; i < times.size(); i++) 
            times[i] = getTime(timeStrings[i]);
        
        sort(times.begin(), times.end());
        
        int res = times.front() + 24 * 60 - times.back();
        for (int i = 1; i < times.size(); i++)
            res = min(res, times[i] - times[i - 1]);
        return res;
    }
};