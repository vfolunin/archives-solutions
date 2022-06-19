class Solution {
    int factorial(int n) {
        static vector<int> memo(10);
        int &res = memo[n];
        if (res)
            return res;
        
        if (!n)
            return res = 1;
        
        return res = factorial(n - 1) * n;
    }
    
public:
    string getPermutation(int size, int index) {
        vector<int> used(size + 1);
        string res;
        
        for (int i = 0; i < size; i++) {
            int digit = 1;
            while (used[digit])
                digit++;
            
            while (index > factorial(size - 1 - i)) {
                index -= factorial(size - 1 - i);
                
                digit++;
                while (used[digit])
                    digit++;
            }
            
            used[digit] = 1;
            res += digit + '0';
        }
        
        return res;
    }
};