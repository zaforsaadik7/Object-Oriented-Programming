#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

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
    ifstream file(fileName); // ifstream is a class which is creating a object name file with the argument fileName.

    if (file.is_open()) //if the object created by ifstream exists then this condition will be executed.
    {
        string storedName, storedPhoneNumber, storedAddress, storedFavoriteFood, storedPassword;
        getline(file, storedName); //It uses the getline function, which reads characters from the input stream (in this case, the file) until it encounters a newline character ('\n') or reaches the end of the line.
        getline(file, storedPhoneNumber);
        getline(file, storedAddress);
        getline(file, storedFavoriteFood);
        getline(file, storedPassword);

        cout << "Enter password: ";
        getline(cin, password);

        if (password == storedPassword)
        {
            cout << "Logged in successfully!"<<endl;
            return true;
        }
        else
        {
            cout << "Incorrect password. Would you like to:"<<endl;
            cout << "1. Reset password"<<endl;
            cout << "2. Sign up for a new account"<<endl;
            int choice;
            cin >> choice;
            cin.ignore(); //The cin.ignore(); statement is used to clear the input buffer in C++. It discards any characters that may still be in the input buffer, allowing you to start fresh when reading new input.
            if (choice == 1)
            {
                string answerFood, answerAddress;
                cout << "Answer your favorite food: ";
                getline(cin, answerFood);
                cout << "Enter your address: ";
                getline(cin, answerAddress);

                if (answerFood == storedFavoriteFood && answerAddress == storedAddress)
                {
                    cout << "Password reset successful!"<<endl;
                    return true;
                }
                else
                {
                    cout << "Incorrect information. Exiting..."<<endl;
                    return false;
                }
            }
            else if (choice == 2)
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

    while (file && numProducts < MAX_PRODUCTS)
    {
        file >> products[numProducts].name >> products[numProducts].price >> products[numProducts].amount;

        // Initialize wishlist member to false (assuming all products are not in the wishlist initially)
        products[numProducts].wishlist = false;

        numProducts++;
    }

    file.close();
}
void displayProductCatalog()
{
    loadProductCatalog();

    // Sort products alphabetically
    for (int i = 0; i < numProducts - 1; ++i)
    {
        for (int j = i + 1; j < numProducts; ++j)
        {
            if (products[i].name > products[j].name)
            {
                swap(products[i], products[j]);
            }
        }
    }

    cout << "Product Catalog:"<<endl;
    for (int i = 0; i < numProducts; ++i)
    {
        cout << i + 1 << ". " << products[i].name << " (" << products[i].price << " taka)"<<endl;
    }

    int choice;
    cout << "Enter the number of the product you want to view details (or 0 to go back): ";
    cin >> choice;
    cin.ignore();

    if (choice >= 1 && choice <= numProducts)
    {
        cout << "You chose: " << products[choice - 1].name << " (" << products[choice - 1].price << " taka)"<<endl;
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
        cout << "2. Add to Cart System"<<endl;
        cout << "3. Add to Wishlist"<<endl;
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
