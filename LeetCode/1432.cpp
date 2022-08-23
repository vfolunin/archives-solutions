class Solution {
public:
    int maxDiff(int n) {
        string s = to_string(n);
        int res = 0;
        
        for (int aFrom = 0; aFrom < 10; aFrom++) {
            for (int aTo = 0; aTo < 10; aTo++) {
                string a = s;
                replace(a.begin(), a.end(), aFrom + '0', aTo +'0');
                
                if (a[0] == '0')
                    continue;
                
                for (int bFrom = 0; bFrom < 10; bFrom++) {
                    for (int bTo = 0; bTo < 10; bTo++) {
                        string b = s;
                        replace(b.begin(), b.end(), bFrom + '0', bTo +'0');
                        
                        if (b[0] == '0')
                            continue;
                        
                        res = max(res, stoi(a) - stoi(b));
                    }
                }
            }
        }
        
        return res;
    }
};