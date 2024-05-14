#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float n;
    cin >> n;
    cout 
        << setiosflags(ios::fixed)
        << setprecision(10)
        << 1.0 / (n * (n - 1) / 2)
        << endl;
    return 0;
}