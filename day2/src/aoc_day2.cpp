#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::ifstream inf{"/workspaces/aoc2024/day2/test/input.txt"};

    if (!inf)
    {
        std::cerr << "Could not find/open input.txt.\n";
        return 1;
    }

    int safeCount{0};

    std::string strInput{};
    std::string temp{};
    char space{' '};

    bool safe{};
    bool increased{};
    bool decreased{};
    bool dampenerUsed{};
    while (std::getline(inf, strInput))
    {
        safe = true;
        increased = false;
        decreased = false;
        dampenerUsed = false;

        std::stringstream ss(strInput);
        int t{};
        int prev{-1};
        int prevPrev{-1};
        int elementCount{0};
        while (std::getline(ss, temp, space))
        {
            elementCount += 1;
            t = std::stoi(temp);
            if (elementCount == 1)
            {
                prev = t;
                continue;
            }
            if (elementCount == 2)
            {
                int res = t - prev;
                if (res > 0)
                {
                    increased = true;
                }
                if (res < 0)
                {
                    decreased = true;
                }
                if (increased && decreased)
                {
                    safe = false;
                }
                if (abs(res) < 1 || abs(res) > 3)
                {
                    safe = false;
                }

                prevPrev = prev;
                prev = t;
                continue;
            }

            int res = t - prev;
            if (res > 0)
            {
                increased = true;
            }
            if (res < 0)
            {
                decreased = true;
            }
            if (increased && decreased)
            {
                safe = false;
            }
            if (abs(res) < 1 || abs(res) > 3)
            {
                safe = false;
            }

            if (safe == false && !dampenerUsed)
            {
                safe = true;
                dampenerUsed = true;
                if (res > 0)
                {
                    increased = false;
                }
                if (res < 0)
                {
                    decreased = false;
                }

                res = t - prevPrev;
                if (res > 0)
                {
                    increased = true;
                }
                if (res < 0)
                {
                    decreased = true;
                }
                if (increased && decreased)
                {
                    safe = false;
                }
                if (abs(res) < 1 || abs(res) > 3)
                {
                    safe = false;
                }
            }

            prevPrev = prev;
            prev = t;
        }

        if (safe)
        {
            safeCount += 1;
        }
    }

    std::cout << safeCount << std::endl;

    return 0;
}
