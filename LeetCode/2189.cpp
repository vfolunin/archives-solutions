class Solution {
    int rec(int cardCount, int prevRow) {
        static vector<vector<int>> memo(501, vector<int>(501, -1));
        int &res = memo[cardCount][prevRow];
        if (res != -1)
            return res;

        if (!cardCount)
            return res = 1;

        res = 0;
        for (int row = 1; row < prevRow && 3 * row - 1 <= cardCount; row++)
            res += rec(cardCount - (3 * row - 1), row);
        return res;
    }

public:
    int houseOfCards(int cardCount) {
        return rec(cardCount, 500);
    }
};