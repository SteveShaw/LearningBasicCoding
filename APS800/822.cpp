int flipgame( vector<int>& fronts, vector<int>& backs )
{
    unordered_set<int> sames;
    for( size_t i = 0; i < fronts.size(); ++i )
    {
        if( fronts[i] == backs[i] )
        {
            //the card with same front and back value
            //is not the card we can win
            sames.insert( fronts[i] );
        }
    }
    int ans = 9999;
    for( int n : fronts )
    {
        if( sames.find( n ) == sames.end() )
        {
            //we can try this card
            ans = ( min )( ans, n );
        }
    }
    for( int n : backs )
    {
        if( sames.find( n ) == sames.end() )
        {
            //we can also try this card
            ans = ( min )( ans, n );
        }
    }
    //when ans=9999, the returned value is zero
    return ans % 9999;
}
