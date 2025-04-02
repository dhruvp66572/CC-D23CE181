#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main() {
    ifstream file("input.c");
    string line;
    map<string, int> identifiers;
    map<string, int> keywords;
    map<string, int> operators;
    map<string, int> numbers;
    map<string, int> others;

    string keyword_list[] = {"int", "char", "return", "if", "else", "for", "while"};
    string operator_list[] = {"+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">="};

    while (getline(file, line)) {
        string word = "";
        for (char c : line) {
            if (isalnum(c) || c == '_') {
                word += c;
            } else {
                if (!word.empty()) {
                    
                    bool is_keyword = false;
                    bool is_operator = false;

                    for (string keyword : keyword_list) {
                        if (word == keyword) {
                            is_keyword = true;
                            break;
                        }
                    }
                    for (string op : operator_list) {
                        if (word == op) {
                            is_operator = true;
                            break;
                        }
                    }
                    if (is_keyword) {
                        keywords[word]++;
                    } else if (is_operator) {
                        operators[word]++;
                    } else if (isalpha(word[0])) {
                        identifiers[word]++;
                    } else {
                        numbers[word]++;
                    }
                    word = "";
                }
                if (!isspace(c)) {
                    string special_char(1, c);
                    others[special_char]++;
                }
            }
        }
        
    }

    cout << "Identifiers:" << endl;
    for (auto const& pair : identifiers) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "Keywords:" << endl;
    for (auto const& pair : keywords) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "Operators:" << endl;
    for (auto const& pair : operators) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "Numbers:" << endl;
    for (auto const& pair : numbers) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "Others:" << endl;
    for (auto const& pair : others) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
