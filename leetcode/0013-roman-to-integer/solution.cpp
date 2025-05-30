class Solution {
    public:
        int charToNum(char a) {
            switch(a) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
            }
        }
    
        int romanToInt(string s) {
            int num = 0;
    
            for (int i = 0; i < s.length(); ++i) {
                if (charToNum(s[i]) < charToNum(s[i + 1]) && i + 1 < s.length()){
                    num -= charToNum(s[i]);
                } else {
                    num += charToNum(s[i]);
                }
            }
    
            return num;
        }
    };