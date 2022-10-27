#include <stdio.h>
#include <string.h>

#define ENCLAVE_FILENAME "enclave.signed.so"

#include "sgx_urts.h"
#include "App.h"
#include "Enclave_u.h"

sgx_enclave_id_t global_eid = 0;

/* ocall functions (untrusted) */
void ocall_app_keyinput(const char *str)
{
    printf("%s", str);
    getchar();
}

/* application entry */
int SGX_CDECL main(int argc, char *argv[])
{
    (void)(argc);
    (void)(argv);

    sgx_status_t ret = SGX_ERROR_UNEXPECTED;

    int untrusted_x = 987654321;

    // initialize enclave
    ret = sgx_create_enclave(ENCLAVE_FILENAME, SGX_DEBUG_FLAG, NULL, NULL, &global_eid, NULL);
    if (ret != SGX_SUCCESS) {
        printf("Enclave init error\n");
        getchar();
        return -1;
    }
 
    // invoke trusted_function();
    int trusted_x;
    ret = trusted_function(global_eid, &trusted_x);
    if (ret != SGX_SUCCESS) {
        printf("Enclave call error\n");
        return -1;
    }

    // destroy the enclave
    sgx_destroy_enclave(global_eid);

    printf ("trusted   value  : %d\n", trusted_x);
    printf ("untrusted value  : %d\n", untrusted_x);

    return 0;
}

