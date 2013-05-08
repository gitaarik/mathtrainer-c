#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "questions.h"

int main(int argc, char *argv[]) {

    srand(time(NULL));
    questions_init();

    int number_questions = 5;
    int i;
    int total_mistakes = 0;
    time_t start_time = time(NULL);

    for(i = 0; i < number_questions; i++) {
        total_mistakes += ask_question();
    }

    int total_time = difftime(time(NULL), start_time);

    if(total_time < 60) {
        printf("\nTime: %i seconds\n", total_time);
    }
    else {
        printf("\nTime: %i:%i\n", total_time / 60, total_time % 60);
    }

    printf("Mistakes: %i\n\n", total_mistakes);

    return 0;

}
