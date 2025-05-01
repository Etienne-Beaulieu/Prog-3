#ifndef LABYRINTHEFILEREADER_H
#define LABYRINTHEFILEREADER_H

#include "Labyrinthe.h"
#include <string>
#include <vector>
#include <cstdint>

class LabyrintheFileReader {
public:
    static Labyrinthe read(const std::string& filename, std::vector<std::pair<uint16_t, uint16_t>>& links);
};

#endif