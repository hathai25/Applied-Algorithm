#include<iostream>

using namespace std;

int main() {
    //get input until # is entered
    string s;
    do {
        cin >> s;
        if (s == "#") continue;
    }
    while (s != "#");
    //print input s
    cout << s;
    return 0;


}