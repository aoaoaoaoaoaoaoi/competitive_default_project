using Pc = pair<double, int>;
using T = tuple<int, int, int>;
using edge = struct { int to; long long dist; };

long long fact[MAX], inv[MAX];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

//printf
printf("%.10f", );

//桁数
cout << fixed << setprecision(10) << ans << endl;

//入れ子vector
vector<vector<int>> data(100, vector<int>(100, -1));