int maxDistToClosest( vector<int>& seats )
{
    //the index of last occupied seat
    int last_person = -1;
    int L = static_cast<int>( seats.size() );
    int ans = 0;
    for( int i = 0; i < L; ++i )
    {
        if( seats[i] == 1 )
        {
            if( last_person < 0 )
            {
                //we can put the person at index zero
                ans = i;
            }
            else
            {
                //we can put the person in the middle of the two occupied seats
                ans = ( max )( ans, ( i - last_person ) / 2 );
            }

            last_person = i;
        }
    }
    //we can put the person at the final seat
    ans = ( max )( ans, L - 1 -  last_person );
    return ans;
}
