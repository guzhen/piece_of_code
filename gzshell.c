#include <stdio.h>
#include <string.h>
#define LENGTH 10
#define VERSION "gz [you can not do any thing] shell v0.3\nv[Enter]:show message\nx[Enter]:exit\n"

int main()
{
  char exit = 0;
  while(!exit)
  {
    printf("input:");
    char str[LENGTH];
    int index = 0;
    char eol = 0;

    /* read line */
    do{
      char c = getchar();
      str[index] = c;
      index++;
      if (index == LENGTH || c == '\n')
      {
        eol = 1;
      }
    }while(!eol);
    
    /* process command */
    if (str[0] == 'x' && str[1] == '\n')
    {
      exit = 1;
    }
    else if (str[0] == 'v' && str[1] == '\n')
    {
      printf(VERSION);
    }
    else
    {
      printf("%s\n",str);
    }
    memset(str,0x00,LENGTH);
  }
  return 0;
}
