#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    const int MAX_INPUT = 1000;
    const int MAX_WORDS = 100;
    const int MAX_LEN = 50;

    char paragraph[MAX_INPUT];
    char* words[MAX_WORDS];
    int counts[MAX_WORDS] = {0};
    int total = 0;

    cin.getline(paragraph, MAX_INPUT);

    char word[MAX_LEN];
    int w = 0;

    for (int i = 0; ; i++) {
        char ch = paragraph[i];

        if (isalpha(ch)) {
            word[w++] = tolower(ch);
        }
        if (!isalpha(ch) || ch == '\0') {
            if (w > 0) {
                word[w] = '\0';
                bool found = false;

                for (int j = 0; j < total; j++) {
                    if (strcmp(word, words[j]) == 0) {
                        counts[j]++;
                        found = true;
                        break;
                    }
                }

                if (!found && total < MAX_WORDS) {
                    words[total] = new char[strlen(word) + 1];
                    strcpy(words[total], word);
                    counts[total] = 1;
                    total++;
                }

                w = 0;
            }
            if (ch == '\0') break;
        }
    }

    for (int i = 0; i < total; i++) {
        cout << words[i] << ": " << counts[i] << endl;
        delete[] words[i];
    }

    return 0;
}
