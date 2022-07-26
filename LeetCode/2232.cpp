class Solution {
public:
    string minimizeResult(string &s) {
        int plus = s.find('+');
        string sa = s.substr(0, plus);
        string sb = s.substr(plus + 1);
        
        long long bestValue = 1e18;
        int bestLSize, bestRSize;
        
        for (int lSize = 0; lSize < sa.size(); lSize++) {
            long long l = lSize ? stoll(sa.substr(0, lSize)) : 1LL;
            long long a = stoll(sa.substr(lSize));
            
            for (int rSize = 0; rSize < sb.size(); rSize++) {
                long long b = stoll(sb.substr(0, sb.size() - rSize));
                long long r = rSize ? stoll(sb.substr(sb.size() - rSize)) : 1LL;
                
                long long value = l * (a + b) * r;
                if (bestValue > value) {
                    bestValue = value;
                    bestLSize = lSize;
                    bestRSize = rSize;
                }
            }
        }
        
        s.insert(s.size() - bestRSize, 1, ')');
        s.insert(bestLSize, 1, '(');
        return s;
    }
};