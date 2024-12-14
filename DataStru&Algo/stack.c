#include <stdio.h>


// Stack implementation with array
// Only support push an pop
#define MAX_SIZE 100


typedef struct MyStack{
    int currTop;
    int stackArr[MAX_SIZE];
}MyStack;

MyStack* stackInit(MyStack*);
MyStack* stackPush(MyStack*, int);
MyStack* stackPop(MyStack*);

int main(){
    MyStack *myS = (MyStack*) malloc(sizeof(MyStack));
    stackInit(myS);
    stackPush(myS, 5);
    stackPop(myS);
    free(myS);
    myS = NULL;
    return 0;
}

MyStack* stackInit(MyStack* myS){
    myS->currTop = 0;
    return myS;
}

MyStack* stackPush(MyStack* myS, int value){
    if(myS->currTop == MAX_SIZE){
        printf("stack is full\n");
        return myS;
    }
    myS->stackArr[myS->currTop] = value;
    myS->currTop +=1;
    return myS;
}
MyStack* stackPop(MyStack* myS){
    if(myS->currTop == 0){
        printf("stack already empty\n");
        return myS;
    }
    myS->currTop -=1;
    return myS;
}