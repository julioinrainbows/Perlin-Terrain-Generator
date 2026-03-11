#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>

#ifndef TERRAIN_HPP
#define TERRAIN_HPP
namespace terrain{
    using sizeType = int; 
    class terrain{
        public:
        sizeType X;
        sizeType Y;
        sizeType Z;
        terrain(sizeType axis, sizeType yxis, sizeType zxis);
        private:
            std::vector<bool> terrainMap;
            void perlin(sizeType x, sizeType y, sizeType z)
            float neighborScore(sizeType x, sizeType y, sizeType z);
        
    }


}
#endif