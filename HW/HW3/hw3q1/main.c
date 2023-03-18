/**
 * CS introduction exersize hw3.
 * Kfir Nissim - 208944017.
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX_LOT_LENGTH 9
#define MAX_CAR_AMOUNT 10

#define EMPTY_SLOT ' '
#define EMPTY_SLOT_INPUT 'x'
#define RED_CAR_CHAR '*'

#define ANGLES 4

#define MAX_TURN_COUNT 10

// gets as input from the user the entire parking lot configuration and retuns
// it's length an empty slot in the parking lot will be represented as 'x', but
// when the lot s printed it should be as ' ' (space)
// @param lot - the 2D array to fill as the parking lot.
// returns int that is the length of the lot
int inputAndParseParkingLot(char lot[MAX_LOT_LENGTH][MAX_LOT_LENGTH]) {
    printf("Are you ready for rush hour?\n");
    int length = -1;
    printf("Please enter the parking lot length: ");
    scanf("%d", &length); // assume this is always correct
    printf("Please enter the parking lot:\n");
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            scanf(" %c", &(lot[i][j]));
            if (lot[i][j] == EMPTY_SLOT_INPUT) {
                lot[i][j] = EMPTY_SLOT;
            }
        }
    }
    return length;
}

// prints the parking lot
// empty slot will be printed as ' ' (define EMPTY_SLOT)
void printParkingLot(char lot[MAX_LOT_LENGTH][MAX_LOT_LENGTH], int length) {
    for (int k = 0; k < length; ++k) {
        printf("~~~");
    }
    printf("\n");
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            printf("|%c|", lot[i][j]);
        }
        printf("\n");
        for (int k = 0; k < length; ++k) {
            printf("~~~");
        }
        printf("\n");
    }
}

void printEnterCar() {
    printf("Enter the car you want to move:\n");
}

void printInvalidCar() {
    printf("Invalid car id! enter again:\n");
}

void printEnterDirection() {
    printf("Please enter the direction to move the car:\n");
}

void printInvalidDirection() {
    printf("Invalid direction!\n");
}

void printInvalidMove() {
    printf("Invalid move!\n");
}

void printGameWon() {
    printf("GAME OVER! YOU WIN :D\n");
}

void printGameLost() {
    printf("GAME OVER! YOU LOST :(\n");
}

// Get the car index from the user, and get the car (square) coordinates on the
// lot - get the top (north) index, left (west), bottom (south) and right (east)
// index values of the car, and store them in carCoords.
// @param lot - the 2D array to fill as the parking lot.
// @param lotLength - the size of the square parking lot.
// @param carCoords - output for the car coordinates on the lot.
// returns the caracter of the car that was recieved from the user.
char getCarCoords(char lot[MAX_LOT_LENGTH][MAX_LOT_LENGTH], int lotLength,
      int carCoords[ANGLES]);
void _getCarCoords(char lot[MAX_LOT_LENGTH][MAX_LOT_LENGTH], int lotLength,
      char car, int carCoords[ANGLES]);

// Move a car in the lot one step up (to the north).
// @param lot - the 2D array to fill as the parking lot.
// @param lotLength - the size of the square parking lot.
// @param car - the character of the car.
// @param carCoords - output for the car coordinates on the lot.
// returns true if the move was valid, false otherwise
bool moveCarNorth(char lot[MAX_LOT_LENGTH][MAX_LOT_LENGTH], int lotLength,
      char car, int carCoords[ANGLES]);

// Move a car in the lot one step down (to the south).
// @param lot - the 2D array to fill as the parking lot.
// @param lotLength - the size of the square parking lot.
// @param car - the character of the car.
// @param carCoords - output for the car coordinates on the lot.
// returns true if the move was valid, false otherwise
bool moveCarSouth(char lot[MAX_LOT_LENGTH][MAX_LOT_LENGTH], int lotLength,
      char car, int carCoords[ANGLES]);

// Move a car in the lot one step left (to the west).
// @param lot - the 2D array to fill as the parking lot.
// @param lotLength - the size of the square parking lot.
// @param car - the character of the car.
// @param carCoords - output for the car coordinates on the lot.
// returns true if the move was valid, false otherwise
bool moveCarWest(char lot[MAX_LOT_LENGTH][MAX_LOT_LENGTH], int lotLength,
      char car, int carCoords[ANGLES]);

// Move a car in the lot one step right (to the east).
// @param lot - the 2D array to fill as the parking lot.
// @param lotLength - the size of the square parking lot.
// @param car - the character of the car.
// @param carCoords - output for the car coordinates on the lot.
// returns true if the move was valid, false otherwise
bool moveCarEast(char lot[MAX_LOT_LENGTH][MAX_LOT_LENGTH], int lotLength,
      char car, int carCoords[ANGLES]);

// Execute a single turn - get the car index and direction from the user,
// and move the car in that direction if possible.
// @param lot - the 2D array to fill as the parking lot.
// @param lotLength - the size of the square parking lot.
// returns true if the move was valid, false otherwise
bool execValidMove(char lot[MAX_LOT_LENGTH][MAX_LOT_LENGTH], int lotLength);

// execute a single valid turn of the game Rush Hour.
// @param lot - the 2D array to fill as the parking lot.
// @param lotLength - the size of the square parking lot.
// returns true if the game is won. false otherwise.
bool playTurn(char lot[MAX_LOT_LENGTH][MAX_LOT_LENGTH], int lotLength);

// Run the game of Rush Hour!
int main() {
    // Good luck.
}
