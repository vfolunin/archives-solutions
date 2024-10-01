class Solution {
public:
    int mostExpensiveItem(int a, int b) {
        vector<int> can(a * b);
        can[0] = 1;

        for (int value : { a, b })
            for (int sum = value; sum < can.size(); sum++)
                can[sum] |= can[sum - value];
        
        int res = can.size() - 1;
        while (can[res])
            res--;
        return res;
    }
};