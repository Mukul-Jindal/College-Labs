#include<bits/stdc++.h>
using namespace std;

// Normal friend function
class myClass{
    int x, y;
public:
    friend int sum(myClass x);
    void set_values(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int sum(myClass a){
    return a.x + a.y;
}

//Class member as a friend function
const int idle = 0;
const int inuse = 1;
class c2;
class c1{
    int status;
public:
    void set_status(int state){
        status = state;
    }
    int idle(c2 b);

    // this won't work beacuse c2 is not defined yet
    // {
    //     if(status || b.status) return 0;
    //     else return 1;
    // }
};

class c2{
    int status;
public:
    void set_status(int state){
        status = state;
    }
    friend int c1::idle(c2 b);
};

int c1::idle(c2 b){
    if(status || b.status) return 0;
    else return 1;
};

int main()
{
    // myClass n;
    // n.set_values(3, 4);
    // cout<<sum(n)<<endl;

    c1 x;
    c2 y;
    x.set_status(idle);
    y.set_status(idle);

    if(x.idle(y)) cout<<"Screen can be used"<<endl;
    else cout<<"Screen is being used"<<endl;

    x.set_status(inuse);
    if(x.idle(y)) cout<<"Screen can be used"<<endl;
    else cout<<"Screen is being used"<<endl;
    return 0;
}