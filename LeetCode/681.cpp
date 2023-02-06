class Solution {
    int decodeTime(string &s) {
        stringstream ss(s);
        int h, m;
        char colon;
        ss >> h >> colon >> m;
        return h * 60 + m;
    }

    string encodeTime(int t) {
        int h = t / 60, m = t % 60;
        stringstream ss;
        ss << setw(2) << setfill('0') << h;
        ss << ":";
        ss << setw(2) << setfill('0') << m;
        return ss.str();
    }

    bool check(string &a, string &b) {
        for (char c : b)
            if (a.find(c) == -1)
                return 0;
        return 1;
    }

public:
    string nextClosestTime(string &s) {
        int time = decodeTime(s);

        while (1) {
            time = (time + 1) % (24 * 60);
            string res = encodeTime(time);
            if (check(s, res))
                return res;
        }
    }
};