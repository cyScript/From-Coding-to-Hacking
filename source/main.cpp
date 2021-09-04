#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

#define Size_OF_ARRAY 128
int main()
{
    int varInt(123456);
    string varString("DefaultString");
    char arrChar[Size_OF_ARRAY] = "Long char array right there ->";
    int* ptr2int(&varInt);
    int** ptr2ptr(&ptr2int);
    int*** ptr2ptr2(&ptr2ptr);
    do
    {
        cout << "Process ID: " << dec << GetCurrentProcessId() << endl;
        cout << endl;
        cout << "varInt        (0x" << hex << uppercase << (uintptr_t)&varInt << ") = " << dec << varInt << endl;
        cout << "varString     (0x" << hex << uppercase << (uintptr_t)&varString << ") = " << dec << varString << endl;
        cout << "arrChar[" << dec << Size_OF_ARRAY << "]  (0x" << hex << uppercase << (uintptr_t)&arrChar << ") = " << dec << arrChar << endl;
        cout << endl;
        cout << "ptr2int       (0x" << hex << uppercase << (uintptr_t)&ptr2int << ") = 0x" << ptr2int << endl;
        cout << "ptr2ptr       (0x" << hex << uppercase << (uintptr_t)&ptr2ptr << ") = 0x" << ptr2ptr << endl;
        cout << "ptr2ptr2      (0x" << hex << uppercase << (uintptr_t)&ptr2ptr2 << ") = 0x" << ptr2ptr2 << endl;
        cout << endl;
        cout << "Press Enter to print again!!" << endl;
        getchar();
    } while (1);
    return EXIT_SUCCESS;
}