#ifndef __UTILS_H__
#define __UTILS_H__


#include <iostream>
#define ASSERT(condition, message) scmales::Utils::_assert(condition, message)
namespace scmales
{
    class Utils
    {
    public:
        Utils(/* args */);
        static void _assert(bool condition, const char *message)
        {
            if (!condition)
            {
                std::cout << message << std::endl;
                std::abort();
            }
        }

        ~Utils();
    };

} // namespace scmales
#endif