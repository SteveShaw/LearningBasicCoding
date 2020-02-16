int minimumLengthEncoding( vector<string>& words )
{
    unordered_set<string_view> good( begin( words ), end( words ) );
    for( const auto& word : words )
    {
        auto sv = string_view( word.c_str(), word.size() );
        for( size_t i = 1; i < sv.size(); ++i )
        {
            //remove all possible sufix from the final set
            good.erase( sv.substr( i ) );
        }
    }
    int ans = 0;
    for( const auto& sv : good )
    {
        ans += ( int )sv.size();
        ++ans;
    }
    return ans;
}

