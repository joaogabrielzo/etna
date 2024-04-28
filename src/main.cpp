#include "etna.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
    etna::Etna etna{};

    try
    {
        etna.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}