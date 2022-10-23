class Solution {
    long long solve(vector<int> &a, int minValue, int maxValue) {
        long long res = 0;
        
        for (int l = 0, minR = 0, maxR = 0; l < a.size(); l++) {
            while (minR < l || minR < a.size() && a[minR] != minValue)
                minR++;
            if (minR == a.size())
                break;
            
            while (maxR < l || maxR < a.size() && a[maxR] != maxValue)
                maxR++;
            if (maxR == a.size())
                break;
            
            res += a.size() - max(minR, maxR);
        }
        
        return res;
    }
    
public:
    long long countSubarrays(vector<int> &a, int minValue, int maxValue) {
        vector<int> part;
        long long res = 0;
        
        for (int value : a) {
            if (minValue <= value && value <= maxValue) {
                part.push_back(value);
            } else {
                res += solve(part, minValue, maxValue);
                part.clear();
            }
        }
        res += solve(part, minValue, maxValue);
        
        return res;
    }
};