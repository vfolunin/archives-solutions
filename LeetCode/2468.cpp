class Solution {
    bool can(int size, int partCount, int partCountLen, int limit) {
        for (int count = 9, len = 1; len <= partCountLen; count *= 10, len++) {
            int suffixLen = len + partCountLen + 3;
            if (suffixLen >= limit)
                return 0;
            size -= (limit - suffixLen) * count;
        }
        return size <= 0;
    }
    
    int getPartCountLen(int size, int limit) {
        for (int partCount = 9, partCountLen = 1; partCountLen < 6; partCount *= 10, partCountLen++)
            if (can(size, partCount, partCountLen, limit))
                return partCountLen;
        return -1;
    }
    
    int getPartCount(int size, int partCountLen, int limit) {
        int partCount = 0;
        
        for (int count = 9, len = 1; len < partCountLen; count *= 10, len++) {
            int suffixLen = len + partCountLen + 3;
            if (suffixLen >= limit)
                return 0;
            size -= (limit - suffixLen) * count;
            partCount += count;
        }
        
        int suffixLen = partCountLen * 2 + 3;
        partCount += (size + (limit - suffixLen) - 1) / (limit - suffixLen);
        
        return partCount;
    }
    
public:
    vector<string> splitMessage(string &s, int limit) {
        int partCountLen = getPartCountLen(s.size(), limit);        
        if (partCountLen == -1)
            return {};
        
        int partCount = getPartCount(s.size(), partCountLen, limit);
        
        vector<string> res;
        int from = 0;
        
        for (int i = 1; i <= partCount; i++) {
            stringstream ss;
            ss << "<" << i << "/" << partCount << ">";
            string suffix = ss.str();
            
            int partSize = limit - suffix.size();
            res.push_back(s.substr(from, partSize) + suffix);
            from += partSize;
        }
        
        return res;
    }
};