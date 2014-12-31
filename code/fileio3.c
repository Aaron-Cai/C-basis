#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp = fopen("test","wb");
    char x[10] = "ABCDEFGHIJ";

    fwrite(x,sizeof(x[0]),sizeof(x)/sizeof(x[0]),fp);
    printf("write done\n");
    fclose(fp);

    FILE *fp1 = fopen("test","rb");
    char* px = malloc(10*sizeof(char));
    fread(px,sizeof(char),10,fp1);
    printf("%s\n",px );
    fclose(fp1);

    return 0;
}
