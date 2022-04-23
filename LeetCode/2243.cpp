class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string nextS;
            for (int from = 0; from < s.size(); from += k) {
                int sum = 0;
                for (int i = 0; i < k && from + i < s.size(); i++)
                    sum += s[from + i] - '0';
                nextS += to_string(sum);
            }
            s.swap(nextS);
        }
        return s;
    }
};