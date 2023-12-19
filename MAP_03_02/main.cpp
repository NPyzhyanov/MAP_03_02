#include <iostream>
#include <vector>
#include <iterator>
#include <future>

#include "for_each.h"

int main()
{
    std::vector<double> V {84.7, -46.1, -2.13, 74.0, 9.44, -15.2, 0.447, 18.6, -94.3, -50.8, 27.9};
    
    auto print = [] (const double& el) { std::cout << el << ' '; };
    
    my_func::for_each(V.begin(), V.end(), print);
    std::cout << std::endl;
    
    my_func::for_each(V.begin(), V.end(), [] (double& el) { el *= 2.5; });
    my_func::for_each(V.begin(), V.end(), print);
    std::cout << std::endl;
    
    struct Sum
    {
        void operator() (double val) { sum += val; }
        double sum {0.0};
    };
    
    Sum s;
    my_func::for_each(V.begin(), V.end(), [&s] (double el) {s(el);});
    std::cout << s.sum << std::endl;
    
    return 0;
}
