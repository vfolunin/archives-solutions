class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
    
    string getString(int h, int m) {
        stringstream ss;
        ss << h << ":" << setw(2) << setfill('0') << m;
        return ss.str();
    }
    
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                if (ones(h) + ones(m) == turnedOn)
                    res.push_back(getString(h, m));
        return res;
    }
};