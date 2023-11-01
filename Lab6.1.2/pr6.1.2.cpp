#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void Create(int* r, const int size, const int Low, const int High, int index = 0) {
    if (index < size) {
        r[index] = Low + rand() % (High - Low + 1);
        Create(r, size, Low, High, index + 1);
    }
}

void Print(int* r, const int size, int index = 0) {
    if (index < size) {
        cout << setw(5) << r[index];
        Print(r, size, index + 1);
    }
    else {
        cout << endl;
    }
}

int Sum(int* r, const int size, int& count, int index = 0) {
    if (index < size) {
        if (r[index] % 2 != 0 && r[index] % 13 != 0) {
            count += r[index];
        }
        Sum(r, size, count, index + 1);
    }
    return count;
}

void ReplaceWithZeros(int* r, const int size, int index = 0) {
    if (index < size) {
        if (r[index] % 2 == 0 || r[index] % 13 == 0) {
            r[index] = 0;
        }
        ReplaceWithZeros(r, size, index + 1);
    }
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    const int n = 23;
    int r[n];
    int Low = 4;
    int High = 68;
    Create(r, n, Low, High);

    cout << "Initial array: ";
    Print(r, n);

    int sum = 0;
    Sum(r, n, sum);
    ReplaceWithZeros(r, n);

    cout << "Modified array: ";
    Print(r, n);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (r[i] != 0) {
            count++;
        }
    }

    cout << "Number of elements: " << count << endl;
    cout << "Sum of elements: " << sum << endl;

    return 0;
}