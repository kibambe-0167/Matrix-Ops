
// program to solve the inverse of the matrix
// it returns the inverse of a matrix
// and some other basic things

#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COLUMN 3

struct matrixdata {
    int location[ ROW ][ COLUMN ];
    int equation_value[ ROW ];
};
typedef struct matrixdata DATA;

void printformat();
void printcolumn( int columnvalue, int rowvalue );


int main()
{
    DATA data;
    int row, column, count, determinant;
    int a1, a2, a3, b1, b2, b3, c1, c2, c3;
    int A1, A2, A3, B1, B2, B3, C1, C2, C3;
    int AA1, AA2, AA3, BB1, BB2, BB3, CC1, CC2, CC3;
    
    printformat();
    
    for( row = 0 ; row < ROW ; row++ )
    {
        for( column = 0 ; column < COLUMN ; column++ )
        {
            printcolumn( column, row );
            scanf( "%d", &data.location[ row ][ column ] );
        }
    }
    
    /*
    for( count = 0 ; count < ROW ; count++ )
    {
        printf( "\nEquation %d is equal to : ", count + 1 );
        scanf( "%d", &data.equation_value[ count ] );
    } */
    
    //finding the minors of the matrix
    a1 = (( data.location[1][1]*data.location[2][2] ) - ( data.location[2][1]*data.location[1][2] ));
    a2 = (( data.location[0][1]*data.location[2][2] ) - ( data.location[2][1]*data.location[0][2] ));
    a3 = (( data.location[0][1]*data.location[1][2] ) - ( data.location[1][1]*data.location[0][2] ));
    
    b1 = (( data.location[1][0]*data.location[2][2] ) - ( data.location[2][0]*data.location[1][2] ));
    b2 = (( data.location[0][0]*data.location[2][2] ) - ( data.location[2][0]*data.location[0][2] ));
    b3 = (( data.location[0][0]*data.location[1][2] ) - ( data.location[1][0]*data.location[0][2] ));
    
    c1 = (( data.location[1][0]*data.location[2][1] ) - ( data.location[2][0]*data.location[1][1] ));
    c2 = (( data.location[0][0]*data.location[2][1] ) - ( data.location[2][0]*data.location[0][1] ));
    c3 = (( data.location[0][0]*data.location[1][1] ) - ( data.location[1][0]*data.location[0][1] ));
    
    //getting the cofactors of the matrix
    a2 *= -1;
    b1 *= -1;
    c2 *= -1;
    b3 *= -1;
    
    //getting the adjoint of the natrix
    A1 = a1;
    A2 = b1;
    A3 = c1;
    
    B1 = a2;
    B2 = b2;
    B3 = c2;
    
    C1 = a3;
    C2 = b3;
    C3 = c3;
    
    printf( "The adjoint of the matrix is :\n" );
    printf( "\n%3d  %3d  %3d\n%3d  %3d  %3d\n%3d  %3d  %3d\n", A1, B1, C1, A2, B2, C2, A3, B3, C3 );
    
    AA1 = (( A1*data.location[0][0] ) + ( B1*data.location[1][0] ) + ( C1*data.location[2][0] ));
    BB1 = (( A1*data.location[0][1] ) + ( B1*data.location[1][1] ) + ( C1*data.location[2][1] ));
    CC1 = (( A1*data.location[0][2] ) + ( B1*data.location[1][2] ) + ( C1*data.location[2][2] ));
    
    AA2 = (( A2*data.location[0][0] ) + ( B2*data.location[1][0] ) + ( C2*data.location[2][0] ));
    BB2 = (( A2*data.location[0][1] ) + ( B2*data.location[1][1] ) + ( C2*data.location[2][1] ));
    CC2 = (( A2*data.location[0][2] ) + ( B2*data.location[1][2] ) + ( C2*data.location[2][2] ));
    
    AA3 = (( A3*data.location[0][0] ) + ( B3*data.location[1][0] ) + ( C3*data.location[2][0] ));
    BB3 = (( A3*data.location[0][1] ) + ( B3*data.location[1][1] ) + ( C3*data.location[2][1] ));
    CC3 = (( A3*data.location[0][2] ) + ( B3*data.location[1][2] ) + ( C3*data.location[2][2] ));
    
    printf( "\nThe identity of the matrix is :\n" );
    printf( "\n%3d  %3d  %3d\n%3d  %3d  %3d\n%3d  %3d  %3d\n\n", AA1, BB1, CC1, AA2, BB2, CC2, AA3, BB3, CC3 );
    
    if( AA1 == 0 && BB2 == 0 && CC3 == 0 )
    {
        printf( "CANT SOLCVE FOR THE INVERSE, CAUSE THE DETERMINANT IS ZERO!\n" );
    }
    
    else
    {
        determinant = AA1;
        printf( "The determinant : %d.\n\n", determinant );
        
        printf( "The inverse of the matrix is:\n\n" );
        
        printf( "\t[%3d%4d%4d]\n   1/%3d[%3d%4d%4d]\n\t[%3d%4d%4d]\n", A1, B1, C1, determinant, A2, B2, C2, A3, B3, C3 );
    }
    
    
    return 0;
}


void printformat()
{
    puts( "The equation in matrix form is :\n");
    
    printf( "\t[ A1 B1 C1 ] ( x )   ( equation 1 value )\n" );
    printf( "\t[ A2 B2 C2 ] ( y ) = ( equation 2 value )\n" );
    printf( "\t[ A3 B3 C3 ] ( z )   ( equation 3 value )\n" );
}

void printcolumn( int columnvalue, int rowvalue )
{
     switch( rowvalue )
    {
        case 0:
            if( columnvalue == 0 )
            {
                printf( "\nEnter A%d :", rowvalue + 1 );
            }
           
            else if( columnvalue == 1 )
            {
                printf( "\nEnter B%d :", rowvalue + 1 );
            }
            
            else if( columnvalue == 2 )
            {
                printf( "\nEnter C%d :", rowvalue + 1 );
            }
           
            else {
                printf( "\nInvalid column!" );
            }
        break;
                
        case 1:
            if( columnvalue == 0 )
            {
                printf( "\nEnter A%d :", rowvalue + 1 );
            }
           
            else if( columnvalue == 1 )
            {
                printf( "\nEnter B%d :", rowvalue + 1 );
            }
            
            else if( columnvalue == 2 )
            {
                printf( "\nEnter C%d :", rowvalue + 1 );
            }
           
            else {
                printf( "\nInvalid column!" );
            }
        break;
                
        case 2:
            if( columnvalue == 0 )
            {
                printf( "\nEnter A%d :", rowvalue + 1 );
            }
           
            else if( columnvalue == 1 )
            {
                printf( "\nEnter B%d :", rowvalue + 1 );
            }
            
            else if( columnvalue == 2 )
            {
                printf( "\nEnter C%d :", rowvalue + 1 );
            }
           
            else {
                printf( "\nInvalid column!" );
            }
        break;
     
        default:
            printf( "Invalid row!\n" );
        break;
    }
}
