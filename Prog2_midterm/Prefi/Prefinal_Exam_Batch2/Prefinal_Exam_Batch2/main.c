#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM		10 
#define STRING_LENGTH	30
#define TRUE			1
#define FALSE			0
#define MAX_RACK		5

typedef char String[STRING_LENGTH];
typedef int Boolean;					// Boolean either TRUE or FALSE value

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	int prodID;
	String prodName;
	Date manufactureDate;
	Date expiryDate;
	float prodPrice;
} Product;

typedef struct {
	Product list[MAX_ITEM];				// the current products in racck
	int itemCount;						// the current number of product items in rack
} Rack;

typedef struct {
	Boolean shelves[MAX_RACK]; 			// TRUE if occupied and FALSE if unocccupied
	Rack rackItems[MAX_RACK];			// the rack that contains actual product items
	float totalMoney;					// total amount in the machine
} VendingMachine;

//main functions

/*
 *	Creates a vending machine instance that will set it as an empty machine.
*/
VendingMachine createVendingMachine();

/*
 * 	The displayVendingMachine() is a simple visualization of the contents. It will
 *	show the racks and the individual items in each rack in order with the 
 *	name and price of the product.
*/
void displayVendingMachine(VendingMachine vm);

/*
 * 	Creates a date with the given integer value of day, month, and year.
*/
Date createDate(int day, int month, int year);

/*
 * 	Creates a product with a given id, name, date of manufacture, date of expriry,
 *	and the price.
*/
Product createProduct(int id, String name, Date mfDate, Date expDate, float price);

/*
 *  The addProduct() function is a simple way to restock a product from a vending machine.
 *  It takes two parammeters: the rack number in which the product will be added and
 *  the product itself. The function then adds the product in the rack considering the 
 *  expiry date of the product. Products near expiry should placed ahead, so they may be
 *	able to dispense first. The function also checks if the rack number is valid and if the
 *	selected rack is not yet full, this will be considered as a successful transaction.
 *  Otherwise it will display the error message and returns a failure transaction.
*/
Boolean addProduct(VendingMachine *vm, int rackNumber, Product prodItem);

/*
 *  The purchaseProduct() function is a simple way to buy a product from a vending machine. 
 *  It takes two parameters: the rack number of the product and the amount of money to pay. 
 *  The function checks if the rack number is valid, if the product is available, and if 
 *	the amount is enough; it will then displays the necessary error message and returns a failure 
 *	transaction. If all conditions are met, the function dispenses the product 
 *	(removes from the vending machine), shows the the change, and returns a successful transaction.
*/
Boolean purchaseProduct(VendingMachine *vm, int rackNumber, float amount);

//helper functions
int days_in_month(int month, int year);
int date_difference(Date d1, Date d2);


int main() {
	VendingMachine vm1 = createVendingMachine();
	
	printf("[1.0] DISPLAY OF AN EMPTY VENDING MACHINE.\n");
//	NO.1 Activate the given code below to show an empty vending machine.
	displayVendingMachine(vm1);
	
	system("PAUSE");
	system("CLS");
	
	printf("[2.0] INITIALLY POPULATED VENDING MACHINE. DISPLAY OF VENDING MACHINE.\n");
//	{take note that the addProduct below are just samples and may not be the same when its checked}	
//	NO.2 Activate lines below to initially populate the vending machine and display it.
	addProduct(&vm1, 2, createProduct(4, "Coke", createDate(1,1,2023), createDate(5,5,2023), 40.0));
	addProduct(&vm1, 2, createProduct(10, "Sprite", createDate(1,1,2023), createDate(25,5,2023), 50.0));
	addProduct(&vm1, 4, createProduct(12, "Beer", createDate(1,1,2023), createDate(2,5,2023), 100.0));
	addProduct(&vm1, 4, createProduct(10, "Sprite", createDate(1,1,2023), createDate(15,5,2023), 50.0));
	addProduct(&vm1, 2, createProduct(2, "Vodka", createDate(1,1,2023), createDate(10,5,2023), 120.0));
	addProduct(&vm1, 0, createProduct(5, "Royal", createDate(1,1,2023), createDate(2,5,2023), 45.0));
	displayVendingMachine(vm1);
	
	system("PAUSE");
	system("CLS");
	
	printf("[3.1] PURCHASING PRODUCT in rack zero with more than the required amount.\n");
//	NO. 3.1 Activate the 2 lines below.	
	purchaseProduct(&vm1, 0, 50);
	displayVendingMachine(vm1);
	
	printf("[3.2] PURCHASING PRODUCT in rack 2 with lacking amount.\n");
//	NO. 3.2 Activate the 2 lines below.
	purchaseProduct(&vm1, 2, 20);
	displayVendingMachine(vm1);
	
	printf("[3.3] PURCHASING PRODUCT in rack 1 (in an empty rack).\n");
//	NO. 3.2 Activate the 2 lines below.
	purchaseProduct(&vm1, 1, 20);
	displayVendingMachine(vm1);
	
	printf("[3.4] TEST\n");
//	NO. 3.2 Activate the 2 lines below.
	purchaseProduct(&vm1, 4, 200);
	displayVendingMachine(vm1);
	
	system("PAUSE");
	return 0;
}

VendingMachine createVendingMachine() {
	VendingMachine vm;
	int i;
	
	vm.totalMoney = 0;
	for(i = 0; i < MAX_RACK; ++i) {
		vm.shelves[i] = FALSE;
		vm.rackItems[i].itemCount = 0;
	}
	
	return vm;
}


void displayVendingMachine(VendingMachine vm) {
	// To do code logic here.
	int i, j, k;
	printf("VENDING MACHINE\n");
	for(i = 0; i < MAX_RACK; i++)
	{
		printf("RACK - %d\n", i);
		if(vm.shelves[i] == FALSE && vm.rackItems[i].itemCount == 0)
		{
			printf("	EMPTY RACK\n\n");
		}
		if (vm.shelves[i] == TRUE)
		{
			for(j = 0; j < vm.rackItems[i].itemCount; j++)
			{
				printf("	Item %d -  %s - Php    %.2f - %d/%d/%d\n", j, vm.rackItems[i].list[j].prodName, vm.rackItems[i].list[j].prodPrice, vm.rackItems[i].list[j].expiryDate.day, vm.rackItems[i].list[j].expiryDate.month, vm.rackItems[i].list[j].expiryDate.year);
			}
		}
	}
	printf("\nTOTAL AMOUNT: Php %.2f\n\n", vm.totalMoney);
}

Date createDate(int day, int month, int year) {
	Date d;
	
	d.day = day;
	d.month = month;
	d.year = year;
	
	return d;	
}

Product createProduct(int id, String name, Date mfDate, Date expDate, float price) {
	Product p;
	
	p.prodID = id;
	strcpy(p.prodName, name);
	p.manufactureDate = mfDate;
	p.expiryDate = expDate;
	p.prodPrice = price;
	
	return p;
}

Boolean addProduct(VendingMachine *vm, int rackNumber, Product prodItem) {
	// To do code logic here.
	int i, j, k; 
	Product temp;

	vm->rackItems[rackNumber].list[vm->rackItems[rackNumber].itemCount] = prodItem;
	vm->rackItems[rackNumber].itemCount++;
	vm->shelves[rackNumber] = TRUE;
	printf("Successfully added.\n");
	 	
	for(j = 0; j < vm->rackItems[rackNumber].itemCount - 1; j++)
	{
		for(k = 0; k < vm->rackItems[rackNumber].itemCount - 1; k++)
		{
			if(date_difference(vm->rackItems[rackNumber].list[k].expiryDate,vm->rackItems[rackNumber].list[k+1].expiryDate) < 0)
			{
				temp = vm->rackItems[rackNumber].list[k+1];
				vm->rackItems[rackNumber].list[k+1] = vm->rackItems[rackNumber].list[k];
				vm->rackItems[rackNumber].list[k] = temp;
			}
		}
	}
		
	return vm->shelves[rackNumber];
}

Boolean purchaseProduct(VendingMachine *vm, int rackNumber, float amount) {
	// To do code logic here.
	float sum;
	int i;
	
	for(i = 0; i < vm->rackItems[rackNumber].itemCount; i++)
	{
		//total bought
		sum += vm->rackItems[rackNumber].list[i].prodPrice;
	}
	
	if (vm->rackItems[rackNumber].itemCount == 0 && vm->shelves[rackNumber] == FALSE)
	{
		printf("Invalid selection the rack is empty.\n");
		vm->totalMoney = 0;
		return FALSE;
	}
	else if(sum > amount)
	{
		printf("Not enough money tendered for the product you want to buy.\n");
		vm->totalMoney = 0;
		return FALSE;
	}
	if(sum < amount)
	{
		printf("Please enjoy your food\n");
		printf("You have a change of Php %.2f.\n", amount - sum);
		vm->shelves[rackNumber] = FALSE;
		vm->rackItems[rackNumber].itemCount = 0;
		vm->totalMoney = sum;
		return vm->shelves[rackNumber];
	}
	
	
}

int days_in_month(int month, int year) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return 29;
        else
            return 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int date_difference(Date d1, Date d2) {
    int days1, days2;

    days1 = d1.day;
    days2 = d2.day;

    int i;

    for (i = 1; i < d1.month; i++) {
        days1 += days_in_month(i, d1.year);
    }

    for (i = 1; i < d2.month; i++) {
        days2 += days_in_month(i, d2.year);
    }

    days1 += (d1.year - 1) * 365 + (d1.year - 1) / 4 - (d1.year - 1) / 100 + (d1.year - 1) / 400;
    days2 += (d2.year - 1) * 365 + (d2.year - 1) / 4 - (d2.year - 1) / 100 + (d2.year - 1) / 400;

    return days2 - days1;
}
