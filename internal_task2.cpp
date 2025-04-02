#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <regex>
using namespace std;

int main() {
    ifstream file("input.html");
    string line;
    map<string, int> htmlTags;
    regex tagRegex("<(.*?)>");

    while (getline(file, line)) {
        smatch match;
        while (regex_search(line, match, tagRegex)) {
            htmlTags[match.str(1)]++;
            line = match.suffix().str();
        }
    }

    cout << "HTML Tags:" << endl;
    for (auto const& pair : htmlTags) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}