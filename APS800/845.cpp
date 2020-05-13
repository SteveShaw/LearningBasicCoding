int longestMountain( vector<int>& A )
{
    int len_up = 0;
    int len_down = 0;
    int ans = 0;
    for( size_t i = 1; i < A.size(); ++i )
    {
        if( A[i] == A[i - 1] )
        {
            //reset up and down length to zero
            len_up = 0;
            len_down = 0;
        }
        else if( A[i]  > A[i - 1] )
        {
            if( len_down > 0 )
            {
                //this is a new sequence of up
                //len_down > 0 means we have a down sequence
                //before
                //so reset up and down length to zero
                len_down = 0;
                len_up = 0;
            }
            //increment the length of sequence up
            ++len_up;
        }
        else
        {
            //increment the length of sequence down
            ++len_down;
        }
        if( ( len_up > 0 ) && ( len_down > 0 ) )
        {
            //only update maximum sequence length
            //when both up and down sequence length are not zero
            //we have to add 1 because those sequence don't have
            //current element count
            ans = ( max )( ans, 1 + len_up + len_down );
        }
    }
    return ans;
}
