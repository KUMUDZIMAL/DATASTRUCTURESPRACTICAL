#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define size 100
char stack[size];
int top=-1;
void push(char item)
{
if(top>=size-1)
{
printf("\nstack is  overflow\n");
}
else
{
top=top+1;
stack[top]=item;
}
}
char pop()
{
char item;
if(top<0)
{
printf("stack is underflow\n");
getchar();
exit(1);
}
else
{
item=stack[top];
top=top-1;
return item;
}
}
int is_operator(char symbol)
{

if(symbol=='^'||symbol=='+'||symbol=='*'||symbol=='-'||symbol=='/'||symbol=='+')
{
return 1;
}
else
{
return 0;
}
}
int precendence(char symbol)
{
if(symbol=='^')
{
return(3);
}
else if(symbol=='*'||symbol=='/')
{
return(2);
}
else if(symbol=='+'||symbol=='-')
{
return(1);
}
else
{
return(0);
}
}
void infixtopostfix(char infix_exp[],char postfix_exp[])
{
int i,j;
char item;
char x;
push('(');
strcat(infix_exp,")");
i=0;
j=0;
item=infix_exp[i];
while(item!='\0')
{
if(item=='(')
{
push(item);
}
else if(isdigit(item)||isalpha(item))
{
postfix_exp[j]=item;
j++;
}
else if(is_operator(item)==1)
{
x=pop();
while(is_operator(x)==1&&precendence(x)>=precendence(item))
{
postfix_exp[j]=x;
j++;
x=pop();
}
push(x);
push(item);
}
else if(item==')')
{
x=pop();
while(x!='(')
{
postfix_exp[j]=x;
j++;
x=pop();
}
}
else
{
printf("invalid infix expression\n");
getchar();
exit(1);
}
i++;
item=infix_exp[i];
}
if(top>0)
{
printf("invalid infix expression\n");
getchar();
exit(1);
}
postfix_exp[j]='\0';
}
int main()
{
char infix [size],postfix [size];
clrscr();
printf("ASSUMPTION:the infix expression contain single letter variable & single digit constant only\n");
printf("enter infix expression\n");
gets(infix);
infixtopostfix(infix,postfix);
printf("postfix expression ");
puts(postfix);
getch();
return 0;
}


