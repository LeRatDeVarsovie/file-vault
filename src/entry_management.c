#include <stdio.h>
#include <string.h>

char entry_value[100];
char entry_content[2056];
char new_entry_value[100];
char new_entry_content[2056];

// Prototypes de fonction
void create_entry(void);
void modif_entry_value(char *entry_value);
void modif_entry_content(char *entry_value);

int main() {
  create_entry();
  return 0;
}
void create_entry(void){

  printf("Veuillez nommer votre entree :\n");
  fgets(entry_value, sizeof(entry_value), stdin);
  entry_value[strcspn(entry_value, "\n")] ='\0';

  char filename[100];
  snprintf(filename, sizeof(filename), "%s.vault", entry_value);

  FILE *fichier = fopen(filename, "w");
  if (fichier == NULL){
    perror("Error lors de creation du fichier");
    return;
  }

  int c;
  while ((c=getchar())!= '\n' && c != EOF);

  printf("Veuillez entrer le contenu de %s : \n", entry_value);
  fgets(entry_content, sizeof(entry_content), stdin);


  fprintf(fichier, "%s\n", entry_content);
  fclose(fichier);

  printf("Votre entree a bien ete enrefistree avec comme contenu :\n %s", entry_content);
}

void modif_entry_value(char *entry_value) {
  printf("Modification de l'entrée '%s'\n", entry_value);

  printf("Veuillez entrer la nouvelle valeur :\n");
  fgets(new_entry_value, sizeof(new_entry_value), stdin);
  new_entry_value[strcspn(new_entry_value, "\n")] = '\0';

  printf("Valeur modifiée avec succès : '%s'\n", new_entry_value);
}
void modif_entry_content(char *entry_value){
  printf("Veuillez entrer le nom de l'entree dont vous souhaitez modifier le contenu :\n");
  fgets(new_entry_content, sizeof(new_entry_content), stdin);
  printf(" L'entree %s a ete  modifiee avec succes ayant comme contenu :\n %s", entry_value, entry_content);
}
