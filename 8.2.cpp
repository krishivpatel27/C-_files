#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence:\n";
    getline(cin, sentence);

    map<string, int> wordFrequency;
    istringstream stream(sentence);
    string word;

    while (stream >> word) {
        bool found = false;

        if (wordFrequency.find(word) != wordFrequency.end()) {
            found = true;
        }

        if (found) {
            wordFrequency[word]++;
        } else {
            wordFrequency[word] = 1;
        }
    }

    cout << "\nWord Frequency Distribution:\n";
    for (auto it = wordFrequency.begin(); it != wordFrequency.end(); ++it) {
        cout << it->first << ": " << it->second << '\n';
    }

    return 0;
}

