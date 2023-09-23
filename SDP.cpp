#include <iostream>
#include <fstream> //The <fstream> library in C++ provides classes and functions for working with files. It allows you to read from and write to files. This library includes classes like ifstream (input file stream), ofstream (output file stream), and fstream (both input and output file stream).
#include <sstream>  //The <sstream> library provides classes and functions for working with strings as if they were streams. It allows you to perform input and output operations on strings, just like you would with cin and cout.
#include <iomanip>  //The <iomanip> library provides tools for manipulating the format of input and output operations. It includes functions like setw, setprecision, and setfill to control the width, precision, and fill characters used in output.
#include <string>


//A stream, in the context of programming, is an abstract representation of a sequence of data that can be read from or written to. It's a fundamental concept used for input and output operations in various programming languages
using namespace std;

const int MAX_PRODUCTS = 1000;  // Maximum number of products
const string FILENAME = "product_catalog.csv";

struct Product
{
    string name;
    double price;
    int amount;
    bool wishlist;  //Now, each product will have a wishlist member, which can be used to keep track of whether the product is in the wishlist or not.You should also initialize the wishlist member when loading products from the catalog or when creating new products. For example, if all products are initially not in the wishlist, you can do this in the loadProductCatalog() function
};

Product products[MAX_PRODUCTS];
int numProducts = 0; //This variable keeps track of the current number of products in the system. It is initially set to 0, indicating that there are no products yet.
string cart = ""; // String to save the list of products in the cart
double totalBill = 0.0; // Variable to count the total bill

void signUp()
{
    string name, phoneNumber, address, favoriteFood, password;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter favorite food: ";
    getline(cin, favoriteFood);
    cout << "Set password: ";
    getline(cin, password);

    string fileName = name + "_" + phoneNumber + ".txt";
    ofstream file(fileName);
    file << name << "\n" << phoneNumber << "\n" << address << "\n" << favoriteFood << "\n" << password << endl;
    file.close();
}
bool logIn()
{
    string name, phoneNumber, password;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);

    string fileName = name + "_" + phoneNumber + ".txt";
    ifstream file(fileName);

    if (file.is_open())
    {
        string storedName, storedPhoneNumber, storedAddress, storedFavoriteFood, storedPassword;
        getline(file, storedName);
        getline(file, storedPhoneNumber);
        getline(file, storedAddress);
        getline(file, storedFavoriteFood);
        getline(file, storedPassword);

        cout << "Enter password: ";
        getline(cin, password);

        if (password == storedPassword)
        {
            cout << "Logged in successfully!" << endl;
            return true;
        }
        else
        {
            cout << "Incorrect password. Would you like to:" << endl;
            cout << "1. Reset password" << endl;
            cout << "2. Re-enter password" << endl;
            cout << "3. Sign up for a new account" << endl;
            int choice;
            cin >> choice;
            cin.ignore();

            if (choice == 1)
            {
                string answerFood, answerAddress;
                cout << "Answer your favorite food: ";
                getline(cin, answerFood);
                cout << "Enter your address: ";
                getline(cin, answerAddress);

                if (answerFood == storedFavoriteFood && answerAddress == storedAddress)
                {

                    // Prompt user for a new password
                    string newPassword;
                    cout << "Enter a new password: ";
                    getline(cin, newPassword);

                    // Update password in the file
                    file.close(); // Close the file to allow writing
                    ofstream outFile(fileName); // Open the file for writing
                    outFile << name << "\n" << phoneNumber << "\n" << storedAddress << "\n" << storedFavoriteFood << "\n" << newPassword << endl;
                    outFile.close(); // Close the file after writing
                    cout << "Password reset successful!" << endl;

                    return true;
                }
                else
                {
                    cout << "Incorrect information. Exiting..." << endl;
                    return false;
                }
            }
            else if (choice == 2)
            {
                // Ask user for password again
                cout << "Enter password: ";
                getline(cin, password);

                if (password == storedPassword)
                {
                    cout << "Logged in successfully!" << endl;
                    return true;
                }
                else
                {
                    cout << "Incorrect password. Exiting..." << endl;
                    return false;
                }
            }

            else if (choice == 3)
            {
                signUp(); // Call the signUp function
                return true; // Assuming signUp() returns true upon successful signup
            }
        }
    }
    else
    {
        cout << "Account not found. Exiting..."<<endl;
        return false;
    }
}



// first 20% of the project.







void loadProductCatalog()
{
    ifstream file(FILENAME);
    if (!file)
    {
        cout << "Error opening file: " << FILENAME << endl;
        return;
    }

    int i = 0;
    while (file && i < MAX_PRODUCTS)
    {
        file >> products[i].name >> products[i].price >> products[i].amount;
        products[i].wishlist = false; // Initialize wishlist member

        i++;
    }

    numProducts = i; // Update the total number of products

    file.close();
}

void displayProductCatalog()
{
    ifstream file(FILENAME);
    if (!file)
    {
        cout << "Error opening file: " << FILENAME << endl;
        return;
    }

    cout << "Product Catalog:" << endl;

    int productNumber = 1;
    while (file && productNumber <= MAX_PRODUCTS)
    {
        string line;
        getline(file, line);

        if (!line.empty())
        {
            stringstream ss(line);
            string name;
            double price;
            int amount;

            ss >> name >> price;

            cout << productNumber << ". " << name<< endl;

            // Initialize product information in the array
            products[productNumber - 1].name = name;
            products[productNumber - 1].price = price;
            products[productNumber - 1].amount = amount;
            products[productNumber - 1].wishlist = false;

            productNumber++;
        }
    }

    numProducts = productNumber - 1;

    file.close();

    int choice;
    cout << "Enter the number of the product you want to view details (or 0 to go back): ";
    cin >> choice;
    cin.ignore();
    if (choice >= 1 && choice <= numProducts)
    {
        cout << "You chose: " << products[choice - 1].name<<endl;
        cout << "Do you want to add it to the cart or wishlist? (1 for cart, 2 for wishlist): ";
        int addTo;
        cin >> addTo;
        cin.ignore();

        if (addTo == 1)
        {
            cout << "How many do you want to buy? ";
            int quantity;
            cin >> quantity;
            cin.ignore();

            if (quantity <= products[choice - 1].amount)
            {
                // Add to cart
                // Reduce the amount of product in stock
                products[choice - 1].amount -= quantity;

                cout << "Added " << quantity << " " << products[choice - 1].name << "(s) to cart."<<endl;

                char more;
                cout << "Do you want to buy more? (y/n): ";
                cin >> more;
                cin.ignore();

                if (more == 'y' || more == 'Y')
                {
                    displayProductCatalog();
                }
            }
            else
            {
                cout << "Insufficient stock. Please choose a smaller quantity."<<endl;
            }
        }
        else if (addTo == 2)
        {
            // Add to wishlist (you can implement this part)
            cout << "Added " << products[choice - 1].name << " to wishlist."<<endl;
        }
        else
        {
            cout << "Invalid choice."<<endl;
        }
    }
    else if (choice == 0)
    {
        // User chose to go back
    }
    else
    {
        cout << "Invalid choice. Please try again."<<endl;
    }
}


void seeCart()
{
    if (cart.empty())
    {
        cout << "You have nothing in the cart."<<endl;
    }
    else
    {
        cout << "Items in the cart:\n" << cart << endl;
        cout << "Total Bill: " << totalBill << " taka"<<endl;
    }
}

void removeFromCart()
{
    if (cart.empty())
    {
        cout << "You have nothing in the cart."<<endl;
        return;
    }

    cout << "Items in the cart:\n" << cart << endl;
    cout << "Enter the number of the product you want to remove: ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice >= 1 && choice <= numProducts)
    {
        size_t startPos = cart.find(to_string(choice) + ".");
        size_t endPos = cart.find("\n", startPos);
        string removedProduct = cart.substr(startPos, endPos - startPos + 1);
        cart.erase(startPos, endPos - startPos + 1);

        totalBill -= products[choice - 1].price;
        cout << "Removed " << removedProduct << " from the cart."<<endl;
    }
    else
    {
        cout << "Invalid choice. Please try again."<<endl;
    }
}

void addToCartSystem()
{
    loadProductCatalog();

    int choice;
    cout << "Options:"<<endl;
    cout << "1. See Cart"<<endl;
    cout << "2. Remove from Cart"<<endl;
    cout << "3. Go back to Display Options"<<endl;
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        seeCart();
        break;
    case 2:
        removeFromCart();
        break;
    case 3:
        // Go back to Display Options
        return;
    default:
        cout << "Invalid choice. Please try again."<<endl;
    }

    addToCartSystem(); // Call recursively for further actions
}



//60% of the project




void addToWishlist()
{
    cout << "Wishlist:"<<endl;

    // Display products in the wishlist
    for (int i = 0; i < numProducts; ++i)
    {
        if (products[i].wishlist)
        {
            cout << i + 1 << ". " << products[i].name << " (" << products[i].price << " taka)"<<endl;
        }
    }

    // Ask if the buyer wants to buy any products
    cout << "Do you want to buy any products? Enter the number (or 0 to go back): ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice >= 1 && choice <= numProducts)
    {
        if (products[choice - 1].wishlist)
        {
            // Product is in the wishlist

            // Add to cart
            products[choice - 1].amount -= 1;
            cart += to_string(choice) + ". " + products[choice - 1].name + " (" + to_string(products[choice - 1].price) + " taka)\n";
            totalBill += products[choice - 1].price;

            // Remove from wishlist
            products[choice - 1].wishlist = false;

            cout << "Added " << products[choice - 1].name << " to cart."<<endl;
        }
        else
        {
            cout << "Product is not in the wishlist. Please choose a product from the wishlist."<<endl;
        }
    }
    else if (choice == 0)
    {
        return; // return user to the main function
    }
    else
    {
        cout << "Invalid choice. Please try again."<<endl;
    }
}

void searchAndFilter()
{
    string searchName;
    cout << "Enter the product name that you want to buy: ";
    getline(cin, searchName);

    bool found = false;

    for (int i = 0; i < numProducts; ++i)
    {
        if (products[i].name == searchName)
        {
            cout << "Product Details:\n";
            cout << "Name: " << products[i].name <<endl;
            cout << "Price: " << products[i].price << " taka"<<endl;
            cout << "Amount in stock: " << products[i].amount <<endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "The product is not found."<<endl;
    }
}


void generateBill()
{
    cout << "Total Bill: " << totalBill << " taka"<<endl;
}


void inStockAndOutOfStockSystem()
{
    bool anyOutOfStock = false;

    for (int i = 0; i < numProducts; ++i)
    {
        if (products[i].amount == 0)
        {
            cout << products[i].name << " is out of stock."<<endl;
            anyOutOfStock = true;
        }
    }

    if (!anyOutOfStock)
    {
        cout << "All products are in stock."<<endl;
    }
}



//80% of the project




int main()
{
    int choice;
    cout << "Options:"<<endl;
    cout << "1. Sign Up"<<endl;
    cout << "2. Log In"<<endl;
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        signUp();
    }
    else if (choice == 2)
    {
        if (!logIn())
        {
            return 0;
        }
    }

    while (true)
    {
        cout << "Options:"<<endl;
        cout << "1. Product Catalog"<<endl;
        cout << "2. Cart System"<<endl;
        cout << "3. Wishlist"<<endl;
        cout << "4. Search and Filter"<<endl;
        cout << "5. Generate a Bill"<<endl;
        cout << "6. In Stock and Out of Stock System"<<endl;
        cout << "7. Log Out"<<endl;

        int option;
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case 1:
            displayProductCatalog();
            break;
        case 2:
            addToCartSystem();
            break;
        case 3:
            addToWishlist();
            break;
        case 4:
            searchAndFilter();
            break;
        case 5:
            generateBill();
            break;
        case 6:
            inStockAndOutOfStockSystem();
            break;
        case 7:
            cout << "Logged out successfully. Exiting...\n";
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}


//100% of the project
