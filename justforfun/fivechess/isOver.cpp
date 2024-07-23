#include<vector>

bool isOver(std::vector<std::vector<short>> chessBoard, std::vector<short> current, bool player){
    // a chess board is usually 15 * 15
    // we define that :
    // black : 1
    // white : 2
    // nothing : 0
    /*we say line first when we discribe an array*/
    /*---------------------------------------------------------------------------*/
    int playerchesses = 0;
    for (int i = -4;i < 5; i++){
        int y = current[1];
        if(y + i < 0) continue;
        if(y + i > 14) break;
        if(chessBoard[i][current[1]] != player) playerchesses = 0;
        if(chessBoard[i][current[1]] == player) playerchesses ++; 
    }
    if(playerchesses == 5) return true;
}

int main(){
    std::vector<std::vector<int>> CHESSBOARD = {{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,    
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
    #include <iostream>
    std::cout << isOver(CHESSBOARD, {0, 0}, 1) << std::endl;
}