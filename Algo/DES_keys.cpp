// Including dependancies
#include <iostream>
#include <string>
#include<vector>

using namespace std;
// Array to hold the 16 keys
string round_keys[16];

// Function to do a circular left shift by 1
string shift_left_once(string key_chunk) {
    string shifted = "";
    for (int i = 1; i < 28; i++) {
        shifted += key_chunk[i];
    }
    shifted += key_chunk[0];
    return shifted;
}

// Function to do a circular left shift by 2
string shift_left_twice(string key_chunk) {
    string shifted = "";
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < 28; j++) {
            shifted += key_chunk[j];
        }
        shifted += key_chunk[0];
        key_chunk = shifted;
        shifted = "";
    }
    return key_chunk;
}

void generate_keys(string key) {
    // The PC1 table
    int pc1[56] = {
            57, 49, 41, 33, 25, 17, 9,
            1, 58, 50, 42, 34, 26, 18,
            10, 2, 59, 51, 43, 35, 27,
            19, 11, 3, 60, 52, 44, 36,
            63, 55, 47, 39, 31, 23, 15,
            7, 62, 54, 46, 38, 30, 22,
            14, 6, 61, 53, 45, 37, 29,
            21, 13, 5, 28, 20, 12, 4
    };
    // The PC2 table
    int pc2[48] = {
            14, 17, 11, 24, 1, 5,
            3, 28, 15, 6, 21, 10,
            23, 19, 12, 4, 26, 8,
            16, 7, 27, 20, 13, 2,
            41, 52, 31, 37, 47, 55,
            30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53,
            46, 42, 50, 36, 29, 32
    };
    // 1. Compressing the key using the PC1 table
    string perm_key = "";
    for (int i = 0; i < 56; i++) {
        perm_key += key[pc1[i] - 1];
    }
    // 2. Dividing the result into two equal halves
    string left = perm_key.substr(0, 28);
    string right = perm_key.substr(28, 28);
    // Generating 16 keys
    for (int i = 0; i < 16; i++) {
        // 3.1. For rounds 1, 2, 9, 16 the key_chunks
        // are shifted by one.
        if (i == 0 || i == 1 || i == 8 || i == 15) {
            left = shift_left_once(left);
            right = shift_left_once(right);
        }
            // 3.2. For other rounds, the key_chunks
            // are shifted by two
        else {
            left = shift_left_twice(left);
            right = shift_left_twice(right);
        }
        // 4. The chunks are combined
        string combined_key = left + right;
        string round_key = "";
        // 5. Finally, the PC2 table is used to transpose
        // the key bits
        for (int i = 0; i < 48; i++) {
            round_key += combined_key[pc2[i] - 1];
        }
        round_keys[i] = round_key;
        cout << "Key " << i + 1 << ": " << round_keys[i] << endl;
    }

}

vector<int> shift_left_once2(vector<int> key_chunk) {
    vector<int> shifted;
    for (int i = 1; i < 28; i++) {
        shifted.push_back(key_chunk[i]);
    }
    shifted.push_back(key_chunk[0]);
    return shifted;
}

// Function to do a circular left shift by 2
vector<int> shift_left_twice2(vector<int> key_chunk) {
    vector<int> shifted;
    for (int i = 2; i < 28; i++) {
        shifted.push_back(key_chunk[i]);
    }
    shifted.push_back(key_chunk[0]);
    shifted.push_back(key_chunk[1]);
    return shifted;
}

void generate_keys2(vector<int> key) {
    // The PC1 table
    int pc1[56] = {
            57, 49, 41, 33, 25, 17, 9,
            1, 58, 50, 42, 34, 26, 18,
            10, 2, 59, 51, 43, 35, 27,
            19, 11, 3, 60, 52, 44, 36,
            63, 55, 47, 39, 31, 23, 15,
            7, 62, 54, 46, 38, 30, 22,
            14, 6, 61, 53, 45, 37, 29,
            21, 13, 5, 28, 20, 12, 4
    };
    // The PC2 table
    int pc2[48] = {
            14, 17, 11, 24, 1, 5,
            3, 28, 15, 6, 21, 10,
            23, 19, 12, 4, 26, 8,
            16, 7, 27, 20, 13, 2,
            41, 52, 31, 37, 47, 55,
            30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53,
            46, 42, 50, 36, 29, 32
    };
    // 1. Compressing the key using the PC1 table
    vector<int> actual_key;// = {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1,
    //                         0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1};

    for (int i = 0; i < 56; i++) {
        actual_key.push_back(i + 1);
    }
//    for (int i = 0; i < 56; i++) {
//        cout << actual_key[i] << " ";
//    }

//     2. Dividing the result into two equal halves
    vector<int> left;
    vector<int> right;
    for (int i = 0; i < 28; i++) {
        left.push_back(actual_key[i]);
    }
    for (int i = 28; i < 56; i++) {
        right.push_back(actual_key[i]);
    }
    // Generating 16 keys
    for (int i = 0; i < 16; i++) {
        // 3.1. For rounds 1, 2, 9, 16 the key_chunks
        // are shifted by one.
        if (i == 0 || i == 1 || i == 8 || i == 15) {
            left = shift_left_once2(left);
            right = shift_left_once2(right);
        }
            // 3.2. For other rounds, the key_chunks
            // are shifted by two
        else {
            left = shift_left_twice2(left);
            right = shift_left_twice2(right);
        }
//        // 4. The chunks are combined

        vector<int> combined_key = left;
        for (int i = 0; i < 28; i++) {
            combined_key.push_back(right[i]);
        }
        vector<int> round_key;
//        // 5. Finally, the PC2 table is used to transpose
//        // the key bits
        for (int i = 0; i < 48; i++) {
            round_key.push_back(combined_key[pc2[i] - 1]);
        }
        cout << "Key " << i + 1 << " : ";
//        cout << endl;
//
//        for (int i = 0; i < 48; i++) {
//            cout << round_key[i] << ' ';
//        }
//        cout << endl;

        sort(round_key.begin(), round_key.end());
        for (int i = 0; i < 48; i++) {
            cout << round_key[i] << ' ';
        }
        cout << endl;

        cout << "Missing bits ";
        for (int i = 0; i < 56; i++) {
            if (find(round_key.begin(), round_key.end(), i + 1) != round_key.end()) {
                // found it
            } else {
                cout << i << " ";
                // doesn't exist
            }
        }
        cout << endl;

    }

}

int main() {
    string key = "1010101010111011000010010001100000100111001101101100110011011101";
    vector<int> mykey;
    for (int i = 0; i < 64; i++) {
        mykey.push_back(i + 1);
    }
//
//    for (int i = 0; i < 64; i++) {
//        cout << mykey[i] << ' ';
//}

    generate_keys2(mykey);

}