#include <iostream>
#include <stdexcept>

using namespace std;

enum Marker {
    X = 1,
    O = 2,
    EMPTY = 3
};


class Player {
public:
    string name;
    Marker marker;
    
    Player(string name, Marker marker) {
        this->name = name;
        this->marker = marker;
    }
};

class Move {
public:
    Player *player;
    int x;
    int y;
    
    Move(Player *player, int x, int y) {
        this->player = player;
        this->x = x;
        this->y = y;
    }
};


class Board {
    vector<vector<Marker>> board;
    int n;
    int numberOfUnFilledSlots;
    
    bool isWonRow(int x, Marker marker) {
        bool won = true;
        
        // row
        for(int i = 0; i < this->n; i++) {
            if(board[x][i] != marker) {
                won = false;
                break;
            }
        }
        return won;
    }
    
    bool isWonColumn(int y, Marker marker) {
        bool won = true;
        for(int i = 0; i < this->n; i++) {
            if(board[i][y] != marker) {
                won = false;
                break;
            }
        }
        return won;
    }
    
    bool isWonDiagonals(Marker marker) {
        bool won = true;
        
        for(int i = 0; i < this->n; i++) {
            if(board[i][i] != marker) {
                won = false;
                break;
            }
        }
        if(won) {
            return true;
        }
        
        won = true;
        for(int i = 0; i < this->n; i++) {
            if(board[i][this->n - i - 1] != marker) {
                won = false;
                break;
            }
        }
        return won;
    }
    
    
    
    
public:
    Board(int n) {
        this->n = n;
        board =vector<vector<Marker>>(n, vector<Marker>(n, EMPTY));
        numberOfUnFilledSlots = 0;
    }
    
    void printBoard() {
        cout << endl;
        for(int i = 0; i < this->n; i++) {
            for(int j = 0; j < this->n; j++) {
                char marker = ' ';
                if(board[i][j] == X) marker = 'X';
                if(board[i][j] == O) marker = 'O';
                
                cout << marker << " ";
            }
            cout << endl;
        }
    }
    
    bool isWon(int x, int y) {
        auto marker = board[x][y];
        return isWonRow(x, marker) || isWonColumn(y, marker) || isWonDiagonals(marker);
    }
    
    bool isValidMove(Move *move) {
        if(move->x >= this->n || move->x < 0 || move->y >= this->n || move->y < 0) {
            return false;
        }
        if(board[move->x][move->y] != EMPTY) {
            return false;
        }
        return true;
    }
    
    bool hasUnFilledSlots() {
        return numberOfUnFilledSlots < n * n;
    }
    
    
    void makeMove(Move *move) {
        if(isValidMove(move)) {
            board[move->x][move->y] = move->player->marker;
            numberOfUnFilledSlots++;
        } else {
            throw "invalid move";
        }
    }
    
};

class Game {
    Player *player1;
    Player *player2;
    vector<Move*> moves;
    Player *currentPlayer;
    Board* board;
    bool isGameFinished;
    
    Player* nextPlayer() {
        if (currentPlayer == player1) {
            return player2;
        }
        return player1;
    }
    
public:
    Game(Player *player1, Player *player2, Board* board) {
        this->player1 = player1;
        this->player2 = player2;
        currentPlayer = player1;
        moves = vector<Move*> ();
        this->board = board;
        this->isGameFinished = false;
        
        if(player1->marker == player2->marker) {
            throw "markers must not be same for both players";
        }
    }
    
    
    void makeMove(Move *move) {
        if(isGameFinished) {
            throw "game already finished";
        }
        
        if(move->player != currentPlayer) {
            throw "you are not the current player";
        }
        
        board->makeMove(move);
        board->printBoard();
        
        moves.push_back(move);
        
        
        if(board->isWon(move->x, move->y)) {
            cout << currentPlayer->name << " won!!" << endl;
            isGameFinished = true;
            return;
        }
        
        if(!board->hasUnFilledSlots()) {
            isGameFinished = true;
            cout << "game is drawn" << endl;
        }
        
        currentPlayer = nextPlayer();
    }
};

int main(int argc, const char * argv[]) {
    try {
        Player *player1 = new Player("player1", X);
        Player *player2 = new Player("player2", O);
        Board *board = new Board(3);
        
        Game *game = new Game(player1, player2, board);
        
        game->makeMove(new Move(player1, 0, 0));
        game->makeMove(new Move(player2, 0, 1));
        game->makeMove(new Move(player1, 1, 1));
        game->makeMove(new Move(player2, 1, 2));
        game->makeMove(new Move(player1, 1, 0));
        game->makeMove(new Move(player2, 2, 2));
        game->makeMove(new Move(player1, 2, 1));
        game->makeMove(new Move(player2, 2, 0));
        game->makeMove(new Move(player1, 0, 2));
    } catch( char const* e ) {
        cout << e << endl;
    }
    
    
    return 0;
}
