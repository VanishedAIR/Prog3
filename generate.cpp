#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 4) {
        cerr << "Usage: generate COUNT MIN MAX" << endl;
        return 1;
    }

    // Parse command line arguments
    int count = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    // Validate arguments
    if (count <= 0 || min >= max) {
        cerr << "Error: Invalid arguments" << endl;
        cerr << "COUNT must be positive and MIN must be less than MAX" << endl;
        return 1;
    }

    // Initialize random seed
    srand(time(NULL));

    // Open output file
    ofstream outFile("numbers.dat");
    if (!outFile) {
        cerr << "Error: Could not open numbers.dat for writing" << endl;
        return 1;
    }

    // Generate and write random numbers
    int range = max - min + 1;
    for (int i = 0; i < count; i++) {
        int randomNum = min + (rand() % range);
        outFile << randomNum << endl;
    }

    outFile.close();
    return 0;
}