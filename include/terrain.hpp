#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>

#ifndef TERRAIN_HPP
#define TERRAIN_HPP
namespace terrains{
    using sizeType = std::size_t;
    class terrain{
    public:
        terrain(sizeType axis, sizeType width, sizeType height); //Default Constructor

        sizeType getX() {return x;}
        sizeType gety() {return y;}
        sizeType getz() {return z;}

        double pointValue(int x1, int y1 , int z1 ) {return terrainMap[x1*(y*z) + y1*z + z1];}
    private:

        sizeType x;
        sizeType y;
        sizeType z;
        std::vector<double> terrainMap; 
        // void perlin(sizeType x, sizeType y, sizeType z)


        
    };


};
#endif