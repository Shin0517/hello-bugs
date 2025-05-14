class Solution {
    public:
        bool isValid(string s) {
            std::stack<char> parenthesesStack;
            for (int i = 0; i < s.size(); i++){
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    parenthesesStack.push(s[i]);
                } else if (!parenthesesStack.empty() && (
                            (parenthesesStack.top() == '(' && s[i] == ')') ||
                            (parenthesesStack.top() == '[' && s[i] == ']') ||
                            (parenthesesStack.top() == '{' && s[i] == '}'))) {
                    parenthesesStack.pop();
                } else {
                    return false;
                }
            }
            return parenthesesStack.empty();
        }
    };