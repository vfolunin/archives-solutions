class Solution {
    int get(vector<int> count1, int count2, char c) {
        count1[c - 'a'] = count2;
        sort(count1.begin(), count1.end());
        int lCount = accumulate(count1.begin(), count1.end() - 1, 0);
        int rCount = min(lCount, count1.back());
        return (lCount + rCount) / 2;
    }

public:
    int score(vector<string> &cards, char c) {
        int countLR = 0;
        vector<int> countL(10), countR(10);
        for (string &card : cards) {
            if (card[0] == c && card[1] == c)
                countLR++;
            else if (card[0] == c)
                countL[card[1] - 'a']++;
            else if (card[1] == c)
                countR[card[0] - 'a']++;
        }

        int res = 0;
        for (int l = 0, r = countLR; l <= countLR; l++, r--)
            res = max(res, get(countL, l, c) + get(countR, r, c));
        return res;
    }
};