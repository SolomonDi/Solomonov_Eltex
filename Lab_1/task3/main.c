#include<stdio.h>
#include<stdlib.h>
#include"calculator.h"

int main(void) {

    Operations oper;
    DataType data_type;
    int countOfNumber = 0;
    int dataTypeChoice = 0;
    int operChoice = 0;
    char runMode = 'y';

    printf("WELCOME TO THE CALULATOR WITH BASIC MATH OPERATIONS AND INTEGER AND DOUBLE DATA TYPES\n");

    do {

    printf("Before start you need choose the data type which you are going to use in math operations\n");
    printf("| Choose datatype: |\n");
    printf("| 1. INTEGER TYPE  |\n");
    printf("| 2. DOUBLE TYPE   |\n");
    printf("YOUR CHOICE: ");
    scanf("%d", &dataTypeChoice);
    
    if(dataTypeChoice == 1 ){

        data_type = INT;
        printf("YOU HAVE CHOOSEN THE INTEGER TYPE NUMBER \n");
    }
    else if (dataTypeChoice == 2){

        data_type = DOUBLE;
        printf("YOU HAVE CHOOSEN THE DOUBLE TYPE NUMBER \n");
    }

    else{
        printf("WRONG DATATYPE \n");
    }

    printf("| CHOOSE THE OPERATION: |\n");
    printf("| 1.      SUM    (+)    |\n");
    printf("| 2.      SUBSTR (-)    |\n");
    printf("| 3.      MULT   (*)    |\n");
    printf("| 4.      DIV    (/)    |\n");
    printf("CHOOSE OPERATION --> ");
    
    scanf(" %d", &operChoice);

    Operations operation;
    if(operChoice >= 0 && operChoice < 4 ){

        operation = (Operations)(operChoice - 1) ;
        printf("OPERATION CHOOSED: %s\n", getOp(operation));
    }
    
    else{

        printf("WRONG CHOOSE, THEN YOUR STANDART OPERATION SUM\n");
        operation = SUM;
    }

    printf("ENTER HOW MUCH NUMBER YOU WANT OPERATE : ");
    scanf("%d", &countOfNumber);

    if(countOfNumber == 0){
        printf("WRONG NUMBER OF ARGUMENTS\n");
    }

    printf("COUNT OF NUMBERS IS : %d \n ", countOfNumber);
    if(data_type == INT){

        int *numbers = malloc(countOfNumber * sizeof(int));

        for(size_t i = 0; i < countOfNumber; ++i){
            
            printf("Number %zu = ", i + 1);
            scanf("%d", &numbers[i]);
        }

        AnyNumber result = runOperation(operation, INT, numbers, countOfNumber);

        printf("RESULT = ");
        printNumber(result);

        free(numbers);
    }
    else{

        double *numbers = malloc(countOfNumber * sizeof(double));

        for (size_t i = 0; i < countOfNumber; ++i){

            printf(" Number %zu = ", i + 1);
            scanf("%lf", &numbers[i]);
        }

        AnyNumber result = runOperation(operation, DOUBLE, numbers, countOfNumber);

        printf("RESULT = ");
        printNumber(result);

        free(numbers);
    }
    printf("\n");
    printf("DO YOU WANT TO CONTINUE(PLEASE NO) Y/N --> ");
    scanf(" %c", &runMode);

    } while(runMode != 'n' && runMode != 'N');


    return 0;

}












