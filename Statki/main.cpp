#include <iostream>
#include <cmath>
#include "raylib.h"

#define SQUARE_BASIC_SIZE 50
#define BOARD_SIZE 10

using namespace std;

class Window
{
public:
    double windowWidth, windowHeight;
    double scale;
    Texture2D background;

    Window();
    Window(double width, double height);

    void loadBackground();

};

Window::Window(double width, double height)
{
    this -> windowWidth = width;
    this -> windowHeight = height;
    this -> scale = sqrt((this -> windowHeight * this -> windowWidth) / (1920 * 1000));
};

Window::Window()
{
    this -> windowWidth = 1280;
    this -> windowHeight = 720;
    this -> scale = sqrt((this -> windowHeight * this -> windowWidth) / (1920 * 1000));
}

void Window::loadBackground()
{
    this -> background = LoadTexture("img/background.png");
}

class Board
{
public:
    int x, y;
    static void initiate_board(Board newBoard[][BOARD_SIZE], int start_x, int start_y);
    static void drawBoard(Board gameBoard[][BOARD_SIZE], Texture2D square);



};

void Board::initiate_board(Board newBoard[][BOARD_SIZE], int start_x, int start_y)
{
    for(int i = 0; i < BOARD_SIZE; i++)
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            newBoard[i][j].x = start_x + 50 * j;
            newBoard[i][j].y = start_y + 50 * i;
        }
}

void Board::drawBoard(Board gameBoard[][BOARD_SIZE], Texture2D square)
{
    for(int i = 0; i < BOARD_SIZE; i++)
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            DrawTexture(square, gameBoard[i][j].x, gameBoard[i][j].y, RAYWHITE);
        }
}


int main()
{
    Window mainWindow = Window(1600, 900);
    InitWindow(mainWindow.windowWidth, mainWindow.windowHeight, "Statki");
    mainWindow.loadBackground();

    Board playerBoard[BOARD_SIZE][BOARD_SIZE];
    Board opponentBoard[BOARD_SIZE][BOARD_SIZE];

    Board::initiate_board(playerBoard, 200, 200);
    Board::initiate_board(opponentBoard, 900, 200);



    Texture2D square = LoadTexture("img/square.png");

    while(!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(WHITE);
            DrawTexture(mainWindow.background, 0, 0, RAYWHITE);
            Board::drawBoard(playerBoard, square);
            Board::drawBoard(opponentBoard, square);



        EndDrawing();
    }
    CloseWindow();
    return 0;
}
