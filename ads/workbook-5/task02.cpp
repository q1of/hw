#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    if (!getline(cin, line) || line.empty()) {
        line = "I love programming";
    }
    stringstream ss(line);
    string word;
    string longestWord = "";
    while (ss >> word) {
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }
    cout << longestWord << endl;
    return 0;
}
