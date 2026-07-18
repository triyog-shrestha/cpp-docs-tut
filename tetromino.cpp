#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
#include <vector>
#include <chrono>
#include <thread>

struct Point{
    int row,col;
};


//erase the previous point before moving down
void erasePoint(vector<Point>& i, vector<vector<int>>& board){
    for (Point& point : i){
        board[point.row][point.col] = 0;
    };
}

//move the tetromino points down
void movePoint(vector<Point>& i){
    for (Point& point : i){
        point.row++;
    };
}

//make the new point
void makePoint(vector<Point>& i, vector<vector<int>>& board){
    for (Point& point : i){
        board[point.row][point.col] = 2;
    };
}


//calculate the lowest point of the tetromino
int calcLowest(const vector<Point>& i){

    int lowest = i[0].row;
    
    for (Point p : i){
        lowest = max(lowest, p.row);
    };
    return lowest;
}


//makes the tetris grid
void makeGrid(const vector<vector<int>>& board){
    for (const auto& row:board){
        for (int tile:row){
            switch (tile) {
                case 1: cout<<'#';break;
                case 0: cout<<'.';break;
                case 2: cout<<'=';break;
            
            }
            cout<<'\t';
        }
        cout<<'\n';
    }

}


//makes the tetrominoes
vector<Point> tetromino(){
    vector<Point> o = {
        {1,1},
        {1,2},
        {2,1},
        {2,2}
    };

    vector<Point> i = {
        {1,1},
        {2,1},
        {3,1},
        {4,1}
    };
    return i;

}

int main(){
    vector<vector<int>> board = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
    };

    makeGrid(board);

    vector<Point> i = tetromino();

  
    int lowest = 0; 
    while (lowest + 1 < board.size()-1) {
        
        erasePoint(i, board);

        movePoint(i);

        makePoint(i,board);
        system("clear");
        
        makeGrid(board);
        this_thread::sleep_for(chrono::milliseconds(500));
        lowest = calcLowest(i);
    }

}


