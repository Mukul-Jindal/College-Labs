#include <bits/stdc++.h>
using namespace std;
class X
{
    int a;

public:
    X(int j) { a = j; }
    int geta() { return a; }
};
int main()
{
    X ob = X(99);     // passes 99 to j
    cout << ob.geta(); // outputs 99
    return 0;
}
