class Solution {
    bool peek(string &s, int from, const string &chars) {
        return from + chars.size() <= s.size() && s.substr(from, chars.size()) == chars;
    }

    bool expect(string &s, int &from, char c) {
        if (from == s.size() || s[from] != c)
            return 0;
        from++;
        return 1;
    }

    bool expect(string &s, int &from, const string &chars) {
        for (char c : chars)
            if (!expect(s, from, c))
                return 0;
        return 1;
    }
    
    bool readCData(string &s, int &from) {
        if (!expect(s, from, "<![CDATA["))
            return 0;
        
        while (from < s.size() && !peek(s, from, "]]>"))
            from++;
        
        if (!expect(s, from, "]]>"))
            return 0;
        
        return 1;
    }

    bool readTag(string &s, int &from) {
        if (!expect(s, from, '<'))
            return 0;

        string tag;
        while (from < s.size() && isupper(s[from])) {
            tag += s[from];
            from++;
        }

        if (tag.size() < 1 || tag.size() > 9)
            return 0;

        if (!expect(s, from, '>'))
            return 0;
        
        string closingTag = "</" + tag + ">";
        while (from < s.size() && !peek(s, from, closingTag)) {
            if (peek(s, from, "<![CDATA[")) {
                if (!readCData(s, from))
                    return 0;
            } else if (s[from] == '<') {
                if (!readTag(s, from))
                    return 0;
            } else {
                from++;
            }
        }
        
        if (!expect(s, from, closingTag))
            return 0;

        return 1;
    }

public:
    bool isValid(string &s) {
        int from = 0;
        return readTag(s, from) && from == s.size();
    }
};