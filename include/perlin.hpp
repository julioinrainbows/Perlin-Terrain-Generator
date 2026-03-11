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



    class perlin{
        public:

            perlin(){
                std::iota(grid.begin(),grid.end(),0);
                std::suffle(grid.begin(),grid.end(),rng);
                p.insert(p.begin(),p.end(),p.begin());
            }

        private:

            std::vector<int> grid;

    }
}

#endif