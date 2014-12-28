#include <stdio.h>
#include <cs50.h>
#include <math.h>



bool check(int numArray[]);


/**
  * BAD Credit from hacker1
  */
int main(void){

    printf("Number:");
    long long numInput = GetLongLong();
      
    // count digits
    long long tmpNum = numInput;
    int digit = 0;
    
    do
    {
        tmpNum /= 10;    
        digit++;
    }
    while(tmpNum!=0);
    // printf("digit - %d",digit);
    
    
    // turn inputNum into an array of ints
    int numArray[digit];
    tmpNum = numInput;    /* renew the tmpNum */
    
    for(int i = (digit-1); i >= 0 ; i--)
    {
        numArray[i] = tmpNum % (10);
        tmpNum /= (10); 
        // printf("numArray[%d] = %d \n",i,numArray[i]);
    }
    
    
    // check if inputNum is a credit card number
    
   
    switch (numArray[0])
    {
        case 3:
            if ( numArray[1] == 4 || numArray[1] == 7)
            {
                // might be an AXE card
                if ( check(numArray) )
                {
                    printf("AMEX\n");
                
                }
                else
                {
                    printf("INVAILD\n");
                }
            }            
            break;
            
        case 5:
            if ( numArray[1] <= 5 && numArray[1] > 0)
            {
                // might be a MasterCard
                 if ( check(numArray) )
                {
                    printf("MASTERCARD\n");
                
                }
                else
                {
                    printf("INVAILD\n");
                }
            } 
            break;
            
        case 4:
            // might be a VISA
             if ( check(numArray) )
                {
                    printf("VISA\n");
                
                }
                else
                {
                    printf("INVAILD\n");
                }
            break;
        
        default : 
           
            printf("INVALID\n");    
            break;
    
    }
    
    // if run successfully
    return 0;
}



bool check(int numArray[])
{
    
    int sum = 0;
    // first step add every other num
    for ( int i = 1 ; i < sizeof(*numArray) ; i += 2)
    {
    
        int d = numArray[i];
        
        if ( d*2 >= 10)
        {
            sum += ( d/10 + d%10);
        }
        else
        {
            sum += d;
        }
    }
    
    // add odd num
    for ( int i = 0 ; i < sizeof(*numArray) ; i += 2)
    {
    
        sum += numArray[i];
    }
    
    // printf("sum = %d",sum);
    return ( sum%10 == 0 );
}











