/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:27:24 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/13 19:27:25 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string line, const std::string& s1, const std::string& s2) {
    size_t start_pos = 0;
    while((start_pos = line.find(s1, start_pos)) != std::string::npos) {
        line = line.substr(0, start_pos) + s2 + line.substr(start_pos + s1.length());
        start_pos += s2.length();
    }
    return line;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Usage: ./replace <files/filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile) {
        std::cerr << "Error: Unable to create output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        outFile << replaceAll(line, s1, s2) << std::endl;
    }

    inFile.close();
    outFile.close();

    std::cout << "Replacement complete. Output written to " << filename << ".replace" << std::endl;
    return 0;
}