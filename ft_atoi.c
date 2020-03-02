#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    if (nb < 0)
    {
        nb = nb * -1;
        ft_putchar('-');
    }
    if (nb > 9)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    if (nb <= 10)
    {
        ft_putchar(nb + '0');
    }
}

int     ft_atoi(char *str)
{
    int i;
    int res;
    int sign;

    i = 0;
    res = 0;
    sign = 1;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return(res * sign);
}

int     main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_putnbr(ft_atoi(argv[1]));
    }
    return(write(1, "\n", 1));
}