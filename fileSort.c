#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sort
{
    char inputarr[500];
    
}s1;
/* Functions */
void fileread(FILE *fp,FILE *fp3);
void check_comment (char) ;  // checks for both types of comments, then passes on control to below comments
void block_comment () ;   //  handles block or multiline comments
void single_comment () ;   // handles single line comments
/* 2 file pointers - 1st is for the file in which we check for comments,
and 2nd is the file in which we copy the code after removing comments  */
FILE *fp , *fp2,*fp3;

int main()
{
    char c;
    int num;
    fp = fopen ("input.txt","rb") ;   // open the first file in read mode
    fp2 = fopen ("content.txt","a+b") ;    // open the second file in write mode
    fp3 = fopen("comment.txt","a+b");
    printf("Enter 1. seperate comment\n");
     printf("Enter 2. seperate content\n");
    scanf("%d" ,&num);
    
    switch(num)
    {
        case 1: 
        {
            printf("Execute successfully\n");
            fread(s1.inputarr,500,1,fp);
            fileread(fp,fp3);    
            break;
           
        }

        case 2:
        {
            printf("Execute successfully\n");
          while((c=fgetc(fp))!=EOF)   
            {
                // read the file character by character
                check_comment(c); 
            }
            break;
        
        }
        
    }
    
    

    //  close both the files at the end of the program
   
    fclose(fp);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
void fileread(FILE *fp,FILE *fp3)
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
                 fputc(s1.inputarr[j],fp3);

                
            }
            // printf("*/");
            fputs("*/",fp3);
            printf("\n");
            
        }
        
        else if (s1.inputarr[i] == '/'&&s1.inputarr[i+1] == '/')
        {
            
            for ( j = i;k==(s1.inputarr[j] == '\n') ; j++)
            {
            //  printf("%c"  , s1.inputarr[j]);
                 fputc(s1.inputarr[j],fp3);
                
            }
           
            printf("\n");
        }
     
      
        
       
       
    }

}

//handles both types of comments
void check_comment(char c)
{
    char d;

    if( c == '/')   // if the character starts with '/', it 'could' be a comment
    {
        if((d=fgetc(fp))=='*')   // if the next character we read is '*', it is the beginning of multiblock comment
         block_comment();  // pass control to function that handles multiblock comments

        else if( d == '/')   // else if the next character we read is '/', it is the beginning of single line comment
        {
          single_comment();// pass control to function that handles single line comment

        }
        else
        {
            // if both the cases fail, it is not a comment, so we add the character as it is in the new file.
            fputc(c,fp2);
            fputc(d,fp2);
        }
    }

    // again, if all above fails, we add the character as it is in the new file.
    else
        fputc(c,fp2);
}


// function that handles block comments
void block_comment()
{

 char d,e;

    while((d=fgetc(fp))!=EOF)   // the block comment has started, read the character by character
    {
    /* keep reading the characters and do nothing,
    as they do not have to be copied into the new file (we are removing the comments)
    */
        if(d=='*')    // if the comment 'seems' like ending
        {
            e=fgetc(fp);  // check if it actually ends (block comments end with '*/')

            if(e=='/')  // if the comment 'has' ended, return from the function
                return;
        }
   }

}


// function that handles single line comments
void single_comment()
{
 char d,e;

    while((d=fgetc(fp))!=EOF)  // the single line comment has started, read the character by character
    {
    /* keep reading the characters and do nothing,
    as they do not have to be copied into the new file (we are removing the comments)
    */
        if(d=='\n')   // check if the comment ends (single comments end with '\n', or newline)
            return;  // if the comment 'has' ended, return from the function

    }

}

