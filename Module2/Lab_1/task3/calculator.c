#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculator.h"

AnyNumber sumInt(int *arg, int count){
    
    if(count <= 0)
        return (AnyNumber){INT, .value.i_v = 0};

    int sum = 0;

    for (size_t i = 0; i < count; ++i)
        sum += arg[i];

    return (AnyNumber){INT, .value.i_v = sum};

}

AnyNumber sumDouble(double *arg, int count){

    if(count <= 0)
        return (AnyNumber){DOUBLE, .value.d_v = 0};

    double sum = 0.0;

    for (int i = 0; i < count; ++i)
        sum += arg[i];


    return (AnyNumber){DOUBLE, .value.d_v = sum};
}

AnyNumber substInt(int *arg, int count){

    if(count <= 0)
        return (AnyNumber){INT, .value.i_v = 0};

    int subst = arg[0];

    for (int i = 1; i < count; ++i)
        subst -= arg[i];


    return (AnyNumber){INT, .value.i_v = subst};
}

AnyNumber substDouble(double *arg, int count){

    if(count <= 0)
        return (AnyNumber){DOUBLE, .value.d_v = 0.0};

    double subst = arg[0];

    for (int i = 1; i < count; ++i)
        subst -= arg[i];

    return (AnyNumber){DOUBLE, .value.d_v = subst};
}

AnyNumber multInt(int *arg, int count){

    if(count <= 0)
        return (AnyNumber){INT, .value.i_v = 0};

    int mult = 1;

    for (int i = 0; i < count; ++i)
        mult *= arg[i];

    return (AnyNumber){INT, .value.i_v = mult};
}

AnyNumber multDouble(double *arg, int count){

    if(count <= 0)
        return (AnyNumber){DOUBLE, .value.d_v = 0};

    double mult = 1.0;

    for (int i = 0; i < count; ++i)
        mult *= arg[i];
   
    return (AnyNumber){DOUBLE, .value.d_v = mult};
}

AnyNumber divInt(int *arg, int count){

    if(count <= 0)
        return (AnyNumber){INT, .value.i_v = 0};

    int div = arg[0];

    for (int i = 1; i < count; ++i){

        if(arg[i] == 0){
            return (AnyNumber){INT, .value.i_v = 0};
        }

        div /= arg[i];
    }

    return (AnyNumber){INT, .value.i_v = div};
}

AnyNumber divDouble(double *arg, int count){

    if(count <= 0)
        return (AnyNumber){DOUBLE, .value.d_v = 0};

    double div = arg[0];

    for (size_t i = 1; i < count; i++){

        if(arg[i] == 0){
            return (AnyNumber){DOUBLE, .value.d_v = 0};
        }

        div /= arg[i];
    }

    return (AnyNumber){DOUBLE, .value.d_v = div};
}


INT_OP intOperations[] = { sumInt, substInt, multInt, divInt };
DOUBLE_OP doubleOperation[] = { sumDouble, substDouble, multDouble, divDouble}; 

AnyNumber runOperation(Operations oper, DataType type, void *arg, int count){

    if (type == INT){

        return intOperations[oper]((int*)arg, count);
    }

    else{

        return doubleOperation[oper]((double*)arg, count);
    }
}

void printNumber(AnyNumber number){

    if (number.d_type == INT){
        printf("%d ", number.value.i_v);
    }

    else{
        printf("%f ", number.value.d_v);
    }
}


const char *getOp(Operations op){

    switch(op){

        case SUM: return "SUM";
        case SUBSTR: return "SUBSTR";
        case MULT: return "MULTIPLICATION";
        case DIV: return "DIV";
        default : return "UNKNOWN OPERATION";
    }
}
