# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

bool compare_masterpass(const char *password) {

    char masterpass[251];

    FILE *file = fopen("masterpassword", "r");
    if (file == NULL) {

        printf("Failed opening file.\n");
        exit(1);
    }

    fgets(masterpass, sizeof(masterpass), file);
    fclose(file);

    return strcmp(password, masterpass) == 0;
}
