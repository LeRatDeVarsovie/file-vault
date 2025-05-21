#include <stdio.h>
#include <string.h>
#include <time.h>

char entry_value[100];
char entry_content[2056];
char new_entry_value[100];
char new_entry_content[2056];

// Prototypes de fonction
void create_entry(void);
void modif_entry_value(void);
void modif_entry_content(void);
void delete_entry(void);

int main() {
    create_entry();
    delete_entry();
  return 0;
}
//Fonction de creation
void create_entry(void){

  printf("Please write your entry name:");
  fgets(entry_value, sizeof(entry_value), stdin);
  entry_value[strcspn(entry_value, "\n")] ='\0';

  char filename[100];
  snprintf(filename, sizeof(filename), "%s.vault", entry_value);

  FILE *fichier = fopen(filename, "w");
  if (fichier == NULL){
    perror("Error while creating the file");
    return;
  }

  int c;
  while ((c=getchar())!= '\n' && c != EOF);

  printf("Please write the content of %s : \n", entry_value);
  fgets(entry_content, sizeof(entry_content), stdin);


  fprintf(fichier, "%s\n", entry_content);
  fclose(fichier);

  printf("Your entry has been registered with the following content :\n %s", entry_content);
}
//Fonction de modif
void modif_entry_value(void) {
  char new_entry_value[100];
  printf("Modification of entry : '%s'\n", entry_value);

  printf("Please enter a new value :\n");
  fgets(new_entry_value, sizeof(new_entry_value), stdin);
  new_entry_value[strcspn(new_entry_value, "\n")] = '\0';

  char old_filename[100];
  char new_filename[100];
  snprintf(old_filename, sizeof(old_filename), "%s.vault", entry_value);
  snprintf(new_filename, sizeof(new_entry_value), "%s.vault", new_entry_value);

  if (rename(old_filename, new_filename) != 0) {
    perror("Failed to rename file");
    return;
  }

  strcpy(entry_value, new_entry_value);
  printf("Entry modification sucessfull  : '%s'\n", new_entry_value);
}
//Fonction de modif (de content)
void modif_entry_content(void){
  printf("Please write down the entry value of the content you wish to modify :\n");
  fgets(new_entry_value, sizeof(new_entry_value), stdin);
  new_entry_value[strcspn(new_entry_value, "\n")] = '\0';

  char old_file_content[2056];
  char new_entry_content[2056];

  printf("Please write the content :\n");
  fgets(new_entry_content, sizeof(new_entry_content), stdin);
  new_entry_content[strcspn(new_entry_content, "\n")] = '\0';

  FILE *fichier = fopen(entry_value, "w");
  if (fichier == NULL){
    perror("Error while modifying the file");
    return;
  }
  fprintf(fichier, "%s\n", new_entry_content);
  printf(" L'entree %s a ete  modifiee avec succes ayant comme contenu :\n %s", entry_value, new_entry_content);
}
//Fonction de suppression (pour l'instant faut tapper le nom de l'entrée.vault)
void delete_entry(void){
    char entry_value[100];

    printf("Please type the entry value you wish to delete :\n");
    fgets(entry_value, sizeof(entry_value), stdin);
    entry_value[strcspn(entry_value, "\n")] = '\0';

    int error_handle = remove(entry_value);
    if (error_handle != 0){
        perror("Error while deleting the file");
        return;
    }  else{
        printf("Entry deletion successful : '%s'\n", entry_value);
    }

}
// :3
