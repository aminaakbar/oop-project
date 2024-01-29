#include <iostream>
#include <string>

using namespace std;

// Base class representing a Room
class Room {
protected:
    int roomNumber;
    double price;

public:
    Room(int number, double cost) : roomNumber(number), price(cost) {}

    virtual void displayInfo() const {
        cout << "Room number: " << roomNumber << "\n";
        cout << "Price per night: $" << price << "\n";
    }
};

// Derived classes for different room categories
class BasicRoom : public Room {
public:
    BasicRoom(int number, double cost) : Room(number, cost) {}

    void displayInfo() const override {
        cout << "Basic Room\n";
        Room::displayInfo();
    }
};

class ComfortableRoom : public Room {
public:
    ComfortableRoom(int number, double cost) : Room(number, cost) {}

    void displayInfo() const override {
        cout << "Comfortable Room\n";
        Room::displayInfo();
    }
};

class LuxuriousRoom : public Room {
public:
    LuxuriousRoom(int number, double cost) : Room(number, cost) {}

    void displayInfo() const override {
        cout << "Luxurious Room\n";
        Room::displayInfo();
    }
};

// Class representing a Customer
class Customer {
protected:
    string name;
    string customer_ID;
    string customer_address;
    string customer_phone_no;
    string customer_email;
    string membership;
    string category;

public:
    // Constructor
    Customer(const string& n, const string& id, const string& address, const string& phone, const string& email, const string& mem, const string& cat)
        : name(n), customer_ID(id), customer_address(address), customer_phone_no(phone), customer_email(email), membership(mem), category(cat) {}

    // Display customer information
    void displayInfo() const {
        cout << "Customer Information:\n";
        cout << "Name: " << name << "\n";
        cout << "ID: " << customer_ID << "\n";
        cout << "Address: " << customer_address << "\n";
        cout << "Phone Number: " << customer_phone_no << "\n";
        cout << "Email: " << customer_email << "\n";
        cout << "Membership: " << membership << "\n";
        cout << "Category: " << category << "\n";
    }
};

// Derived classes for different customer categories
class SilverCustomer : public Customer {
private:
    int loyaltyPoints;

public:
    // Constructor
    SilverCustomer(const string& n, const string& id, const string& address, const string& phone, const string& email)
        : Customer(n, id, address, phone, email, "Silver Membership", "Silver"), loyaltyPoints(0) {}

    // Display additional information for SilverCustomer
    void displayInfo() const {
        Customer::displayInfo();
        cout << "Loyalty Points: " << loyaltyPoints << "\n";
    }
};

class GoldCustomer : public Customer {
private:
    double discountRate;

public:
    // Constructor
    GoldCustomer(const string& n, const string& id, const string& address, const string& phone, const string& email)
        : Customer(n, id, address, phone, email, "Gold Membership", "Gold"), discountRate(0.1) {}

    // Function to apply discount
    void applyDiscount(double amount) const {
        cout << name << " applied " << discountRate * 100 << "% discount. New amount: $" << (1 - discountRate) * amount << "\n";
    }
};

class PlatinumCustomer : public Customer {
private:
    int priorityLevel;

public:
    // Constructor
    PlatinumCustomer(const string& n, const string& id, const string& address, const string& phone, const string& email)
        : Customer(n, id, address, phone, email, "Platinum Membership", "Platinum"), priorityLevel(1) {}

    // Function to access priority service
    void accessPriorityService() const {
        cout << name << " has access to priority services.\n";
    }
};

// Class for Bill Management and Reservation System
class HotelManagement {
private:
    Room* rooms[3][3];  // Array to store different types of rooms
    Customer* customer;

public:
    // Constructor
    HotelManagement() {
        // Initialize rooms array (example)
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                rooms[i][j] = nullptr; // Initialize to nullptr (no rooms assigned)
            }
        }
        customer = nullptr; // No customer initially
    }

    // Function to check room availability
    bool isRoomAvailable(int row, int col) const {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && rooms[row][col] == nullptr) {
            return true;
        }
        return false;
    }

    // Function to assign a room to a customer
    void assignRoomToCustomer(Room* room, int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && rooms[row][col] == nullptr) {
            rooms[row][col] = room;
            cout << "Room assigned to customer.\n";
        } else {
            cout << "Invalid room selection or room already occupied.\n";
        }
    }

    // Function to display information about assigned rooms
    void displayAssignedRooms() const {
        cout << "Assigned Rooms:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (rooms[i][j] != nullptr) {
                    cout << "Room [" << i << "][" << j << "]: ";
                    rooms[i][j]->displayInfo();
                    cout << "\n";
                }
            }
        }
    }

    // Add other necessary member functions as per the requirement
};

int main() {
    // Create instances of rooms
    BasicRoom basicRoom(101, 50.0);
    ComfortableRoom comfortRoom(201, 100.0);
    LuxuriousRoom luxuryRoom(301, 200.0);

    // Display information about each room
    cout << "Basic Room Details:\n";
    basicRoom.displayInfo();
    cout << "\nComfortable Room Details:\n";
    comfortRoom.displayInfo();
    cout << "\nLuxurious Room Details:\n";
    luxuryRoom.displayInfo();

    // Create instances of customers
    SilverCustomer silverCustomer("John Silver", "S123", "Silver St.", "123456789", "john.silver@email.com");
    GoldCustomer goldCustomer("Golden Gold", "G456", "Gold St.", "987654321", "golden.gold@email.com");
    PlatinumCustomer platinumCustomer("Platinum Person", "P789", "Platinum St.", "111222333", "platinum.person@email.com");

    // Display information about each customer
    cout << "\nSilver Customer Details:\n";
    silverCustomer.displayInfo();
    cout << "\nGold Customer Details:\n";
    goldCustomer.displayInfo();
    cout << "\nPlatinum Customer Details:\n";
    platinumCustomer.displayInfo();

    // Apply discount for GoldCustomer
    double totalAmount = 500.0;
    goldCustomer.applyDiscount(totalAmount);

    // Access priority service for PlatinumCustomer
    platinumCustomer.accessPriorityService();

    // Hotel Management
    HotelManagement hotel;

    // Check room availability and assign rooms
    cout << "\nRoom Availability:\n";
    cout << "Room [1][1] available? " << (hotel.isRoomAvailable(1, 1) ? "Yes" : "No") << "\n";
    hotel.assignRoomToCustomer(&basicRoom, 1, 1);

    // Display assigned rooms
    hotel.displayAssignedRooms();

    return 0;
}

