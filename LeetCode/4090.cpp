struct Counter {
    unordered_map<char, int> count;

    void add(char c, int delta) {
        count[c] += delta;
        if (!count[c])
            count.erase(c);
    }

    int size() {
        return count.size();
    }
};

class Solution {
public:
    int countMagicalPairs(string &s) {
        int res = 0;
        for (int l = 0; l < s.size(); l++) {
            Counter counterL1, counterL2, counterR1, counterR2;
            for (int m1 = l, m2 = l, r = l; r < s.size(); r++) {
                counterR1.add(s[r], 1);
                counterR2.add(s[r], 1);
                while (counterL1.size() < counterR1.size()) {
                    counterL1.add(s[m1], 1);
                    counterR1.add(s[m1], -1);
                    m1++;
                }
                while (counterL2.size() <= counterR2.size()) {
                    counterL2.add(s[m2], 1);
                    counterR2.add(s[m2], -1);
                    m2++;
                }
                res += m2 - m1;
            }
        }
        return res;
    }
};