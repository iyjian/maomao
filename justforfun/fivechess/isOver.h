#include<vector>

char isOver(std::vector<std::vector<short>> chessBoard, std::vector<short> current){
    // a chess board is usually 15 * 15
    // we define that :
    // black : 1
    // white : 2
    // nothing : 0
    /*we say line first when we discribe an array*/
    int black = 0;
    int white = 0;

    for (int i = 0; i < 15; i++){
        short Yline = chessBoard[i][current[1]];
        switch (Yline) {
            case 1:
                white = 0;
                black += 1;
                break;
            case 2:
                black = 0;
                white += 1;
                break;
            case 0:
                black = 0;
                white = 0;
                break;
            default:
                break;
        }
    if (black == 5) return 1;
    if (white == 5) return 2;
    return 0;
        

    }
}