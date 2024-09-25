#include "libdie.h"
#include <stdio.h>

extern enum CRASH_CODE;

int main(int argc, char* argv) {
    printf("testing crash..\n");
    die(PGRM_INVOKE_FAILURE, "crashed :(");
    return 0;
}