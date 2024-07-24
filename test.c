// #include "push_swap.h"
// int check(char **str)
// {
//     int i;
//     int j;
//     int sign;

//     i = 1;
//     while (str[i])
//     {
//         j = 0;
//         sign = 0;
//         while (str[i][j] == ' ' || str[i][j] == '\t')
//             j++;
//         if (str[i][j] == '\0') return 0;
//         while (str[i][j])
//         {
//             if (str[i][j] == '-' || str[i][j] == '+')
//             {
//                 if (sign) return 0;  
//                 sign = 1;
//                 j++;
//                 if (str[i][j] == '\0') return 0; 
//             }
//             else if (str[i][j] == ' ' || str[i][j] == '\t')
//             {
//                 while (str[i][j] == ' ' || str[i][j] == '\t')
//                     j++;
//                 if (str[i][j] && (str[i][j] < '0' || str[i][j] > '9'))
//                     return 0;
//             }
//              if (str[i][j] < '0' || str[i][j] > '9')
//                 return 0;
//             j++;
//         }
//         i++;
//     }
//     return 1;
// }


// int main(int ac,char **av)
// {
//     printf("%d",check(av));
// }