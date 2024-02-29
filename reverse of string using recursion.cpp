#include <stdio.h>
#include <string.h>

void reverse_string(char *s, int start, int end) {
    if (start >= end) {
        return;
    }
    
    // Swap characters at start and end indices
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    
    // Recursively reverse the substring
    reverse_string(s, start + 1, end - 1);
}

int main() {
    char str[] = "Hello, World!";
    int length = strlen(str);
    
    // Reverse the string
    reverse_string(str, 0, length - 1);
    
    printf("Reversed string: %s\n", str);  // Output: "!dlroW ,olleH"
    
    return 0;
}
