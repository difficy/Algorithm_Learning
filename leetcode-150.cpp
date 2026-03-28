class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        for (auto to : tokens) {
            if (to != "*" && to != "/" && to != "+" && to != "-") {
                st.push(stoi(to));
            }
            else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (to == "*") {
                    st.push(a * b);
                }
                else if (to == "/") {
                    st.push(b / a);
                }
                else if (to == "+") {
                    st.push(a + b);
                }
                else {
                    st.push(b - a);
                }
            }
        }
        return st.top();
    }
};