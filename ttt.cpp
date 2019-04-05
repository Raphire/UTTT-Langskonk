// "ttt.cpp"
// Jeffrey Drost

#include "ttt.h"

int ttt::EvaluateBoard(const MicroState &b, const Player &maximize)
{
    Player winner = GetWinner(b);
    if(winner == Player::None) return 0;
    if(winner == maximize) return 9 - PlayerCount(b, maximize); // Its best to win in the least turns possible
    return -1; // Its better if opponent had to do many moves to win
}

Player ttt::GetWinner(const MicroState &b)
{
    // Horizontal
    if(b[0] == b[1] && b[1] == b[2] && b[2] != Player::None) return b[0];
    if(b[3] == b[4] && b[4] == b[5] && b[5] != Player::None) return b[3];
    if(b[6] == b[7] && b[7] == b[8] && b[8] != Player::None) return b[6];

    // Vertical
    if(b[0] == b[3] && b[3] == b[6] && b[6] != Player::None) return b[0];
    if(b[1] == b[4] && b[4] == b[7] && b[7] != Player::None) return b[1];
    if(b[2] == b[5] && b[5] == b[8] && b[8] != Player::None) return b[2];

    // Diagonal
    if(b[0] == b[4] && b[4] == b[8] && b[8] != Player::None) return b[0];
    if(b[2] == b[4] && b[4] == b[6] && b[6] != Player::None) return b[2];

    return  Player::None;
}

bool ttt::CloseWin(const MicroState &b, const Player &me , const bool myWin)
{
    if(myWin){
        // Horizontal
        if(b[0] == b[1] && b[2] == Player::None && b[0] == me) return true;
        if(b[3] == b[4] && b[5] == Player::None && b[3] == me) return true;
        if(b[6] == b[7] && b[7] == Player::None && b[6] == me) return true;
        if(b[0] == b[2] && b[1] == Player::None && b[0] == me) return true;
        if(b[3] == b[5] && b[4] == Player::None && b[3] == me) return true;
        if(b[6] == b[8] && b[7] == Player::None && b[6] == me) return true;
        if(b[1] == b[2] && b[0] == Player::None && b[1] == me) return true;
        if(b[4] == b[5] && b[3] == Player::None && b[4] == me) return true;
        if(b[7] == b[8] && b[6] == Player::None && b[7] == me) return true;

        // Vertical
        if(b[0] == b[3] && b[6] == Player::None && b[0] == me) return true;
        if(b[1] == b[4] && b[7] == Player::None && b[1] == me) return true;
        if(b[2] == b[5] && b[8] == Player::None && b[2] == me) return true;
        if(b[0] == b[6] && b[3] == Player::None && b[0] == me) return true;
        if(b[1] == b[7] && b[4] == Player::None && b[1] == me) return true;
        if(b[2] == b[8] && b[5] == Player::None && b[2] == me) return true;
        if(b[3] == b[6] && b[0] == Player::None && b[3] == me) return true;
        if(b[4] == b[7] && b[1] == Player::None && b[4] == me) return true;
        if(b[5] == b[8] && b[2] == Player::None && b[5] == me) return true;

        // Diagonal
        if(b[0] == b[4] && b[8] == Player::None && b[0] == me) return true;
        if(b[2] == b[4] && b[6] == Player::None && b[2] == me) return true;
        if(b[4] == b[8] && b[0] == Player::None && b[4] == me) return true;
        if(b[4] == b[6] && b[2] == Player::None && b[4] == me) return true;
        if(b[8] == b[0] && b[4] == Player::None && b[8] == me) return true;
        if(b[6] == b[2] && b[4] == Player::None && b[6] == me) return true;

        return false;
    }
    else{
        // Horizontal
        if(b[0] == b[1] && b[2] == Player::None && b[0] != Player::None && b[0] != me) return true;
        if(b[3] == b[4] && b[5] == Player::None && b[3] != Player::None && b[3] != me) return true;
        if(b[6] == b[7] && b[7] == Player::None && b[6] != Player::None && b[6] != me) return true;
        if(b[0] == b[2] && b[1] == Player::None && b[0] != Player::None && b[0] != me) return true;
        if(b[3] == b[5] && b[4] == Player::None && b[3] != Player::None && b[3] != me) return true;
        if(b[6] == b[8] && b[7] == Player::None && b[6] != Player::None && b[6] != me) return true;
        if(b[1] == b[2] && b[0] == Player::None && b[1] != Player::None && b[1] != me) return true;
        if(b[4] == b[5] && b[3] == Player::None && b[4] != Player::None && b[4] != me) return true;
        if(b[7] == b[8] && b[6] == Player::None && b[7] != Player::None && b[7] != me) return true;

        // Vertical
        if(b[0] == b[3] && b[6] == Player::None && b[0] != Player::None && b[0] != me) return true;
        if(b[1] == b[4] && b[7] == Player::None && b[1] != Player::None && b[1] != me) return true;
        if(b[2] == b[5] && b[8] == Player::None && b[2] != Player::None && b[2] != me) return true;
        if(b[0] == b[6] && b[3] == Player::None && b[0] != Player::None && b[0] != me) return true;
        if(b[1] == b[7] && b[4] == Player::None && b[1] != Player::None && b[1] != me) return true;
        if(b[2] == b[8] && b[5] == Player::None && b[2] != Player::None && b[2] != me) return true;
        if(b[3] == b[6] && b[0] == Player::None && b[3] != Player::None && b[3] != me) return true;
        if(b[4] == b[7] && b[1] == Player::None && b[4] != Player::None && b[4] != me) return true;
        if(b[5] == b[8] && b[2] == Player::None && b[5] != Player::None && b[5] != me) return true;

        // Diagonal
        if(b[0] == b[4] && b[8] == Player::None && b[0] != Player::None && b[0] != me) return true;
        if(b[2] == b[4] && b[6] == Player::None && b[2] != Player::None && b[2] != me) return true;
        if(b[4] == b[8] && b[0] == Player::None && b[4] != Player::None && b[4] != me) return true;
        if(b[4] == b[6] && b[2] == Player::None && b[4] != Player::None && b[4] != me) return true;
        if(b[8] == b[0] && b[4] == Player::None && b[8] != Player::None && b[8] != me) return true;
        if(b[6] == b[2] && b[4] == Player::None && b[6] != Player::None && b[6] != me) return true;

        return false;
    }
}

std::vector<int> ttt::GetMoves(const MicroState &b)
{
    std::vector<int> moves = {};
    if(GetWinner(b) != Player::None) return moves;
    else for(int m = 0; m < 9; m++)
        if(b[m] == Player::None) moves.push_back(m);
    return moves;
}

Player ttt::GetPlayer(const MicroState & b)
{
    int x = PlayerCount(b, Player::X);
    int o = PlayerCount(b, Player::O);
    int d = x - o;

    if(d == 0) return Player::X;
    if(d > 0) return Player::O;
    return Player::X;
}

std::vector<MicroState> ttt::GetChildren(const MicroState &b)
{
    std::vector<MicroState> children = {};

    std::vector<int> moves = GetMoves(b);
    Player turn = GetPlayer(b);

    for(int m = 0; m < moves.size(); m++)
        children.push_back(DoMove(b, moves[m], turn));

    return children;
}

MicroState ttt::DoMove(const MicroState &b, int &m, const Player &p)
{
    MicroState newBoard = b;
    newBoard[m] = p;
    return newBoard;
}

int ttt::PlayerCount(const MicroState &b, const Player &p)
{
    int c = 0;
    for(int i = 0; i < 9; i++)
        if(b[i] == p) c++;
    return c;
}

Player ttt::IsWinnableBy(const MicroState &b)
{
    if(GetWinner(b) != Player::None) return Player::None;

    Player winnableBy = Player::None;
    int wins[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
            {0, 4, 8}, {2, 4, 6}
    };

    // Check if each win pos can still be occupied by each player
    for(int w = 0; w < 8; w++)
    {
        if(b[wins[w][0]] != Player::X && b[wins[w][1]] != Player::X && b[wins[w][2]] != Player::X) // If player O can win this win
            if(winnableBy == Player::X) return Player::Both;
            else winnableBy = Player::O;

        if(b[wins[w][0]] != Player::O && b[wins[w][1]] != Player::O && b[wins[w][2]] != Player::O) // If player O can win this win
            if(winnableBy == Player::O) return Player::Both;
            else winnableBy = Player::X;
    }
    return winnableBy;
}

bool ttt::IsGameOver(const MicroState &b) {
    if(GetMoves(b).size() == 0) return true;
    return false;
}
