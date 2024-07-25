#include <stdbool.h>
#include <stdlib.h>

#include "fork.h"
#include "thread.h"

int main(void) {
    create_thread();
    return EXIT_SUCCESS;
}
