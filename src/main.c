# include <stdio.h>
# include <stdlib.h>

# include "../include/diskops/diskops.h"
# include "../include/password/password.h"

int main(){

    char *password;

    if (!(file_exists("masterpassword"))) {

        printf("No password detected, please create a master password (250 Characters Maximum):\n");
        scanf("%s", password);

        if (sizeof(password) > 250) {

            printf("Password too long!\n");
            exit(1);
        }

        // TODO: Hash `password` using a hashing function.

        create_master_password(password);
    } else {

        printf("Please enter your password:\n");
        scanf("%s", password);

        // TODO: Hash `password` using a hashing function.

        if (!(check_password(password))) {

            printf("Incorrect password!\n");
            exit(1);
        }
    }

    return 0;
}
