#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line = "I love programming";
    stringstream ss(line);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    for (int i = static_cast<int>(words.size()) - 1; i >= 0; i--) {
        cout << words[i] << (i > 0 ? " " : "");
    }
    cout << endl;

    return 0;
}
