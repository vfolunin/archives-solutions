class Solution {
public:
    int findTheLongestBalancedSubstring(string &s) {
        for (int length = s.size(); length; length--) {
            if (length % 2)
                continue;
            
            int half = length / 2;

            for (int i = 0; i + length <= s.size(); i++)
                if (s.substr(i, half) == string(half, '0') && s.substr(i + half, half) == string(half, '1'))
                    return length;
        }

        return 0;
    }
};