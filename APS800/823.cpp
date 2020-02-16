int numFactoredBinaryTrees( vector<int>& A )
{
    //sort A first
    sort( begin( A ), end( A ) );
    vector<int> F( A.size(), 1 );
    auto mod = []( long long n )
    {
        return n % 1000000007ll;
    };
    unordered_map<int, size_t> m;
    for( size_t i{}; i < A.size(); ++i )
    {
        //since A[i]/A[j] < A[i]
        //we can add to hash map in fly
        m[A[i]] = i;
        for( size_t j{}; j < i; ++j )
        {
            int q = A[i] / A[j];
            int r = A[i] - q * A[j];
            if( r == 0 )
            {
                auto it = m.find( q );
                if( it != m.end() )
                {
                    //both factors of A[i]
                    //can be found in A
                    F[i] = mod( F[i] + mod( ( long long )F[j] * ( long long )F[it->second] ) );
                }
            }
        }
    }
    //accumulate all numbers of binary trees
    int ans = 0;
    for( int x :  F )
    {
        ans = mod( ans + x );
    }
    return ans;
}