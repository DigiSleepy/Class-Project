//================================ HEADER FILES =======================
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>

//======================================================================
using namespace std;
int error;
struct books{
	string bName, aName, pYear;
	int nPages;
	float price;
	};
//---------------------------------------------------------------------
void show(); // First screen 
void bdr(); // For borders
void login(string& admin, string& passward); // Admin login function
void staff(string& user, string& pass1); // Staff and Guest login function
void adminMenu(); // Menu for Admin to add, delete and update things...
//void StaffMenu();// not made yet
//void GuestMenu();// not made yet

void AddBooks();// for adding books into the store...
void AdminOptions();// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void DeleteOptions();// xxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void SearchOptions();// xxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void UpdateOptions();// xxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//=============================================fuction to change font size
void fontsize()
{
	short font, x, y;
	do
	{
		error = 0;
		cout << "\n\tEnter font size : ";
		cin >> font;
		if (font >= 25 || font <= 5)
		{
			cout << "\nPlease enter font size less than 25 & greather than 5... ";
			error = 1;
			cin.clear();
			cin.ignore(10, '\n');
		}
	} while (error == 1);
	x = font;
	y = 2 * x;
	HANDLE Hout = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD fsize = { x, y };
	CONSOLE_FONT_INFOEX Font = { sizeof(Font) };
	::GetCurrentConsoleFontEx(Hout, FALSE, &Font);

	Font.dwFontSize = fsize;
	SetCurrentConsoleFontEx(Hout, 0, &Font);
	cin.clear();
	system("cls");
}
//-----------------------------------------------------------------------------------
//====================================== function to change the background theme
void color()
{
	int col;
	cout << "\n\t1. Black and While theme" << endl;
	cout << "\n\t2. While and Black theme" << endl;
	cout << "\n\t0. Return" << endl;

	do
	{
		do
		{
			error = 0;
			cout << "\n\tPlease chose an option : ";
			cin >> col;
			if (cin.fail())
			{
				cout << "\n\tPlease enter a valid input. " << endl;
				cin.clear();
				cin.ignore(10, '\n');
			}
		} while (error == 1);
		if (col == 1)
		{
			system("color 0F");
			system("cls");
			return;
		}
		else if (col == 2)
		{
			system("color F0");
			system("cls");
			return;
		}
	} while (col != 0);
}
//------------------------------------------------------------------------
//======================================================== MENU
void menu()
{
	system("cls");
	bdr();
	cout << "\n\n\t\tPLEASE SELECT ONE OF THE FOLLOWING OPTIONS\n";bdr();
	cout << "\n\t\t	1. ADMIN MENU "
		<< "\n\n\t\t	2. STAFF MENU "
		<< "\n\n\t\t	3. GUEST  "
		<< "\n\n\t\t	4. CHANGE FONTSIZE"
		<< "\n\n\t\t	5. CHANGE THEME "
		<< "\n\n\t\t	6. ABOUT "
		<< "\n\n\t\t	0. EXIT\n\n\n";bdr();bdr();bdr();bdr();bdr();bdr();

}
//-------------------------------------------------------------------------------
//============================================ password asterisk generator
string getpass(const char* prompt, bool show_asterisk = true)
{
	const char BACKSPACE = 8;
	const char RETURN = 13;
	string password;
	unsigned char ch = 0;
	cout << "\n\n\t" << prompt;
	DWORD con_mode;
	DWORD dwRead;
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hIn, &con_mode);
	SetConsoleMode(hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

	while (ReadConsoleA(hIn, &ch, 1, &dwRead, NULL) && ch != RETURN)
	{
		if (ch == BACKSPACE)
		{
			if (password.length() != 0)
			{
				if (show_asterisk)
					cout << "\b \b";
				password.resize(password.length() - 1);
			}
		}
		else
		{
			password += ch;
			if (show_asterisk)
				cout << '*';
		}
	}
	cout << endl;
	return password;
}
//-----------------------------------------------------------------------





//=============================== MAIN FUNCTION =========================
int main()
{
	//-------------------- Start Screen ----------------------------
	show();
	//-------------------------------------------------------------


	//----------------------------- Welcome Message ---------------------------------------
	/*
	cout << "\n\n\n\t\t\t *** ";
	Sleep(999);
	cout << " *** ";
	Sleep(999);
	cout << " *** ";
	Sleep(999);
	cout << " *** ";
	Sleep(999);
	system("cls");
	*/
	bdr();bdr();bdr();bdr();bdr();bdr();
	cout << setw(70) << "WELCOME TO AKIHABARA MANGA CAFE" << endl << endl;
	cout << setw(70) << "EAT AND ENJOY THE LATEST COMICS" << endl << endl;
	bdr();bdr();bdr();bdr();bdr();bdr();
	system("pause");system("cls");
	//--------------------------------------------------------------------------------------
	
	menu();
	int option;
	
	int choice;
	string user, password;
	
	option = getch();
	do
		{
		option = getch();
		switch (option)
		{
		case 49:// ASKI FOR 1 ------ ADMIN MENU
		{
			system("cls");
			bdr();bdr();
			cout << "\n\n\t\t" << "PLEASE LOGIN INTO YOUR ACCOUNT: ";
			
			cout << "\n\t\tPlease enter the admin username : ";
			cin >> user;
			//cout << "\n\tPleaase enter the password : ";
			//cin >> password;
			password = getpass("\tPlease enter the password : ", true);
			login(user, password);
			break;
		}

		case 50:// ASKI FOR 2 ----------- STAFF MENU
		{
			system("cls");
			cout << "\n\n\t\t" << "PLEASE LOGIN INTO YOUR ACCOUNT: ";
			cout << "\n\tPlease enter the staff username : ";
			cin >> user;
			password = getpass("Please enter the  password : ", true);
			staff(user, password);
		
			break;
		}

		case 51:// ASKI FOR 3 ----------- GUEST
		{
			system("cls");
			cout << "\n\n\t\t" << "GUEST ACCOUNT";
			user = "abc";
			password = "abc";
			staff(user, password);
		
			break;
		}

		case 52:// ASKI FOR 4 --------- CHANGE FONT-SIZE
		{
			fontsize();
			break;
		}

		case 53:// ASKI FOR 5 ---------- CHANGE THEME
		{
			color();
			break;
		}

		case 54:// ASKI FOR 6 ----------- ABOUT 
		{
			system("cls");
			bdr();bdr();
			cout << "\n\t\t\t\t\t   ~|~ ABOUT THIS PROGRAM ~|~\n";
			bdr();bdr();
			cout << endl;
			cout << setw(45) << "Manga cafe:" << endl;
			cout << "\tA manga café is a type of café, originating from Japan, where" << endl;
			cout << "\tpeople can read manga. People pay for the amount of time they" << endl;
			cout << "\tstay in the café. Most manga cafés also offer internet access like" << endl;
			cout << "\tinternet cafés and vice versa, making the two terms mostly" << endl;
			cout << "\tinterchangeable in Japan." << endl;
			bdr();
			cout << "\n\n\t\tIN THIS PROGRAM I AM JUST GONNA BE DOING BASICS TASKS LIKE ADDING BOOKS"
				<< "\n\tIN THE STORE AND SELLING" << endl;


			break;
		}

		/*------------------------------------------
		case 48: // ASKI FOR 0 ----------- EXIT
		{
			cout << "0";

			break;
		}
		---------------------------------------------*/

		default:
		{
			cout << "\n\t\tPlease enter the correct option..\n\t\t";
			system("pause");
			menu();
			break;
		}
		}
	} while (option != 48);

	return 0;
}





//======================================================================================================
void show() {
	//	cout << "                       **************************************************************************\n";
	//	cout << "                     ******************************************************************************\n";
	//	cout << "                   **********************************************************************************\n";
	cout << "                 **************************************************************************************\n";
	cout << "               ******************************************************************************************\n";
	cout << "             **********************************************************************************************\n";
	cout << "           **************************************************************************************************\n";
	cout << "         ******************************************************************************************************\n";
	cout << "       **********************************************************************************************************\n";
	cout << "     **************************************************************************************************************\n";
	cout << "   ******************************************************************************************************************\n";
	cout << " **********************************************************************************************************************\n";
	cout << "                    **********             _____________________                          **********\n";
	cout << "                    **********            | M A N G A ~~~~~~~~~ ]                         **********\n";
	cout << "                    **********            | ~~~~~~~~ C A F E ~~ ]                         **********\n";
	cout << "                    **********             ^^^^^^^^^^^^^^^^^^^^^                          **********\n";
	cout << "                    **********                                                            **********\n";
	cout << "                    **********                                                            **********\n";
	cout << "                    **********    ___________________                                     **********\n";
	cout << "                    **********    |    _________    |                                     **********\n";
	cout << "                    **********    |   |         |   |        ____________                 **********\n";
	cout << "                    **********    |   |         |   |       |      |     |                **********\n";
	cout << "                    **********    |   |         |   |       |      |     |                **********\n";
	cout << "                    **********    |   |_________|   |       |------|-----|                **********\n";
	cout << "                    **********    |                 |       |      |     |                **********\n";
	cout << "                    **********    |              O  |       |______|_____|                **********\n";
	cout << "                    **********    |    _________    |                                     **********\n";
	cout << "                    **********    |   |         |   |                                     **********\n";
	cout << "                    **********    |   |         |   |                                     **********\n";
	cout << "                    **********    |   |         |   |                                     **********\n";
	cout << "                    **********    |   |_________|   |                                     **********\n";
	cout << "                    **********    |                 |                                     **********\n";
	system("pause");system("cls");
}
//------------------------------------------------------------------------------------------------------
//======================================================================================================
void bdr() {
	cout << "\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0"
		<< "\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0"
		<< "\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0"
		<< "\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0"
		<< "\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0"
		<< "\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0"
		<< endl;
}












//------------ Login function for admin -----------------
void login(string& admin, string& passward) {
	string users[20];
	string pass[20];
	bool valid = false;

	int x = 0;
	ifstream usFile;
	usFile.open("admin.txt");

	usFile >> users[x] >> pass[x];

	while (usFile) // read usernames and passwords from file and store them in arrays
	{
		x++;
		if (x >= 20) // not to exeed the array limit
			break;
		usFile >> users[x] >> pass[x];
	}
	for (int a = 0; a < x; a++)
	{
		if (admin == users[a] && passward == pass[a]) // match user names and passwards with array components
		{
			cout << "\n\tSuccessfully logged into admin account" << endl;
			valid = true;
			adminMenu();
			break;
		}
	}
	if (!valid)
	{
		cout << "\n\tUsername & password invalid try again\t\t\n\n";
		system("pause");
	}

}


// Login Function for Staffs
void staff(string& user, string& pass1)
{
	string users[200];
	string pass[200];
	bool valid = false;

	int x = 0;
	ifstream usFile;
	usFile.open("user.txt");
	char choice;

	usFile >> users[x] >> pass[x];
	while (usFile) // read user names and passwords from file and store them in array
	{
		x++;
		if (x >= 200) // not to exceed the array limit
			break;
		usFile >> users[x] >> pass[x];
	}

	for (int a = 0; a < x; a++)
	{
		if (user == users[a] && pass1 == pass[a]) // match user names and password
		{
			cout << "\tSuccessfully logged into staff account" << endl;
			valid = true;
			// ---------------------------------------- ADD STAFF MENU HERE
			
			break;
		}
		if (user == "abc" && pass1 == "abc")
		{
			cout << "\n\tSuccessfully logged into guest account" << endl;
			valid = true;
			// -------------------------------------- ADD GUEST MENU HERE
			
			break;
		}
	}
	if (!valid)
	{
		cout << "\n\tUsername & password is invalid \n\n";
		system("pause");
	}
}

// Admin Functions
void AdminOptions()
{
	system("pause");
	system("cls");

	cout << "\n\n\t	WELCOME TO ADMINISTRATOR MENU" << endl;
	cout << "\t	================================================" << endl;
	cout << "\n\t1 : ADD NEW BOOKS" << endl;
	cout << "\n\t2 : DISPLAY ALL BOOKS" << endl;
	cout << "\n\t3 : SEARCH BOOKS" << endl;
	cout << "\n\t4 : DELETE BOOKS" << endl;
	cout << "\n\t5 : UPDATE BOOKS" << endl;
	cout << "\n\t6 : VIEW SPECIAL OFFERS" << endl;
	cout << "\n\t7 : VIEW LOGIN REPORT " << endl;
	cout << "\n\t8 : HELP" << endl;
	cout << "\n\t0 : RETURN TO MAIN MENU" << endl;
}

//-------------------------------------------------- add new books
void AddBooks()
{
	ofstream myFile;
	myFile.open("books.txt", ios::app);
	
	
	short bookID;
	cout << "Enter the book ID: "; cin >> bookID;
	books b[bookID];
	
	for (int i = bookID; i <= bookID; i++){
		i--;
		cout << "------------------Book " << i+1 << "---------------------\n";
		cin.ignore();
		cout << "Enter the Author name of book " << i+1 << "     : "; getline(cin,b[i].aName);
		cout << "Enter the name of book " << i+1 << "            : "; getline(cin,b[i].bName);
		cout << "Enter the Publishing year in dd/mm/yyyy format  : "; getline(cin,b[i].pYear);
		cout << "Enter the number of pages of book " << i+1 << " : "; cin >> b[i].nPages;
		cout << "Enter the price of the book " << i+1 << "       : "; cin >> b[i].price;
		cout << "\n=======================================================================\n";
		
//--------------------------Display Output---------------------------------------------------
		cout << bookID << endl;
		//cout << "\n=======================================================================\n";
		cout << "The name of the Author of book " << i+1 << " is    : " << b[i].aName << endl;
		cout << "The name of the book " << i+1 << "                 : " << b[i].bName << endl;
		cout << "The year of publish of book " << i+1 << " is       : " << b[i].pYear << endl;
		cout << "The number of pages in book " << i+1 << " is       : " << b[i].nPages << endl;
		cout << "The price of the book " << i+1 << " is             : " << b[i].price << endl;
		//cout << "\n=======================================================================\n";
		cout << "\n=======================================================================\n";

//--------------------------File Handling-----------------------------------------------------
		myFile << bookID << endl;
		//myFile << "\n=======================================================================\n";
		myFile << "The name of the Author of book " << i+1 << " is    : " << b[i].aName << endl;
		myFile << "The name of the book " << i+1 << "                 : " << b[i].bName << endl;
		myFile << "The year of publish of book " << i+1 << " is       : " << b[i].pYear << endl;
		myFile << "The number of pages in book " << i+1 << " is       : " << b[i].nPages << endl;
		myFile << "The price of the book " << i+1 << " is             : " << b[i].price << endl;
		//myFile << "\n=======================================================================\n";
		myFile << "\n=======================================================================\n";
		i++;
	}
}

//-------------------------------------------------- Search option
void SearchOptions()
{
	system("cls");
	cout << "\n\t\tSEARCH BOOKS" << endl;
	cout << "\t================================================\n\n\n";
	cout << "\n\t1 : SEARCH BOOKS BY ID " << endl;
	cout << "\n\t2 : SEARCH BOOKS BY CATEGORY" << endl;
	cout << "\n\t3 : SEARCH BY BOOKS NAME " << endl;
	cout << "\n\t4 : SEARCH BY BOOK AUTHOR" << endl;
	cout << "\n\t5 : SEARCH BY PRICE" << endl;
	cout << "\n\t0 : BACK TO ADMIN MENU" << endl;

}

//------------------------------------------------- Update options
void UpdateOptions()
{
	system("cls");
	cout << "\n\t\tUPDATE BOOKS " << endl;
	cout << "\t====================================================" << endl;
	cout << "\n\t1 : SEARCH & UPDATE BY BOOK ID" << endl
		<< "\n\t2 : SEARCH & UPDATE BY BOOK CATEGORY\n"
		<< "\n\t3 : SEARCH & UPDATE BY BOOK NAME\n"
		<< "\n\t4 : SEARCH & UPDATE BY BOOK AUTHOR\n"
		<< "\n\t5 : DISPLAY LIST & UPDATE\n"
		<< "\n\t0 : BACK TO ADMIN MENU\n";
}

// --------------------------------------------------------- DELETE OPTIONS
void DeleteOptions()
{
	system("cls");
	cout << "\n\t\tDELETE BOOKS " << endl;
	cout << "\t====================================================" << endl;// CHANGE IT TO BORDER
	cout << "\n\t1 : SEARCH & DELETE BY BOOK ID" << endl
		<< "\n\t2 : SEARCH & DELETE BY BOOK CATEGORY\n"
		<< "\n\t3 : SEARCH & DELETE BY BOOK NAME\n"
		<< "\n\t4 : SEARCH & DELETE BY BOOK AUTHOR\n"
		<< "\n\t5 : DISPLAY LIST & DELETE\n"
		<< "\n\t0 : BACK TO ADMIN MENU\n";
}

//------------------------------------------- ADMIN MENU
void adminMenu()
{
	int sel,newbooks,allbooks, searchbooks, updateops, dltops, searchops;
	do
	{
		AdminOptions();
		do
		{
			error = 0;
			cout << "\n\n\tPlease enter your selection : ";
			cin >> sel;
			if (cin.fail())
			{
				cout << "\tPlease enter a valid input : " << endl;
				error = 1;
				cin.clear();
				cin.ignore(10, '\n');
			}
		} while (error == 1);

		switch (sel)
		{
		case 1:// Add new books
		{
			AddBooks();
		} break;

		case 2:// display all books
		{

		} break;

		case 3:// search books
		{
		
		} break;

		case 4:// delete books
		{
			
		} break;

		case 5:// update books
		{
			
		} break;

		case 6:// create special offers
		{

		} break;

		case 7:// help..
		{

		} break;

//		case 8:// Return..
//		{
//
//		} break;

		case 0:// Return..
		{
			system("pause");
			return;
		} break;


		default:
			cout << "\n\tInvalid Selection...	try again.... ";
		}
		/*
		if (sel == 3)
		{
			do
			{
				SearchOptions();

				do
				{
					error = 0;
					cout << "\n\n\tPlease enter your selection : ";
					cin >> searchops;
					if (cin.fail())
					{
						cout << "\n\tPlease enter a valid input : " << endl;
						error = 1;
						cin.clear();
						cin.ignore(10, '\n');
					}
				} while (error == 1);
				switch (searchops)
				{
				case 1:
				{
					
				} break;

				case 2:
				{

				} break;

				case 3:
				{

				} break;

				case 4:
				{

				} break;

				case 5:
				{

				} break;

				case 0:
				{

				} break;

				default:	cout << "\n\tInvalid selection... try again....";

				}
			} while (searchops != 0);
		}
		if (sel == 4)
		{
			do
			{
				DeleteOptions();

				do
				{
					error = 0;
					cout << "\n\n\tPlease enter your selection : ";
					cin >> dltops;
					if (cin.fail())
					{
						cout << "\n\tPlease enter a valid input : " << endl;
						cin.clear();
						cin.ignore(10, '\n');
					}
				} while (error == 1);
				switch (dltops)
				{
				case 1:
				{

				} break;
				case 2:
				{

				} break;
				case 3:
				{

				} break;
				case 4:
				{

				} break;
				case 5:
				{

				} break;
				case 0:
				{

				} break;

				default:	cout << "\n\tInvalid selection... Try again.... ";
					//break;
				}
			} while (dltops != 0);
		}
		if (sel == 5)
		{

			do
			{
				UpdateOptions();

				do
				{
					error = 0;
					cout << "\n\n\tPlease enter your selection : ";
					cin >> updateops;
					if (cin.fail())
					{
						cout << "\n\tPlease enter a valid input : " << endl;
						cin.clear();
						cin.ignore(10, '\n');
					}
				} while (error == 1);
				switch (updateops)
				{
				case 1: break;
				case 2: break;
				case 3: break;
				case 4: break;
				case 5: break;
				case 0: break;
				default:	cout << "\n\tInvalid selection... Try again....";
				}
			} while (updateops != 0);
		} 
		*/
	} while (sel !=0);
}

