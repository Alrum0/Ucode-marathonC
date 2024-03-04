#include "minilibmx.h"
#include "calculator.h"


int main(int argv, char* argc[]) {
        if (argv != 4) {
        write(2,"usage: ./calc [operand1] [operation] [operand2]\n", 48);
        exit(-1);
    }
    enum e_error my_error = -1;

    char *operand1 = mx_strdup(argc[1]);
    char *operand2 = mx_strdup(argc[3]);
    char *operation = mx_strdup(argc[2]);

    if (mx_atoi(operand1) == -351351351 || mx_atoi(operand2) == -351351351)
    {

        my_error = INCORRECT_OPERAND;
    }
    
    else if(mx_strlen(operation) != 1 || (operation[0] != '+' && operation[0] != '-' && operation[0] != '*' && operation[0] != '/' && operation[0] != '%')){

        my_error = INCORRECT_OPERATION;
    }
    else if(mx_atoi(operand2) == 0 && (operation[0] = '/')){
        my_error = DIV_BY_ZERO;
    }

    if (my_error == INCORRECT_OPERAND) {
        write(2,"error: invalid number\n", 22);
        exit(-1);
    }
    if (my_error == INCORRECT_OPERATION) {
        write(2,"error: invalid operation\n", 25);
        exit(-1);
    }
    if (my_error == DIV_BY_ZERO) {
        write(2,"error: division by zero\n", 24);
        exit(-1);
    }
    enum e_operation my_operation = SUB;
    switch (operation[0]) {
    case '-':
        my_operation = SUB;
        break;
    case '+':
        my_operation = ADD;
        break;
    case '*':
        my_operation = MUL;
        break;
    case '/':
        my_operation = DIV;
        break;
    case '%':
        my_operation = MOD;
        break;
    }
    t_operation result;
    result.op = operation[0];
    switch (my_operation)
    {
    case SUB:
        result.f = mx_sub;
        break;
    case ADD:
        result.f = mx_add;
        break;
    case MUL:
        result.f = mx_mul;
        break;
    case DIV:
        result.f = mx_div;
        break;
    case MOD:
        result.f = mx_mod;
        break;
    }
    int out_result = (int)result.f(mx_atoi(operand1), mx_atoi(operand2));
    printf("%d\n", out_result);
}


