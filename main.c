#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct book {
    char name[100];
    int pageNumber;
    float price;
} Book;

typedef struct library {
    Book books[100];
} Library; //Later, I will think if this struct is useful or not. For now, it is not.

void addBookToLib(Book lib[], int numOfBooks) {
    if (numOfBooks < 100) {
        char name[100];
        int pageNum;
        float price;

        printf("|-*-|What is the name of the book: ");
        fgets(name, 100, stdin);
        name[strcspn(name, "\n")] = 0; // remove the newline character from the end of the string
        //name[strlen(name) - 1] = '\0';

        printf("|-*-|How many pages are there in the book: ");
        scanf("%d", &pageNum);

        printf("|-*-|What is the price (TL): ");
        scanf("%f", &price);

        strcpy(lib[numOfBooks].name, name);
        lib[numOfBooks].pageNumber = pageNum;
        lib[numOfBooks].price = price;

        printf("|-!***!-|The book is added successfully to the library.\n");
    }

    else {
        printf("There is not enough space to add one more book.\n");
    }
}

void printBookInfo(Book book){
    printf("\n------*------Information About the Book \"%s\"------*------\n", book.name);
    printf("\t-Name of the Book: %s\n", book.name);
    printf("\t-Page Number of the Book: %d\n", book.pageNumber);
    printf("\t-Price of the Book (TL): %.2f\n", book.price);
}

void searchBook(Book lib[], int numOfBooks) {
    char name[100];
    bool doesExist = false;
    
    printf("Enter the name of the book about which you want to search: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0; // remove the newline character from the end of the string

    for (int i = 0; i < numOfBooks; i++) {
        if (strcmp(lib[i].name, name) == 0) {
            printBookInfo(lib[i]); 
            doesExist = true;
            break;
        }
    }
    if (!doesExist) {
        printf("\n!!WARNING!! The book does NOT exist !!WARNING!!\n");
    }
}

void deleteBook(Book lib[100], int numOfBooks) {
    char name[100];
    bool doesExist = false;
    int i;

    printf("Enter the name of the book you want to delete: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0; // remove the newline character from the end of the string

    for (i = 0; i < numOfBooks; i++) {
        if (strcmp(lib[i].name, name) == 0) {
            doesExist = true;
            for (int j = i; j < numOfBooks; j++) {
                if (j == 99) {
                    strcpy(lib[j].name, "");
                    lib[j].pageNumber = 0;
                    lib[j].price = 0;
                }
                else {
                    lib[j] = lib[j + 1];
                }
            }
            printf("|-!***!-|The book is deleted successfully from the library.\n");
            break;
        }
    }
    if (!doesExist) {
        printf("\n!!WARNING!! The book does NOT exist !!WARNING!!\n");
    }
}

void printTheLibrary(Book lib[], int numOfTheBooks) {
    printf("\n------------------------All of the Books------------------------\n");
    for (int i = 0; i < numOfTheBooks; i++) {
        printf("Book %d: %s\n",(i + 1), lib[i].name);
    }
    printf("----------------------------------------------------------------\n");
}

void masterLucifer() {
    printf("~~~~~~Dedim iki kişiyiz!~~~~~~\n");
}

void welcome() {
    printf(" --------------------------------------\n");
    printf(" --------------------------------------\n");
    printf("| Welcome to Lucifer's Virtual Library |\n");
    printf(" --------------------------------------\n");
    printf(" --------------------------------------\n");
}

int main() {
    Book myLib[100];
    int numOfTheBooks = 0;
    bool flag = true;

    welcome();

    int choice;
    char termToCheckInput;

    while (flag) {
        printf("\n Which operation would you like to perform:\n");    
        printf("(Enter a number between 1-4. Any other input will cause program to stop.)\n\n");
        printf("\t1-Add a book\n");
        printf("\t2-Search for information of a book\n");
        printf("\t3-Delete a book\n");
        printf("\t4-Print the names of the existing books\n");
        printf("\t5-Hear a wise word from the mighty master Lucifer\n\n");

        printf("Enter your choice: ");
        if (scanf("%d%c", &choice, &termToCheckInput) != 2 || termToCheckInput != '\n' || choice < 1 || choice > 5) {
            flag = false;
        }
        else {
            switch (choice) {
                case 1: 
                    addBookToLib(myLib, numOfTheBooks);
                    numOfTheBooks++;
                    break;
                case 2:
                    searchBook(myLib, numOfTheBooks);
                    break;
                case 3:
                    deleteBook(myLib, numOfTheBooks);
                    numOfTheBooks--;
                    break;
                case 4:
                    printTheLibrary(myLib, numOfTheBooks);
                    break;
                case 5:
                    masterLucifer();
                    break;
            }
        }
    }
    return 0;
}

