#include <iostream>
using namespace std;

int binomialCoeff(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

void printPascal(int n)
{
    for (int line = 0; line < n; line++) {
        for (int i = 0; i <= line; i++)
            cout << " " << binomialCoeff(line, i);
        cout << "\n";
    }
}

int main()
{
    int jumlah = 3;
    printPascal(jumlah);
    return 0;
}
