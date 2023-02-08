class Solution {
    bool can(vector<int> &damage, int armor, long long hp) {
        int maxIndex = max_element(damage.begin(), damage.end()) - damage.begin();

        for (int i = 0; i < damage.size(); i++) {
            int dmg = damage[i];
            if (i == maxIndex)
                dmg = max(0, dmg - armor);

            if (hp <= dmg)
                return 0;
            
            hp -= dmg;
        }

        return 1;
    }

public:
    long long minimumHealth(vector<int> &damage, int armor) {
        long long l = -1, r = 1;
        
        while (!can(damage, armor, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(damage, armor, m))
                r = m;
            else
                l = m;
        }

        return r;
    }
};