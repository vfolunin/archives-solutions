struct VowelCounter {
    static inline const string vowels = "aeiou";
    vector<int> count;
    int zeroCount;

    VowelCounter() : count(vowels.size()), zeroCount(vowels.size()) {}

    void add(char c, int delta) {
        if (int index = vowels.find(c); index != -1) {
            zeroCount -= !count[index];
            count[index] += delta;
            zeroCount += !count[index];
        }
    }
};

struct ConsonantCounter {
    static inline const string vowels = "aeiou";
    int count = 0;

    void add(char c, int delta) {
        if (int index = vowels.find(c); index == -1)
            count += delta;
    }
};

class Solution {
public:
    long long countOfSubstrings(string &s, int k) {
        VowelCounter vowelCounter;
        ConsonantCounter consonantCounterL;
        ConsonantCounter consonantCounterR;
        long long res = 0;

        for (int vl1 = 0, vl2 = 0, cl1 = 0, cl2 = 0, r = 0; r < s.size(); r++) {
            vowelCounter.add(s[r], 1);
            while (!vowelCounter.zeroCount)
                vowelCounter.add(s[vl2++], -1);

            consonantCounterL.add(s[r], 1);
            while (consonantCounterL.count > k)
                consonantCounterL.add(s[cl1++], -1);

            consonantCounterR.add(s[r], 1);
            while (consonantCounterR.count >= k)
                consonantCounterR.add(s[cl2++], -1);
            
            int l1 = max(vl1, cl1);
            int l2 = min(vl2, cl2);
            res += max(l2 - l1, 0);
        }

        return res;
    }
};