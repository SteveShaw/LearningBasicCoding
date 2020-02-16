int numFriendRequests( vector<int>& ages )
{
    const int N = 120;
    vector<int> count( N + 1, 0 );
    for( int age : ages )
    {
        count[age] += 1;
    }
    int ans = 0;
    for( int a1 = 0; a1 <= N; ++a1 )
    {
        int cnt_a1 = count[a1];
        for( int a2 = 0; a2 <= N; ++a2 )
        {
            int cnt_a2 = count[a2];
            if( a1 / 2 + 7 >= a2 )
            {
                continue;
            }
            if( a1 < a2 )
            {
                continue;
            }
            if( ( a1 < 100 ) && ( 100 < a2 ) )
            {
                continue;
            }
            ans += ( cnt_a1 * cnt_a2 );
            if( a1 == a2 )
            {
                //for the same age we need to
                //decrease the repeated counts
                ans -= cnt_a1;
            }
        }
    }
    return ans;
}
