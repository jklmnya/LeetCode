#include "headers/CoreMinial.h"


/**
 *              计算后缀表达式
 *  1. 若遇到数字，则直接压栈
 *  2. 遇到操作符，则从栈中弹出两个元素；将两个元素运算的结果压入栈中
 *  3. 注意若是‘-’ 或者是 ‘/’，则要交换两个数字的位置
 *  4. eg —— 1-2 --> 1 2 -
 * 
 * */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int op1 = 0, op2 = 0;
        for (auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                op1 = st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                if (token == "+") {
                    st.push(op1 + op2);
                } else if (token == "-") {
                    st.push(op2 - op1);
                } else if (token == "*") {
                    st.push(op1 * op2);
                } else {
                    st.push(op2 / op1);
                }
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};