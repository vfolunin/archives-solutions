class Solution {
public:
    vector<int> findEvenNumbers(vector<int> &digits) {
        vector<int> count(10);
        for (int digit : digits)
            count[digit]++;
        
        vector<int> res;
        
        for (int value = 100; value < 1000; value += 2) {
            vector<int> need(10);
            for (int v = value; v; v /= 10)
                need[v % 10]++;
            
            bool ok = 1;
            for (int digit = 0; ok && digit < 10; digit++)
                ok &= count[digit] >= need[digit];
            
            if (ok)
                res.push_back(value);
        }
        
        return res;
    }
};