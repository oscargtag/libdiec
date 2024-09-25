#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum CRASH_CODE {
    // (other) error codes go here
    UNDEFINED = -1,
    EXIT = 0,

    // 1** error codes. fatals
    FATAL_SYSHEADER_NOT_FOUND = 100,
    FATAL_SYSHEADER_CRASH = 101,
    FATAL_SYSHEADER_CALL_DEATH = 102,
    FATAL_SYSHEADER_UNKNOWN = 1000,

    FATAL_HEADER_NOT_FOUND = 110,
    FATAL_HEADER_CRASH = 111,
    FATAL_HEADER_CALL_DEATH = 112,
    FATAL_HEADER_UNKNOWN = 1100,

    FATAL_MEM_ALLOC_FAILURE = 120,
    FATAL_MEM_ALLOC_SEG_FAULT = 121,
    FATAL_MEM_ALLOC_EXCEEDED = 122,
    FATAL_MEM_ALLOC_UNKNOWN = 1200,

    FATAL_MEM_SYSTEM_MAX = 130,
    FATAL_MEM_SYSTEM_LIMITED = 131,
    FATAL_MEM_SYSTEM_DEALLOCATED = 132,
    FATAL_MEM_SYSTEM_UNKNOWN = 1300,

    FATAL_UNKNOWN = 1,

    // 2** error codes, program-defined errors
    PRGM_USER_ACTION_FAILURE = 200,
    PRGM_USER_ACTION_NOT_PERMITTED = 201,
    PRGM_USER_ACTION_UNKNOWN = 2000,

    PRGM_INTERNAL_PANIC = 210,
    PRGM_INTERNAL_DIE = 211,
    PRGM_RECOVER_FAILURE = 212,

    PRGM_UNKNOWN = 2,

    // 22** for your own custom errors
    PGRM_INVOKE_FAILURE = 220,
    PRGM_PRE_CUSTOM_ERROR = 2200,
};

void die(enum CRASH_CODE exit_code, char* message) {
    bool message_defined = false;
    bool crash_defined = false;
    
    if (message != NULL) { message_defined = true; };
    if (exit_code != NULL) { crash_defined = true; };

    if (crash_defined && message_defined) {
        printf("die: crash_code=%i. message=%s.\n", exit_code, message);
    } else if (crash_defined) {
        printf("die: crash_code=%i", exit_code);
    } else {
        printf("die[error]: program attempted to crash, but invoked die() wrong");
    }
}