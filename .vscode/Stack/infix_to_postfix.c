#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>

char stack[30],infix[30],prefix[30];
int top = -1, max=30;

void push(int data)
{
    if(top == max-1)
    {
        printf("\nstack overflow occurs\n");
    }
    else 
    {
        top++;
        stack[top] = infix[data];
    }
}


char pop()
{
    char data;
    if(top < 0)
    {
        printf("\nstack overflow occurs\n");
        exit(0);
    }
    else
    {
        data = stack[top];
        stack[top] = '\0';
        top--;
        return(data);
    }
    return 0;
}

int precedence(char ops)
{
    if(ops == '+' || ops =='-')
        return (1);
    else if(ops == '*' || ops =='/')
        return (2);
    else
        return 0;
}


void infix_to_prefix()
{
    int i = 0,j = 0;
    strrev(infix);
    while(infix[i] != '\0')
    {
        if(infix[i] >= 'a' && infix[i] <= 'z')
        {
            prefix[j] = infix[i];
            j++;
            i++;
        }
        else if(infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
        {
            push(i);
            i++;
        }
        else if(infix[i] == '(')
        {
            while(stack[top] != ')') 
            {
                prefix[j] = pop();
                j++;
            }
            pop();
            i++;
        }
        else if(infix[i] == '[')
        {
            while(stack[top] != ']') 
            {
                prefix[j] = pop();
                j++;
            }
            pop();
            i++;
        }
        else if(infix[i] == '{')
        {
            while(stack[top] != '}')
            {
                prefix[j] = pop();
                j++;
            }
            pop();
            i++;           
        }
        else
        {
            if(top == -1)
            {
                push(i);
                i++;
            }

            else if( precedence(infix[i]) < precedence(stack[top]))
            {
                prefix[j] = pop(); 
                j++;
                while(precedence(stack[top]) > precedence(infix[i]))
                {
                    prefix[j] = pop();    
                    j++;
                    if(top < 0) 
                    {
                        break;
                    }
                }
                push(i);
                i++;
            }

            else if(precedence(infix[i]) >= precedence(stack[top]))
            {
                push(i); 
                i++;
            }
        }
    }

    while(top != -1)
    {
        prefix[j] = pop();
        j++;
    }

    strrev(prefix);
    prefix[j] = '\0';
}

int main()
{
    printf("This is the program to convert the infix to prefix");
    printf("\nEnter the Infix Expression\n");
    scanf("%s",infix);
    infix_to_prefix();
    printf("The Prefix Expression is %s ",prefix);
    return 0;
}