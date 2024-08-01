#include <iostream>
#include <cstring>
using namespace std;

class STRING {
    static const int MAX_LEN = 100; // Maximum length of the string
    char str[MAX_LEN];
    int len;

public:
    // Default constructor
    STRING() : len(0) {
        str[0] = '\0'; // Initialize the string with an empty string
    }

    // Constructor to initialize from a C-string
    STRING(const char *s) {
        len = strlen(s);
        if (len >= MAX_LEN) {
            len = MAX_LEN - 1; // Ensure the string fits within the array
        }
        strncpy(str, s, len);
        str[len] = '\0';
    }

    // Get data from user
    void getData() {
        char temp[MAX_LEN];
        cout << "Enter the string: ";
        cin >> temp;
        len = strlen(temp);
        if (len >= MAX_LEN) {
            len = MAX_LEN - 1; // Ensure the string fits within the array
        }
        strncpy(str, temp, len);
        str[len] = '\0';
    }

    // Display the string
    void displayData() const {
        if (str[0] != '\0') {
            cout << "The string is: " << str << endl;
        } else {
            cout << "The string is empty." << endl;
        }
    }

    // Overload + operator for string concatenation
    STRING operator+(const STRING &s) const {
        STRING temp;
        temp.len = len + s.len;
        if (temp.len >= MAX_LEN) {
            temp.len = MAX_LEN - 1; // Ensure the string fits within the array
        }
        strncpy(temp.str, str, len);
        strncpy(temp.str + len, s.str, temp.len - len);
        temp.str[temp.len] = '\0';
        return temp;
    }

    // Overload = operator for string assignment
    STRING& operator=(const STRING &s) {
        if (this != &s) { // Check for self-assignment
            len = s.len;
            if (len >= MAX_LEN) {
                len = MAX_LEN - 1; // Ensure the string fits within the array
            }
            strncpy(str, s.str, len);
            str[len] = '\0';
        }
        return *this;
    }

    // Overload == operator for string comparison
    bool operator==(const STRING &s) const {
        return strcmp(str, s.str) == 0;
    }
};

int main() {
    STRING s1, s2, s3, s4;
    s1.getData();
    s2.getData();
    s3 = s1 + s2;
    s3.displayData();
    s4 = s1;
    s4.displayData();
    if (s1 == s2) {
        cout << "The strings are equal." << endl;
    } else {
        cout << "The strings are not equal." << endl;
    }
    return 0;
}
