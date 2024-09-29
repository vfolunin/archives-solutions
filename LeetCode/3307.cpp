class Solution {
public:
    char kthCharacter(long long index, vector<int> &ops) {
        index--;
        
        int i = 0;
        while ((1LL << i) <= index)
            i++;
        
        int shift = 0;
        for ( ; i; i--) {
            if (index >= (1LL << i) / 2) {
                index -= (1LL << i) / 2;
                shift += ops[i - 1];
            }
        }

        return shift % 26 + 'a';
    }
};