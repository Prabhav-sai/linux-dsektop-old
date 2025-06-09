# Q1

## Bank Account Management Program

This is a program that allows users to manage bank accounts. Users can perform the following operations:

- Create a new account (savings or current)
- Delete an existing account
- Perform transactions (withdrawal or deposit)
- Display all accounts
- Display low balance accounts

### STRUCTURES:

1. Enum accounttype:
typedef enum accounttype{
    savings,
    current,
}accounttype;

This is an enumeration type that defines two possible values: `savings` and `current`. These will be used to specify the type of account.

2. Structure AccountInfo:

typedef struct AccountInfo{
    int AccountNumber;
    accounttype AccountType;
    char Name[50];
    float Balance;
}AccountInfo;

This structure defines the information associated with an account. It includes:

- AccountNumber: An integer representing the account number.
- AccountType: An enum (accounttype) indicating whether the account is of type `savings` or `current`.
- Name: An array of characters (string) representing the account holder's name.
- Balance: A floating-point number representing the current balance of the account.

3. Structure Accountnode:

typedef struct Accountnode{
    AccountInfo Account;
    struct Accountnode * next;
}Accountnode;

This structure represents a node in a linked list of accounts. It includes:

- Account: An instance of the `AccountInfo` structure, which contains the account details.
- next: A pointer to the next node in the linked list.

4. Typedef `LinkedList`:

typedef Accountnode* LinkedList;

- This typedef defines `LinkedList` as a pointer to an `Accountnode`. It will be used to refer to the head of the linked list.

### FUNCTIONS:

1. void display(LinkedList Accountlist)
   This function is responsible for displaying the details of all accounts in the linked list.

2. void lowBalanceAccounts(LinkedList AccountList)
   This function identifies and displays accounts with a balance less than 100.

3. void PrintNode(AccountInfo Account)
   This function prints the details of a single account.

4. int CheckNode(LinkedList AccountList,char Name[],accounttype AccountType)
   This function checks if an account with a given name and account type already exists in the linked list.

5. LinkedList createAccount(LinkedList AccountList,accounttype AccountType,char Name[],float Amount)
   This function creates a new account node and inserts it into the linked list.

6. LinkedList deleteAccount(LinkedList AccountList,accounttype AccountType,char Name[])
   This function deletes an account from the linked list based on the account type and name.

7. void transaction(LinkedList AccountList,int AccountNumber,float Amount,int code)
   This function performs a transaction (either a withdrawal or deposit) on a specific account.

8. int main()
   This is the main function where the program execution begins. It contains a loop that reads user commands and performs corresponding operations on the linked list of accounts.

### USAGE

1. Creating a new account:
   - Command: "CREATE" AccountType Name Amount
   - Example: CREATE savings JohnDoe 5000

2. Deleting an account:
   - Command: "DELETE" AccountType Name
   - Example: DELETE savings JohnDoe

3. Performing a transaction:
   - Command: "TRANSACTION" AccountNumber Amount Code
   - code 0 for withdrawal, 1 for deposit
   - Example: TRANSACTION 101 1000 1


4. Displaying low balance accounts:
   Command: "LOWBALANCE"

5. Displaying all accounts:
   Command: "DISPLAY"

6. Exiting the program:
   Command: "EXIT"

### NOTE:
- Account numbers are automatically assigned starting from 100.
- Create Account appropriately add an Account to a position which also manages the deleted account(meaning adds to the first deleted  place).
- The minimum balance required for an account is 100.
- but you can create an account with balance less than 100, such accounts will be displayed in the lowbalance command.
- You can't make a transaction that changes your balance to less than account 100.
- Until you enter the command "EXIT" , the programme will keep prompting you to enter an command , it will ignore commands other than the ones mentions above.


# Q2

## Complex Number Operations Program

This program allows users to perform various operations on complex numbers which are:

- addition
- subtraction
- dot product
- cosine similarity

### Structures:

complexnumber

typedef struct complexnumber{
    int size;
    float* number;
}complexnumber;

- size: An integer indicating the size of the complex number (number of elements).
- number: A pointer to an array of floats representing the elements of the complex number.


### Functions:

1. complexnumber ADD(complexnumber c1,complexnumber c2)
   This function performs addition on two complex numbers and returns the result.

2. complexnumber SUB(complexnumber c1,complexnumber c2)
   This function performs subtraction on two complex numbers and returns the result.

3. float DOT(complexnumber c1,complexnumber c2)
   This function calculates the dot product of two complex numbers and returns the result as a float.

4. float MOD(complexnumber c1)
   This function calculates the modulus (magnitude) of a complex number and returns the result as a float.
   This function is used for a part of cosine similarity fn.

5. float COSINE(complexnumber c1,complexnumber c2)
   This function calculates the cosine similarity between two complex numbers and returns the result as a float.

6. void PrintComplex(complexnumber c1)
   This function prints the elements of a complex number.
   This is for output of ADD and SUB fns.

### USAGE

1. Input a command:
   Enter "ADD", "SUB", "DOT", or "COSINE" to choose the operation.

2. Enter the dimension (n) of the complex vectors.

3. Input the elements of the first complex vector.

4. Input the elements of the second complex vector.

5. Enter -1 to exit the program.

The program will display the result of the selected operation.

### EXAMPLE:

ADD
3
1.0 2.0 3.0
4.0 5.0 6.0

RESULT: 5.00 7.00 9.00

-1


### NOTE:
#### * You have to add "-lm" in the command centre like "gcc q2.c   -lm" for the code to run and compile
- A structure compelx number has been used which contains size and a pointer.
- The program uses dynamic memory allocation for complex number storage.
- The complex numbers will be stored in float data type to make the functions accurate.
- The output displayed will be upto 2 decimal places.
- The program will keep asking for an command until an "-1" has been entered.It will ignore any command other than the ones mentioned above.

### CONSTRAINTS:
- No direct usage of arrays.

# Q3

## COLORS - Remove Duplicates

This program takes a list of colors as input, represented by integers, and removes any duplicate colors, leaving only distinct colors in the modified linked list.

### Structures:

colornode

typedef struct colornode{
    int color; // no of color
    struct colornode * next; // pointer to next node
}colornode;
- color: An integer representing the color.
- next: A pointer to the next node in the linked list. 

Linkedlist

typedef colornode* Linkedlist;
- This typedef defines Linkedlist as a pointer to a colornode. It will be used to refer to the head of the linked list.

### Functions:

1. Linkedlist append(int colouradd,Linkedlist l)
   This function appends a new color node with the specified color to the end of the linked list.

2. void removeduplicates(Linkedlist l)
   This function removes duplicate colors from the linked list.

3. void printlist(Linkedlist l)
   This function prints the elements of the linked list.

### USAGE

1. Input the number of colors (n) in the list.
2. Input the colors (represented by integers).
3. The program will create a linked list with the provided colors and remove any duplicate colors.
4. The modified linked list will be displayed as output.

### EXAMPLE:

Input:
Enter the number of colors in the list: 6
Enter the colors: 1 2 2 3 4 4

Output:
Modified Linked List: 1 -> 2 -> 3 -> 4

### NOTE:
- Colors are represented by numbers.

### CONSTRAINTS:
- A Linked List need to be made to take inputs
- The list has to be modified in place
- This programme only works when the numbers are input in a non-decreasing order.