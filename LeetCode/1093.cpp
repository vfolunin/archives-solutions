class Solution {
public:
    vector<double> sampleStats(vector<int> &count) {
        vector<double> res(5);
        
        while (!count[res[0]])
            res[0]++;
        
        res[1] = count.size() - 1;
        while (!count[res[1]])
            res[1]--;
        
        long long totalCount = 0;
        for (int i = 0; i < count.size(); i++) {
            res[2] += (double)i * count[i];
            totalCount += count[i];
        }
        res[2] /= totalCount;
        
        long long curCount = 0;
        for (int i = 0; i < count.size(); i++) {
            if ((curCount + count[i]) * 2 >= totalCount) {
                res[3] = i;
                if (totalCount % 2 == 0 && (curCount + count[i]) * 2 == totalCount) {
                    do {
                        i++;
                    } while (!count[i]);
                    res[3] = (res[3] + i) / 2;
                }
                break;
            }
            curCount += count[i];
        }
        
        res[4] = max_element(count.begin(), count.end()) - count.begin();
        
        return res;
    }
};