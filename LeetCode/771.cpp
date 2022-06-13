class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        
        int res = 0;
        for (char stone : stones)
            res += jewelSet.count(stone);
        
        return res;
    }
};