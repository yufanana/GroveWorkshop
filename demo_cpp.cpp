#include <math.h>
#include <iostream>

using namespace std;

bool state;

class Person{
    public:
        string name;
        int age;

    Person(string newName,int newAge){
        name = newName;
        age = newAge;
    }

    void speak(){
        cout << "My name is " << name << endl;
    }
};


int myFunction(int x, int y){
    return x+y;
}

void checkState(int c){

    if(c > 0){
        state = 1;
    } else {
        state = 0;
    }
}

int main(){
    // this is a comment
    
    int a = 3;
    int b = 4;
    int c = myFunction(a,b);
    checkState(c);

    cout << "c: " << c << endl;
    cout << "state: " << state << endl;

    Person person("John", 20);
    person.speak();
    
    return 0;
}