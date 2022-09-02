class Solution {
public:
    vector<string> removeComments(vector<string> &lines) {
        vector<string> res;
        
        bool inBlock = 0;
        string resLine;
        
        for (string &line : lines) {
            for (int i = 0; i < line.size(); i++) {
                if (inBlock) {
                    if (i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/') {
                        inBlock = 0;
                        i++;
                        continue;
                    }
                } else {
                    if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/')
                        break;
                    
                    if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*') {
                        inBlock = 1;
                        i++;
                        continue;
                    }

                    resLine += line[i];
                }
            }
            
            if (!inBlock && !resLine.empty()) {
                res.push_back(resLine);
                resLine.clear();
            }
        }
        
        return res;
    }
};