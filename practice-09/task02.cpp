#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in1("input1.txt");
    ifstream in2("input2.txt");
    string x, y;
    in1 >> x;
    in2 >> y;
    ofstream out("output.txt");
    if (x.find(y) != string::npos || y.find(x) != string::npos) {
        cout << "yes" << endl;
        if (out.is_open()) {
            out << "yes" << endl;
        }
    } else {
        cout << "no" << endl;
        if (out.is_open()) {
            out << "no" << endl;
        }
    }
    return 0;
}
