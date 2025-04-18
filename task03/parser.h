#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_ARG_MAX_BYTES 128

typedef struct config_option config_option;
typedef config_option* config_option_t;

struct config_option {
    config_option_t prev;
    char key[CONFIG_ARG_MAX_BYTES];
    char value[CONFIG_ARG_MAX_BYTES];
};

config_option_t read_config_file(const char* path) {  
    FILE* fp;
    
    if ((fp = fopen(path, "r+")) == NULL) {
        perror("fopen()");
        return NULL;
    }
    
    config_option_t last_co_addr = NULL;
    
    while (1) {
        config_option_t co = (config_option_t)calloc(1, sizeof(config_option));  
        if (co == NULL) {
            continue;
        }
        memset(co, 0, sizeof(config_option));
        co->prev = last_co_addr;
        
        if (fscanf(fp, "%s = %s", co->key, co->value) != 2) {
            if (feof(fp)) {
                free(co);  // Prevent memory leak on EOF
                break;
            }
            if (co->key[0] == '#') {  // Handle comments
                while (fgetc(fp) != '\n');
                free(co);
                continue;
            }
            perror("fscanf()");
            free(co);
            continue;
        }
        last_co_addr = co;
    }
    fclose(fp);  // Close the file
    return last_co_addr;
}
