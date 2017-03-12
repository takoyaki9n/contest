#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string read_bomb_dir() {
    string bombDir; // Current distance to the bomb compared to previous distance (COLDER, WARMER, SAME or UNKNOWN)
    cin >> bombDir; cin.ignore();
    return bombDir;
}

void print_position(int x, int y) {
    cout << x << " " << y << endl;
}

int next(int q, int pq, int &l, int &r, string bd) {
    if (bd == "COLDER") {
        if (pq < q) r = (pq + q - 1) / 2;
        else        l = (pq + q) / 2 + 1;
    } else if (bd == "WARMER") {
        if (pq < q) l = (pq + q) / 2 + 1;
        else        r = (pq + q - 1) / 2;
    } else if (bd == "SAME") {
        l = r = (pq + q) / 2;
    } else {
        cerr << "Invalid response: " << bd << endl;
    }
    return (q - l < r - q)? r: l;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    cerr << "W = " << W << ", H = " << H << endl;;
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();

    int X = X0, Y = Y0;
    
    int Xl = 0, Xr = W - 1;
    read_bomb_dir();
    int pX = X; X = Xl + Xr - X;
    print_position(X, Y);
    while (Xl < Xr) {
        int tmp = X;
        X = next(X, pX, Xl, Xr, read_bomb_dir());
        pX = tmp;
        cerr << "X: [" << Xl << ", " << Xr << "]\n";
        print_position(X, Y);
    }

    int Yl = 0, Yr = H - 1;
    read_bomb_dir();
    int pY = Y; Y = Yl + Yr - Y;
    print_position(X, Y);
    while (Yl < Yr) {
        int tmp = Y;
        Y = next(Y, pY, Yl, Yr, read_bomb_dir());
        pY = tmp;
        cerr << "Y: [" << Yl << ", " << Yr << "]\n";
        print_position(X, Y);
    }

    while (true) {
        read_bomb_dir();
        print_position(X, Y);
    }
}