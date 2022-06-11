class Solution {
    int joseph(int n, int k) {
        return n > 1 ? (joseph(n - 1, k) + k) % n : 0;
    }
    
public:
    int findTheWinner(int n, int k) {
        return joseph(n, k) + 1;
    }
};