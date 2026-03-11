#include "../include/terrain.hpp"
#include "../include/perlin.hpp"
#include <iostream>
using namespace terrains;
using namespace pn;


    terrain::terrain(sizeType axis, sizeType width, sizeType height) : x(axis), y(width), z(height) {
        perlin Perlin;
        terrainMap.resize(x*y*z);
        float scale = 0.015;
        auto index = [&](int x1, int y1, int z1){
            return x1*(y*z) + y1*z + z1;
        };

        for(int i = 0; i < x; ++i) for(int j = 0; j < y; ++j) for(int k = 0; k < z; ++k){
            double scale = 0.43;
            terrainMap[index(i,j,k)] = Perlin.noise(scale*i,scale*j,scale*k);
        }                   
    };


int main(){
    terrain heightMap(12,12,12);   
    for(int i = 0; i < 12; ++i) for(int j = 0; j < 12; ++j) for(int k = 0; k < 12; ++k){
        std::cout << heightMap.pointValue(i,j,k) << " ";
    }        
}