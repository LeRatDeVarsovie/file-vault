# include <stdio.h>
# include <stdlib.h>

# include "../include/diskops/diskops.h"
# include "../include/password/password.h"

int main(){

    char password[251];

    if (!(file_exists("masterpassword"))) {

        printf("No password detected, please create a master password (250 Characters Maximum):\n");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0;

        // TODO: Hash `password` using a hashing function.

        file_from_text("masterpassword", password);
    } else {

        printf("Please enter your password:\n");
        scanf("%s", password);

        // TODO: Hash `password` using a hashing function.

        if (!(compare_masterpass(password))) {

            printf("Incorrect password!\n");
            exit(1);
        }
    }

    return 0;
}
