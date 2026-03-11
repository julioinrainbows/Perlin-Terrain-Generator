#include <algorithm>
#include <numeric>
#include <vector>
#include <random>
#include <cmath>

unsigned int seed = 40324;
std::mt19937 rng(seed);


#ifndef PERLIN_HPP
#define PERLIN_HPP

namespace pn{

    using sizeType = std::size_t;

    class perlin{
    public:
        perlin(){
            std::iota(grid.begin(),grid.end(),0);
            std::shuffle(grid.begin(),grid.end(),rng);
            grid.insert(grid.end(),grid.begin(),grid.end());
        }

        double noise(double x, double y, double z){
            int X = static_cast<int>(std::floor(x)) & 255;
            int Y = static_cast<int>(std::floor(y)) & 255;
            int Z = static_cast<int>(std::floor(z)) & 255;

            double xlow = x - std::floor(x);
            double ylow = y - std::floor(y);
            double zlow = z - std::floor(z);
            
            double u = fade(xlow);
            double v = fade(ylow);
            double w = fade(zlow);

            int A  = grid[X] + Y;
            int AA = grid[A] + Z;
            int AB = grid[A + 1] + Z;
            int B  = grid[X + 1] + Y;
            int BA = grid[B] + Z;
            int BB = grid[B + 1] + Z;

            return lerp(w,lerp(v,lerp(u, grad(grid[AA], xlow, ylow, zlow),
            grad(grid[BA], xlow-1, ylow, zlow)),
            lerp(u, grad(grid[AB], xlow, ylow-1, zlow),
            grad(grid[BB], xlow-1, ylow-1, zlow))),
            lerp(v,lerp(u, grad(grid[AA+1], xlow, ylow, zlow-1),
            grad(grid[BA+1], xlow-1, ylow, zlow-1)),
            lerp(u, grad(grid[AB+1], xlow, ylow-1, zlow-1),
            grad(grid[BB+1], xlow-1, ylow-1, zlow-1))));
        };

        
    private:

        double fade(double c){
            return c*c*c*(c*(c*6-15) + 10);
        };

        
        double grad(int hash, double x, double y, double z){
            int h = hash & 15;
            double u = h < 8 ? x : y;
            double v = h < 4 ? y : (h == 12 || h == 14 ? x : z);

            return ((h & 1) ? -u : u) + ((h & 2) ? -v : v);
        }
        double lerp(double t,double a,double b){
            return a + t*(b-a);
        }
        std::vector<sizeType> grid = std::vector<sizeType>(256);
    };

}

#endif