#ifndef WORDLE_WORD_LIST_H
#define WORDLE_WORD_LIST_H

#include <string.h>
#include <stdlib.h>

#include "list.h"

FILE *word_get_file(int language);

LIST *word_list_load(int language);

char *word_get_random(LIST *list);

#endif //WORDLE_WORD_LIST_H
