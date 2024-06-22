#include <stdio.h>
#include <spdlog/spdlog.h>

#define PROJECT_NAME "testproject"

int main(int argc, char **argv) {
    if(argc != 1) {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
    printf("This is project %s.\n", PROJECT_NAME);
    spdlog::info("i love c++");
    return 0;
}
