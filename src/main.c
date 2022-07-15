#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#include "word_list.h" 

int main() {
    // set up the random number generator seed
    srand((unsigned) time(NULL));

    // print the logo
    printf(">=============<\n");
    printf("  W O R D L E\n");
    printf(">=============<\n\n");

    // print the menu
    printf("0.) English\n");
    printf("1.) Croatian\n\n");

    // get the selection
    int language;
    scanf("%d", &language);
    getchar();
    if (language < 0 || language > 1) {
        printf("Invalid language selected!\n");
        system("pause");
        system("cls");
        main();
    }
    system("cls");

    // load the word list
    LIST *word_list = word_list_load(language);

    // get the random word from the list
    char *word = word_get_random(word_list);

    // print the word to the console
    //printf("Word: %s", word);

    // Wordle mechanics #1
    int tries = 0, guessed = 0;
    char word_guess[5], temp;
    char wordle[6][5];
    if(word[5]=='\0'){
        word[5]='\n';
    }
    else if(word[5]=='\n'){
        word[5]='\0';
    }
    
    // Populate the array with _
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 5; j++){
            wordle[i][j] = '_';
        }
    }

    // Print the empty array
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 5; j++){
            printf("%c ", wordle[i][j]);
        }
        printf("\n");
    }

    // Wordle mechanics #2
    while(tries != 6){
        printf("Your guess: ");
        fgets(word_guess, 6, stdin);
        getchar();
        system("cls");
        int color = 0;
        for(int i = 0; i < 5; i++){
            wordle[tries][i] = word_guess[i];
        }
        for(int row = 0; row <= 5; row++){
            for(int column = 0; column <= 4; column++){
                temp = wordle[row][column];
                for(int test = 0; test <= 4; test++){
                    if(temp != word[test]){
                        printf("\033[0;37m");
                    }
                    if(temp == word[test] && column == test){
                        printf("\033[0;32m");
                        break;
                    }
                    else if(temp == word[test]){
                        printf("\033[0;33m");
                        break;
                    }
                }
                //yellow printf("\033[0;33m");
                //white printf("\033[0;37m");
                //green printf("\033[0;32m");
                printf("%c ", temp);
                printf("\033[0;37m");
            }
            printf("\n");
        }
        tries ++;
        if(strcmp(word, word_guess) == 0){
            break;
        }
    }
    if(strcmp(word, word_guess) == 0){
        printf("\nYou won! The word was %s.\n", word);
        printf("Congrats! You've guessed the word in %d tries!\n\n", tries);
    }
    else if(tries == 6){
        printf("\nYou lost! The word was %s.\n", word);
        printf("Bummer! You've failed to guess the word under %d tries!\n\n", tries);
    }
    system("pause");
    system("cls");
    main();

    // free the list
    list_free(word_list);

    // return out of the application
    return 0;
}