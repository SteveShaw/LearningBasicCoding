int largestIsland( vector<vector<int>>& grid )
{
    auto N = grid.size();
    int color = 2;
    vector<int> areas;
    int ans = 0;
    //calculate size of each connected component with value 1
    //associate the color and index in array "areas"
    for( size_t r = 0; r < N; ++r )
    {
        for( size_t c = 0; c < N; ++c )
        {
            if( grid[r][c] == 1 )
            {
                areas.push_back( dfs( grid, r, c, color ) );
                ans = ( max )( ans, areas.back() );
                ++color;
            }
        }
    }
    //check each zero
    for( size_t r = 0; r < N; ++r )
    {
        for( size_t c = 0; c < N; ++c )
        {
            if( grid[r][c] == 0 )
            {
                //check neighbor cells
                //for cell with value 1, we can
                //infer from its color to know if they
                //belong to same connected area
                int total = 0;
                //use seen to filter duplicate connected component
                //through the color
                set<int> seen;
                //check four directions
                if( r < N - 1 )
                {
                    color = grid[r + 1][c];
                    if( color != 0 )
                    {
                        total += areas[color - 2];
                        seen.insert( color );
                    }
                }
                if( r > 0 )
                {
                    color = grid[r - 1][c];
                    if( color != 0 )
                    {
                        if( seen.find( color ) == seen.end() )
                        {
                            total += areas[color - 2];
                            seen.insert( color );
                        }
                    }
                }
                if( c < N - 1 )
                {
                    color = grid[r][c + 1];
                    if( color != 0 )
                    {
                        if( seen.find( color ) == seen.end() )
                        {
                            total += areas[color - 2];
                            seen.insert( color );
                        }
                    }
                }
                if( c  > 0 )
                {
                    color = grid[r][c - 1];
                    if( color != 0 )
                    {
                        if( seen.find( color ) == seen.end() )
                        {
                            total += areas[color - 2];
                        }
                    }
                }
                //update final result
                ans = ( max )( ans, total + 1 );
            }
        }
    }
    return ans;
}
//helper function to do dfs to get size of the component, also mark each cell as give color
int dfs( vector<vector<int>>& grid, size_t r, size_t c, int color )
{
    grid[r][c] = color;
    int res = 1;
    auto N = grid.size();
    if( ( r < N - 1 ) && ( grid[r + 1][c] == 1 ) )
    {
        res  += dfs( grid, r + 1, c, color );
    }
    if( ( r > 0 ) && ( grid[r - 1][c] == 1 ) )
    {
        res += dfs( grid, r - 1, c, color );
    }
    if( ( c < N - 1 ) && ( grid[r][c + 1] == 1 ) )
    {
        res += dfs( grid, r, c + 1, color );
    }
    if( ( c > 0 ) && ( grid[r][c - 1] == 1 ) )
    {
        res += dfs( grid, r, c - 1, color );
    }
    return res;
}
