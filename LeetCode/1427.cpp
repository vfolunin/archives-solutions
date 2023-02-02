class Solution {
public:
    string stringShift(string &s, vector<vector<int>> &shifts) {
        int totalShift = 0;
        for (vector<int> &shift : shifts)
            totalShift += (shift[0] ? -1 : 1) * shift[1];
        
        totalShift %= (int)s.size();
        if (totalShift < 0)
            totalShift += s.size();

        rotate(s.begin(), s.begin() + totalShift, s.end());
        return s;
    }
};