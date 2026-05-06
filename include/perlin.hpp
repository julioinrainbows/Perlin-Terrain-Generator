#include <algorithm>
#include <numeric>
#include <vector>
#include <random>
#include <cmath>

#pragma once

namespace pn{

    using sizeType = std::size_t;

    class perlin{
    public:
    
        perlin(){
            std::random_device rd;
            std::mt19937 rng(rd());
            std::iota(grid.begin(),grid.begin() + 256,0);
            std::shuffle(grid.begin(),grid.begin() + 256,rng);
            std::copy(grid.begin(), grid.begin() + 256, grid.begin() + 256);
        }

        double noise(double x, double y) const{
            
            int X = static_cast<int>(std::floor(x)) & 255;
            int Y = static_cast<int>(std::floor(y)) & 255;

            double xlow = x - std::floor(x);
            double ylow = y - std::floor(y);
            
            double u = fade(xlow);
            double v = fade(ylow);

            int A  = grid[X] + Y;
            int AA = grid[A];
            int AB = grid[A + 1];

            int B  = grid[X + 1] + Y;
            int BA = grid[B];
            int BB = grid[B + 1];

            return lerp(
                v,
                lerp(u,grad(grid[AA], xlow,ylow), grad(grid[BA], xlow -1, ylow)),
                lerp(u,grad(grid[AB],xlow,ylow-1), grad(grid[BB], xlow -1 , ylow - 1))
            );
        };


        
    private:

        static constexpr double fade(double c) noexcept{
            return c*c*c*(c*(c*6-15) + 10);
        };
        
        static constexpr double grad(int hash, double x, double y)  noexcept{
            int h = hash & 3;

            double u = (h & 1) ? -x : x;
            double v = (h & 2) ? -y : y;


            return u + v;
        }
        
        static constexpr double lerp(double t,double a,double b)  noexcept{
            return a + t*(b-a);
        }

        std::array<int,512> grid;

    };

};