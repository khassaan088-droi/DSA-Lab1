#include <iostream>
using namespace std;

int naiveSearch(const char text[], const char pattern[]) {
    if (pattern[0] == '\0') 
     return 0;
    for (int i = 0; text[i] != '\0'; i++) {
        int j = 0;
        while (text[i + j] == pattern[j] && pattern[j] != '\0') {
            j++;
        }
        if (pattern[j] == '\0') return i;
    }

    return -1;
}

int main() {
    cout << naiveSearch("hello world", "hello") << endl; 
    cout << naiveSearch("hello world", "world") << endl; 
    cout << naiveSearch("hello world", "cpp") << endl;   
    cout << naiveSearch("hello world", "") << endl;      
    return 0;
}