#include "../push_swap.h"
void chose_sort(int len, t_stack *sa, t_stack *sb,int *tab)
{
    if(len == 3)
        sort_three(&sa);
    else if(len > 5 && len <= 100)
        sort(&sa, &sb,tab,len,len/4);
    else
        sort(&sa, &sb,tab,len,30);
}