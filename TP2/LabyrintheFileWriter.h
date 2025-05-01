#ifndef LABYRINTHEFILEWRITER_H
#define LABYRINTHEFILEWRITER_H

#include <string>
#include <vector>
#include <cstdint>

class LabyrintheFileWriter {
public:
    static void ecrireSolution(const std::string& filename, const std::vector<uint16_t>& solution);
};

#endif