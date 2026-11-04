#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool is_removed(char c) {
    char lower = tolower(c);
    string targets = "useragreement";
    for (char t : targets) {
        if (lower == t) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    char c;
    while (in.get(c)) {
        if (!is_removed(c)) {
            out.put(c);
        }
    }
    return 0;
}
