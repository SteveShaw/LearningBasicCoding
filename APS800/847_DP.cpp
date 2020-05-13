int shortestPathLength( vector<vector<int>>& graph )
{
    int N = static_cast<int>( graph.size() );
    deque<vector<int>> dists( N, vector<int>( 1 << N, N * N ) );
    for( int node = 0; node < N; ++node )
    {
        dists[node][1 << node] = 0;
    }
    //iterate all the possible states and update
    //distance for nodes in the path starting from each node
    for( int state = 0; state < ( 1 << N ); ++state )
    {
        bool exit = false;
        while( !exit )
        {
            //we may run the iteration below a few times
            //so we need exit to control
            exit = true;
            for( int node = 0; node < N; ++node )
            {
                int d = dists[node][state];
                for( int next : graph[node] )
                {
                    int next_state = state | ( 1 << next );
                    if( d + 1 < dists[next][next_state] )
                    {
                        dists[next][next_state] = d + 1;
                        if( state == next_state )
                        {
                            //next state is same as current state
                            //we may need to run the iteration again
                            //to find possible shorter length
                            exit = false;
                        }
                    }
                }//end "for(next)"
            }//end "for(node)"
        }//end "while"
    }//end "for(state)"
    //select the global shortest length from
    //all paths starting from each node
    int ans = N * N;
    for( int node = 0; node < N; ++node )
    {
        ans = ( min )( ans, dists[node].back() );
    }
    return ans;
}
