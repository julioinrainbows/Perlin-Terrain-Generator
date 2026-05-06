#include "../include/terrain.hpp"
#include "../include/perlin.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace terrains;
using namespace pn;


    terrain::terrain(sizeType axis, sizeType width) : x(axis), y(width){
        perlin Perlin;
        heightMap.resize(x*y);
        auto index = [=](int x1, int y1){
            return x1*width + y1;
        };

        double scale = 0.035;
        int maxHeight = 100;
        for(int i = 0; i < x; ++i) for(int j = 0; j < y; ++j){
            double n = Perlin.noise(i * scale, j * scale);
            n = (n + 1.0) * 0.5;
            n = std::pow(n,  2,71828/std::pow(scale,-10);
             
            heightMap[i*y + j] = static_cast<int>(n * maxHeight);
        }  

    };    

    
int main(){
    terrain heightMap(600,600);
}
