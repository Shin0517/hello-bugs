class Solution {
    public:
        bool isValid(string s) {
            std::stack<char> stack;
            for (char ch : s){
                if (ch == '(' || ch == '[' || ch == '{') {
                    stack.push(ch);
                } else {
                    if (stack.empty()) return false;
                    
                    char top = stack.top();
                    if ((top == '(' && ch == ')') ||
                        (top == '[' && ch == ']') ||
                        (top == '{' && ch == '}')) {
                        stack.pop();
                    } else {
                        return false;
                    }
                }
            }
            return stack.empty();
        }
};