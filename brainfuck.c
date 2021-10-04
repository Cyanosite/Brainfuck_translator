#include <stdio.h>
int main()
{
    int pos = 0, ciklus = 0, i;
    char szalag[32768] = {0};
    char programkod[] = "++++++++++[>+++++++++<-]>.>++++++++++[>++++++++++<-]>>+++[<+++++>-]<.----.--.<+++[>---<-]>--.<+++[>++++<-]>+.+++.";
    for (i = 0; programkod[i] != 0 && ciklus != -1; ++i)
    {
        if (programkod[i] == '[')
        {
            ++ciklus;
        }
        else if (programkod[i] == ']')
        {
            --ciklus;
        }
    }
    if (ciklus == -1)
    {
        printf("Syntax error!");
        return -1;
    }
    for (i = 0; programkod[i] != 0; ++i)
    {
        switch (programkod[i])
        {
        case '>':
            if (pos == 32768-1)
                return -1;
            ++pos;
            break;
        case '<':
            if (pos == 0)
                return -1;
            --pos;
            break;
        case '+':
            ++szalag[pos];
            break;
        case '-':
            --szalag[pos];
            break;
        case '.':
            printf("%c", szalag[pos]);
            break;
        case ',':
            if ((scanf("%c", &szalag[pos])) == EOF)
                szalag[pos] = -1;
            break;
        case '[':
            if (szalag[pos] == 0)
            {
                ciklus = 1;
                for (++i; ciklus != 0; ++i)
                {
                    if (programkod[i] == '[')
                        ++ciklus;
                    else if (programkod[i] == ']')
                        --ciklus;
                }
                --i;
            }
            break;
        case ']':
            if (szalag[pos] == 0)
            {
                break;
            }
            ciklus = 1;
            for (--i; ciklus != 0 && i > -1; --i)
            {
                if (programkod[i] == '[')
                    --ciklus;
                else if (programkod[i] == ']')
                    ++ciklus;
            }
            ++i;
            break;
        default:
            break;
        }
    }
    return 0;
}