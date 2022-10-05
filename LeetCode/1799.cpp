class Solution {
    void rec(vector<int> &a, vector<int> &gcds, int &res) {
        if (gcds.size() * 2 == a.size()) {
            vector<int> sortedGcds = gcds;
            sort(sortedGcds.begin(), sortedGcds.end());
            
            int sum = 0;
            for (int i = 0; i < sortedGcds.size(); i++)
                sum += (i + 1) * sortedGcds[i];
            res = max(res, sum);
            
            return;
        }
        
        int i = 0;
        while (!a[i])
            i++;
        int valueI = a[i];
        a[i] = 0;
        
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j]) {
                int valueJ = a[j];
                a[j] = 0;
                
                gcds.push_back(gcd(valueI, valueJ));
                rec(a, gcds, res);
                gcds.pop_back();
                
                a[j] = valueJ;
            }
        }
                    
        a[i] = valueI;
    }
    
public:
    int maxScore(vector<int> &a) {
        vector<int> gcds;
        int res = 0;
        rec(a, gcds, res);
        return res;
    }
};