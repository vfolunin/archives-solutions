class Solution {
public:
    int countOddLetters(int n) {
        static const vector<string> digits = {
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
        };

        vector<int> count(26);
        for (; n; n /= 10)
            for (char c : digits[n % 10])
                count[c - 'a']++;

        return count_if(count.begin(), count.end(), [](int n) {
            return n % 2;
        });
    }
};