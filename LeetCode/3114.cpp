class Solution {
    bool matches(const string &time, string &pattern) {
        for (int i = 0; i < time.size(); i++)
            if (time[i] != pattern[i] && pattern[i] != '?')
                return 0;
        return 1;
    }

    string toTime(int t) {
        stringstream ss;
        ss << setw(2) << setfill('0') << t / 60 << ":";
        ss << setw(2) << setfill('0') << t % 60;
        return ss.str();
    }

public:
    string findLatestTime(string &pattern) {
        int res = 12 * 60 - 1;
        while (!matches(toTime(res), pattern))
            res--;
        return toTime(res);
    }
};