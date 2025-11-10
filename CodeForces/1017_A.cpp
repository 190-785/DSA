#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        string modernName = "";
        modernName += s1[0];
        modernName += s2[0];
        modernName += s3[0];
        cout << modernName << endl;
    }
    return 0;
}