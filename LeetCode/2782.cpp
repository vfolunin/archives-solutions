class Solution {
public:
    int numberOfCategories(int n, CategoryHandler *categoryHandler) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            bool hasSame = 0;
            for (int j = 0; j < i && !hasSame; j++)
                hasSame |= categoryHandler->haveSameCategory(i, j);
            res += !hasSame;
        }        
        return res;
    }
};