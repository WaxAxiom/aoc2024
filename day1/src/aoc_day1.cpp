#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <iterator>

int main(int argc, char const *argv[])
{
    std::ifstream inf{"/workspaces/aoc2024/day1/test/input.txt"};

    if (!inf)
    {
        std::cerr << "Could not find/open input.txt.\n";
        return 1;
    }

    int a{};
    int b{};
    int total{};
    int similarity{};

    std::multiset<int> left_list{};
    std::multiset<int> right_list{};

    std::string strInput{};
    std::string str1{};
    std::string str2{};
    while (std::getline(inf, strInput))
    {
        std::stringstream s(strInput);
        s >> str1 >> str2;

        left_list.insert(std::stoi(str1));
        right_list.insert(std::stoi(str2));
    }

    for (std::multiset<int>::iterator it1 = left_list.begin(), it2 = right_list.begin();
         (it1 != left_list.end()) && (it2 != right_list.end());
         it1++, it2++)
    {
        total += abs(*it1 - *it2);
        similarity += *it1 * right_list.count(*it1);
    }

    std::cout << "total: " << total << " similarity: " << similarity << std::endl;

    return 0;
}
