int uniqueLetterString( string S )
{
    vector<array<int, 2>> indices( 26, array<int, 2> {-1, -1} );
    int i = 0;
    auto bmod = []( int n )
    {
        return n % 1000000007;
    };
    int ans = 0;
    for( char c : S )
    {
        int ci = c - 'A';
        int x = bmod( ( i - indices[ci][1] ) * ( indices[ci][1] - indices[ci][0] ) );
        ans = bmod( ans + x );
        indices[ci][0] = indices[ci][1];
        indices[ci][1] = i;

        ++i;
    }
    //we have consider the final substring part
    //that contains only only one character
    //this part is not covered in the last loop
    for( int ci = 0; ci < 26; ++ci )
    {
        auto x = bmod( ( i - indices[ci][1] ) * ( indices[ci][1] - indices[ci][0] ) );
        ans = bmod( ans + x );
    }
    return ans;
}