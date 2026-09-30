class Solution {
public:
    vector<bool> validSubarrays(vector<int> &a, int targetCount, int queryL, int queryR, int queryCount) {
        vector<pair<int, int>> rRange(a.size(), { -1, -1 });
        map<int, int> count1, count2;
        for (int l = 0, r1 = 0, r2 = 0; l < a.size(); l++) {
            while (r1 < a.size() && count1.size() < targetCount) {
                count1[a[r1]]++;
                r1++;
            }
            while (r2 < a.size() && count2.size() <= targetCount) {
                count2[a[r2]]++;
                r2++;
            }

            rRange[l] = { r1, r2 - 1 };

            if (!--count1[a[l]])
                count1.erase(a[l]);
            if (!--count2[a[l]])
                count2.erase(a[l]);
        }

        unordered_set<int> randomValues;
        unordered_map<int, int> randomMapping;
        static minstd_rand generator;
        for (int value : a) {
            if (randomMapping.contains(value))
                continue;
            while (1) {
                int randomValue = generator();
                if (!randomValues.contains(randomValue)) {
                    randomValues.insert(randomValue);
                    randomMapping[value] = randomValue;
                    break;
                }
            }
        }

        vector<int> prefixXor(a.size());
        for (int i = 0; i < a.size(); i++)
            prefixXor[i] = randomMapping[a[i]] ^ (i ? prefixXor[i - 1] : 0);
        
        vector<bool> res(queryCount);
        for (int i = 0; i < queryCount; i++) {
            res[i] = rRange[queryL].first <= queryR && queryR <= rRange[queryL].second &&
                     !(prefixXor[queryR] ^ (queryL ? prefixXor[queryL - 1] : 0));

            int modifier = res[i] ? queryL + queryR : queryR - queryL;
            queryL = (queryL ^ modifier) % a.size();
            queryR = (queryR ^ modifier) % a.size();
            if (queryL > queryR)
                swap(queryL, queryR);
        }
        return res;
    }
};