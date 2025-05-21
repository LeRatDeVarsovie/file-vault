# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

void create_master_password(const char *password) {

    FILE *file = fopen("masterpassword", "w");
    if (file == NULL) {

        printf("Failed creating file.\n");
        exit(1);
    }

    fprintf(file, "%s", password);

    fclose(file);
}

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
