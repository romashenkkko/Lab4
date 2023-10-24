#include <stdio.h>
#include <string.h>
#include <ctype.h>

void oppositeCase(char* str) {
    int ln = strlen(str);

    for (int i = 0; i < ln; i++) {
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }
}

void upperCase() {
    char input[1000];

    printf("Enter a sentence to be uppercased: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    oppositeCase(input);

    printf("Sentence with characters in opposite case: %s\n", input);
}

/////////////
int isRotation(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2 || len1 == 0) {
        return 0;
    }

    char combined[2 * len1 + 1];
    strcpy(combined, str1);
    strcat(combined, str1);

    if (strstr(combined, str2) != NULL) {
        return 1;
    } else {
        return 0;
    }
}

int countPunctuationMarks(char str[]) {
    int count = 0;
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        if (ispunct(str[i])) {
            count++;
        }
    }

    return count;
}

void reverseString(char str[]) {
    int length = strlen(str);
    char temp;
    int j, i;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char first_string[1000];
    char second_string[1000];
    char third_string[1000];

    printf("Enter the first string: ");
    fgets(first_string, sizeof(first_string), stdin);

    printf("Enter the second string: ");
    fgets(second_string, sizeof(second_string), stdin);

    printf("Enter the third string: ");
    fgets(third_string, sizeof(third_string), stdin);
    first_string[strcspn(first_string, "\n")] = '\0';
    second_string[strcspn(second_string, "\n")] = '\0';
    third_string[strcspn(third_string, "\n")] = '\0';

    int result = isRotation(first_string, second_string);
    int punctuationCount = countPunctuationMarks(third_string);

    if (result) {
        printf("The second string is a rotation of the first string.\n");
    } else {
        printf("The second string is not a rotation of the first string.\n");
    }

    printf("Number of punctuation marks in the third string: %d\n", punctuationCount);
    upperCase();

    return 0;
}
