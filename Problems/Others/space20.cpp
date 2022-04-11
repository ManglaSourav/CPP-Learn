#include<iostream>
#include<string>

using namespace std;

//string replace_str(string str) {
//
//    string rep_str = "%20";
//    int index = 0;
//    int count = 0;
//    while (index != -1) {
//        index = str.find(" ", index + 1);
//        if (index > 0) {
//            count++;
//        }
//    }
//    cout << str.length();
//    str.resize(str.length() + (2 * count));
//    cout << str.length();
//
//    return str;
//}

void replace_str(char *str) {

    int spaces = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            spaces++;
        }
    }
    int old_length = strlen(str);
    int new_len = old_length + 2 * spaces;
    str[new_len] = '\0';
    for (int i = old_length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[new_len - 1] = '0';
            str[new_len - 2] = '2';
            str[new_len - 3] = '%';
            new_len = new_len - 3;
        } else {
            new_len--;
            str[new_len] = str[i];
        }
    }
}

int main() {
    char mystring[1000] = "I am sourav mangla";
    replace_str(mystring);
    cout << mystring;
    return 0;
}

