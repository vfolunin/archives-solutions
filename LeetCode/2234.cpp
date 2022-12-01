class Solution {
    long long getSum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
    long long needFlowers(vector<long long> &p, int count) {
        long long lastFlowers = getSum(p, count - 1, count - 1);
        long long totalFlowers = getSum(p, 0, count - 1);
        return count * lastFlowers - totalFlowers;
    }
    
    long long getMinFlowers(vector<long long> &p, long long newFlowers) {
        if (p.empty())
            return 0;
        
        int l = 1, r = p.size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (needFlowers(p, m) <= newFlowers)
                l = m;
            else
                r = m;
        }
        
        int count = l;
        long long lastFlowers = getSum(p, count - 1, count - 1);
        long long additionalFlowers = newFlowers - needFlowers(p, count);
        return lastFlowers + additionalFlowers / count;
    }
    
public:
    long long maximumBeauty(vector<int> &flowers, long long newFlowers, long long target, long long full, long long partial) {
        sort(flowers.begin(), flowers.end());
        
        long long fullCount = 0;
        while (!flowers.empty() && flowers.back() >= target) {
            fullCount++;
            flowers.pop_back();
        }
        
        vector<long long> p = { flowers.begin(), flowers.end() };
        partial_sum(p.begin(), p.end(), p.begin());

        long long fullBonus = full * fullCount;
        long long partialBonus = partial * min(getMinFlowers(p, newFlowers), target - 1);
        long long res = fullBonus + partialBonus;
        
        for (fullCount++; !flowers.empty(); fullCount++) {
            newFlowers -= target - flowers.back();
            if (newFlowers < 0)
                break;
            flowers.pop_back();
            p.pop_back();
            
            fullBonus = full * fullCount;
            partialBonus = partial * min(getMinFlowers(p, newFlowers), target - 1);
            res = max(res, fullBonus + partialBonus);
        }
        
        return res;
    }
};