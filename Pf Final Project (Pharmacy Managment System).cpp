/*  
		Project:   Pharmacy Management System For Semester Project
	*/		


#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 200;

struct Product
{
    string name;
    int price;
};

struct Employee
{
    string name;
    int salary;
    int attendance;
};

struct MedicalStore
{
    Product products[MAX_PRODUCTS];
    int num_products;
    Employee employees[MAX_PRODUCTS];
    int num_employees;
    int password;
};

// Initializes a MedicalStore with empty products and employees and the given password
void initStore(MedicalStore &store, int password)
{
    store.num_products = 0;
    store.num_employees = 0;
    store.password = password;
}

// Prints the menu for the admin
void printAdminMenu()
{
    cout << "PRESS 1 to add a product" << endl;
    cout << "PRESS 2 TO delete a product" << endl;
    cout << "PRESS 3 TO see the record of a product" << endl;
    cout << "PRESS 4 TO calculate the salary of an employer" << endl;
    cout << "PRESS 5 TO change the password of the employers login" << endl;
    cout << "PRESS 6 TO change the price of a existing product" << endl;
    cout << "PRESS 7 TO EXIT" << endl;
}

// Prints the menu for the employer
void printEmployerMenu()
{
    cout << "PRESS 1 to see the list of products" << endl;
    cout << "Press 2 to sale the Product at 5% discount" << endl;
    cout << "Press 3 to give the manual discount" << endl;
    cout << "Press 4 to search the product" << endl;
    cout << "Press 5 to Exit" << endl;
}

// Adds a product to the store
void addProduct(MedicalStore &store)
{
    cout << "Enter the name of the product: ";
    cin >> store.products[store.num_products].name;
    cout << "Enter the price of the product: ";
    cin >> store.products[store.num_products].price;
    cout << "Product successfully added" << endl;
    store.num_products++;
}

// Deletes a product from the store
void deleteProduct(MedicalStore &store)
{
    cout << "Enter the name of the product to delete: ";
    string product_name;
    cin >> product_name;

    int product_index = -1;
    for (int i = 0; i < store.num_products; i++)
    {
        if (store.products[i].name == product_name)
        {
            product_index = i;
            break;
        }
    }

    if (product_index == -1)
    {
        cout << "Product not found " << endl;
            return;
    }

    for (int i = product_index; i < store.num_products - 1; i++)
    {
        store.products[i] = store.products[i + 1];
    }
    store.num_products--;
    cout << "Product successfully deleted" << endl;
}

// Displays the record of a product
void displayProductRecord(const MedicalStore &store)
{
    cout << "Enter the name of the product: ";
    string product_name;
    cin >> product_name;

    for (int i = 0; i < store.num_products; i++)
    {
        if (store.products[i].name == product_name)
        {
            cout << "Name: " << store.products[i].name << endl;
            cout << "Price: " << store.products[i].price << endl;
            return;
        }
    }

    cout << "Product not found" << endl;
}

// Calculates the salary of an employee
void calculateSalary(MedicalStore &store)
{
    cout << "Enter the name of the employee: ";
    string employee_name;
    cin >> employee_name;

    for (int i = 0; i < store.num_employees; i++)
    {
        if (store.employees[i].name == employee_name)
        {
            int salary = store.employees[i].salary;
            int attendance = store.employees[i].attendance;
            int bonus = attendance * 100;
            salary += bonus;
            cout << "Total salary: " << salary << endl;
            return;
        }
    }

    cout << "Employee not found" << endl;
}

// Changes the password of the employer login
void changePassword(MedicalStore &store)
{
    cout << "Enter the new password: ";
    cin >> store.password;
    cout << "Password successfully changed" << endl;
}

// Changes the price of a product
void changePrice(MedicalStore &store)
{
    cout << "Enter the name of the product: ";
    string product_name;
    cin >> product_name;

    for (int i = 0; i < store.num_products; i++)
    {
        if (store.products[i].name == product_name)
        {
            cout << "Enter the new price: ";
            cin >> store.products[i].price;
            cout << "Price successfully changed" << endl;
            return;
        }
    }

    cout << "Product not found" << endl;
}

// Sells a product at a 5% discount
void sellProduct(MedicalStore &store)
{
    cout << "Enter the name of the product: ";
    string product_name;
    cin >>
        product_name;

    for (int i = 0; i < store.num_products; i++)
    {
        if (store.products[i].name == product_name)
        {
            int price = store.products[i].price;
            int discount = price * 0.05;
            price -= discount;
            cout << "Total price: " << price << endl;
            return;
        }
    }

    cout << "Product not found" << endl;
}

// Sells a product with a manual discount
void sellProductWithDiscount(MedicalStore &store)
{
    cout << "Enter the name of the product: ";
    string product_name;
    cin >> product_name;

    for (int i = 0; i < store.num_products; i++)
    {
        if (store.products[i].name == product_name)
        {
            int price = store.products[i].price;
            cout << "Enter the discount amount: ";
            int discount;
            cin >> discount;
            price -= discount;
            cout << "Total price: " << price << endl;
            return;
        }
    }

    cout << "Product not found" << endl;
}

// Searches for a product
void searchProduct(const MedicalStore &store)
{
    cout << "Enter the name of the product: ";
    string product_name;
    cin >> product_name;

    for (int i = 0; i < store.num_products; i++)
    {
        if (store.products[i].name == product_name)
        {
            cout << "Product found" << endl;
            return;
        }
    }

    cout << "Product not found" << endl;
}

int main()
{
    MedicalStore store;
    initStore(store, 1234);

    while (true)
    {
        cout << "Press 1 to enter into ADMIN account" << endl;
        cout << "Press 2 to enter into the EMPLOYER account" << endl;
        int account;
        cin >> account;

        if (account == 1)
        {
            cout << "Enter the password: ";
            int password;
            cin >> password;

            if (password != store.password)
            {
                cout << "Incorrect password" << endl;
                continue;
            }

            while (true)
            {
                printAdminMenu();
                int option;
                cin >> option;

                if (option == 1)
                {
                    addProduct(store);
                }
                else if (option == 2)
                {
                    deleteProduct(store);
                }
                else if (option == 3)
                {
                    displayProductRecord(store);
                }
                else if (option == 4)
                {
                    calculateSalary(store);
                }
                else if (option == 5)
                {
                    changePassword(store);
                }
                else if (option == 6)
                {
                    changePrice(store);
                }
                else if (option == 7)
                {
                    break;
                }
                else
                {
                    cout << "Invalid option" << endl;
                }
            }
        }
        else if (account == 2)
        {
            while (true)
            {
                printEmployerMenu();
                int option;
                cin >> option;

                if (option == 1)
                {
                    for (int i = 0; i < store.num_products; i++)
                    {
                        cout << store.products[i].name << " " << store.products[i].price << endl;
                    }
                }
                else if (option == 2)
                {
                    sellProduct(store);
                }
                else if (option == 3)
                {
                    sellProductWithDiscount(store);
                }
                else if (option == 4)
                {
                    searchProduct(store);
                }
                else if (option == 5)
                {
                    break;
                }
                else
                {
                    cout << "Invalid option" << endl;
                }
            }
        }
        else
        {
            cout << "Invalid account" << endl;
        }
    }

    return 0;
}
