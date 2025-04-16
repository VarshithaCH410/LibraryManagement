#include <stdio.h>
#include<string.h>
char stack[100];
int top=-1;
void push(char x)
{
     top=top+1;
     stack[top]=x;
}
void pop()
{
     top--;
}
int main()
{
   char exp[50],ch;
   int i,len;
   printf("Enter expression:");
   scanf("%s",exp);
   len=strlen(exp);
   int flag=0;
   for(i=0;i<len;i++)
   {
    	ch=exp[i];
       	if(ch=='('||ch=='{'||ch=='[')
       		push(ch);
        else if((ch==')'&&stack[top]=='(')||(ch==']'&&stack[top]=='[')||(ch=='}'&&stack[top]=='{'))
        {
       		pop();
       		continue;
       	}
       	else
       	{
       		if(ch==')'||ch=='}'||ch==']' && stack[top]=='\0')
			{
				flag=-1;
			   	break;
		    }	
	    }
   }
   	if(flag==-1)
   		printf("not Balanced");
   	else if(top==-1)
   		printf("Balanced");
   	else
   		printf("not Balanced");
}