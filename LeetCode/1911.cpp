class Solution {
public:
    long long maxAlternatingSum(vector<int> &a) {
        long long oddSum = 0, evenSum = 0;
        
        for (int value : a) {
            long long nextOddSum = evenSum + value;
            long long nextEvenSum = oddSum - value;
            
            oddSum = max(oddSum, nextOddSum);
            evenSum = max(evenSum, nextEvenSum);
        }
        
        return max(oddSum, evenSum);
    }
};