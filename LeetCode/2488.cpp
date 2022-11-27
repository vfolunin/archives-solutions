class Solution {
public:
    int countSubarrays(vector<int> &a, int median) {
        int balance = 0, medianSeen = 0, res = 0;
        vector<unordered_map<int, int>> seen = { {}, { { balance, 1 } } };
        
        for (int i = 0; i < a.size(); i++) {
            balance += a[i] > median;
            balance -= a[i] < median;
            medianSeen |= a[i] == median;
            
            if (medianSeen)
                res += seen[1 - i % 2][balance] + seen[i % 2][balance - 1];
            seen[i % 2][balance]++;            
        }
        
        return res;
    }
};