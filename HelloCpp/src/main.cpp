// Including some standard library headers
#include <random>
#include <iostream>

// Including spdlog
#include <spdlog/spdlog.h>

int main()
{
    // Basic Hello world message
    std::cout << "Hello C++" << std::endl;

    // Initializing logger to show every log level in the console
    spdlog::set_default_logger(spdlog::stdout_color_mt("console"));
    spdlog::set_level(spdlog::level::trace);

    // Get a good random number
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 engine(seed);
    std::uniform_int_distribution<unsigned> distribution;
    auto random_number = distribution(engine);

    // Display a basic log message
    SPDLOG_DEBUG("Here is my log message, and a random number: {}", random_number);

    // The End :)
    return EXIT_SUCCESS;
}