#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> sequence;
    int number;

    cout << "Enter integers (type -1 to finish):\n";

    while (cin >> number && number != -1) {
        sequence.push_back(number);
    }

    vector<int> sequence_copy = sequence;

    for (size_t i = 0; i < sequence.size() / 2; ++i) {
        swap(sequence[i], sequence[sequence.size() - 1 - i]);
    }

    cout << "\n[Method 1] Reversed manually: ";
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << "\n";

    for (size_t i = 0; i < sequence_copy.size() / 2; ++i) {
        swap(sequence_copy[i], sequence_copy[sequence_copy.size() - 1 - i]);
    }

    cout << "[Method 2] Reversed manually using swapping: ";
    for (int num : sequence_copy) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}

