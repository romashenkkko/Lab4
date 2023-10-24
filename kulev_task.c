#include <stdio.h>
#include <string.h>

int main() {
    char user_sentence[1000];
    printf("Enter a sentence: ");
    fgets(user_sentence, sizeof(user_sentence), stdin);

   
    char sentence_copy[1000];
    strcpy(sentence_copy, user_sentence);

    char *separator = strtok(sentence_copy, " ,\n");

    char unique_words[1000][50];
    int word_counter[1000] = {0};
    int unique_word_count = 0;

    while (separator != NULL) {
        int is_unique = 1;

        int len = strlen(separator);
        if (separator[len - 1] == '\n') {
            separator[len - 1] = '\0';
        }

        for (int i = 0; i < unique_word_count; i++) {
            if (strcmp(separator, unique_words[i]) == 0) {
                word_counter[i]++;
                is_unique = 0;
                break;
            }
        }

        if (is_unique) {
            strcpy(unique_words[unique_word_count], separator);
            word_counter[unique_word_count]++;
            unique_word_count++;
        }

        separator = strtok(NULL, " ,\n");
    }

    printf("Unique words in the sentence: ");
    for (int i = 0; i < unique_word_count; i++) {
        printf("%s ", unique_words[i]);
    }
    printf("\n");

    return 0;
}
