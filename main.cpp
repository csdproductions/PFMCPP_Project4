/*
 Project 4 - Part 1 / 9
 video: Chapter 2 Part 7
 Returning Values tasks 

 Create a branch named Part1

 Purpose:  This project will take you through the process of writing a class that wraps a numeric type, beginning with writing simple member functions and ending with a fully templated class with lots of functionality. 
 
 1) write 3 UDTs named FloatType, DoubleType, IntType.
 
 2) give each UDT the following member functions:
        add( lhs, rhs );
        subtract( lhs, rhs );
        multiply( lhs, rhs );
        divide( lhs, rhs );
 3) implement the appropriate action in the member function. 
         a) Be aware that floating point division by 0 is legal, but integer division by 0 will crash your program.  
         b) Handle this possible input when you write your divide() functions.
         c) you should warn the user if they're doing floating-point-division-by-zero but not prevent the division from happening
         d) you should warn AND prevent the division from happening if it is an integer-division-by-zero.
 
 4) make them return the correct primitive type. e.g. if you're implementing the FloatType::add function, your implementation would start like this:
        float FloatType::add( float lhs, float rhs )
 
 5) declare a few instances of each class in main() and call the member functions with the appropriate arguments.
        FloatType ft;
        auto result = ft.add(3.2f, 23.f );
 
 6) print out those results using std::cout:
        std::cout "result of ft.add(): " << result << std::endl;
 
 7) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
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
    std::cout << "Result of dt.divide(): " << dt.divide(lhsd, rhsd) << std::endl;
        

    IntType it;
    int lhsi = 7;
    int rhsi = 8;

    std::cout << "-------------------------------" << std::endl;
    std::cout << "Result of it.add(): " << it.add(lhsi, rhsi) << std::endl; 
    std::cout << "Result of it.subtract(): " << it.subtract(lhsi, rhsi) << std::endl;  
    std::cout << "Result of it.multiply(): " << it.multiply(lhsi, rhsi) << std::endl;
    std::cout << "Result of it.divide(): " << it.divide(lhsi, 0)  << std::endl;
}
