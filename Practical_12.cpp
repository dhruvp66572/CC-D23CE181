#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isNumber(const string &s) {
    return !s.empty() && (isdigit(s[0]) || (s[0] == '-' && s.size() > 1));
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to evaluate an operation
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0;
        case '^': return pow(a, b);
    }
    return 0;
}

// Evaluate an expression given as a vector of tokens
string evaluateExpression(vector<string> &tokens) {
    stack<double> values;
    stack<char> ops;
    vector<string> optimizedTokens;

    for (size_t i = 0; i < tokens.size(); i++) {
        if (isNumber(tokens[i])) {
            values.push(stod(tokens[i]));
        } else if (isOperator(tokens[i][0])) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i][0])) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i][0]);
        } else {
            optimizedTokens.push_back(tokens[i]);
        }
    }

    while (!ops.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    if (!values.empty()) optimizedTokens.insert(optimizedTokens.begin(), to_string(values.top()));
    string result;
    for (const string &token : optimizedTokens) {
        result += token + " ";
    }
    return result;
}

// Tokenizes the input expression
vector<string> tokenize(const string &expr) {
    vector<string> tokens;
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    string input;
    cout << "Enter an arithmetic expression: ";
    getline(cin, input);
    
    vector<string> tokens = tokenize(input);
    string optimizedExpr = evaluateExpression(tokens);
    
    cout << "Optimized Expression: " << optimizedExpr << endl;
    return 0;
}

// int main() {
//     // Sample expressions
//     std::vector<std::string> expressions = {
//         "5 + x - 3 * 2",
//         "2 + 3 * 4 - 1",
//         "x + ( 3 * 5 ) - 2",
//         "( 22 / 7 ) * r * r"
//     };

//     for (const auto& expression : expressions) {
//         std::string optimized = constantFolding(expression);
//         std::cout << "Input: " << expression << std::endl;
//         std::cout << "Output: " << optimized << std::endl << std::endl;
//     }

//     return 0;
// }
