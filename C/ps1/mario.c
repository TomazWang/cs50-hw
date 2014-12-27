#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int height;
    do
    {
        printf("Height: ");
        height = GetInt();
    }while(height < 0 || height > 23);
  
    
    
    for(int row=0; row < height; row++)
    {

        // for each row, print cols
        for(int col=0; col < height; col++)
        {
            
            if (col < (height - row - 1))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
            
        }
        
        // a new row
        printf("#\n"); 
    }
    
    return 0;
}


