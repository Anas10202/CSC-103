#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;

vector<vector<bool> > world = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int numNghbrs(const vector<vector<bool>>& curr, int r, int c){
    int ret=0;
    int Rows = curr.size();
    int Cols = curr[0].size();
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            ret += curr[(r+i+Rows)%Rows][(c+j+Cols)%Cols];
        }
    }
    return ret - curr[r][c];
}

bool alive(const vector<vector<bool>>& curr, int r, int c){
    int nghbrs = numNghbrs(curr, r, c);
    if(curr[r][c]){
        return nghbrs == 2 || nghbrs == 3;
    }
    else{
        return nghbrs == 3;
    }
}

void grid(const vector<vector<bool>>& world, int rows, int cols){
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            if(world[r][c]) {
                cout << "O";
            } 
            else {
                cout << ".";
            }
        }
        cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout <<  argv[0] ;
        return 1;
    }

    int num_generations = std::stoi(argv[1]);

    vector<vector<bool>> future(world);
    int rows = world.size();
    int cols = world[0].size();

    for (int gen = 0; gen <= num_generations; gen++) {
        if (gen == num_generations) {
            grid(world, rows, cols);
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                future[r][c] = alive(world, r, c);
            }
        }
        world = future;
    }

    return 0;
}

 
