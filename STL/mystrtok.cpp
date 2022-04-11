#include<iostream>
#include<cstring>


using namespace std;

char *mystrtok(char *str, char delim) {

    static char *input = NULL;

    if (str != NULL) {
        input = str;
    }

    if (input == NULL) {
        return NULL;
    }

    char *token = new char[strlen(input) + 1];
    int i = 0;
    for (; input[i] != '\0'; i++) {
        if (input[i] != delim) {
            token[i] = input[i];
        } else {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }
    token[i] = '\0';
    input = NULL;
    return token;
}


int main() {

    cout << '2' - '0';
    return 0;
    char str[1000];
    cout << "Enter a line:- ";
    cin.getline(str, 1000);


    char *token = mystrtok(str, ' ');

    while (token != NULL) {
        cout << token << endl;
        token = mystrtok(NULL, ' ');
    }

    return 0;
}