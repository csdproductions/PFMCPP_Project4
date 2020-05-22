/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */











 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers  
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
        These functions should return the result of calling the function that takes the primitive.
     
 
 5) print out the results with some creative couts 
    i.e.
         FloatType ft(0.1f);
         IntType it(3);
         std::cout << "adding 3 and subtracting 'it' from 'ft' results in the following value: " << *ft.add(2.f).subtract( it ).value << std::endl;  //note the dereference of the `value` member of `ft`
 
 6) Don't let your heap-allocated owned type leak!
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 */




#include <iostream>

struct FloatType
{
    float add(float lhs, float rhs);
    float subtract(float lhs, float rhs);
    float multiply(float lhs, float rhs);
    float divide(float lhs, float rhs);
};

float FloatType::add(float lhs, float rhs)
{
    return lhs + rhs;
}

float FloatType::subtract(float lhs, float rhs)
{
    return lhs - rhs;
}

float FloatType::multiply(float lhs, float rhs)
{
    return lhs * rhs;
}

float FloatType::divide(float lhs, float rhs)
{
    std::cout << "You know you're dividing by zero right? Answer is: ";
    return lhs / rhs;
}

struct DoubleType
{
    double add(double lhs, double rhs);
    double subtract(double lhs, double rhs);
    double multiply(double lhs, double rhs);
    double divide(double lhs, double rhs);
};

double DoubleType::add(double lhs, double rhs)
{
    return lhs + rhs;
}

double DoubleType::subtract(double lhs, double rhs)
{
    return lhs - rhs;
}

double DoubleType::multiply(double lhs, double rhs)
{
    return lhs * rhs;
}

double DoubleType::divide(double lhs, double rhs)
{
    std::cout << "You know you're dividing by zero right? Answer is: ";
    return lhs / rhs;
}

struct IntType
{
    int add(int lhs, int rhs);
    int subtract(int lhs, int rhs);
    int multiply(int lhs, int rhs);
    int divide(int lhs, int rhs);
};

int IntType::add(int lhs, int rhs)
{
    return lhs + rhs;
}

int IntType::subtract(int lhs, int rhs)
{
    return lhs - rhs;
}

int IntType::multiply(int lhs, int rhs)
{
    return lhs * rhs;
}

int IntType::divide(int lhs, int rhs)
{
    if(rhs == 0)
    {   
        std::cout << "Sorry, you can't divide by zero! ";
        return 0;
    }
    return lhs / rhs;      
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    std::cout << "good to go!" << "\n" << std::endl;

    FloatType ft;
    float lhsf = 3.2f;
    float rhsf = 20.1f;

    std::cout << "-------------------------------" << std::endl;
    std::cout << "Result of ft.add(): " << ft.add(lhsf, rhsf) << std::endl;
    std::cout << "Result of ft.subtract(): " << ft.subtract(lhsf, rhsf) << std::endl;
    std::cout << "Result of ft.multiply(): " << ft.multiply(lhsf, rhsf) << std::endl;
    std::cout << "Result of ft.divide(): " << ft.divide(lhsf, 0.f) << std::endl;

    DoubleType dt;
    double lhsd = 9.1;
    double rhsd = 22.2;
   
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Result of dt.add(): " << dt.add(lhsd, rhsd) << std::endl;
    std::cout << "Result of dt.subtract(): " << dt.subtract(lhsd, rhsd) << std::endl;
    std::cout << "Result of dt.multiply(): " << dt.multiply(lhsd, rhsd) << std::endl;
    std::cout << "Result of dt.divide(): " << dt.divide(lhsd, 0.0) << std::endl;
        

    IntType it;
    int lhsi = 7;
    int rhsi = 8;

    std::cout << "-------------------------------" << std::endl;
    std::cout << "Result of it.add(): " << it.add(lhsi, rhsi) << std::endl; 
    std::cout << "Result of it.subtract(): " << it.subtract(lhsi, rhsi) << std::endl;  
    std::cout << "Result of it.multiply(): " << it.multiply(lhsi, rhsi) << std::endl;
    std::cout << "Result of it.divide(): " << it.divide(lhsi, 0)  << std::endl;
}
