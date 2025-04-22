class Solution {
public:
    string winningPlayer(int x, int y) {
        int turn = 0;
        while (true) {
            if (x < 1 || y < 4) {
                break;
            }
            x -= 1;
            y -= 4;
            turn = 1 - turn;
        }
        return turn == 0 ? "Bob" : "Alice";
    }
};