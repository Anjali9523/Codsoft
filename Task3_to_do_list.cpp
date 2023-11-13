#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int ID;

struct todo {
    int id;
    string task;
    bool completed;
};

void addTodo() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    todo newTodo;
    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, newTodo.task);
    ID++;
    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << newTodo.task;
    write << "\n" << "false"; // Initialize the task as not completed
    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    char ch;
    cout << "Do you want to add more task? y/n" << endl;
    cin >> ch;
    if (ch == 'y') {
        addTodo();
    }
    else {
        cout << "\n\tTask has been added successfully";
        return;
    }
}

void print(const todo& task) {
    cout << "\n\tID is: " << task.id;
    cout << "\n\tTask is: " << task.task;
    cout << "\n\tCompleted: " << (task.completed ? "Yes" : "No");
}

void readData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    todo task;
    ifstream read;
    read.open("todo.txt");

    if (read.peek() == EOF) {
        cout << "No tasks found. Add some tasks to display." << endl;
        return;
    }

    cout << "\n\t------------------Your current Tasks in the list--------------------";
    while (!read.eof()) {
        read >> task.id;
        read.ignore();
        getline(read, task.task);
        string completed;
        read >> completed;
        task.completed = (completed == "true");
        print(task);
    }
    read.close();
}

int searchData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    int id;
    cout << "\n\tEnter task id: ";
    cin >> id;
    todo task;
    ifstream read;
    read.open("todo.txt");
    while (!read.eof()) {
        read >> task.id;
        read.ignore();
        getline(read, task.task);
        string completed;
        read >> completed;
        task.completed = (completed == "true");
        if (task.id == id) {
            print(task);
            return id;
        }
    }
}

void deleteData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    int id = searchData();
    cout << "\n\tDo you want to delete this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo task;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        while (!read.eof()) {
            read >> task.id;
            read.ignore();
            getline(read, task.task);
            string completed;
            read >> completed;
            task.completed = (completed == "true");
            if (task.id != id) {
                tempFile << "\n" << task.id;
                tempFile << "\n" << task.task;
                tempFile << "\n" << (task.completed ? "true" : "false");
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted successfully";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

void updateData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    int id = searchData();
    cout << "\n\tYou want to update this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo newData;
        cout << "\n\tEnter todo task : ";
        cin.get();
        getline(cin, newData.task);
        todo task;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        while (!read.eof()) {
            read >> task.id;
            read.ignore();
            getline(read, task.task);
            string completed;
            read >> completed;
            task.completed = (completed == "true");
            if (task.id != id) {
                tempFile << "\n" << task.id;
                tempFile << "\n" << task.task;
                tempFile << "\n" << (task.completed ? "true" : "false");
            }
            else {
                tempFile << "\n" << task.id;
                tempFile << "\n" << newData.task;
                tempFile << "\n" << (task.completed ? "true" : "false");
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask updated successfully";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

void markAsCompleted() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    int id = searchData();
    cout << "\n\tMark this task as completed (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo task;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        while (!read.eof()) {
            read >> task.id;
            read.ignore();
            getline(read, task.task);
            string completed;
            read >> completed;
            task.completed = (completed == "true");
            if (task.id != id) {
                tempFile << "\n" << task.id;
                tempFile << "\n" << task.task;
                tempFile << "\n" << (task.completed ? "true" : "false");
            }
            else {
                tempFile << "\n" << task.id;
                tempFile << "\n" << task.task;
                tempFile << "\n" << "true"; // Mark the task as completed
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask marked as completed successfully";
    }
    else {
        cout << "\n\tTask not marked as completed";
    }
}

int main() {
    system("cls");
    system("Color E0"); // "Color XY", X - background color, Y - text color
    system("todoapp");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t*                      WELCOME TO Your ToDo List                      *" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl << endl;
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout << endl << endl;
        cout << "\n\t1. Add task";
        cout << "\n\t2. See tasks";
        cout << "\n\t3. Search task";
        cout << "\n\t4. Delete task";
        cout << "\n\t5. Update task";
        cout << "\n\t6. Mark as completed";
        cout << "\n\t7. Exit";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addTodo();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        case 6:
            markAsCompleted();
            break;
        case 7:
            return 0;
        }
    }
}
