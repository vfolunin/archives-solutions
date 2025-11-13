class Solution {
public:
    int reverse(int x) {
        string s = to_string(llabs(x));
        ::reverse(s.begin(), s.end());
        if (x < 0)
            s = "-" + s;

        string m = to_string(x >= 0 ? INT_MAX : INT_MIN);
        if (s.size() < m.size() || s < m)
            return stoi(s);
        
        return 0;
    }
};