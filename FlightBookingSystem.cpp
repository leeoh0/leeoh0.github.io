#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_BOOKINGS = 100; // Maximum number of bookings

struct Booking {
    int id;
    string passengerName;
    string flightNumber;
    string destination;
};

Booking bookings[MAX_BOOKINGS]; // Array to store bookings
int bookingCount = 0; // Current count of bookings

void createBooking() {
    if (bookingCount >= MAX_BOOKINGS) {
        cout << "Booking limit reached. Cannot add more bookings.\n";
        return;
    }

    Booking newBooking;
    newBooking.id = bookingCount + 1;

    cout << "Enter passenger name: ";
    cin.ignore();
    getline(cin, newBooking.passengerName);

    cout << "Enter flight number: ";
    getline(cin, newBooking.flightNumber);

    cout << "Enter destination: ";
    getline(cin, newBooking.destination);

    bookings[bookingCount] = newBooking;
    bookingCount++;

    cout << "Booking created successfully!\n\n";
}

void readBookings() {
    if (bookingCount == 0) {
        cout << "No bookings found.\n\n";
        return;
    }

    cout << left << setw(5) << "ID" << setw(20) << "Passenger Name" << setw(15) 
         << "Flight Number" << setw(20) << "Destination" << endl;
    cout << string(60, '-') << endl;

    for (int i = 0; i < bookingCount; i++) {
        cout << left << setw(5) << bookings[i].id
             << setw(20) << bookings[i].passengerName
             << setw(15) << bookings[i].flightNumber
             << setw(20) << bookings[i].destination << endl;
    }

    cout << endl;
}

void updateBooking() {
    int id;
    cout << "Enter booking ID to update: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].id == id) {
            found = true;

            cout << "Enter new passenger name: ";
            cin.ignore();
            getline(cin, bookings[i].passengerName);

            cout << "Enter new flight number: ";
            getline(cin, bookings[i].flightNumber);

            cout << "Enter new destination: ";
            getline(cin, bookings[i].destination);

            cout << "Booking updated successfully!\n\n";
            break;
        }
    }

    if (!found) {
        cout << "Booking ID not found.\n\n";
    }
}

void deleteBooking() {
    int id;
    cout << "Enter booking ID to delete: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].id == id) {
            found = true;
            for (int j = i; j < bookingCount - 1; j++) {
                bookings[j] = bookings[j + 1];
            }
            bookingCount--;
            cout << "Booking deleted successfully!\n\n";
            break;
        }
    }

    if (!found) {
        cout << "Booking ID not found.\n\n";
    }
}

void menu() {
    cout << "Flight Booking System\n";
    cout << "1. Create Booking\n";
    cout << "2. View Bookings\n";
    cout << "3. Update Booking\n";
    cout << "4. Delete Booking\n";
    cout << "5. Exit\n";
}

int main() {
    int choice;

    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createBooking();
                break;
            case 2:
                readBookings();
                break;
            case 3:
                updateBooking();
                break;
            case 4:
                deleteBooking();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n\n";
        }
    } while (choice != 5);

    return 0;
}
