#include<stdio.h>
#include<string.h>
struct sort
{
    char inputarr[500];
    char comment[500];
    char content[500];
}s1;
void fileread(FILE *input,FILE *comment,FILE *content)
{
    int i,j,k=0;
    for ( i = 0; i < strlen(s1.inputarr); i++)
    {
        //    printf("%c"  , s1.inputarr[i]);
        
               
         if (s1.inputarr[i] == '/'&&s1.inputarr[i+1] == '*')
        {
        //    printf("%d"  , i);
        //    printf("%c"  , s1.inputarr[i]);

            for ( j = i;k==(s1.inputarr[j] == '*'&&s1.inputarr[j+1] == '/') ; j++)
            {
                //    printf("%c"  , s1.inputarr[j]);
                 fputc(s1.inputarr[j],comment);

                
            }
            fputs("*/",comment);
            printf("\n");
            
        }
        
        else if (s1.inputarr[i] == '/'&&s1.inputarr[i+1] == '/')
        {
            
            for ( j = i;k==(s1.inputarr[j] == '\n') ; j++)
            {
            //  printf("%c"  , s1.inputarr[j]);
                 fputc(s1.inputarr[j],comment);
                
            }
           
            printf("\n");
        }
        else if ()
        {
           
        }
        
       
        
       
    }
    
    
    
}
int main()
{
    FILE *input,*comment,*content;
    input = fopen("input.txt","rb");
    comment = fopen("comment.txt","w+b");
    content = fopen("content.txt","w+b");
    fread(&s1.inputarr,500,1,input);
   fileread(input,comment,content);

    // fwrite(s1.comment,strlen(s1.comment),1,comment);

    // fwrite(s1.content,strlen(s1.content),1,content);
    fclose(input);
    fclose(comment);
    fclose(content);
    return 0;
}
