#include<iostream>
using namespace std;

class person{
    private:
    string name;
    int studentID;
    int age;

    public:
    //init()
    void init(string n, int id, int a){
        name = n;
        studentID = id;
        age = a;
    }
    //printstudentinfo()
    void printstudentinfo(){
        cout<<"Name:" <<name
            <<"Student ID:" <<studentID
            <<"Age:" <<age<<endl;
    }
    //getID()
    int getID(){
        return studentID;
    }
    //getage()
    int getage(){
        return age;
    }
    //getname()
    string getname(){
        return name;
    }
    //Swap function to access private data
    friend void personswap(person &p1, person &p2);
};

    //personswap()
     void personswap(person &p1, person &p2){

        //Temporary variables
        string tempname = p1 .name;
        int tempID = p1 .studentID;
        int tempage = p1 .age;

        //Swap values
        p1 .name = p2 .name;
        p1 .studentID = p2 .studentID;
        p1 .age = p2 .age;

        p2 .name = tempname;
        p2 .studentID = tempID;
        p2 .age = tempage;
    }

    int main(){
        person p1, p2;

        p1 .init("Alice", 2026312345, 20);
        p2 .init("Bob", 2019354321, 25);

        cout<<"Before swap:"<<endl;
        p1 .printstudentinfo();
        p2 .printstudentinfo();

        //Swap
        personswap(p1, p2);

        cout<<"\nAfter swap:"<<endl;
        p1 .printstudentinfo();
        p2 .printstudentinfo();

        return 0;
    }

    
