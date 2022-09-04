class Solution {
public:
    string largestTimeFromDigits(vector<int> &a) {
        sort(a.begin(), a.end());
        vector<int> res(4, -1);
        
        do {
            if (a[0] * 10 + a[1] < 24 && a[2] * 10 + a[3] < 60)
                res = max(res, a);
        } while (next_permutation(a.begin(), a.end()));
        
        if (res[0] == -1)
            return "";
        
        stringstream ss;
        ss << res[0] << res[1] << ":" << res[2] << res[3];
        return ss.str();
    }
};