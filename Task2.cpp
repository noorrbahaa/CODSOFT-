#include <iostream>
using namespace std;

int main()
{
    int x, y;
    string ch;
    again:
    cout << "Please enter two numbers" << endl;
    cin >> x >> y;
    int res = 0;
    char oper;
    cout << "Please choose an operation to perform" << endl;
    cin >> oper;
    switch (oper) {
    case '+':
        res = x + y;
        cout << "The result is " << res << endl << endl;
        break;
    case '-':
        res = x - y;
        cout << "The result is " << res << endl;
        break;
    case '*':
        res = x * y;
        cout << "The result is " << res << endl;
        break;
    case '/':
        res = x / y;
        cout << "The result is " << res << endl;
        break;
    default:
        cout << "You entered invalide operand " << endl;
    }
    cout << "Would you like to try again?" << endl;
    cin >> ch;
    if (ch == "yes") { goto again; }
  
}