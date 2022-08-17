class Solution {
    bool isBalanced(int n) {
        vector<int> count(10);
        while (n) {
            count[n % 10]++;
            n /= 10;
        }
        
        for (int i = 0; i < count.size(); i++)
            if (count[i] && count[i] != i)
                return 0;
        return 1;
    }
    
public:
    int nextBeautifulNumber(int n) {
        do {
            n++;
        } while (!isBalanced(n));
        return n;
    }
};