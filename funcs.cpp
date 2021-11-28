//https://contest.yandex.ru/contest/27794/problems/C/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    int n, r;
    input >> n >> r;

    std::vector<int> a(n);
    std::copy_n(std::istream_iterator<int>(input),n,a.begin());

    int count=0;
    int ir=0;
    for(int il=0; il<a.size()-1; ++il){
        ir = std::max(ir,il+1);
        for(;ir<a.size();++ir){
            if(a[ir]-a[il]>r){
                count+=a.size()-ir;
                break;
            }
        }
    }

    output << count;
}
