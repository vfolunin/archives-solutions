class Solution {
    int digitSum(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    
public:
    int countLargestGroup(int n) {
        vector<int> groupSize(40);        
        for (int i = 1; i <= n; i++)
            groupSize[digitSum(i)]++;
        
        int maxSize = *max_element(groupSize.begin(), groupSize.end());
        return count(groupSize.begin(), groupSize.end(), maxSize);
    }
};