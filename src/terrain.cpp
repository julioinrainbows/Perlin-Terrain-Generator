#include "terrain.hpp"

using namespace terrain;



    terrain(sizeType axis, sizeType yxis, sizeType zxis) : X(axis), Y(yxis), Z(zxis) {
        terrainMap.resize(X*Y*Z);
        float scale = 0.015;
        auto index = [&](int x, int y, int z){
            return x*(Y*Z) + y*Z + z;
        };

        for(int i = 0; i < X; ++i) for(int j = 0; j < Y; ++j) for(k = 0; k < Z; ++k){
            terrainMap[index(i,j,k)] = perlin(i*scale,j*scale,k*scale);
        }                   
    };
