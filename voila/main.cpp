#include <iostream>
#include <vector>
#include <algorithm>

struct Client {
    std::string name;
    std::string accountNumber;
    double balance;
};

std::vector<Client> clients {
    {"John Smith", "12345", 1000.0},
    {"Jane Doe", "67890", 2000.0},
    {"Bob Johnson", "13579", 500.0},
    {"Alice Green", "24680", 3000.0},
    {"Tom Lee", "97531", 700.0},
    {"Sarah Brown", "86420", 4000.0},
    {"David Kim", "11111", 1500.0}
};

void showClientMenu(Client& client) {
    int clientOption;

    do {
        std::cout << "\n**********MENU*********\n"
                  << "1. Check Balance\n"
                  << "2. Deposit\n"
                  << "3. Withdraw\n"
                  << "4. Return to Menu\n"
                  << "5. Exit\n"
                  << "************************\n";
    }
        clientOption = getIntegerInput("Option: ");


        switch (clientOption) {
            case 1:
                std::cout << "Balance is: " << client.balance << " $\n";
                break;
            case 2: {
                std::cout << "Deposit amount: ";
                double depositAmount = getIntegerInput("");
                client.balance += depositAmount;
                std::cout << "New balance is: " << client.balance << " $\n";
                break;
            }
            case 3: {
                std::cout << "Withdraw amount: ";
                double withdrawAmount = getIntegerInput("");
                if (withdrawAmount > client.balance) {
                    std::cout << "Insufficient funds.\n";
                } else {
                    client.balance -= withdrawAmount;
                    std::cout << "New balance is: " << client.balance << " $\n";
                }
                break;
            }
            case 4:
                std::cout << "Returning to main menu...\n";
                break;
            case 5:
                std::cout << "Thank you for using our banking system!\n";
                exit(0);
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (clientOption != 4);
}

void showAdminMenu() {
    std::string username = getStringInput("Enter admin username: ");
    std::string password = getStringInput("Enter admin password: ");

    if (username != "Prince" || password != "0078") {
        std::cout << "Invalid username or password. Access denied.\n";
        return;
    }

        switch (adminOption) {
        case 1:
            if (clients.empty()) {
                std::cout << "No clients found.\n";
            } else {
                std::cout << "\n**********CLIENT DETAILS*********\n";
                for (const auto& client : clients) {
                    std::cout << "Name: " << client.name << "\n"
                              << "Account Number: " << client.accountNumber << "\n"
                              << "Balance: " << client.balance << " $\n"
                              << "*********************************\n";
                }
            }
            break;
        case 2: {
            std::cout << "\n**********CREATE NEW CLIENT*********\n";
            Client newClient;
            newClient.name = getStringInput("Name: ");
            newClient.accountNumber = getStringInput("Account Number: ");
            newClient.balance = getDoubleInput("Balance: ");
            clients.push_back(newClient);
            std::cout << "Client created successfully.\n";
            break;
        }
        case 3: {
            std::cout << "\n**********EDIT CLIENT*********\n";
            std::string accountNumber = getStringInput("Enter account number of the client to edit: ");
            auto it = std::find_if(clients.begin(), clients.end(), [&](const Client& c) { return c.accountNumber == accountNumber; });
            if (it == clients.end()) {
                std::cout << "Client not found.\n";
            } else {
                Client& client = *it;
                std::cout << "What do you want to edit?\n"
                          << "1. Name\n"
                          << "2. Balance\n"
                          << "3. Both Name and Balance\n"
                          << "4. Cancel\n"
                          << "*************************\n";
                int editOption = getIntegerInput("Option: ");
                switch (editOption) {
                    case 1:
                        client.name = getStringInput("New name: ");
                        std::cout << "Client updated successfully.\n";
                        break;
                    case 2:
                        client.balance = getDoubleInput("New balance: ");
                        std::cout << "Client updated successfully.\n";
                        break;
                    case 3:
                        client.name = getStringInput("New name: ");
                        client.balance = getDoubleInput("New balance: ");
                        std::cout << "Client updated successfully.\n";
                        break;
                    case 4:
                        std::cout << "Canceling edit...\n";
                        break;
                    default:
                        std::cout << "Invalid option. Please try again.\n";
                }
            }
            break;
        }
        case 4: {
            std::cout << "\n**********DELETE CLIENT*********\n";
            std::string accountNumber = getStringInput("Enter account number of the client to delete: ");
            auto it = std::find_if(clients.begin(), clients.end(), [&](const Client& c) { return c.accountNumber == accountNumber; });
            if (it == clients.end()) {
                std::cout << "Client not found.\n";
            } else {
                clients.erase(it);
                std::cout << "Client deleted successfully.\n";
            }
            break;
        }
        case 5:
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
    }
} while (adminOption != 5);
