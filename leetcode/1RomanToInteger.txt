class Solution {
public:
    int valueOfChar(char ch) {
         if (ch=='I')
             return 1;
        else if(ch=='V') {
            return 5;
        }else if(ch=='X') {
            return 10;
        }else if(ch=='L') {
            return 50;
        }else if(ch=='C') {
            return 100;
        }else if(ch=='D') {
            return 500;
        }else if(ch=='M') {
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int result = 0;
        size_t i=0;
        for(i=0;i<s.length()-1;i++) {
            char c = s[i];
            char n = s[i+1];
            if (c=='I' && n=='V') {
                result += 4; i++;
            }else if (c=='I' && n=='X') {
                result += 9;i++;
            }else if (c=='X' && n=='L') {
                result += 40;i++;
            }else if (c=='X' && n=='C') {
                result += 90;i++;
            }else if (c=='C' && n=='D') {
                result += 400;i++;
            }else if (c=='C' && n=='M') {
                result += 900;i++;
            } else {
                result += valueOfChar(c);
            }
        }
        if (i<s.length()) {
          result += valueOfChar(s[s.length()-1]);
        }
        return result;
    }
    
   
};



///////////////////////////////////////////

class Solution {
public:
    
    void initMap() {
        m_map['I'] = 1;
        m_map['V'] = 5;
        m_map['X'] = 10;
        m_map['L'] = 50;
        m_map['C'] = 100;
        m_map['D'] = 500;
        m_map['M'] = 1000;
    }
    int romanToInt(string s) {
        initMap();
        int result = 0;
        size_t i=0;
        for(i=0;i<s.length()-1;i++) {
            char c = s[i];
            char n = s[i+1];
            if (c=='I' && n=='V') {
                result += 4; i++;
            }else if (c=='I' && n=='X') {
                result += 9;i++;
            }else if (c=='X' && n=='L') {
                result += 40;i++;
            }else if (c=='X' && n=='C') {
                result += 90;i++;
            }else if (c=='C' && n=='D') {
                result += 400;i++;
            }else if (c=='C' && n=='M') {
                result += 900;i++;
            } else {
                result += m_map[c];
            }
        }
        if (i<s.length()) {
          result += m_map[s[s.length()-1]];
        }
        return result;
    }
    
   private:
    map<char,int> m_map;
};