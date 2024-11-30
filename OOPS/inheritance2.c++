#include<bits/stdc++.h>
using namespace std;

class base{
protected:
    int i;
public:
    base(int x){
        i = x;
        cout<<"Constructing base class\n";
    }
    ~base(){
        cout<<"Destructing base class\n";
    }
};

class derived: public base{
    int j;
public:
    derived(int x, int y): base(y){
        j = x;
        cout<<"Constructing derived class\n";
    };
    ~derived(){
        cout<<"Destructing derived class\n";
    }
    void show(){
        cout<<i<<" "<<j<<endl;
    }
};

int main()
{
    derived ob(3,4);
    ob.show();
    return 0;
}