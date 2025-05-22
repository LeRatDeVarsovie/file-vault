
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fonction de création
void create_entry(void){
  char entry_value[101];
  char entry_content[2056];
  char filename[128];

  printf("Please write your entry name (100 characters max): ");
  if (fgets(entry_value, sizeof(entry_value), stdin) == NULL) {
    fprintf(stderr, "Error reading input.\n");
    exit(1);
  }

  if (strchr(entry_value, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Your entry name exceeds the max length.\n");
    exit(1);
  }

  entry_value[strcspn(entry_value, "\n")] = '\0';

  snprintf(filename, sizeof(filename), "%s.vault", entry_value);

  FILE *fichier = fopen(filename, "w");
  if (fichier == NULL){
    perror("Error while creating the file");
    exit(1);
  }

  printf("Please write the content of %s:\n", entry_value);
  if (fgets(entry_content, sizeof(entry_content), stdin) == NULL) {
    fprintf(stderr, "Error reading content.\n");
    fclose(fichier);
    exit(1);
  }

  if (strchr(entry_content, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Your entry content exceeds the max length.\n");
    fclose(fichier);
    exit(1);
  }

  entry_content[strcspn(entry_content, "\n")] = '\0';
  fprintf(fichier, "%s\n", entry_content);
  fclose(fichier);

  printf("Your entry has been registered with the following content:\n%s\n", entry_content);
}

// Fonction de modification du nom
void modif_entry_value(void) {
  char entry_value[101];
  char new_entry_value[101];
  char old_filename[128];
  char new_filename[128];

  printf("Please enter the name of the entry to modify:\n");
  if (fgets(entry_value, sizeof(entry_value), stdin) == NULL) {
    fprintf(stderr, "Error reading input.\n");
    exit(1);
  }

  if (strchr(entry_value, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Your entry name exceeds the max length.\n");
    exit(1);
  }

  entry_value[strcspn(entry_value, "\n")] = '\0';

  printf("Please enter the new entry name:\n");
  if (fgets(new_entry_value, sizeof(new_entry_value), stdin) == NULL) {
    fprintf(stderr, "Error reading input.\n");
    exit(1);
  }

  if (strchr(new_entry_value, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("New entry name exceeds the max length.\n");
    exit(1);
  }

  new_entry_value[strcspn(new_entry_value, "\n")] = '\0';

  snprintf(old_filename, sizeof(old_filename), "%s.vault", entry_value);
  snprintf(new_filename, sizeof(new_filename), "%s.vault", new_entry_value);

  if (rename(old_filename, new_filename) != 0) {
    perror("Failed to rename file");
    exit(1);
  }

  printf("Entry renamed successfully: '%s'\n", new_entry_value);
}

// Modification du contenu d'une entrée
void modif_entry_content(void){
  char entry_value[101];
  char new_entry_content[2056];
  char filename[128];

  printf("Please write down the entry title to modify:\n");
  if (fgets(entry_value, sizeof(entry_value), stdin) == NULL) {
    fprintf(stderr, "Error reading input.\n");
    exit(1);
  }

  if (strchr(entry_value, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Your entry name exceeds the max length.\n");
    exit(1);
  }

  entry_value[strcspn(entry_value, "\n")] = '\0';
  snprintf(filename, sizeof(filename), "%s.vault", entry_value);

  printf("Please write the new content:\n");
  if (fgets(new_entry_content, sizeof(new_entry_content), stdin) == NULL) {
    fprintf(stderr, "Error reading content.\n");
    exit(1);
  }

  if (strchr(new_entry_content, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Content exceeds the max length.\n");
    exit(1);
  }

  new_entry_content[strcspn(new_entry_content, "\n")] = '\0';

  FILE *fichier = fopen(filename, "w");
  if (fichier == NULL){
    perror("Error while modifying the file");
    exit(1);
  }

  fprintf(fichier, "%s\n", new_entry_content);
  fclose(fichier);
  printf("The entry '%s' has been successfully modified.\nNew content:\n%s\n", entry_value, new_entry_content);
}

// Suppression d'une entrée
void delete_entry(void){
  char entry_value[101];
  char filename[128];

  printf("Please type the entry name you wish to delete:\n");
  if (fgets(entry_value, sizeof(entry_value), stdin) == NULL) {
    fprintf(stderr, "Error reading input.\n");
    exit(1);
  }

  if (strchr(entry_value, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Your entry name exceeds the max length.\n");
    exit(1);
  }

  entry_value[strcspn(entry_value, "\n")] = '\0';
  snprintf(filename, sizeof(filename), "%s.vault", entry_value);

  if (remove(filename) != 0){
    perror("Error while deleting the file");
    exit(1);
  }

  printf("Entry deletion successful: '%s'\n", filename);
}
