#include <string>
#include <iostream>

using namespace std;

    class People
    {
        People();

    public: //can be used anywhere in the program
        short getAge() { return Age; }
    
    protected:
    
    private: //can only be accessed by People
        short Age{26};

    };

    People Arron;

