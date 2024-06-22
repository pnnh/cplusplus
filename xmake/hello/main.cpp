extern "C"
{
#include <stdio.h>
}

#include <spdlog/spdlog.h>

int main()
{
    printf("%s", "hello\n");
    spdlog::info("i love c++");
}