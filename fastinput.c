#define gc getchar_unlocked
inline int getn()
{
    int n = 0 , s = 1 ;
    char p = getchar( ) ;
    if( p == '-' )
        s = -1 ;
    while( ( p < '0' || p > '9' ) && p != EOF && p != '-' )
        p = getchar( ) ;
    if( p == '-' )
        s = -1 , p = getchar( ) ;
    while( p >= '0' && p <= '9' )
    {
        n = ( n << 3 ) + ( n << 1 ) + ( p - '0' ) ;
        p = getchar( ) ;
    }
    return n * s ;
}
 
