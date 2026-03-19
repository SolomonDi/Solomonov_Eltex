#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef enum {

    SUM,
    SUBSTR,
    MULT,
    DIV

} Operations;

typedef enum {

    INT,
    DOUBLE

} DataType;

typedef struct {

   DataType d_type; 

    union { 

        int i_v;
        double d_v;

    } value;
}AnyNumber;

typedef AnyNumber (*INT_OP)(int *arg, int count);
typedef AnyNumber (*DOUBLE_OP)(double *arg, int count);


AnyNumber sumInt(int *arg, int count);

AnyNumber sumDouble(double *arg, int count);

AnyNumber substInt(int *arg, int count);

AnyNumber substDouble(double *arg, int count);

AnyNumber multInt(int *arg, int count);

AnyNumber multDouble(double *arg, int count);

AnyNumber divInt(int *arg, int count);

AnyNumber divDouble(double *arg, int count);


AnyNumber runOperation(Operations oper, DataType type, void *arg, int count);

void printNumber(AnyNumber number);


const char *getOp(Operations op);




#endif