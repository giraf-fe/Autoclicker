// Autoclicker.cpp : Defines the entry point for the application.
//

#include "Autoclicker.h"

int main()
{
    int cpsmin;
    int cpsmax = 0;
    int* debugptr = &cpsmax;
    int doubleclickchance;
    int clickfailchance;
    bool dofatigue;
    float fatiguerate;
    float fatiguerecovery;
    float maxfatigue;
    std::string temp;
    std::cout << "CPS Max: ";
    std::cin >> cpsmax;
    std::cout << "CPS Min: ";
    std::cin >> cpsmin;
    std::cout << "Double Click Chance: ";
    std::cin >> doubleclickchance;
    std::cout << "Click Fail Chance: ";
    std::cin >> clickfailchance;
fatigue:
    std::cout << "Enable Fatigue? This option can make the cps drop below the minimum cps specified, but makes it significantly harder to detect. (y/n):";
    std::string j;
    std::cin >> j;
    float fatigue = 0.0f;
    if (j[0] == 'y')
    {
        dofatigue = true;
        std::cout << "Fatigue rate (ms of delay for each click, recommended 0.03-0.08):";
        std::cin >> fatiguerate;
        std::cout << "Max Fatigue delay(in ms, recommended 50ms, anything over 70ms is unrealistic): ";
        std::cin >> maxfatigue;
        std::cout << "Fatigue Recovery rate:";
        std::cin >> fatiguerecovery;
    }
    else if (j[0] == 'n') { dofatigue = false; }
    else { goto fatigue; }

    INPUT Click[2] = { 0 };

    Click[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    Click[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    int range = (1000 / cpsmin) - (1000 / cpsmax);
    float minms = 1000 / cpsmax;
    bool safety = false;
    std::cout << "Started autoclicker...\n";
    while (true)
    {
        bool clicking = false;
	    srand((unsigned)std::chrono::system_clock::now().time_since_epoch().count());
        if (GetAsyncKeyState('X') && !safety)
        {
	        clicking = true;
            if (dofatigue)
            {
                if (fatigue < (float)maxfatigue)
                {
                    fatigue += (fatiguerate);
                }
            }
            float i = minms + (rand() % range) + fatigue;
            int faildecision = rand() % 100;
            int doubleclickdecision = rand() % 100;
            if (faildecision < clickfailchance) { goto skip; }

            SendInput(2, Click, sizeof(INPUT));
            if (doubleclickdecision < doubleclickchance)
            {
                Sleep(i / 10);
                SendInput(2, Click, sizeof(INPUT));
            }
            skip:
            Sleep(i - 10);
        }
        if (dofatigue && fatigue > 0.0f && !clicking) { fatigue -= fatiguerecovery; Sleep(minms); }
        if (GetAsyncKeyState(VK_F4)) {
            if (!safety) {
                std::cout << "Safety ON." << "\n";
                safety = true;
            }
            else {
                std::cout << "Safety OFF." << "\n";
                safety = false;
            }
            Sleep(250);
        }
    }

    return 0;
}
