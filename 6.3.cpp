#include <iostream>
using namespace std;

class SortedMerger {
private:
    int* arr1;
    int* arr2;
    int size1;
    int size2;
    int* merged;
    int mergedSize;

public:
    SortedMerger(int s1, int s2) {
        size1 = s1;
        size2 = s2;
        arr1 = new int[size1];
        arr2 = new int[size2];
        mergedSize = size1 + size2;
        merged = new int[mergedSize];
    }

    void readArrays() {
        cout<<"Enter "<<size1<<" sorted elements for first array:\n";
        for (int i = 0; i<size1; ++i) {
            cin>>arr1[i];
        }

        cout<<"Enter "<<size2<<" sorted elements for second array:\n";
        for (int i = 0; i<size2; ++i) {
            cin>>arr2[i];
        }
    }

    void mergeArrays() {
        int i = 0, j = 0, k = 0;

        while (i<size1 && j<size2) {
            if (arr1[i]<arr2[j]) {
                merged[k++] = arr1[i++];
            } else {
                merged[k++] = arr2[j++];
            }
        }

        while (i<size1) {
            merged[k++] = arr1[i++];
        }

        while (j<size2) {
            merged[k++] = arr2[j++];
        }
    }

    void displayMergedArray() const {
        cout<<"Merged sorted array:\n";
        for (int i = 0; i<mergedSize; ++i) {
            cout<<merged[i]<<" ";
        }
        cout<<"\n";
    }

    ~SortedMerger() {
        delete[] arr1;
        delete[] arr2;
        delete[] merged;
    }
};


int main() {
    int size1, size2;

    cout<<"Enter size of first sorted array: ";
    cin>>size1;
    cout<<"Enter size of second sorted array: ";
    cin>>size2;


    SortedMerger merger(size1, size2);


    merger.readArrays();
    merger.mergeArrays();
    merger.displayMergedArray();


    return 0;
}
