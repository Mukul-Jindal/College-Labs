#include<bits/stdc++.h>
using namespace std;

class test{
    static int x;

public:
    static int y;
    void func(int x){
        cout<<"Value of static x is: "<<test::x<<endl;
        cout<<"Value of local x is: "<<x<<endl;
    }
};

// Static variable of class are to be initialized outside the class like this
int test::x = 10;
int test::y = 20;

int main()
{
    test t1;
    int x = 100;
    t1.func(x);
    cout<<"test::y: "<<test::y<<endl;
    return 0;
}