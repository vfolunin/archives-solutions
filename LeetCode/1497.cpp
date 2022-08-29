class Solution {
public:
    bool canArrange(vector<int> &a, int divisor) {
        unordered_multiset<int> remainders;
        
        for (int value : a) {
            int remainder = (value % divisor + divisor) % divisor;
            int complement = (divisor - remainder) % divisor;
            
            if (auto it = remainders.find(complement); it != remainders.end())
                remainders.erase(it);
            else
                remainders.insert(remainder);
        }
        
        return remainders.empty();
    }
};