#include <stdlib.h>
#include <stdio.h>

int cmp( const void *p1, const void *p2 )
{
    int x = *( int * )p1;
    int y = *( int * )p2;

    return ( x > y ) - ( y > x );

}

#define N   4

int main( void )
{   
    int a[N][2] =
    {        
        { 1, 7},
        { 5, 4},
        { 2, 3},
        { 4, 1}
    };

    for ( size_t i = 0; i < N; i++ )
    {
        for ( size_t j = 0; j < 2; j++ ) printf( "%d ", a[i][j] );
        printf( "\n" );
    }
    printf( "\n" );

    qsort( a, 4, sizeof( int[2] ), cmp );

    for ( size_t i = 0; i < N; i++ )
    {
        for ( size_t j = 0; j < 2; j++ ) printf( "%d ", a[i][j] );
        printf( "\n" );
    }
    printf( "\n" );
}