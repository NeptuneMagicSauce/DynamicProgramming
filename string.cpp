#include <bits/stdc++.h>
using namespace std;

/*

objective =
count all unique strings
that are substrings of input data
found by removing characters from
the beginning or from the end

*/

int process(string input)
{
    set<string> results;

    for (std::size_t size = input.size(); size>0; --size) {
        for (std::size_t start=0; start<input.size(); ++start) {
            auto size_clamped = std::min(size, input.size() - start);
            auto substr = input.substr(start, size_clamped);
            results.insert(substr);
        }
    }

    return results.size();
}
