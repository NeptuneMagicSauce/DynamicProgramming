#include <bits/stdc++.h>
using namespace std;

/*

count all unique strings
that are substrings of input data
found by removing characters from
the beginning or from the end

*/

int process(string input)
{
    set<string> results;

    for (int size = input.size(); size>0; --size) {
        for (int start=0; start<input.size(); ++start) {
            auto size_clamped = std::min(size, int(input.size() - start));
            auto substr = input.substr(start, size_clamped);
            results.insert(substr);
        }
    }

    return results.size();
}
