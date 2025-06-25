#include <iostream>
#include <cctype>
#include <cstring>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        std::string str(argv[i]);
        int len = str.length();
        for (int j = 0; j < len; j++)
            str[j] = std::toupper(str[j]);
        std::cout << str;
        if (i < argc - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
