#include "word_list.h"

FILE *word_get_file(int language) {
    return fopen(language == 0 ? "D:/Korisnici/spaji/Dokumenti/Programiranje/Wordle/res/words_english.txt" : "D:/Korisnici/spaji/Dokumenti/Programiranje/Wordle/res/words_croatian.txt", "r");
}

LIST *word_list_load(int language) {
    LIST *list = list_create();
    FILE *file = word_get_file(language);

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *data = (char *) calloc(256, sizeof(char));
        strcpy(data, line);
        list_add(list, data);
    }

    fclose(file);
    return list;
}

char *word_get_random(LIST *list) {
    int size = list->size;
    int index = (int) (((float) rand() / (float) RAND_MAX) * (float) size);
    if (index < 0)
        index *= -1;

    return list_get(list, index);
}