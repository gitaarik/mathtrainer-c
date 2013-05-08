#include <stdio.h>
#include <stdlib.h>
#include "questions.h"

Question last_question;

void questions_init() {
    last_question.first = 0;
    last_question.second = 0;
    last_question.calc_type = '+';
}

int ask_question() {

    Question question = get_question();
    int user_answer;
    int attempts = 0;

    while(attempts == 0 || user_answer != question.answer) {

        if(attempts > 0) {
            printf("Fout!\n");
        }

        attempts++;

        printf("\n%i %c %i\n", question.first, question.calc_type, question.second);
        scanf("%i", &user_answer);

    }

    return attempts - 1;

}

Question get_question() {

    Question new_question;
    int generated = 0;

    while(
        !generated ||
        (new_question.first == last_question.first &&
        new_question.second == last_question.second &&
        new_question.calc_type == last_question.calc_type)
    ) {

        new_question.first = random_number();
        new_question.second = random_number();
        new_question.calc_type = random_calc_type();

        switch(new_question.calc_type) {

            case '+':
                new_question.answer = new_question.first + new_question.second;
                break;

            case '-':

                if(new_question.second > new_question.first) {
                    int second;
                    second = new_question.second;
                    new_question.second = new_question.first;
                    new_question.first = second;
                }

                new_question.answer = new_question.first - new_question.second;

                break;

            case '*':
                new_question.answer = new_question.first * new_question.second;
                break;

            case '/':
                new_question.answer = new_question.first;
                new_question.first = new_question.first * new_question.second;
                break;

        }

        generated = 1;

    }

    last_question.first = new_question.first;
    last_question.second = new_question.second;
    last_question.calc_type = new_question.calc_type;

    return new_question;

}

int random_number() {
    return (rand() % 9) + 1;
}

char random_calc_type() {

    char calc_type;

    switch(rand() % 4) {

        case 0:
            calc_type = '+';
            break;

        case 1:
            calc_type = '-';
            break;

        case 2:
            calc_type = '*';
            break;

        case 3:
            calc_type = '/';
            break;

    }

    return calc_type;

}
