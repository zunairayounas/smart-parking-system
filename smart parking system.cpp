#include <iostream>
#include <string>
using namespace std;

class ParkingSystem
{
private:
    string cars[10];
    int count;

public:
    ParkingSystem()
    {
        count = 0;
    }
    void parkCar()
    {
        if (count == 10)
        {
            cout << "\nParking Full!\n";
            return;
        }
        cout << "Enter Car Number: ";
        cin >> cars[count];
        count++;
        cout << "Car Parked Successfully!"<<endl;
    }
    void removeCar()
    {
        string car;
        bool found = false;

        cout << "Enter Car Number to Remove: ";
        cin >> car;
		   for (int i = 0; i < count; i++)
        {
            if (cars[i] == car)
            {
                for (int j = i; j < count - 1; j++)
                {
                    cars[j] = cars[j + 1];
                }
                count--;
                found = true;
                cout << "Car Removed Successfully!\n";
                break;
            }
        }
        if (!found)
        {
            cout << "Car Not Found!\n";
        }
    }
    void showCars()
    {
        if (count == 0)
        {
            cout << "No Cars Parked.\n";
            return;
        }
        cout << "\nParked Cars:\n";
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << cars[i] << endl;
        }
    }
    void availableSlots()
    {
        cout << "Available Slots: " << 10 - count << endl;
    }
};

int main()
{
    ParkingSystem parking;
    int choice;

    do
    {
        cout << "\n===== SMART PARKING SYSTEM =====\n";
        cout << "1. Park Car"<<endl;
        cout << "2. Remove Car"<<endl;
        cout << "3. Show Parked Cars"<<endl;
        cout << "4. Available Slots"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            parking.parkCar();
            break;
        case 2:
            parking.removeCar();
            break;
        case 3:
            parking.showCars();
            break;
        case 4:
            parking.availableSlots();
            break;
        case 5:
            cout << "Thank You!"<<endl;
            break;
        default:
            cout << "Invalid Choice!"<<endl;
        }
    } while (choice != 5);
    return 0;
}
