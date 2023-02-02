class Solution {
public:
    bool isDecomposable(string &s) {
        int row = 1, has2 = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                row++;
            } else {
                if (row % 3 == 1 || row % 3 == 2 && has2)
                    return 0;
                has2 |= row % 3 == 2;

                row = 1;
            }
        }
        
        if (row % 3 == 1 || row % 3 == 2 && has2)
            return 0;
        has2 |= row % 3 == 2;
        
        return has2;
    }
};