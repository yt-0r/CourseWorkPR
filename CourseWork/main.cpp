#include "lib/mainmenu.h"
#include <iostream>
#include <time.h>
using namespace sf;
int width;
int height;
Texture background;
Texture zero;
Texture cross;
int grid[3][3];
int isPlayerTurn = 1;
int count = 0;
int countGame = 0;
int win = 0;
int countPlayer = 0;
int sost;
int sist;
int zero_grid() {
    for (int i = 0;i < 3; i++) {
        for (int j = 0;j < 3; j++) {
            grid[i][j] = 0;
        }
    }
    return 0;
}
int init() {
    background.loadFromFile("./images/grid.png");
    background.setSmooth(true);
    zero.loadFromFile("./images/zero.png");
    zero.setSmooth(true);
    cross.loadFromFile("./images/cross.png");
    cross.setSmooth(true);
    return 0;
}
int draw(RenderWindow & window) {
    window.clear(Color::White);
    Sprite temp;
    temp.setTexture(background);
    temp.setPosition(0, 0);
    window.draw(temp);
    Sprite cell;
    for (int i = 0; i < 3;i++) {
        for (int j = 0; j < 3; j++) {      
            if (grid[j][i] == 1) {
                cell.setPosition(i * 200, j * 200);
                cell.setTexture(cross);
                
            }
            window.draw(cell);
        }
    }
    for (int i = 0; i < 3;i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[j][i] == 2) {
                cell.setPosition(i * 200, j * 200);
                cell.setTexture(zero);
                
            }
            window.draw(cell);
        }
    }
    return 0;
}
void bot(int choise) {
    while (choise == 1 && isPlayerTurn == 0) {
        if (countPlayer == 0) {
            if (grid[1][1] == 1) sost = 1;
            if (grid[0][0] == 1) sost = 2;
            if (grid[0][1] == 1) sost = 3;
            if (grid[0][2] == 1) sost = 4;
            if (grid[1][0] == 1) sost = 5;
            if (grid[1][2] == 1) sost = 6;
            if (grid[2][0] == 1) sost = 7;
            if (grid[2][1] == 1) sost = 8;
            if (grid[2][2] == 1) sost = 9;
        }
        if (countPlayer >= 0 && sost == 1) {
            if (grid[2][2] != 2) {
                grid[2][2] = 2;
                isPlayerTurn = 1;
                countGame++;
                countPlayer++;
                break;
            }
            if (countPlayer == 1) {
                if (grid[0][0] == 1) sist = 1;
                if (grid[0][1] == 1) sist = 2;
                if (grid[0][2] == 1) sist = 3;
                if (grid[1][0] == 1) sist = 4;
                if (grid[1][2] == 1) sist = 5;
                if (grid[2][0] == 1) sist = 6;
                if (grid[2][1] == 1) sist = 7;
            }
            if (countPlayer >= 1 && sist == 1) {
                if (grid[2][0] != 2) {
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][1] == 0) {
                    grid[2][1] = 2;     //если игрок тупит, бот выйгрывает
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][1] == 1) {
                    if (grid[0][1] != 2) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[1][0] != 2) {
                            grid[1][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 2) {
                if (grid[2][1] != 2) {
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][0] == 0) {
                    grid[2][0] = 2;     //если игрок тупит, бот выйгрывает
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][0] == 1) {
                    if (grid[0][2] != 2) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[1][0] != 2) {
                            grid[1][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 3) {
                if (grid[2][0] != 2) {
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][1] == 0) {
                    grid[2][1] = 2;     //если игрок тупит, бот выйгрывает
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][1] == 1) {
                    if (grid[0][1] != 2) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[1][0] != 2) {
                            grid[1][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 4) {
                if (grid[1][2] != 2) {
                    grid[1][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][2] == 0) {
                    grid[0][2] = 2;     //если игрок тупит, бот выйгрывает
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][2] == 1) {
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[2][1] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 5) {
                if (grid[1][0] != 2) {
                    grid[1][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][2] == 1) {
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;     //другая ситуация
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;  //win
                    }
                    if (countPlayer > 2 && grid[0][1] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[2][1] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
                if (countPlayer > 1 && grid[2][0] == 1) {
                    if (grid[0][2] != 2) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[2][1] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
                if (countPlayer > 1 && grid[2][1] == 1) {
                    if (grid[0][1] != 2) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][0] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
                if (countPlayer > 1 && grid[0][1] == 1) {
                    if (grid[2][1] != 2) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][0] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
                if (countPlayer > 1 && grid[0][0] == 1) {
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][1] != 1) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;  //win
                    }
                    if (countPlayer > 2 && grid[2][1] == 1) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                }
            }
            if (countPlayer >= 1 && sist == 6) {
                if (grid[0][2] != 2) {
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[1][2] == 0) {
                    grid[1][2] = 2;     //если игрок тупит, бот выйгрывает
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[1][2] == 1) {
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[2][1] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }

            }
            if (countPlayer >= 1 && sist == 7) {
                if (grid[0][1] != 2) {
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][2] == 1) {
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;     //другая ситуация
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;  //win
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[1][0] != 2) {
                            grid[1][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
                if (countPlayer > 1 && grid[2][0] == 1) {
                    if (grid[0][2] != 2) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[1][0] != 2) {
                            grid[1][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
                if (countPlayer > 1 && grid[1][2] == 1) {
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][0] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
                if (countPlayer > 1 && grid[1][0] == 1) {
                    if (grid[1][2] != 2) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][0] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
                if (countPlayer > 1 && grid[0][0] == 1) {
                    if (grid[0][2] != 2) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] != 1) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;  //win
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                }
            }
        }
        if (countPlayer >= 0 && sost == 2) {
            if (grid[1][1] != 2) {
                grid[1][1] = 2;
                isPlayerTurn = 1;
                countGame++;
                countPlayer++;
                break;
            }
            if (countPlayer == 1) {
                if (grid[0][1] == 1) sist = 1;
                if (grid[0][2] == 1) sist = 2;
                if (grid[1][0] == 1) sist = 3;
                if (grid[1][2] == 1) sist = 4;
                if (grid[2][0] == 1) sist = 5;
                if (grid[2][1] == 1) sist = 6;
                if (grid[2][2] == 1) sist = 7;
            }
            if (countPlayer >= 1 && sist == 1) {
                if (grid[0][2] != 2) {
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][0] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 2){
                if (grid[0][1] != 2) {
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][1] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 3) {
                if (grid[2][0] != 2) {
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][2] == 1) {   //если игрок защищается 
                    if (grid[0][1] != 2) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][1] == 0) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][1] == 1) {
                        if (grid[2][2] != 2) {
                            grid[2][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 4) {
                if (grid[0][2] != 2) {
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][0] == 1) {   //если игрок защищается 
                    if (grid[0][1] != 2) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][1] == 0) {   //если игрок не защищается
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;//win
                    }
                    if (countPlayer > 2 && grid[2][1] == 1) {
                        if (grid[1][0] != 2) {
                            grid[1][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 5) {
                if (grid[1][0] != 2) {
                    grid[1][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[1][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[1][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[1][2] == 1) {   //если игрок защищается 
                    if (grid[0][1] != 2) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {   //если игрок не защищается
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 6) {
                if (grid[2][0] != 2) {
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][2] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 7) {
                if (grid[0][1] != 2) {
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][1] == 1) {   //если игрок защищается 
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 0) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
        }
        if (countPlayer >= 0 && sost == 3) {
            if (grid[1][1] != 2) {
                grid[1][1] = 2;
                isPlayerTurn = 1;
                countGame++;
                countPlayer++;
                break;
            }
            if (countPlayer == 1) {
                if (grid[0][0] == 1) sist = 1;
                if (grid[0][2] == 1) sist = 2;
                if (grid[1][0] == 1) sist = 3;
                if (grid[1][2] == 1) sist = 4;
                if (grid[2][0] == 1) sist = 5;
                if (grid[2][1] == 1) sist = 6;
                if (grid[2][2] == 1) sist = 7;
            }
            if (countPlayer >= 1 && sist == 1) {
                if (grid[0][2] != 2) {
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][0] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 2) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[1][2] != 2) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                
                    if (countPlayer > 2 && grid[1][0] == 0) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 3) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 0) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 4) {
                if (grid[0][2] != 2) {
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][0] == 1) {   //если игрок защищается 
                    if (grid[0][0] != 2) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 0) {   //если игрок не защищается
                        grid[2][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;//win
                    }
                    if (countPlayer > 2 && grid[2][2] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 5) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {   //если игрок не защищается
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 6) {
                if (grid[2][0] != 2) {
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][2] == 1) {   //если игрок защищается 
                    if (grid[0][0] != 2) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 0) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[2][2] != 2) {
                            grid[2][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 7) {
                if (grid[0][2] != 2) {
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][0] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[0][0] != 2) {
                            grid[0][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }   
                    }
                }
            }
        }
        if (countPlayer >= 0 && sost == 4) {
            if (grid[1][1] != 2) {
                grid[1][1] = 2;
                isPlayerTurn = 1;
                countGame++;
                countPlayer++;
                break;
            }
            if (countPlayer == 1) {
                if (grid[0][0] == 1) sist = 1;
                if (grid[0][1] == 1) sist = 2;
                if (grid[1][0] == 1) sist = 3;
                if (grid[1][2] == 1) sist = 4;
                if (grid[2][0] == 1) sist = 5;
                if (grid[2][1] == 1) sist = 6;
                if (grid[2][2] == 1) sist = 7;
            }
            if (countPlayer >= 1 && sist == 1) {
                if (grid[0][1] != 2) {
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][1] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 2) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[1][2] != 2) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }

                    if (countPlayer > 2 && grid[1][0] == 0) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 3) {
                if (grid[2][1] != 2) {
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][1] == 1) {   //если игрок защищается 
                    if (grid[0][0] != 2) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 0) {
                        grid[2][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 4) {
                if (grid[2][2] != 2) {
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][0] == 1) {   //если игрок защищается 
                    if (grid[0][1] != 2) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][1] == 0) {   //если игрок не защищается
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;//win
                    }
                    if (countPlayer > 2 && grid[2][1] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 5) {
                if (grid[2][1] != 2) {
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][1] == 1) {   //если игрок защищается 
                    if (grid[0][0] != 2) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 0) {   //если игрок не защищается
                        grid[2][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 6) {
                if (grid[1][2] != 2) {
                    grid[1][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[1][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[1][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[1][0] == 1) {   //если игрок защищается 
                    if (grid[0][0] != 2) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 0) {
                        grid[2][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 7) {
                if (grid[1][2] != 2) {
                    grid[1][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[1][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[1][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[1][0] == 1) {   //если игрок защищается 
                    if (grid[2][1] != 2) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 0) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 1) {
                        if (grid[0][0] != 2) {
                            grid[0][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
        }
        if (countPlayer >= 0 && sost == 5) {
            if (grid[1][1] != 2) {
                grid[1][1] = 2;
                isPlayerTurn = 1;
                countGame++;
                countPlayer++;
                break;
            }
            if (countPlayer == 1) {
                if (grid[0][0] == 1) sist = 1;
                if (grid[0][1] == 1) sist = 2;
                if (grid[0][2] == 1) sist = 3;
                if (grid[1][2] == 1) sist = 4;
                if (grid[2][0] == 1) sist = 5;
                if (grid[2][1] == 1) sist = 6;
                if (grid[2][2] == 1) sist = 7;
            }
            if (countPlayer >= 1 && sist == 1) {
                if (grid[2][0] != 2) {
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][2] == 1) {   //если игрок защищается 
                    if (grid[0][1] != 2) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][1] == 0) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][1] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 2) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[0][2] != 2) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][0] == 0) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][0] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 3) {
                if (grid[0][1] != 2) {
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][1] == 1) {   //если игрок защищается 
                    if (grid[0][0] != 2) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 0) {
                        grid[2][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 4) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[0][2] != 2) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][0] == 0) {   //если игрок не защищается
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;//win
                    }
                    if (countPlayer > 2 && grid[2][0] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 5) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[2][1] != 2) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 0) {   //если игрок не защищается
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 6) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 0) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 7) {
                if (grid[0][1] != 2) {
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][1] == 1) {   //если игрок защищается 
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 0) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
        }
        if (countPlayer >= 0 && sost == 6) {
            if (grid[1][1] != 2) {
                grid[1][1] = 2;
                isPlayerTurn = 1;
                countGame++;
                countPlayer++;
                break;
            }
            if (countPlayer == 1) {
                if (grid[0][0] == 1) sist = 1;
                if (grid[0][1] == 1) sist = 2;
                if (grid[0][2] == 1) sist = 3;
                if (grid[1][0] == 1) sist = 4;
                if (grid[2][0] == 1) sist = 5;
                if (grid[2][1] == 1) sist = 6;
                if (grid[2][2] == 1) sist = 7;
            }
            if (countPlayer >= 1 && sist == 1) {
                if (grid[0][1] != 2) {
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][1] == 1) {   //если игрок защищается 
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 0) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[2][2] != 2) {
                            grid[2][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 2) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[0][2] != 2) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][0] == 0) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][0] == 1) {
                        if (grid[2][1] != 2) {
                            grid[2][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 3) {
                if (grid[2][2] != 2) {
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][0] == 1) {   //если игрок защищается 
                    if (grid[0][1] != 2) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][1] == 0) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][1] == 1) {
                        if (grid[2][0] != 2) {
                            grid[2][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 4) {
                if (grid[0][2] != 2) {
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][0] == 1) {   //если игрок защищается 
                    if (grid[0][0] != 2) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 0) {   //если игрок не защищается
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;//win
                    }
                    if (countPlayer > 2 && grid[0][1] == 1) {
                        if (grid[2][2] != 2) {
                            grid[2][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 5) {
                if (grid[2][1] != 2) {
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][1] == 1) {   //если игрок защищается 
                    if (grid[0][0] != 2) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 0) {   //если игрок не защищается
                        grid[2][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 6) {
                if (grid[2][2] != 2) {
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][0] == 1) {   //если игрок защищается 
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 0) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 7) {
                if (grid[0][2] != 2) {
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][0] == 1) {   //если игрок защищается 
                    if (grid[2][1] != 2) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 0) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 1) {
                        if (grid[0][0] != 2) {
                            grid[0][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
        }
        if (countPlayer >= 0 && sost == 7) {
            if (grid[1][1] != 2) {
                grid[1][1] = 2;
                isPlayerTurn = 1;
                countGame++;
                countPlayer++;
                break;
            }
            if (countPlayer == 1) {
                if (grid[0][0] == 1) sist = 1;
                if (grid[0][1] == 1) sist = 2;
                if (grid[0][2] == 1) sist = 3;
                if (grid[1][0] == 1) sist = 4;
                if (grid[1][2] == 1) sist = 5;
                if (grid[2][1] == 1) sist = 6;
                if (grid[2][2] == 1) sist = 7;
            }
            if (countPlayer >= 1 && sist == 1) {
                if (grid[1][0] != 2) {
                    grid[1][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[1][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[1][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[1][2] == 1) {   //если игрок защищается 
                    if (grid[0][1] != 2) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][1] == 0) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][1] == 1) {
                        if (grid[2][2] != 2) {
                            grid[2][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 2) {
                if (grid[1][0] != 2) {
                    grid[1][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[1][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[1][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[1][2] == 1) {   //если игрок защищается 
                    if (grid[2][2] != 2) {
                        grid[2][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }

                    if (countPlayer > 2 && grid[0][0] == 0) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 3) {
                if (grid[0][1] != 2) {
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[1][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[1][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[1][2] == 1) {   //если игрок защищается 
                    if (grid[2][2] != 2) {
                        grid[2][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][0] == 0) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][0] == 1) {
                        if (grid[1][0] != 2) {
                            grid[1][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 4) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[2][1] != 2) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 0) {   //если игрок не защищается
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;//win
                    }
                    if (countPlayer > 2 && grid[0][1] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 5) {
                if (grid[2][1] != 2) {
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][1] == 1) {   //если игрок защищается 
                    if (grid[0][0] != 2) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 0) {   //если игрок не защищается
                        grid[2][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 6) {
                if (grid[2][2] != 2) {
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][0] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 7) {
                if (grid[2][1] != 2) {
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][1] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
        }
        if (countPlayer >= 0 && sost == 8) {
            if (grid[1][1] != 2) {
                grid[1][1] = 2;
                isPlayerTurn = 1;
                countGame++;
                countPlayer++;
                break;
            }
            if (countPlayer == 1) {
                if (grid[0][0] == 1) sist = 1;
                if (grid[0][1] == 1) sist = 2;
                if (grid[0][2] == 1) sist = 3;
                if (grid[1][0] == 1) sist = 4;
                if (grid[1][2] == 1) sist = 5;
                if (grid[2][0] == 1) sist = 6;
                if (grid[2][2] == 1) sist = 7;
            }
            if (countPlayer >= 1 && sist == 1) {
                if (grid[1][0] != 2) {
                    grid[1][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[1][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[1][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[1][2] == 1) {   //если игрок защищается 
                    if (grid[0][2] != 2) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][0] == 0) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][0] == 1) {
                        if (grid[2][2] != 2) {
                            grid[2][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 2) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }

                    if (countPlayer > 2 && grid[0][2] == 0) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[1][0] != 2) {
                            grid[1][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 3) {
                if (grid[0][0] != 2) {
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][2] == 1) {   //если игрок защищается 
                    if (grid[1][2] != 2) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 0) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 4) {
                if (grid[2][0] != 2) {
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][2] == 1) {   //если игрок защищается 
                    if (grid[0][0] != 2) {
                        grid[0][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[2][2] == 0) {   //если игрок не защищается
                        grid[2][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;//win
                    }
                    if (countPlayer > 2 && grid[2][2] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 5) {
                if (grid[2][2] != 2) {
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][0] == 1) {   //если игрок защищается 
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 0) {   //если игрок не защищается
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[0][1] != 2) {
                            grid[0][1] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 6) {
                if (grid[2][2] != 2) {
                    grid[2][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][0] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 7) {
                if (grid[2][0] != 2) {
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][2] == 1) {   //если игрок защищается 
                    if (grid[1][2] != 2) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 0) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[0][0] != 2) {
                            grid[0][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
        }
        if (countPlayer >= 0 && sost == 9) {
            if (grid[1][1] != 2) {
                grid[1][1] = 2;
                isPlayerTurn = 1;
                countGame++;
                countPlayer++;
                break;
            }
            if (countPlayer == 1) {
                if (grid[0][0] == 1) sist = 1;
                if (grid[0][1] == 1) sist = 2;
                if (grid[0][2] == 1) sist = 3;
                if (grid[1][0] == 1) sist = 4;
                if (grid[1][2] == 1) sist = 5;
                if (grid[2][0] == 1) sist = 6;
                if (grid[2][1] == 1) sist = 7;
            }
            if (countPlayer >= 1 && sist == 1) {
                if (grid[0][1] != 2) {
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][1] == 1) {   //если игрок защищается 
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 0) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 2) {
                if (grid[0][2] != 2) {
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][0] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[0][0] != 2) {
                            grid[0][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 3) {
                if (grid[1][2] != 2) {
                    grid[1][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[1][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[1][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[1][0] == 1) {   //если игрок защищается 
                    if (grid[2][1] != 2) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 0) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 1) {
                        if (grid[0][0] != 2) {
                            grid[0][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 4) {
                if (grid[0][1] != 2) {
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][1] == 1) {   //если игрок защищается 
                    if (grid[2][0] != 2) {
                        grid[2][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 0) {
                        grid[0][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][2] == 1) {
                        if (grid[1][2] != 2) {
                            grid[1][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 5) {
                if (grid[0][2] != 2) {
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[2][0] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[2][0] == 1) {   //если игрок защищается 
                    if (grid[2][1] != 2) {
                        grid[2][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 0) {
                        grid[0][1] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[0][1] == 1) {
                        if (grid[0][0] != 2) {
                            grid[0][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 6) {
                if (grid[2][1] != 2) {
                    grid[2][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][1] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][1] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][1] == 1) {   //если игрок защищается 
                    if (grid[1][0] != 2) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 0) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][2] == 1) {
                        if (grid[0][2] != 2) {
                            grid[0][2] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 7) {
                if (grid[2][0] != 2) {
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][2] == 1) {   //если игрок защищается 
                    if (grid[1][2] != 2) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 0) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[0][0] != 2) {
                            grid[0][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
            if (countPlayer >= 1 && sist == 8) {
                if (grid[2][0] != 2) {
                    grid[2][0] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 1 && grid[0][2] == 0) {    //если игрок тупит, бот выйгрывает
                    grid[0][2] = 2;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;  //win
                }
                if (countPlayer > 1 && grid[0][2] == 1) {   //если игрок защищается 
                    if (grid[1][2] != 2) {
                        grid[1][2] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 0) {
                        grid[1][0] = 2;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 2 && grid[1][0] == 1) {
                        if (grid[0][0] != 2) {
                            grid[0][0] = 2;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }
        }
        }
  
    while (choise == 2 && isPlayerTurn == 0) {
        if (countPlayer < 1) {  //первый ход бота в центр
            grid[1][1] = 1;
            countPlayer++;
            countGame++;
            isPlayerTurn = 1;
            break;
        }
        if (countPlayer == 1) {
            if (grid[0][1] == 2) sost = 1;
            if (grid[1][0] == 2) sost = 2;
            if (grid[2][1] == 2) sost = 3;
            if (grid[1][2] == 2) sost = 4;
            if (grid[0][0] == 2) sost = 5;
            if (grid[2][0] == 2) sost = 6;
            if (grid[2][2] == 2) sost = 7;
            if (grid[0][2] == 2) sost = 8;
        }
        if (countPlayer > 0 && sost == 1) { //бот ходит в зависимости от хода игрока
            if (grid[0][0] == 0) {
                grid[0][0] = 1;
                countPlayer++;
                countGame++;

                isPlayerTurn = 1;
                break;
            }
            if (countPlayer > 1 && grid[0][1] == 2 && grid[2][2] == 0) {    //если игрок не защищается, бот ставит крестик и выйгрывает
                grid[2][2] = 1;
                countPlayer++;
                countGame++;
                isPlayerTurn = 1;
                break;  //win
            }
            if (countPlayer > 1 && grid[0][1] == 2 && grid[2][2] == 2) {    //если игрок защищается, бот ставит крестик в выйгрышную позицию
                if (grid[2][0] != 1) {
                    grid[2][0] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                }
                if (countPlayer > 2 && grid[1][0] == 2) {
                    grid[0][2] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                    break; //win
                }
                if (countPlayer > 2 && grid[0][2] == 2) {
                    grid[1][0] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                    break; //win
                }
                if (countPlayer > 2 && (grid[2][1] == 2 || grid[1][2] == 2)) {
                    grid[1][0] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                    break; //win
                }
            }
        }
        if (countPlayer > 0 && sost == 2) {
            if (grid[2][0] != 1) {
                grid[2][0] = 1;
                countPlayer++;
                countGame++;
                isPlayerTurn = 1;
                break;
            }
            if (countPlayer > 1 && grid[1][0] == 2 && grid[0][2] == 0) {    //если игрок не защищается, бот ставит крестик и выйгрывает
                grid[0][2] = 1;
                countPlayer++;
                countGame++;
                isPlayerTurn = 1;
                break;  //win
            }
            if (countPlayer > 1 && grid[1][0] == 2 && grid[0][2] == 2) {    //если игрок защищается, бот ставит крестик в выйгрышную позицию
                if (grid[2][2] != 1) {
                    grid[2][2] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                }
                if (countPlayer > 2 && (grid[0][0] == 2)) {
                    grid[2][1] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                    break; //win
                }
                if (countPlayer > 2 && (grid[2][1] == 2)) {
                    grid[0][0] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                    break; //win
                }
                if (countPlayer > 2 && (grid[0][1] == 2 || grid[1][2] == 2)) {
                    grid[0][0] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                    break; //win
                }
            }
        }
        if (countPlayer > 0 && sost == 3) {
            if (grid[2][2] != 1) {
                grid[2][2] = 1;
                countPlayer++;
                countGame++;
                isPlayerTurn = 1;
                break;
            }
            if (countPlayer > 1 && grid[2][1] == 2 && grid[0][0] == 0) {    //если игрок не защищается, бот ставит крестик и выйгрывает
                grid[0][2] = 1;
                countPlayer++;
                countGame++;
                break;  //win
                isPlayerTurn = 1;
            }
            if (countPlayer > 1 && grid[2][1] == 2 && grid[0][0] == 2) {    //если игрок защищается, бот ставит крестик в выйгрышную позицию
                if (grid[0][2] != 1) {
                    grid[0][2] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                }
                if (countPlayer > 2 && grid[2][0] == 2) {
                    grid[1][2] = 1;
                    countPlayer++;
                    countGame++;
                    break; //win
                    isPlayerTurn = 1;
                }
                if (countPlayer > 2 && grid[1][2] == 2) {
                    grid[2][0] = 1;
                    countPlayer++;
                    countGame++;
                    break; //win
                    isPlayerTurn = 1;
                }
                if (countPlayer > 2 && (grid[0][1] == 2 || grid[1][0] == 2)) {
                    grid[2][0] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                    break; //win
                }
            }
        }
        if (countPlayer > 0 && sost == 4) {
            if (grid[0][2] != 1) {
                grid[0][2] = 1;
                countPlayer++;
                countGame++;
                isPlayerTurn = 1;
                break;
            }
            if (countPlayer > 1 && grid[1][2] == 2 && grid[2][0] == 0) {    //если игрок не защищается, бот ставит крестик и выйгрывает
                grid[2][0] = 1;
                countPlayer++;
                countGame++;
                isPlayerTurn = 1;
                break;  //win
            }
            if (countPlayer > 1 && grid[1][2] == 2 && grid[2][0] == 2) {    //если игрок защищается, бот ставит крестик в выйгрышную позицию
                if (grid[0][0] != 1) {
                    grid[0][0] = 1;
                    countPlayer++;
                    isPlayerTurn = 1;
                    countGame++;
                }
                if (countPlayer > 2 && (grid[0][1] == 2)) {
                    grid[2][2] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                    break; //win
                }
                if (countPlayer > 2 && (grid[2][2] == 2)) {
                    grid[0][1] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                    break; //win
                }
                if (countPlayer > 2 && (grid[1][0] == 2 || grid[2][1] == 2)) {
                    grid[2][2] = 1;
                    countPlayer++;
                    countGame++;
                    isPlayerTurn = 1;
                    break; //win

                }
            }

        }
        if (countPlayer > 0 && sost == 5) {
            if (grid[0][1] != 1) {
                grid[0][1] = 1;
                countPlayer++;
                countGame++;
                isPlayerTurn = 1;
                break;
            }
            if (countPlayer > 1 && grid[2][1] == 0) {       //если игрок не защищается бот ставит крестик
                grid[2][1] = 1;
                break;  //win
            }
            if (countPlayer > 1 && grid[2][1] != 0) {
                if (grid[1][0] != 1) {
                    grid[1][0] = 1;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 2 && grid[1][2] == 0) {       //если игрок не защищается бот ставит крестик
                    grid[1][2] = 1;
                    break;  //win
                }
                if (countPlayer > 2 && grid[1][2] != 0) {
                    if (grid[0][2] != 1) {
                        grid[0][2] = 1;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 3 && grid[2][0] == 0) {       //если игрок не защищается бот ставит крестик
                        grid[2][0] = 1;
                        break;
                    }
                    if (countPlayer > 3 && grid[2][0] != 0) {
                        if (grid[2][2] != 1) {
                            grid[2][2] = 1;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }

        }
        if (countPlayer > 0 && sost == 6) {
            if (grid[1][0] != 1) {
                grid[1][0] = 1;
                countPlayer++;
                countGame++;
                isPlayerTurn = 1;
                break;
            }
            if (countPlayer > 1 && grid[1][2] == 0) {       //если игрок не защищается бот ставит крестик
                grid[1][2] = 1;
                break;  //win
            }
            if (countPlayer > 1 && grid[1][2] != 0) {
                if (grid[2][2] != 1) {
                    grid[2][2] = 1;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 2 && grid[0][0] == 0) {       //если игрок не защищается бот ставит крестик
                    grid[0][0] = 1;
                    break;  //win
                }
                if (countPlayer > 2 && grid[0][0] != 0) {
                    if (grid[0][1] != 1) {
                        grid[0][1] = 1;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 3 && grid[2][1] == 0) {       //если игрок не защищается бот ставит крестик
                        grid[2][1] = 1;
                        break;
                    }
                    if (countPlayer > 3 && grid[2][1] != 0) {
                        if (grid[0][2] != 1) {
                            grid[0][2] = 1;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }

        }
        if (countPlayer > 0 && sost == 7) {
            if (grid[1][2] != 1) {
                grid[1][2] = 1;
                countPlayer++;
                countGame++;
                isPlayerTurn = 1;
                break;
            }
            if (countPlayer > 1 && grid[1][0] == 0) {       //если игрок не защищается бот ставит крестик
                grid[1][0] = 1;
                break;  //win
            }
            if (countPlayer > 1 && grid[1][0] != 0) {
                if (grid[2][0] != 1) {
                    grid[2][0] = 1;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 2 && grid[0][2] == 0) {       //если игрок не защищается бот ставит крестик
                    grid[0][2] = 1;
                    break;  //win
                }
                if (countPlayer > 2 && grid[0][2] != 0) {
                    if (grid[0][1] != 1) {
                        grid[0][1] = 1;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 3 && grid[2][1] == 0) {       //если игрок не защищается бот ставит крестик
                        grid[2][1] = 1;
                        break;
                    }
                    if (countPlayer > 3 && grid[2][1] != 0) {
                        if (grid[2][1] != 1) {
                            grid[0][0] = 1;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }

        }
        if (countPlayer > 0 && sost == 8) {
            if (grid[1][2] != 1) {
                grid[1][2] = 1;
                countPlayer++;
                countGame++;
                isPlayerTurn = 1;
                break;
            }
            if (countPlayer > 1 && grid[1][0] == 0) {       //если игрок не защищается бот ставит крестик
                grid[1][0] = 1;
                break;  //win
            }
            if (countPlayer > 1 && grid[1][0] != 0) {
                if (grid[0][1] != 1) {
                    grid[0][1] = 1;
                    isPlayerTurn = 1;
                    countGame++;
                    countPlayer++;
                    break;
                }
                if (countPlayer > 2 && grid[2][1] == 0) {       //если игрок не защищается бот ставит крестик
                    grid[2][1] = 1;
                    break;  //win
                }
                if (countPlayer > 2 && grid[2][1] != 0) {
                    if (grid[0][0] != 1) {
                        grid[0][0] = 1;
                        isPlayerTurn = 1;
                        countGame++;
                        countPlayer++;
                        break;
                    }
                    if (countPlayer > 3 && grid[2][2] == 0) {       //если игрок не защищается бот ставит крестик
                        grid[2][2] = 1;
                        break;
                    }
                    if (countPlayer > 3 && grid[2][2] != 0) {
                        if (grid[2][0] != 1) {
                            grid[2][0] = 1;
                            isPlayerTurn = 1;
                            countGame++;
                            countPlayer++;
                            break;
                        }
                    }
                }
            }

        }
    }
}
void game_stat() {
    if (grid[0][0] == 1 && grid[0][1] == 1 && grid[0][2] == 1) win = 1;   
    if (grid[1][0] == 1 && grid[1][1] == 1 && grid[1][2] == 1) win = 1;
    if (grid[2][0] == 1 && grid[2][1] == 1 && grid[2][2] == 1) win = 1; 
    if (grid[0][0] == 1 && grid[1][0] == 1 && grid[2][0] == 1) win = 1;
    if (grid[0][1] == 1 && grid[1][1] == 1 && grid[2][1] == 1) win = 1;
    if (grid[0][2] == 1 && grid[1][2] == 1 && grid[2][2] == 1) win = 1;  
    if (grid[0][0] == 1 && grid[1][1] == 1 && grid[2][2] == 1) win = 1;   
    if (grid[2][0] == 1 && grid[1][1] == 1 && grid[0][2] == 1) win = 1;
       


    if (grid[0][0] == 2 && grid[0][1] == 2 && grid[0][2] == 2) win = 2;
    if (grid[1][0] == 2 && grid[1][1] == 2 && grid[1][2] == 2) win = 2;
    if (grid[2][0] == 2 && grid[2][1] == 2 && grid[2][2] == 2) win = 2;
    if (grid[0][0] == 2 && grid[1][0] == 2 && grid[2][0] == 2) win = 2;
    if (grid[0][1] == 2 && grid[1][1] == 2 && grid[2][1] == 2) win = 2;
    if (grid[0][2] == 2 && grid[1][2] == 2 && grid[2][2] == 2) win = 2;
    if (grid[0][0] == 2 && grid[1][1] == 2 && grid[2][2] == 2) win = 2;
    if (grid[2][0] == 2 && grid[1][1] == 2 && grid[0][2] == 2) win = 2;
}
int main()
{
    VideoMode screen;
    screen = VideoMode::getDesktopMode();
    width = screen.width;
    height = screen.height;


    RenderWindow window(VideoMode(width / 3.2, width / 3.2), L"Крестики нолики", Style::Titlebar | Style::Close);

    int choise = menu(window, width, height);
    if (choise == 5) return 0;
    init();
    zero_grid();
    if (choise == 1) isPlayerTurn = 1;
    if (choise == 2) isPlayerTurn = 0;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left && isPlayerTurn) {
                    if (choise == 1) {
                        int x = (int)(event.mouseButton.x / 200);
                        int y = (int)(event.mouseButton.y / 200);
                        if (grid[y][x] == 0) {
                            grid[y][x] = 1;
                            countGame++;
                            isPlayerTurn = 0;
                        }
                        if (grid[x][y] != 0)

                            continue;
                    }
                }
                if (event.mouseButton.button == Mouse::Left && isPlayerTurn) {
                    if (choise == 2) {
                        int x = (int)(event.mouseButton.x / 200);
                        int y = (int)(event.mouseButton.y / 200);
                        if (grid[y][x] == 0) {
                            grid[y][x] = 2;
                            isPlayerTurn = 0;
                            countGame++;
                        }
                        if (grid[x][y] != 0) continue;
                    }
                }
            }
            if (isPlayerTurn == 0) bot(choise);
        }
        game_stat();
        draw(window);
        window.display();
        if (win == 1 && choise == 1 || win == 2 && choise == 2) std::cout << "You Win :)";
        if (win == 1 && choise == 2 || win == 2 && choise == 1) std::cout << "\nYou Lose :(\n\n";
        if (countGame == 9 && win == 0) std::cout << "\nDraw :/\n\n";
        if (countGame == 9 || win != 0) window.close();
    }
    return 0;
}