#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 100
char stack[N];
char infix[N];
char postfix[N];
int top=-1;
void push(int val){
    if(top<N){
        top++;
        stack[top]=val;
    }
    else{
        printf("Stack overflow");
    }
}
int pop(){
    if(top<=-1){
        printf("Stack underflow");
    }
    else{
        int c=stack[top];
        top--;
        return c;
    }
}
int isEmpty(){
    if(top<=-1){
        return 1;
    }
    else{
        return 0;
    }
}
int precedence(char symbol){
    if(symbol=='^'){
        return 3;
    }
    else if(symbol =='/' || symbol == '*'){
        return 2;
    }
    else if(symbol == '+' || symbol == '-'){
        return 1;
    }
    else{
        return 0;
    }
}
int space(char symbol){
    if(symbol == ' ' || symbol == '\t'){
        return 1;
    }
    else{
        return 0;
    }
}
void infixTOpostfix(){
    char symbol,popped_element;
    int j=0;
    for(int i=0;i < strlen(infix);i++) {                    //strlen(infix) return size of infix array excluding '/0'
        symbol=infix[i];
        if(!space(symbol)){                               // if symbol is not a white space
            switch(symbol){
                case '(':
                push(symbol);
                break;
                case ')':
                while ((popped_element=pop())!='(')
                {
                    postfix[j++]=popped_element;
                }
                break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                while(!isEmpty() && precedence(stack[top])>=precedence(symbol)){
                    postfix[j++]=pop();
                }
                push(symbol); 
                break;
                default:
                postfix[j++]=symbol;
            }
        }    
    }
    while(!isEmpty()){                        //for all left in stack 
            postfix[j++]=pop();
        postfix[j]='\0';
        }
}
int postfixEvaluation(){
    int a,b;
    for(int i=0;i<strlen(postfix);i++){
        //operand
        if(postfix[i]>='0' && postfix[i]<='9'){
            push(postfix[i]-'0');   //always putting integar in stack rather than character
        }
        else{
            //operator
            a=pop();
            b=pop();
            if(postfix[i]=='+'){
                push(b+a);
            }
            else if(postfix[i]=='-'){
                push(b-a);
            }
            else if(postfix[i] == '*'){
                push(b*a);
            }
            else if(postfix[i]=='/'){
                push(b/a);
            }
            else{
                push(pow(b,a));
            }
        }
    }
}

void print(){
    printf("The equivalent postfix expression is:  ");
    for(int i=0;i<strlen(postfix);i++){
        printf("%c",postfix[i]);
    }
    printf("\n");
}

int main(){
    printf("Enter the infix expression:");
    gets(infix);
    infixTOpostfix();
    print();
    int result=postfixEvaluation();
    // print();
    printf("The result obtained after postfix evaluation is:");
    printf("%d\n",result);   
}