#include <iostream>
#include <fstream>
using namespace std;

void bubbleSort(int A[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < (size - 1) - i; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 3) {
        cerr << "Usage: mysort input_file output_file" << endl;
        return 1;
    }

    // Open input file
    ifstream inFile(argv[1]);
    if (!inFile) {
        cerr << "Error: Could not open input file " << argv[1] << endl;
        return 1;
    }

    // Read numbers into array
    const int MAX_SIZE = 1000000;
    int numbers[MAX_SIZE];
    int count = 0;
    int num;

    while (inFile >> num && count < MAX_SIZE) {
        numbers[count++] = num;
    }

    inFile.close();

    // Sort the array
    cout << "Starting Array bubble sort with " << count << " items" << endl;
    bubbleSort(numbers, count);
    cout << "Ending bubble sort" << endl;

    // Write sorted numbers to output file
    ofstream outFile(argv[2]);
    if (!outFile) {
        cerr << "Error: Could not open output file " << argv[2] << endl;
        return 1;
    }

    for (int i = 0; i < count; i++) {
        outFile << numbers[i] << endl;
    }

    outFile.close();
    return 0;
}

