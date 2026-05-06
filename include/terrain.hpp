#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <array>

#pragma once

namespace terrains{
    using sizeType = std::size_t;

    class terrain{

    public:
        terrain(sizeType axis, sizeType width); //Default Constructor
        
        sizeType getX() {return x;}
        sizeType gety() {return y;}

        uint8_t heightValue(int x1, int y1){
            return heightMap[x1*y + x];
        }
        
        void saveToVox(std::string path);

    private:
        
        sizeType x;
        sizeType y;
        std::vector<uint8_t>heightMap; 
        // void perlin(sizeType x, sizeType y, sizeType z)


        
    };


};