#include "Enclave_t.h"
#include <stdio.h>
#include <string.h>

int trusted_function()
{
    int trusted_x = 987654321;
    ocall_app_keyinput("Please enter keyboard to show variables in memory ...");
    return trusted_x;
}
