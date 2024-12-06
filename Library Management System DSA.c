#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create Structure of Library
struct library {
    char book_name[50];
    char author[50];
    int pages;
    float price;
};

int main()
{
    struct library lib[100];
    char ar_nm[50];
    int i, input, count;
    i = input = count = 0;

    while (input != 6) { 
        printf("\nLIBRARY MANAGEMENT SYSTEM\n");
        printf("\n1. Add book information\n2. Display book information\n");
        printf("3. List all books of given author\n");
        printf("4. List the count of books in the library\n");
        printf("5. Remove a book\n6. Exit");

        // Enter the book details
        printf("\n\nEnter one of the above: ");
        scanf("%d", &input);
        getchar(); // Consume newline character left by scanf

        // Process the input
        switch (input) {
            // Add book
            case 1:
                printf("Enter book name: ");
                fgets(lib[count].book_name, sizeof(lib[count].book_name), stdin);
                lib[count].book_name[strcspn(lib[count].book_name, "\n")] = 0; // Remove newline

                printf("Enter author name: ");
                fgets(lib[count].author, sizeof(lib[count].author), stdin);
                lib[count].author[strcspn(lib[count].author, "\n")] = 0; // Remove newline

                // Increment count after adding a book
                count++;
                break;

            // Print book info
            case 2:
                printf("You have entered the following information:\n");
                for (i = 0; i < count; i++) {
                    printf("Book name = %s\t Author name = %s\n",
                           lib[i].book_name, lib[i].author);
                }
                break;

            // Take the author name as input
            case 3:
                printf("Enter author name: ");
                fgets(ar_nm, sizeof(ar_nm), stdin);
                ar_nm[strcspn(ar_nm, "\n")] = 0; // Remove newline
                for (i = 0; i < count; i++) {
                    if (strcmp(ar_nm, lib[i].author) == 0) {
                        printf("Book name: %s, Author: %s\n",
                               lib[i].book_name, lib[i].author);
                    }
                }
                break;

            // Print total count
            case 4:
                printf("\nNumber of books in Library: %d\n", count);
                break;

            // Remove a book
            case 5:
                printf("Enter the index of the book to remove (0 to %d): ", count - 1);
                int index;
                scanf("%d", &index);
                if (index >= 0 && index < count) {
                    printf("Removing book: %s by %s\n", lib[index].book_name, lib[index].author);
                    for (i = index; i < count - 1; i++) {
                        lib[i] = lib[i + 1]; // Shift books left
                    }
                    count--; // Decrease the count
                    printf("Book removed successfully.\n");
                } else {
                    printf("Invalid index.\n");
                }
                break;

            case 6:
                exit(0);
        }
    }
    return 0;
}
