#include <vector>
#include <string>
#include <stack>

#include "gtest/gtest.h"

using namespace std;

// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/?fbclid=IwAR1ELnj87j9bLdIIOatPq595iDYISE1rOH99AIiWEIdA72jBTwVuPfw6XPE

class Solution 
{
    public:
        bool isOperand(string& operand) {
            if (operand == "+" || operand == "-" || operand == "*" || operand == "/") {
                return true;
            }
            else {
                return false;
            }
        }
        int operate(int val1, string& operand, int val2) {
            if (operand == "+") {
                return val1 + val2;
            }
            else if (operand == "-") {
                return val1 - val2;
            }
            else if (operand == "*") {
                return val1 * val2;
            }
            else if (operand == "/") {
                return val1 / val2;
            }
        }

        int evalRPN(vector<string>& tokens) {
            vector<string>::iterator itr;
            stack<string> tokenstack;
            for (itr = tokens.begin(); itr != tokens.end(); itr++) {
                string token = *itr; 
                if (isOperand(token)) {
                    string val2 = tokenstack.top();
                    tokenstack.pop();
                    string val1 = tokenstack.top();
                    tokenstack.pop();
                    int value = operate(stoi(val1), token, stoi(val2));
                    tokenstack.push(to_string(value));
                }
                else { // value
                    tokenstack.push(token);
                }
            }
            return stoi(tokenstack.top());
        }
};

TEST(EvaluateRPN, HandlesPositiveInput)
{
    Solution solution;
    vector<string> input;
    input = {"2", "1", "+", "3", "*"};
    EXPECT_EQ(solution.evalRPN(input) , 9);

    input = {"4", "13", "5", "/", "+"};
    EXPECT_EQ(solution.evalRPN(input) , 6);

    input = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    EXPECT_EQ(solution.evalRPN(input) , 22);

}
