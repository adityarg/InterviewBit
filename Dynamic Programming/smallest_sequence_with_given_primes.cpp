// https://www.geeksforgeeks.org/ugly-numbers/
// UGLY NUMBERS

vector<int> Solution::solve(int A, int B, int C, int D)
{
    // vector to store 'D' numbers
    vector<int> v; v.push_back(1);
    int minimum=1,iA=0,iB=0,iC=0;
    int next_multiple_of_A=v[iA]*A;
    int next_multiple_of_B=v[iB]*B;
    int next_multiple_of_C=v[iC]*C;
    for(int i=1;i<=D;i++)
    {
        minimum=min(next_multiple_of_A,min(next_multiple_of_B,next_multiple_of_C));
        v.push_back(minimum);
        
        if(minimum==next_multiple_of_A) {iA++; next_multiple_of_A=v[iA]*A;}
        if(minimum==next_multiple_of_B) {iB++; next_multiple_of_B=v[iB]*B;}
        if(minimum==next_multiple_of_C) {iC++; next_multiple_of_C=v[iC]*C;}
    }
    v.erase(v.begin());
    return v;
}