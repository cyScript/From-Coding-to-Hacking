#include <Windows.h>
#include <iostream>

using namespace std;

int main() {

	DWORD pid = 0; // The process ID of our target process
	cout << "PID: ";
	cin >> dec >> pid; // Prompting user for PID

	HANDLE hProcess = OpenProcess(PROCESS_VM_READ, FALSE, pid);
	if (hProcess == NULL) { // Failed to get a handle
		cout << "OpenProcess failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	// Prompting user for memory address to read
	uintptr_t memAddrOfString = 0x0;
	uintptr_t memAddrOfChar = 0x0;
	uintptr_t memAddrOfPointer = 0x0;
	cout << "Memory address of the string to read (in hexadecimal): 0x";
	cin >> hex >> memAddrOfString;
	cout << "Memory address of the char to read (in hexadecimal): 0x";
	cin >> hex >> memAddrOfChar;
	cout << "Memory address of the ptr to read (in hexadecimal): 0x";
	cin >> hex >> memAddrOfPointer;
	cout << "Reading Memory..." << endl;

	// Reading from dummy proc
	int* intReadptr = 0;
	int intRead = 0;
	char arraySize[128] = "Long char array right there ->";
	string strRead;

	BOOL ReadStr = ReadProcessMemory(hProcess, (LPCVOID)0xCDF0BFFD30, &strRead, sizeof(string), NULL);
	BOOL ReadChar = ReadProcessMemory(hProcess, (LPCVOID)0xCDF0BFFCB0, &arraySize, sizeof(arraySize), NULL);
	BOOL ReadPtr = ReadProcessMemory(hProcess, (LPCVOID)0xCDF0BFFCA8, &intReadptr, 8, NULL);
	BOOL ReadPtr2ptr = ReadProcessMemory(hProcess, (LPCVOID)intReadptr, &intRead, sizeof(int), NULL);

	// Display
	cout << "ptr2int = " << hex << intReadptr << endl;
	cout << "varInt = " << dec << intRead << endl;
	cout << "varString = " << strRead << endl;
	cout << "arrChar = " << arraySize << endl;
	cout << "Press enter to continuee";
	CloseHandle(hProcess);
	return EXIT_SUCCESS;
}