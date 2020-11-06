#include <bits/stdc++.h>
using namespace std;

/*

input data is 2D grid with these values:
0 = empty
1 = blocked
2 = gold coin

objective =
count the number of paths that go
from start (0,0)
to finish (n-1, m-1)
collecting all gold coins

 */

// types
struct Point { int x, y; };
struct Path
{
    vector<Point> points;
    int gold_collected;
};

// const data
const vector<Point> deltas =
{
    {  0,  1 },
    {  0, -1 },
    {  1,  0 },
    { -1,  0 },
};

// state data
int gold_count = 0;
vector<Path> paths;

void recurse(vector<vector<int>>& data, Path current_path)
{
    auto start = current_path.points.back();

    if (start.x < 0 || start.y < 0 ||
        start.x >= int(data.size()) || start.y >= int(data[0].size())) {
        // out of bounds
        return;
    }

    auto value = data[start.x][start.y];

    if (value == 1) {
        // blocked cell
        return;
    }

    // count gold
    current_path.gold_collected += (value == 2);

    if (start.x == int(data.size()) - 1 &&
        start.y == int(data[0].size()) - 1 &&
        current_path.gold_collected == gold_count) {
        // reached ending with all gold
        paths.push_back(current_path);
        return;
    }

    for (auto& delta: deltas) {
        // recurse in all 4 directions
        Path next_path = current_path;
        next_path.points.push_back({ start.x + delta.x, start.y + delta.y });
        recurse(data, next_path);
    }
}

int process(vector<vector<int>> data)
{
    for (auto& row: data) {
        for (auto d: row) {
            gold_count += (d == 2);
        }
    }
    recurse(data, { { { 0, 0 } }, 0 });

    return paths.size();
}
