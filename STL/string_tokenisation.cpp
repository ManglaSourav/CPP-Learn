#include<iostream>

#include<iostream>
#include<sstream>
#include<vector>
#include<cstring>

using namespace std;


int main() {

    string input;
    getline(cin, input);
    //"this is a sunny day"

    //create a string stream object
    stringstream ss(input);

    // >> and << operators
    string token;
    vector<string> tokens;
    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }

    //print all all tokens
    for (auto token: tokens) {
        cout << token << ",";
    }


//    this works on char array;
    char input2[1000];
    cin.getline(input2, 1000);

    //strtok()
    char *token2 = strtok(input2, " ");


    while (token2 != NULL) {
        cout << token2 << endl;
        token2 = strtok(NULL, " ");
    }

    return 0;
}