#ifndef FOR_EACH_H
#define FOR_EACH_H

namespace my_func
{

template<class It, class Function, size_t max_serial_execution_size = 4>
void for_each(It begin, It end, Function f)
{
    size_t current_size = std::distance(begin, end);
    if (current_size <= max_serial_execution_size)
    {
        for (auto it = begin; it != end; it++)
        {
            f(*it);
        }
        return;
    }
    
    auto mid = begin;
    std::advance(mid, current_size / 2);
    
    std::future<void> ft_res = std::async(std::launch::async, my_func::for_each<It, Function>, mid, end, f);
    my_func::for_each(begin, mid, f);
    
    ft_res.wait();
}

}

#endif // FOR_EACH_H
