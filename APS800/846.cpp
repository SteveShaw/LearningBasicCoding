bool isNStraightHand( vector<int>& hand, int W )
{
    map<int, int> m;
    //put all cards into the tree map
    for( int n : hand )
    {
        auto[it, flag] = m.try_emplace( n, 0 );
        it->second += 1;
    }
    //for current lowest card
    //find if the consecutive cards are available
    for( auto[card, count] : m )
    {
        if( count > 0 )
        {
            //check the possible card sequence [card, card+1, ..., card+W-1]
            for( int n = card + 1; n < card + W; ++n )
            {
                auto it = m.find( n );
                if( it == m.end() )
                {
                    return false;
                }
                int n_count = it->second;
                if( n_count < count )
                {
                    //we don't have enough
                    //cards to form the sequence
                    return false;
                }
                it->second -= count;
            }
        }
    }
    return true;
}
