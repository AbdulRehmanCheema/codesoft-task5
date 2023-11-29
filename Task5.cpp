#include <iostream>
#include <iomanip> // we use this library if we have to use some certain functions such as for precision  or alignment,
#include <vector>

using namespace std;

const int ROWS = 5;
const int COLS = 8;
const double TICKET_PRICE = 10.0;

// Function to display the seating arrangement
void displaySeats(const vector<vector <char> > && seats) 
{
    cout << "  ";
    for (int i = 1; i <= COLS; ++i) 
	{
        cout << setw(2) << i << " ";
    }
    cout << "\n";

    for (int i = 0; i < ROWS; ++i)
	 {
        cout << char('A' + i) << " ";
        for (int j = 0; j < COLS; ++j)
		 {
            cout << seats[i][j] << "  ";
        }
        cout << "\n";
    }
}

// Function to check if a seat is available
bool isSeatAvailable(const vector<vector<char>> &seats, int row, int col) 
{
    return seats[row][col] == 'O';
}

// Function to book a seat
void bookSeat(vector<vector<char>> &seats, int row, int col) 
{
    seats[row][col] = 'X';
}

int main()
 {
    vector<vector<char>> seats(ROWS, vector<char>(COLS, 'O'));

    char choice;
    do {
        cout << "Movie Ticket Booking System\n";
        cout << "1. View Movie Listings\n";
        cout << "2. Book a Ticket\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case '1':
                displaySeats(seats);
                break;
            case '2':
                char row;
                int col;
                cout << "Enter seat (e.g., A1): ";
                cin >> row >> col;

                int rowIndex = row - 'A';
                int colIndex = col - 1;

                if (rowIndex >= 0 && rowIndex < ROWS && colIndex >= 0 && colIndex < COLS) {
                    if (isSeatAvailable(seats, rowIndex, colIndex)) 
					{
                        bookSeat(seats, rowIndex, colIndex);
                        cout << "Seat booked successfully. Total cost: $" << fixed << setprecision(2) << TICKET_PRICE << "\n";
                    }
					 else 
					{
                        cout << "This seat is already booked. Please choose another seat.\n";
                    }
                } 
				else 
				{
                    cout << "Invalid seat selection. Please try again.\n";
                }
                break;
            case '3':
                cout << "Exiting the program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } 
	while (choice != '3');
    system("pause");
    return 0;
}
