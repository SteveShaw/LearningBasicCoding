string shiftingLetters( string S, vector<int>& shifts )
{
    int last_shift = 0;
    //we process from the end of S
    for( size_t i = 0; i < shifts.size(); ++i )
    {
        //get reversed index
        auto j = shifts.size() - i - 1;
        int ci = S[j] - 'a';
        int shift = ( ( shifts[j] % 26 )  + last_shift ) % 26;
        last_shift = shift;
        ci = ( ci + shift ) % 26;
        S[j] = 'a' + ci;
    }
    return S;
}
