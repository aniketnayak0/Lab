#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class Library{
    long ISBN;
    int numberOfCopies,issuedBook=0;
    char bookTitle[100],author[100];
    public:
    void getData(){
        cout << "Enter Book Details" << endl;
        cout << "ISBN: ";
        cin >> ISBN;
        cin.ignore();
        cout << "Book Title: ";
        cin.getline(bookTitle,100);
        cout << "Name of author: ";
        cin.getline(author,100);
        cout << "Number of copies: ";
        cin >> numberOfCopies;
    }
    void displayData(){
        cout << "ISBN: " << ISBN << endl;
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
        cout << "Number of copies available: " << numberOfCopies << endl;
        cout << "Number of copies issued: " << issuedBook << endl;
    }
    void addNewBook(){
        Library obj,obj1;
        fstream file;
        file.open("catalog.bin",ios::in|ios::out|ios::binary);
        if(file.is_open()==false){
            cerr << "File cannot be opened";
            return;
        }
        obj1.getData();
        while(file.read(reinterpret_cast<char*>(&obj),sizeof(obj))){
            if(obj1.ISBN == obj.ISBN){
                cout << "Record already exist";
                file.close();
                return;
            }
        }
        file.clear();
        file.seekp(0,ios::end);
        file.write(reinterpret_cast<char*>(&obj1),sizeof(obj1));
        if (!file.good()) {
            cerr << "Error occurred while writing to file" << endl;
        } else {
            cout << "Book added successfully" << endl;
        }
        file.close();
    }
    void issueBook(){
        Library obj;
        fstream file;
        int searchISBN,pos;
        bool found = false;
        cout << "ISBN: ";
        cin >> searchISBN;
        file.open("catalog.bin",ios::in|ios::out|ios::binary);
        if(file.is_open()==false){
            cerr << "File cannot be opened";
            return;
        }
        while(file.read(reinterpret_cast<char*>(&obj),sizeof(obj))){
            if(obj.ISBN==searchISBN){
                found = true;
                cout << "Book found" << endl;
                int count;
                cout << "Enter the number of book being issued: ";
                cin >> count;
                if(count > obj.numberOfCopies){
                    cout << "Only " << obj.numberOfCopies << " books are available";
                    file.close();
                    return;
                }
                else if(count < 0){
                    cout << "Invalid Input";
                    file.close();
                    return;
                }
                else{
                    obj.numberOfCopies -= count;
                    obj.issuedBook +=count;
                    pos=file.tellg();
                    file.seekp(pos-sizeof(obj),ios::beg);
                    file.write(reinterpret_cast<char*>(&obj),sizeof(obj));
                    if (!file.good()) {
                        cerr << "Error occurred while writing to file" << endl;
                    } else {
                        cout << "Book issued successfully" << endl;
                    }           
                    file.close();
                    break;
                }
            }
        }
        if(found == false){
            cout << "Book not found";
            file.close();
            return;
        }
        

    }
    void returnBook(){
        Library obj;
        int searchISBN,pos;
        bool found = false;
        cout << "ISBN: ";
        cin >> searchISBN;
        fstream file; 
        file.open("catalog.bin",ios::in|ios::out|ios::binary);
        if(file.is_open()==false){
            cerr << "File cannot be opened";
            return;
        }
        while(file.read(reinterpret_cast<char*>(&obj),sizeof(obj))){
            if(obj.ISBN==searchISBN){
                found = true;
                cout << "Book found" << endl;
                int count;
                cout << "Enter the number of book being returned: ";
                cin >> count;
                if(count < 0){
                    cout << "Invalid Input";
                    file.close();
                    return;
                }
                else{
                    obj.numberOfCopies += count;
                    obj.issuedBook -= count;
                    pos=file.tellg();
                    file.seekp(pos-sizeof(obj),ios::beg);
                    file.write(reinterpret_cast<char*>(&obj),sizeof(obj));
                    if (!file.good()) {
                        cerr << "Error occurred writing to file" << endl;
                    } else {
                        cout << "Book returned successfully" << endl;
                    }
                    file.close();
                }
            }
        }
        if(found == false){
            cout << "Book not found";
            file.close();
            return;
        }
        
    }
    void updateBookDetails(){
        Library obj,obj1;
        int searchISBN,pos;
        bool found = false;
        cout << "ISBN: ";
        cin >> searchISBN;
        fstream file; 
        file.open("catalog.bin",ios::in|ios::out|ios::binary);
        if(file.is_open()==false){
            cerr << "File cannot be opened";
            return;
        }
        while(file.read(reinterpret_cast<char*>(&obj),sizeof(obj))){
            if(obj.ISBN==searchISBN){
                found = true;
                pos = file.tellg();
                cout << "Book found" << endl;
                cout << "Update book datails" << endl;
                obj.getData();
                file.clear();
                file.seekg(0, ios::beg);       //searching record from start
                while(file.read(reinterpret_cast<char*>(&obj1),sizeof(obj1))){
                    if(obj1.ISBN==obj.ISBN && pos != file.tellg()){
                        cout << "New record already exist";
                        file.close();
                        return;
                    }
                }
                file.clear();
                file.seekp(pos-sizeof(obj),ios::beg);
                file.write(reinterpret_cast<char*>(&obj),sizeof(obj));
                if (!file.good()) {
                    cerr << "Error occurred while writing to file" << endl;
                } else {
                    cout << "Book details updated successfully" << endl;
                }
                file.close();
            }
        }
        if(found == false){
            cout << "Book not found";
            file.close();
            return;
        }
        
    }
    void deleteBook(){
        Library obj;
        int searchISBN,pos;
        bool found = false;
        cout << "ISBN: ";
        cin >> searchISBN;
        fstream file; 
        file.open("catalog.bin",ios::in|ios::out|ios::binary);
        if(file.is_open()==false){
            cerr << "File cannot be opened";
            return;
        }
        while(file.read(reinterpret_cast<char*>(&obj),sizeof(obj))){
            if(obj.ISBN==searchISBN){
                found = true;
                cout << "Book found" << endl;
                int c;
                cout << "Enter 1 to conform: ";
                cin >> c;
                if(c == 1){
                    if(obj.numberOfCopies == 0 && obj.issuedBook == 0){
                        obj.ISBN = 0;
                        strcpy(obj.bookTitle,"");
                        strcpy(obj.author,"");
                        pos=file.tellg();
                        file.seekp(pos-sizeof(obj),ios::beg);
                        file.write(reinterpret_cast<char*>(&obj),sizeof(obj));
                        if (!file.good()) {
                            cerr << "Error occurred while writing to file" << endl;
                        } else {
                             cout << "Book deleted successfully" << endl;
                        }
                        file.close();
                    }
                    else if(obj.numberOfCopies != 0 && obj.issuedBook != 0){
                        cout << obj.numberOfCopies << "copies of this book are still available" << endl;
                        cout << obj.issuedBook << "book have been issued" << endl;
                        cout << "Cancelling" << endl;
                        file.close();
                        return;
                    }
                    else if(obj.numberOfCopies != 0){
                        cout << obj.numberOfCopies << "copies of this book are still available" << endl;
                        cout << "Cancelling" << endl;
                        file.close();
                        return;
                    }
                    else if(obj.issuedBook != 0){
                        cout << obj.issuedBook << "book have been issued" << endl;
                        cout << "Cancelling" << endl;
                        file.close();
                        return;
                    }
                }
                else{
                    cout << "cancelling";
                    file.close();
                    return;
                }
            }
            
        }
        if(found == false){
            cout << "Book not found";
            file.close();
            return;
        }
        
    }
    void searchBook(){
        Library obj;
        int searchISBN;
        bool found = false;
        ifstream file;
        cout << "ISBN: ";
        cin >> searchISBN;
        file.open("catalog.bin",ios::in|ios::binary);
        if(file.is_open()==false){
            cerr << "file cannot be open";
            return;
        }
        while(file.read((char*)&obj,sizeof(obj))){
            if(obj.ISBN == searchISBN){
                found = true;
                obj.displayData();
                file.close();
                return;
            }
        }
        if(found == false){
            cout << "Book not found";
            return;
        }
    }
};
int main(){
    Library obj;
    int choice;
    cout << "\nLibrary Management System" << endl;
    cout << "1. Add New Book" << endl;
    cout << "2. Search Book" << endl;
    cout << "3. Issue Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Update Book Details" << endl;
    cout << "6. Delete Book" << endl;
    cout << "7. Exit" << endl;
    while(true){
        cout << "\nEnter your choice (8 to see choices again and 7 for exit) : ";
        cin >> choice;
        if(choice == 1){
            obj.addNewBook();
        }
        else if(choice == 2){
            obj.searchBook();
        }
         else if(choice == 3){
            obj.issueBook();
        }
        else if(choice == 4){
            obj.returnBook();
        }
         else if(choice == 5){
            obj.updateBookDetails();
        }
         else if(choice == 6){
            obj.deleteBook();
        }
        else if(choice == 7){
            cout << "Exiting";
            return 0;
        }
        else if(choice == 8){
            cout << "1. Add New Book" << endl;
            cout << "2. Search Book" << endl;
            cout << "3. Issue Book" << endl;
            cout << "4. Return Book" << endl;
            cout << "5. Update Book Details" << endl;
            cout << "6. Delete Book" << endl;
            cout << "7. Exit" << endl;
        }
        else{
            cout << "Invalid choice\nTry again" << endl;

        }
    }
}