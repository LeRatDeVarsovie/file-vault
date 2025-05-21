# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>


bool check_password(const char *password) {

    char master_password[250];

    FILE *file = fopen("masterpassword", "r");
    if (file == NULL) {

        printf("Failed opening file.\n");
        exit(1);
    }

    fgets(master_password, sizeof(master_password), file);
    fclose(file);

    return strcmp(password, master_password) == 0;
}
