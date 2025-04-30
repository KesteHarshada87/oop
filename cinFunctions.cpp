#include <iostream>
using namespace std;

int main() {
    char ch1, ch2;
    
    cout << "Enter a string: ";
    cin.get(ch1);  // Read the first character
    cin.get(ch2);  // Read the second character

    cin.ignore(1000, '\n'); // Ignore the rest of the input buffer
    
    cout << "First character: " << ch1 << endl;
    cout << "Second character: " << ch2 << endl;

    return 0;
}

