int shortestPathLength( vector<vector<int>>& graph )
{
    //number of nodes in the graph
    int N = static_cast<int>( graph.size() );
    queue<pair<int, int>> q;
    //we need this 2d vector to record the distances of each node
    //to the starting node. Initialized with N * N which is the largest possbile path
    deque<vector<int>> dists( N, vector<int>( 1 << N, N * N ) );
    for( int node = 0; node < N; ++node )
    {
        q.emplace( node, 1 << node );
        //starting node distance is zero
        dists[node][1 << node] = 0;
    }
    while( !q.empty() )
    {
        auto [node, state] = q.front();
        q.pop();
        int d = dists[node][state];
        if( state == ( 1 << N ) - 1 )
        {
            //all the nodes are visited
            //d is the shortest distance
            //because this is BFS
            return d;
        }
        for( int child : graph[node] )
        {
            //mark child node is visited
            //set corresponding bit
            int next_state = ( state | ( 1 << child ) );
            if( d + 1 < dists[child][next_state] )
            {
                //the distance is smaller,update
                dists[child][next_state] = d + 1;
                //put into the BFS queue
                q.emplace( child, next_state );
            }
        }
    }
    //we are not supposed to be here
    return -1;
}
