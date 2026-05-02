class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string op: tokens) {
            if(op == "+" || op == "-" || op == "*" || op == "/") {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if(op == "+") s.push(a+b);
                else if(op == "-") s.push(a-b);
                else if(op == "*") s.push(a*b);
                else if(op == "/") s.push(a/b);
            } else {
                s.push(stoi(op));
            }
        }
        return s.top();
    }
};
