/*
This code implements the paging and offset numbers. 
When an integer is given as inp, It first checks whether the entered number is negative or not.
 If it is not negative then it converts to b format and takes the right most 11 bits to convert to decimal form. 
 This right most 11 bits is offset value. 
 The remaining value other than 11 bits from the left most is the page number. 
 This code is very well implemented to even handle the negative cases. 
*/


#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>

using namespace std;

string to_bin(unsigned int num) {
    return bitset<32>(num).to_string(); // Converts the decimal to binary format.
}

unsigned int bin_to_dec(const string &b) {
    unsigned int d = 0;
    for (char dgt : b) {
        d = d * 2 + (dgt - '0');    // Converts the binary form to Decimal form.
    }
    return d;
}

int main(int argc, char *argv[]) {
    // Checking if a command-line argument is provided
    if (argc != 2) {
        cout << "Usage: " << argv[0] << endl;
        return 1;
    }

    // Converting argument to integer
    char *end;
    long inp = strtol(argv[1], &end, 10);

    // Check for valid inp
    if (*end != '\0' || inp <= 0) {
        cout << "Please provide a valid virtual address." << endl;
        return 1;
    }

    unsigned int num = static_cast<unsigned int>(inp);
    string b = to_bin(num);

    string o_bin = b.substr(b.length() - 11); // Rightmost 11 digits
    string p_bin = b.substr(0, b.length() - 11); // Remaining digits

    unsigned int o_dec = bin_to_dec(o_bin);
    unsigned int p_dec = bin_to_dec(p_bin);

    cout << "Page number = " << p_dec << endl;
    cout << "Offset = " << o_dec << endl;
    return 0;
}
