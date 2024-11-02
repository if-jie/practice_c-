/*
 * @Author: 1454164915@qq.com 1454164915@qq.com
 * @Date: 2024-11-02 12:27:18
 * @LastEditors: 1454164915@qq.com 1454164915@qq.com
 * @LastEditTime: 2024-11-02 15:25:17
 * @FilePath: /learn/C++/snake/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEinc
 * 
 */
#include <iostream>
#include <vector>


using namespace std;

#define cols 20
#define rows 20

char board[cols*rows];

void fill_board(){

    int x,y;
    for(y = 0; y < cols; y++){
        for(x = 0; x < cols; x++){
            if(x == 0 ||y==0 ||x == cols - 1||y == cols - 1){
                board[y*cols + x] = '#';
            }else{
                board[y*cols + x] = ' ';

            }
        }
    }
}

void clear_screen(){
    system("clear");

}


void print_board(){

    int x,y;

    // clear_screen();
    for(y = 0; y < rows; y++){
        for(x = 0; x < cols; x++){
            if(board[y*cols+x] == '\0') cout<<' ';
            else cout<<board[y*cols+x];
        }
        cout<<endl;
    }
}

/// @brief 
struct snakePart {
    int x,y;

};

#define SNAKE_MAX 256

struct Snake{
    int length;
    struct snakePart part[SNAKE_MAX];
};

struct Snake snake;

// food struct
struct food{
    int x,y; 
    int consum;   
};
struct food eat[5];






void draw_snake(){
    // board[snakeX*cols+snakeY] = '@';

    int i;
    for(i=snake.length-1; i > 0 ; i--){
        board[snake.part[i].y*cols+snake.part[i].x] = '*';
    }
    board[snake.part[0].y*cols+snake.part[0].x] = '@';


}

void move_snake(const int& a,const int& b){

    int i;
    for(i = snake.length-1; i > 0; i--){
        snake.part[i] = snake.part[i-1];
    }
    snake.part[0].x += a;
    snake.part[0].y += b;
}
 
void read_keyboard(){
    int ch = getchar();
    // int ch;
    // cin >> ch;
    switch (ch)
    {
    case 'w': move_snake(0,-1); break;
    case 's': move_snake(0,1); break;
    case 'a': move_snake(-1,0); break;
    case 'd': move_snake(1,0); break;
    
    default:
        break;
    }
}




void place_food(){
    int i;
    for (i = 0; i < 6; i++)
    {        /* code */
        if(!eat[i].consum){
            board[eat[i].y*cols + eat[i].x] = '+';
        }
    }
    
    // board[6*cols + 4] = '+';
}

void set_up(){

    int i;
    for (i = 0; i < 6; i++)
    {
        eat[i].x = 1 + rand() % (cols -2);
        eat[i].y = 1 + rand() % (rows -2);
        eat[i].consum = 0;

    }
}

void game_logic(){
    int i;
     
    for(i = 0; i < 6; i++){
        if(!eat[i].consum){
            if(eat[i].x == snake.part[0].x &&
               eat[i].y == snake.part[0].y){
                eat[i].consum = 1;
                snake.length++;
               }
        }
    }




}





int main(int argc, char **argv){

    snake.length = 1;
    snake.part[0].x = 5;
    snake.part[0].y = 5;

    // foo
    set_up();

    while(1){
        fill_board();
        place_food();
        game_logic();

        draw_snake();

        print_board();
        read_keyboard();
    }
    return 0;
}