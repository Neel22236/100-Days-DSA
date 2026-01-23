/*Problem: A secret system stores code names in forward order. 
To display them in mirror format, you must transform the given code name 
so that its characters appear in the opposite order.*/

#include <stdio.h>
#include <string.h>
void reverseString(char str[]) {
    int length = strlen(str);
    char reversed[length + 1]; // +1 for null terminator

    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i]; // Reverse the string
    }
    reversed[length] = '\0'; // Null terminate the reversed string

    printf("Reversed code name: %s\n", reversed);
}