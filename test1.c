#include <stdio.h>
#include <ctype.h>
int is_only_spaces(char *str)
{
    int i=0;
    int sign = 0;
   while(str[i])
   {
    if(str[i] == '-' || str[i]=='+')
    {
        if(sign)
            return 0;
            sign = 1;
    }
    i++;
   }
   sign =0;
    return 1;
    
}
int is_num(char *str)
{
    int i =0 ;
    int cont_a = 0;
    while(str[i])
    {
    
    if(str[i] == ' ' || str[i] == '\t' && str[i+1] != '\0')
        i++;
    if(!is_only_spaces(str))
        return 0;
    
    else if(str[i] >= '0' && str[i] <= '9')
    {
        i++;
        cont_a = 1;
    }
     else if(str[i] < '0' || str[i] >'9')
        return 0;
    else
        i++;
    }
    if(cont_a)
        return 1;
    return 0;
}
int check(char **str)
{
    int i =1;
    while(str[i])
    {
        if(!is_num(str[i]))
            return 0;
    i++;
    
    }
    return 1;
}

int main(int ac,char **av) {
   printf("%d\n",check(av));

}
