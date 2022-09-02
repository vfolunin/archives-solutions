class Solution {
public:
    bool canTransform(string &a, string &b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i])
                continue;
            
            if (b[i] == 'L') {
                if (a[i] == 'R')
                    return 0;
                
                int j = i;
                while (j < a.size() && a[j] == 'X')
                    j++;
                
                if (j == a.size() || a[j] == 'R')
                    return 0;
                
                swap(a[i], a[j]);
            } else if (b[i] == 'R') {
                return 0;
            } else if (a[i] == 'L') {
                return 0;
            } else {
                int j = i;
                while (j < a.size() && a[j] == 'R')
                    j++;
                
                if (j == a.size() || a[j] == 'L')
                    return 0;
                
                swap(a[i], a[j]);
            }
        }
        
        return 1;
    }
};