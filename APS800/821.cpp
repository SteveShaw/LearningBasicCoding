vector<int> shortestToChar( string S, char C )
{
    vector<int> ans( S.size(), ( int )S.size() );
    int prev = -100000;
    int i{};
    //scan from left to right
    for( auto ch : S )
    {
        if( ch == C )
        {
            prev = i;
        }
        //only care about C on the left
        ans[i] = i - prev;
        ++i;
    }
    //scan from right to left
    prev = 100000;
    i = ( int )S.size() - 1;

    for( ; i >= 0; --i )
    {
        if( S[i] == C )
        {
            prev = i;
        }
        //only care about C on the right
        ans[i] = ( min )( ans[i], prev - i );
    }
    return ans;
}
