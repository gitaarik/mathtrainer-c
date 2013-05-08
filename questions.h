void questions_init();
int ask_question();
typedef struct {
    int first;
    int second;
    int answer;
    char calc_type;
} Question;
Question get_question();
int random_number();
char random_calc_type();
