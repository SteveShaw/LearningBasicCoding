string toGoatLatin( string S )
{
    size_t start{};
    string ans;
    string_view sv( S.c_str(), S.size() );
    //help lambda to check if a char is a vowl
    auto is_vowl = []( char c )
    {
        switch( c )
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return true;

        default:
            break;

        }

        return false;
    };

    int count = 1;
    while( true )
    {
        //find next space
        auto p = S.find( ' ', start );
        p = ( min )( S.size(), p );
        //get the word
        auto word = sv.substr( start, p - start );
        if( is_vowl( word[0] ) )
        {
            ans += word;
        }
        else
        {
            ans += sv.substr( start + 1, p - start - 1 );
            ans.push_back( sv[start] );
        }
        ans += "ma";
        ans.append( count, 'a' );
        ans.push_back( ' ' );
        if( p >= S.size() )
        {
            //approach the end of S
            break;
        }
        //update next word's start
        start = p + 1;
        ++count;
    }
    ans.pop_back();
    return ans;
}
