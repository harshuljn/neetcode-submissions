class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int,int)>> ops = {
            {"+", [](int a, int b){ return a + b; }},
            {"-", [](int a, int b){ return a - b; }},
            {"*", [](int a, int b){ return a * b; }},
            {"/", [](int a, int b){ return a / b; }}
        };

        stack<int> st;

        for (const string& token : tokens) {
            if (ops.count(token)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(ops[token](a, b));
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
