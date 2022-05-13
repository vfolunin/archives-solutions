class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;
        
        k--;
        return kthGrammar(n - 1, k / 2 + 1) ^ (k % 2);
    }
};