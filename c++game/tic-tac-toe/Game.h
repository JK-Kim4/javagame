#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Game{
    
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};   // ������ ũ�� [3][3] int �迭
    bool isEnd = false;    // ���� ���� ����
    char winner;   // ����
    int round = 1;
    
    
    public:
        Game(){};  // �⺻ ������
 
        // ���� �������� ���� ǥ��
        void getBoardStatus(){
            for(int i = 0; i < 3; i++) {
                for(int j = 0;  j < 3; j++){
                    if(board[i][j] == 0){
                        cout << "   ";
                    }else if (board[i][j] == 1){
                        cout << " X ";
                    }else if (board[i][j] == 2){
                        cout << " O ";
                    }
                    cout << " || ";
                }
                cout << endl;
            }
        }; 
        
        
        // ����� �Է°� ������ �ݿ�
        bool doAction(int i, int x, int y){
            if(board[x-1][y-1] == 0){    
                board[x-1][y-1] = i;
                round++;
                return true;
            }
            else{ 
               return false;
            }
        };
        
        
        // ������ ����, return ����
        char checkBingo(){
        
            for(int i = 0; i < 3; i ++){
                if(board[i][0] > 0){
                    if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])){
                        if(board[0][0] == 1){
                            winner = 'X';
                        }else{
                            winner = 'O';
                        }
                        isEnd = true;
                        return winner;
                    }
                }
            }; // ���� ���� : row
         
         
            for(int j = 0; j < 3; j ++){
                if(board[0][j] > 0){
                    if((board[0][j] == board[1][j]) && (board[1][j] == board[2][j])){
                        if(board[0][0] == 1){
                            winner = 'X';
                        }else{
                            winner = 'O';
                        }
                        isEnd = true;
                        return winner;
                    }
                }
            }; // ���� ���� : colum
            
            if((board[0][0] > 0) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){
                if(board[0][0] == 1){
                    winner = 'X';
                }else{
                    winner = 'Y';
                }
                isEnd = true;
                return winner;
            }// ���� ���� �밢�� 1
            
            if((board[0][2] > 0) && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])){
                if(board[0][2] == 1){
                    winner = 'X';
                }else{
                    winner = 'Y';
                }
                isEnd = true;
                return winner;
            }// ���� ���� �밢�� 2
            
            return NULL; 
        };
        
        //field isEnd�� return
        bool getIsEnd(){
            return isEnd;
        }
        
        int getRound(){
            return round;
        }
    
};

