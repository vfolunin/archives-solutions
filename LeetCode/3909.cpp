class Solution {
public:
    int compareBitonicSums(vector<int> &a) {
        long long lSum = a.front();
        for (int i = 1; a[i - 1] < a[i]; i++)
            lSum += a[i];
            
        long long rSum = a.back();
        for (int i = a.size() - 2; a[i] > a[i + 1]; i--)
            rSum += a[i];
        
        if (lSum > rSum)
            return 0;
        else if (lSum < rSum)
            return 1;
        else
            return -1;
    }
};