
/*--------------------------------------------
  Name: Hamza Fareed Ahmed Syed

  Title: Knight Escape
  The objective of this game is to get the white knight to the empty
        square in the upper right-hand corner of the board.

        The knight can only move in the way that it does during a traditional
        chess game. This means that a knight can only move in a valid L-shape
        (two squares in a horizontal direction, then one in a vertical direction
 OR two squares in a vertical direction, then one in a horizontal direction).

 ---------------------------------------------*/

#include <cctype>   // for toupper()
#include <iostream> // for input and output
#include <string>
using namespace std;

string p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
string p11, p12, p13, p14, p15, p16, p17, p18, p19, p20;
string p21, p22, p23, p24, p25;

// Characters of the pieces to be used on the board
// Note that these are global constants, so their values cannot be changed.
const string WhiteKnight = "\u2658"; // White knight character
const string BlackKnight = "\u265E"; // Black knight character
const string BlankPosition = " ";    // Blank position character

//--------------------------------------------------------------------------------
// Display welcome message, introducing the user to the program and
// describing the instructions for the game
void displayWelcomeMessage() {
  cout << "Project: Knight Escape \n"
       << " \n"
       << "The objective of this puzzle is to get the white knight "
       << "up to the empty square in the top right corner of the board. "
       << "Use standard knight moves from a traditional chess game, "
       << "where a knight moves in an L-shape. \n"
       << "This means that a knight can only move either "
       << "1) two squares in a horizontal direction, then one in a vertical "
          "direction, OR "
       << "2) two squares in a vertical direction, then one in a horizontal "
          "direction."
       << " \n"
       << "Your score decreases by 5 with each valid move, and by 10 with each "
          "invalid move. \n"
       << "Try to complete the puzzle with the smallest number of valid moves!"
       << endl;
} // end displayWelcomeMessage()

// ----------------------------------------------------------------------
// Display the current board, along with the corresponding positions
// This function makes use of global variables p1..p25, which represent
// each of the positions on the board
void displayBoard() {
  cout << "\n"
       << "    Board   "
       << "      Position \n"
       << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5
       << "     1  2  3  4  5 \n"
       << " " << p6 << " " << p7 << " " << p8 << " " << p9 << " " << p10
       << "     6  7  8  9 10 \n"
       << " " << p11 << " " << p12 << " " << p13 << " " << p14 << " " << p15
       << "    11 12 13 14 15 \n"
       << " " << p16 << " " << p17 << " " << p18 << " " << p19 << " " << p20
       << "    16 17 18 19 20 \n"
       << " " << p21 << " " << p22 << " " << p23 << " " << p24 << " " << p25
       << "    21 22 23 24 25 \n"
       << endl;
} // end displayBoard()

void setBox(string piece, int n) {
  if (n == 1)
    p1 = piece;
  else if (n == 2)
    p2 = piece;
  else if (n == 3)
    p3 = piece;
  else if (n == 4)
    p4 = piece;
  else if (n == 5)
    p5 = piece;
  else if (n == 6)
    p6 = piece;
  else if (n == 7)
    p7 = piece;
  else if (n == 8)
    p8 = piece;
  else if (n == 9)
    p9 = piece;
  else if (n == 10)
    p10 = piece;
  else if (n == 11)
    p11 = piece;
  else if (n == 12)
    p12 = piece;
  else if (n == 13)
    p13 = piece;
  else if (n == 14)
    p14 = piece;
  else if (n == 15)
    p15 = piece;
  else if (n == 16)
    p16 = piece;
  else if (n == 17)
    p17 = piece;
  else if (n == 18)
    p18 = piece;
  else if (n == 19)
    p19 = piece;
  else if (n == 20)
    p20 = piece;
  else if (n == 21)
    p21 = piece;
  else if (n == 22)
    p22 = piece;
  else if (n == 23)
    p23 = piece;
  else if (n == 24)
    p24 = piece;
  else
    p25 = piece;
}

string getBox(int n) {
  if (n == 1)
    return p1;
  else if (n == 2)
    return p2;
  else if (n == 3)
    return p3;
  else if (n == 4)
    return p4;
  else if (n == 5)
    return p5;
  else if (n == 6)
    return p6;
  else if (n == 7)
    return p7;
  else if (n == 8)
    return p8;
  else if (n == 9)
    return p9;
  else if (n == 10)
    return p10;
  else if (n == 11)
    return p11;
  else if (n == 12)
    return p12;
  else if (n == 13)
    return p13;
  else if (n == 14)
    return p14;
  else if (n == 15)
    return p15;
  else if (n == 16)
    return p16;
  else if (n == 17)
    return p17;
  else if (n == 18)
    return p18;
  else if (n == 19)
    return p19;
  else if (n == 20)
    return p20;
  else if (n == 21)
    return p21;
  else if (n == 22)
    return p22;
  else if (n == 23)
    return p23;
  else if (n == 24)
    return p24;
  return p25;
}

// ----------------------------------------------------------------------
// Main() function of the program, containing the loop that controls
// game play
int main() {

  displayWelcomeMessage();
  // Set board values to the default starting position
  // ...
  p1 = p2 = p3 = p4 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = p14 = p15 =
      p16 = p17 = p18 = p19 = p20 = p22 = p23 = p24 = p25 = BlackKnight;
  p21 = WhiteKnight;

  displayBoard();

  int moveNumber = 1;
  int score = 500;

  cout << "Current score: " << score << endl << endl;
  // Loop that controls game play
  while (score > 0) {
    cout << moveNumber << ". "
         << "Enter one of the following: \n"
         << "  - M to move a knight from one position to another, \n"
         << "  - R to reset the board back to the beginning, or \n"
         << "  - X to exit the game. \n"
         << "Your choice -> ";
    char menuOption;
    cin >> menuOption;
    menuOption = toupper(menuOption); // convert user input to uppercase

    // If the user entered 'X' to exit,
    // break out of this loop that controls game play
    // ...
    if (menuOption == 'X') {
      cout << "Exiting..." << endl;
      cout << "Thank you for playing!" << endl;
      return 0;
    }

    // If the user entered 'R' to reset,
    // reset the board back to the beginning
    // ...
    if (menuOption == 'R') {
      cout << endl << "   *** Restarting" << endl;
      p1 = p2 = p3 = p4 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = p14 =
          p15 = p16 = p17 = p18 = p19 = p20 = p22 = p23 = p24 = p25 =
              BlackKnight;
      p5 = "";
      p21 = WhiteKnight;

      moveNumber = 1;
      score = 500;

      displayBoard();
      cout << "Current score: " << score << endl << endl;
    }

    // If the user entered 'M' to move a knight,
    // ask for the position of the knight to be moved
    // ...
    if (menuOption == 'M') {
      int from, to;
      cout << "Enter the positions from and to, separated by a space (e.g. 14 "
              "5 to move the knight in position 14 to position 5): ";
      cin >> from;
      cin >> to;

      cout << "You have chosen to move a knight from position " << from
           << " to position " << to << "." << endl;
      // Check that FROM position is valid, i.e. within 1-25
      if (!(from >= 1 && from <= 25)) {
        cout << "The source position should be a valid position on the board(1 "
                "- 25). Try again."
             << endl;
        score = score - 10;
        cout << "Current score: " << score << endl << endl;
        continue;
      }

      // Check that TO position is valid, i.e. within 1-25
      else if (!(to >= 1 && to <= 25)) {
        cout << "The destination position should be a valid position on the "
                "board(1 - 25). Try again."
             << endl;
        score = score - 10;
        cout << "Current score: " << score << endl << endl;
        continue;
      }

      // Check that the source position has a knight
      else if (getBox(from) == "") {
        cout << "The source position should have a knight. Try again." << endl;
        score = score - 10;
        cout << "Current score: " << score << endl << endl;
        continue;
      }

      // Check that the destination position is empty
      else if (getBox(to) != "") {
        cout << "The destination position should be empty. Try again." << endl;
        score = score - 10;
        cout << "Current score: " << score << endl << endl;
        continue;
      }

      // Check that the move is valid - knights can only move in an L-shape
      int x1, y1, x2, y2;
      x1 = (from - 1) / 5 + 1;
      y1 = (from - 1) % 5 + 1;

      x2 = (to - 1) / 5 + 1;
      y2 = (to - 1) % 5 + 1;

      if (!(x1 + 2 == x2 && y1 + 1 == y2) && !(x1 + 2 == x2 && y1 - 1 == y2) &&
          !(x1 - 2 == x2 && y1 + 1 == y2) && !(x1 - 2 == x2 && y1 - 1 == y2) &&
          !(x1 + 1 == x2 && y1 + 2 == y2) && !(x1 - 1 == x2 && y1 + 2 == y2) &&
          !(x1 + 1 == x2 && y1 - 2 == y2) && !(x1 - 1 == x2 && y1 - 2 == y2)) {
        cout << "Invalid move. Knights can only move in an L-shape. Try again."
             << endl;
        score = score - 10;
        cout << "Current score: " << score << endl << endl;
        continue;
      }
      // Make the move and update the board
      else {
        setBox(getBox(from), to);
        setBox("", from);
        if (p5 == WhiteKnight) {
          break;
        }
        score = score - 5;
        displayBoard();
        cout << "Current score: " << score << endl << endl;
        moveNumber++;
      }
    }
  } // end loop for game play

  if (p5 == WhiteKnight) {
    displayBoard();
    cout << endl << "Congratulations, you did it!" << endl;
  } else {
    cout << endl
         << "You have run out of moves.Try to do better next time!" << endl;
  }

  cout << "Thank you for playing!" << endl;
  return 0;
}
