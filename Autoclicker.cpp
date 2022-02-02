// Autoclicker.cpp : Defines the entry point for the application.
//

#include "Autoclicker.h"

int main()
{
    int cpsmin;
    int cpsmax;
    int doubleclickchance;
    int clickfailchance;
    std::string temp;
    std::cout << "CPS Max: ";
    std::cin >> cpsmax;
    std::cout << "CPS Min: ";
    std::cin >> cpsmin;
    std::cout << "Double Click Chance: ";
    std::cin >> doubleclickchance;
    std::cout << "Click Fail Chance: ";
    std::cin >> clickfailchance;


    INPUT Click[2] = { 0 };

    Click[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    Click[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    int range = (1000 / cpsmin) - (1000 / cpsmax);
    int minms = 1000 / cpsmax;
    std::cout << "Started autoclicker...\n";
    while (true)
    {
        srand((unsigned)std::chrono::system_clock::now().time_since_epoch().count());
        if (GetAsyncKeyState(VK_MBUTTON))
        {
            int i = minms + (rand() % range);
            int faildecision = rand() % 100;
            int doubleclickdecision = rand() % 100;
            if (faildecision < clickfailchance)
            {
                std::cout << "Clicked Failed Intentionally.\n";
                goto skip;
            }
            SendInput(2, Click, sizeof(INPUT));
            if (doubleclickdecision < doubleclickchance)
            {
                Sleep(i / 10);
                SendInput(2, Click, sizeof(INPUT));
                std::cout << "Sent double click.\n";
            }
        skip:
            Sleep(i - 10);
        }
    }
	return 0;
}
