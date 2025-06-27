/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 09:42:41 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/27 12:02:12 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <istream>

bool is_directory(const std::string &path)
{

    struct stat path_stat;
    if (stat(path.c_str(), &path_stat) != 0)
    {
        return false;
    }
    return S_ISDIR(path_stat.st_mode);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Wrong number of arguements" << std::endl;
        std::cout << "Expecting: filename, target and replacement";
        return 1;
    }

    std::string filename = argv[1];
    std::string target = argv[2];
    std::string replacement = argv[3];
    std::ifstream infile(filename.c_str());
    bool is_match = false;


    if (is_directory(filename))
    {
        std::cerr << filename << " is a directory" << std::endl;
        return 1;
    }
    else if (!infile.is_open())
    {
        std::cerr << "Error: Cannot open file ";
        std::cerr << filename << std::endl;
        return 1;
    }
    else if (infile.peek() == EOF)
    {
        std::cerr << "No content in " << filename << std::endl;
        return 1;
    }
    else
    {
        std::string new_file = filename + ".replace";
        std::string line;
        std::ofstream outfile(new_file.c_str());

        while (infile.good())
        {

            std::size_t start = 0;
            std::size_t end = 0;
            std::getline(infile, line);
            while (start != std::string::npos)
            {
                start = line.find(target, end);
                if (start == std::string::npos)
                    outfile << line.substr(end, line.npos);
                else
                {
                    outfile << line.substr(end, start);
                    outfile << replacement;
                    end = start + target.length();
                    is_match = true;
                }
            }
            if (infile.good())
                outfile << std::endl;
        }
        outfile.close();
        if (!is_match)
            std::cout << "No match found" << std::endl;
    }
    return 0;
}