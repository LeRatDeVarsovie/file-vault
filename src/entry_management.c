#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void create_entry(void) {
  char entry_value[102];
  char entry_content[2056];
  char filename[108];

  printf("Please write your entry name (100 characters max): ");
  if (fgets(entry_value, sizeof(entry_value), stdin) == NULL) {
    perror("Error reading input.");
    exit(1);
  }
  if (strchr(entry_value, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Your entry name exceeds the max length.\n");
    exit(1);
  }

  entry_value[strcspn(entry_value, "\n")] = '\0';

  for (int i = 0; entry_value[i] != '\0'; i++) {
    char c = entry_value[i];
    if (!((c >= 'a' && c <= 'z') ||
          (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') ||
          c == '_' || c == '-')) {
      printf("❌ Invalid character '%c' in entry name. Only letters, numbers, '-' and '_' are allowed.\n", c);
      exit(1);
      // a bit messy verification but allows the user to use accents
    }
  }

  
  snprintf(filename, sizeof(filename), "%s.vault", entry_value);

  printf("Please write the content of %s:\n", entry_value);
  if (fgets(entry_content, sizeof(entry_content), stdin) == NULL) {
    fprintf(stderr, "Error reading content.\n");
    exit(1);
  }

  if (strchr(entry_content, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Your entry content exceeds the max length.\n");
    exit(1);
  }

  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error while creating the file");
    exit(1);
  }

  fprintf(file, "%s\n", entry_content);
  fclose(file);

  printf("Your entry has been registered with the following content:\n%s\n", entry_content);
}

void modif_entry_value(void) {
  char entry_value[102];
  char new_entry_value[102];
  char old_filename[108];
  char new_filename[108];

  printf("Please enter the name of the entry to modify:\n");
  if (fgets(entry_value, sizeof(entry_value), stdin) == NULL) {
    perror("Error reading input.");
    exit(1);
  }

  if (strchr(entry_value, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Your entry name exceeds the max length.\n");
    exit(1);
  }

  entry_value[strcspn(entry_value, "\n")] = '\0';

  for (int i = 0; entry_value[i] != '\0'; i++) {
    char c = entry_value[i];
    if (!((c >= 'a' && c <= 'z') ||
          (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') ||
          c == '_' || c == '-')) {
      printf("❌ Invalid character '%c' in entry name. Only letters, numbers, '-' and '_' are allowed.\n", c);
      exit(1);
      // a bit messy verification but allows the user to use accents
    }
  }

  

  printf("Please enter the new entry name:\n");
  if (fgets(new_entry_value, sizeof(new_entry_value), stdin) == NULL) {
    perror("Error reading input.");
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

void modif_entry_content(void) {
  char entry_value[102];
  char new_entry_content[2056];
  char filename[108];

  printf("Please write down the entry title to modify:\n");
  if (fgets(entry_value, sizeof(entry_value), stdin) == NULL) {
    perror("Error reading input.");
    exit(1);
  }

  if (strchr(entry_value, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Your entry name exceeds the max length.\n");
    exit(1);
  }

  entry_value[strcspn(entry_value, "\n")] = '\0';

  for (int i = 0; entry_value[i] != '\0'; i++) {
    char c = entry_value[i];
    if (!((c >= 'a' && c <= 'z') ||
          (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') ||
          c == '_' || c == '-')) {
      printf("❌ Invalid character '%c' in entry name. Only letters, numbers, '-' and '_' are allowed.\n", c);
      exit(1);
      // a bit messy verification but allows the user to use accents
    }
  }

  
  snprintf(filename, sizeof(filename), "%s.vault", entry_value);

  printf("Please write the new content:\n");
  if (fgets(new_entry_content, sizeof(new_entry_content), stdin) == NULL) {
    perror("Error reading content.");
    exit(1);
  }

  if (strchr(new_entry_content, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Content exceeds the max length.\n");
    exit(1);
  }

  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error while modifying the file");
    exit(1);
  }

  fprintf(file, "%s\n", new_entry_content);
  fclose(file);
  printf("The entry '%s' has been successfully modified.\nNew content:\n%s\n", entry_value, new_entry_content);
}

void delete_entry(void) {
  char entry_value[102];
  char filename[108];

  printf("Please type the entry name you wish to delete:\n");
  if (fgets(entry_value, sizeof(entry_value), stdin) == NULL) {
    perror("Error reading input.");
    exit(1);
  }

  if (strchr(entry_value, '\n') == NULL) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Your entry name exceeds the max length.\n");
    exit(1);
  }

  entry_value[strcspn(entry_value, "\n")] = '\0';


  for (int i = 0; entry_value[i] != '\0'; i++) {
    char c = entry_value[i];
    if (!((c >= 'a' && c <= 'z') ||
          (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') ||
          c == '_' || c == '-')) {
      printf("❌ Invalid character '%c' in entry name. Only letters, numbers, '-' and '_' are allowed.\n", c);
      exit(1);
      // a bit messy verification but allows the user to use accents
    }
  }

    snprintf(filename, sizeof(filename), "%s.vault", entry_value);

  if (remove(filename) != 0) {
    perror("Error while deleting the file");
    exit(1);
  }

  printf("Entry deletion successful: '%s'\n", filename);
}

