class Solution {
public:
    string largestEven(string s) {
        int i = s.rfind('2') + 1;
        if (!i)
            return "";

        s.erase(s.begin() + i, s.end());
        return s;
    }
};