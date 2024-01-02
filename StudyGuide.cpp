// File for refresher 
#include <iostream> //files useful for input and output to console
#include <string>
#include <vector>
#include <array>
#include <stdio.h>
#include <memory>
#include <cmath>
#include "BaseCharacter.h"
#include "Student.h"
using namespace std; //includes entire std library; warning:updates in std can cause program errors

namespace Arron
{
    void printName(const string name)
    {
        cout << name << endl;
    }
}

using namespace Arron;

//most common recursive function example. factorial calls itself until n = 1.
unsigned long long Factorial(int num1)
{
    if(num1==1 || num1==0)
    {
        return 1LL;
    }
    else
    {
        return num1 * Factorial(num1-1);
    }
}

//function overloading
int Add(int intNum1, int intNum2 )
{
    return intNum1 + intNum2;
}

/*inlining means the body of the function gets substituted at the point of the function call, meaning
Add() would turn into return floatNum1 + floatNum2. Mostly used for small functions. Could improve performance*/
inline float Add(float floatNum1, float floatNum2) { return floatNum1 + floatNum2; }

inline void DoubleRoll(unsigned int& diceRoll)
{
    diceRoll += diceRoll;
    cout << diceRoll << endl;
}

struct RectangleVar //data type that allows grouping of related variables
{
    int xCoor{};
    int yCoor{};
    int width{100};
    int height{100};
};

//linked list
struct node // node data structure
{
    int number; // element in the first half of the node
    struct node *next; // pointer in the 2nd node that points to the element of the next node
};

bool search(node *tree, int numero);

int main(int argc, char *argv[]) // begin program
//First element of argv is the program; the remaining are arguments passed to the program. argc is argument count.
//arguments can be added through properties
{
    for (int i{0}; i < argc; i++)
    {
        cout << argv[i] << endl;
        cout << argc << endl;
    }

    cout << "learning C++ yay"<< endl; // send string to the console then end the line

    //most common data types
    short shortNum{1};
    int intNum{2};
    float floatNum{3.f};
    double doubleNum{4.f};
    long longNum{};
    long long longLongNum{};
    unsigned short uShortNum{};
    unsigned int uIntNum{};
    unsigned long uLongNum{};
    unsigned long long uLongLongNum{};
    char Char{'y'}; //single quote for single char
    string String{"it be like that"};
    auto autoIntNum{32}; //compiler will declare variable with automatic type deduction.
    bool dayTime{}; //default value is true

    //size in bites of data types
    cout << "short size: " << sizeof(shortNum) << endl;
    cout << "int size: " << sizeof(intNum) << endl;
    cout << "float size: " << sizeof(floatNum) << endl;
    cout << "double size: " << sizeof(doubleNum) << endl;
    cout << "long size: " << sizeof(longNum) << endl;
    cout << "long long size: " << sizeof(longLongNum) << endl;
    cout << "u short size: " << sizeof(uShortNum) << endl;
    cout << "u int size: " << sizeof(uIntNum) << endl;
    cout << "u long size: " << sizeof(uLongNum) << endl;
    cout << "u long long size: " << sizeof(uLongLongNum) << endl;
    cout << "char size: " << sizeof(Char) << endl;
    cout << "String size: " << sizeof(String) << endl;


    /* Explicit type conversion between 2 incompatible types
    Cast NarcaseDose to an int. Common in random # generation.
    Truncation: discarding the fractional part when a decimal is converted */
    int NarcanVolume{4};
    float NarcanDose{2.f};
    NarcanVolume = static_cast<int>(NarcanDose);
    
    int autoStorage{}; //autoStorage has automatic storage duration meaning it only exists within a set of brackets
    //static int staticStorage{}; //staticStorage has static storage so it exists until the program ends
    thread_local int threadStorage{}; //threadStorage has thread storage duration so each thread can have it own instance of threadStorage.

    //<=> 3 way comparison introduced in C20. returns 0 if values are equal, -1 if 1st is < 2nd, or 1 if 1st > 2nd.
    //auto result = shortNum <=> intNum;

    //bitwise operators perform operations on bits of an int value.


    //ternary operators: condition ? result_if_true : result if false. shorthand if-else statement
    shortNum > intNum ? cout << shortNum : cout << intNum << endl;

    switch(shortNum) //only used with ints and enums
    {
        case 1: cout << "Yes it's " << shortNum << endl;
        break; //break signals to exit the switch statement

        default: cout << "not shortNum" << endl;
        break;
    }


    for (char i : String) // range based for loop. interate through string and stores the elements in i;
    {
        cout << shortNum << endl;
    }

    while(shortNum < 3)
    {
        cout << shortNum;
        shortNum++;
    }

    int studyArray[2][2] {{1,2},{3,4}}; //multidimensional array
    array<int,3>stdarray {1,2,3}; //std array
    vector <int> myVector {1,2,3,4,5}; //dynamic sizing and remember their size
    vector<int> pvec (10, 0); //creates a vector of 10 ints initialized to 0
    vector<vector<int>> vector2D (3, vector<int>(10)); //parenthesis initialize the vector; 3 rows and 10 columns of vectors
    vector2D[1][2] = 42;

    cout << String.length() << endl;
    cout << String.append(" sometimes") << endl;

    //variations of random number generation
    unsigned int Time = time(0);
    srand(Time);
    unsigned int rollNum = (rand() % 6) + 1;
    cout << rollNum << endl;

    cout << Factorial(16) << endl;

    int *pIntNum = &intNum; //points to the address intNum
    cout << pIntNum << endl; 

    const float* pFloatNum{&floatNum}; // pointer to const - floatNum cannot be changed via pointer
    cout << pFloatNum << endl;

    long* const pLongNum = &longNum; // constant pointer - value/address cannot be changed.
    cout << pLongNum << endl;

    const double *const pDoubleNum{&doubleNum}; // address stored in pointer and value pointed to cannot be changed.
    cout << pDoubleNum << endl;

    //pHeap points to new data on heap that contains memory for an int that we initialize to 100.
    //pHeap is the only way to access the new value
    int *pHeap{new int{100}};
    delete pHeap; // every new needs a delete else it will leak
    //delete only deletes the new int 100 not pHeap so pHeap is now a dangling pointer. 
    // pHeap still contains the address of memory
    pHeap = 0;

    int *pArrPtr { new int[5] {1,2,3,4,5}};
    delete[] pArrPtr;
    pArrPtr = 0;

    //smart poiters automatically deallocate memory when destroyed
    unique_ptr<short>upShort{new short}; 
    // or 
    unique_ptr<int>U_Int{make_unique<int>(100)};
    unique_ptr<vector<short>>U_Vector{new vector<short>(2)};
    U_Vector->push_back(16);
    cout << U_Vector->at(2) << endl; //2 is the third element in the vector

    //multiple shared pointers can point to the same memory location
    shared_ptr<int>S_Short{make_shared<int>(100)};
    shared_ptr<string[]> S_String{new string[3]};
    S_String[0] = "Daniel";
    S_String[1] = "Day";
    S_String[2] = "Lewis";
    cout << S_String[2] << endl;

    //linked to a shared_ptr and has the same address. does not increase reference count 
    weak_ptr<int>W_Short{S_Short};

    int& intNum2{intNum};
    cout << intNum2 << endl;

    int refAdd = Add(intNum2, intNum2);
    cout << refAdd << endl;

    unsigned int& diceRoll = rollNum;

    DoubleRoll(diceRoll);

    enum class PrimaryColor : int {RED, Blue, Green, SizeofEnum};
    PrimaryColor favoriteColor{PrimaryColor::RED};

    //include the file that contains the Base class. Instantiate Arron. Calls constructors which prints age to the console.
    Base Arron(20, 50);
    Arron.height = 74;

    //Rictus pointer points to the memory address height and dereferences to allow us access.
    unique_ptr<Base>Rictus{new Base(70, 50)};
    // Rictus.height{70}; does not work because a pointer gives you the location of the value, therefore we must dereference first
    (*Rictus).height = 69; //nightmare syntax
    Rictus->height = 68; // The instance pointer gets the member from the arrow operator.

    Base Samuel(20, 50); //calls constrctur with no parameters. 

    Base CopySamuel{Samuel}; //calls copy constructor.
    cout << *CopySamuel.grade << endl;

    RectangleVar Uno;
    RectangleVar Dos;

    Uno.xCoor = 50;
    Uno.yCoor = 0;
    Dos.xCoor = 0;
    Dos.yCoor = 50;
   
    cout << Base::GetBaseCount() << endl;

    Samuel=CopySamuel; //Overloaded operator
    cout << Samuel.height << endl; //in this case will be a garbage value

    node *list = NULL; // node called list that will point to the first node we're using

    for (int i = 1; i < argc; i++) // iterate over the argument count
    {
        int number = atoi(argv[i]); // change a string number to an int number

        node *n = new node; // allocate new memory that holds a new node
        if (n == NULL)
        {
            return 42; // if the pointer points to nothing, error
        }
        n->number = number; // the number the temp node points to is the new number
        n->next = NULL; // the 2nd elemnt in the node that will be a pointer initially contains nothing.
        n->next = list; //next now points to list
        list = n; //the actual list points to the first node
    }
    node *ptr = list; // points to the first node in the list
    while(ptr != NULL)
    {
        cout << ptr->number << endl; //print the numbers in the list
        ptr = ptr->next; // will eventually be NULL for the last element, ending the loop
    }

    ptr = list; //point back to list

    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    Base Janny("Janny", 50);
    Student Robbie;

    Janny.greeting();
    Robbie.greeting();

    Base *newPtr = new Student; //cannot use smart pointers
    newPtr->greeting();

    delete newPtr; //delete Student memory
    newPtr = 0; // initialize newPtr so its not dangling

    class STEM{};

    class Math : public STEM {};

    class Calculus : public Math{};

    STEM *Stemptr{new Calculus};

    //Turn a pointer to STEM to a pointer to Calculus
    Calculus *StemToCalc{static_cast<Calculus*>(Stemptr)};

    return 0; //end procgram. compiler would also add by default
}
