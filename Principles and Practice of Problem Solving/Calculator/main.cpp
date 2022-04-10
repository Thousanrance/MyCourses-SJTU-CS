/*
Problem Description

Implement a basic calculator to evaluate a simple expression string.
The expression string contains real numbers(double), +, -, *, / operators, open ( and closing parentheses ), empty spaces, and ends with ;.
The result retains three decimal places(rounded).
Meanwhile, you should handle the following 3 kinds of errors in your program:

Divide by zero: If the divisor of the \ operator is 0, you should output divide by zero.
Unexpected character: When Token_stream::get is called, if the character encountered is not expected ones, you should output unexpected character.
Unclosed parentheses: If the parentheses are not matched, you should output unclosed parentheses.

Please fill in codes for function Token_stream::get, expression, term and primary.

Example 1
Input: 2 +3 /4;
Output: 2.750

Example 2
Input: (8 - 9)/   -3;
Output: 0.333

Example 3
Input: 16   +7/ (3 - 9 / 3)-  (  5*    5);
Output: divide by zero

Example 4
Input: 1 @ 2;
Output: unexpected character

Example 5
Input: (1 + 2;
Output: unclosed parentheses

Note
Numbers can have signs, such as +5.6, -7.1.
There will be at most 1 kind of error in each test sample.
Except for the mentioned 3 kinds of errors, test samples do not include other errors.

Reference
Bjarne Stroustrup, “Programming: principles and practice using C++”, 2nd Edition, Addison Wesley. Chapter 6-7.
Lecture 3-4.
*/

#include <iostream>
#include <iomanip>
#include <errno.h>
using namespace std;


class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Token(char ch)    // make a Token from a char //for +-*/()
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double //for number
        :kind(ch), value(val) { }
};


class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

Token_stream::Token_stream()
    :full(false), buffer(0){}

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) perror("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch (ch) {
    case ';':    // for "print"
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('n', val);   // let 'n' represent "a number"
    }
    // please implement here!
    // handle unexpected character
    default:
        perror("unexpected character");
    }
}

Token_stream ts;        // provides get() and putback() //全局变量
double expression();
double term();
double primary();

double expression()
{
    // please implement here!
    double left = term();   //read and evaluate a Term
    Token t = ts.get();     //get the next Token from the Token stream
    while(true)
    {
        switch(t.kind)
        {
            case '+':
                left += term(); //evaluate Term and add
                t = ts.get();
                break;
            case '-':
                left -= term(); //evaluate Term and subtract
                t = ts.get();
                break;
            default:
                ts.putback(t);  //put t back into the token stream
                return left;    //finally:no more + or -;return the answer
        }
    }
}

double term()
{
    // please implement here!
    double left = primary();
    Token t = ts.get();
    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if(d == 0)
                {
                    perror("divide by zero");
                }
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double primary()
{
    // please implement here!
    Token t = ts.get();
    switch(t.kind)
    {
        case '(':   //handle '('expression')'
        {
            double d = expression();
            t = ts.get();
            if(t.kind != ')')
            {
                perror("unclosed parentheses");
            }
            return d;
        }
        case 'n':   //we use 'n' to represent a number
            return t.value; //return the number's value
        case '-':
            return - primary();  //handle a negative
        case '+':
            return primary();
        default:
            perror("primary expected");
    }
}


int main()
{
    double val = 0;
    try {
        while (cin) {
            Token t = ts.get();
            if (t.kind == ';')
            {
                cout << fixed;
                cout << setprecision(3) << val << '\n';
                break;
            }
            else
                ts.putback(t);
            val = expression();
        }
    }
    catch (exception& e) {
        cout << e.what() << '\n';
    }
}
