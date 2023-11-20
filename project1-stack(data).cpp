// project1-stack(data).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

using namespace std;



class DLLNode {

public:

    int info; // the num of the data in the node

    DLLNode* next, * prev;  // the two pointer on the node which points to the next and previous nodes



    DLLNode() {

        next = prev = 0; // used to create a subtute pointer node

    }

    DLLNode(int i, DLLNode* n = 0, DLLNode* p = 0) {  //creates a new node and input the information while pointing to the next and prev of that node creating a ddl

        info = i; next = n; prev = p;

    }

};

class StackByDLL {

private:

    DLLNode* head, * tail; //head is the top of the stack and tail is the bottom

    int size; // the total size of inputs in the stack



public:

    bool isEmpty() { //if the stack is empty return either true or false

        if (size == 0) {

            return true;

        }

        else {

            return false;

        }

    }

    void push(char val) { //pushes a new element into the stack

        size += 1; //size increased with the new element added

        if (isEmpty()) { //if empty new element is the head and tail and points to null both ways

            DLLNode* pNew = new DLLNode(val, 0, 0);

            head = tail = pNew;

        }

        else { //if the stack is not empty then the element points to the node ahead of it which is old head, after that head is moved into its new spot

            DLLNode* pNew = new DLLNode(val, head, 0);

            head = pNew;

        }



    }

    void pop() {

        if (isEmpty()) { //if empty then nothing is removed



        }

        else { //if not empty then size is decreased since the remove of a node and the old head value is change to null and head now become the next value in the stack

            size -= 1;

            head->info = NULL;

            head = head->next;

        }





    }

    char top() {// checks the top of stack

        if (!isEmpty()) {

            return head->info; //return the info given

        }

        else {

            return 'e'; //make the value state empty due to stack

        }

    }

    void clear() {//deletes ever node in the stack

        if (isEmpty()) { //if empty do nothing

        }
        else {

            while (size != 0) { //delete everything until the size of stack is 0

                head->info = NULL;

                head = head->next;

                size--;

            }

        }



    }

    void display() {

        DLLNode* temp = new DLLNode(); //make a temp pointer poointing to head
        temp = head;
        char reverse[25] = { }; //used to store the info info in the stack
        if (!(isEmpty())) {


            for (int y = 0; y < size; y++) { //get ever value within the stack and stores it to reverse array
                reverse[y] = char(temp->info);
                temp = temp->next;
            }
            for (int x = size; x > -1; x--) {//prints the array backward so that Tail is display until it gets to head
                cout << reverse[x] << " ";
            }


        }

        else {
            cout << "empty";//prints empty is stack is empty
        }
    }

};





int main() {

    StackByDLL* s = new StackByDLL(); //new stack

    bool balancedFlag;

    char expr[25];

    cout << "Enter an expression (* to terminate): ";

    cin >> expr;// user enters expr up to 25 char



    int brakePad = 0; //used to stop from the loop if a closing is misused (shortcircuit)




    while (expr[0] != '*') { //continues if the input is not * which is used to exit system


        balancedFlag = true;//resets the result to being balanced
        int exprS = 0;

        for (int i = 0; i < 25; i++) {//used to know the limit of input given

            if (expr[i] == 0) {

                break;

            }

            exprS++;

        }

        for (int i = 0; i < exprS; i++) { //for the amount given run



            if (s->isEmpty()) { //if stack is empty



                if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') { //push the value if the stack is an opening type

                    s->push(expr[i]);

                }

                else { //if not opening type statement is false

                    balancedFlag = false;

                }



            }

            else {

                if (expr[i] == '(' || expr[i] == ')' || expr[i] == '{' || expr[i] == '}' || expr[i] == '[' || expr[i] == ']') { //if system has closing and opening

                    switch (s->top()) {//check the last inputed value

                    case '(': //if the value is (

                        if (expr[i] == ')') { //check if the new expr is ) if so pop the top value

                            s->pop();

                        }
                        else if (expr[i] == '}' || expr[i] == ']') {//if wrong closing break out of loop and make balance false
                            brakePad = 1;
                            balancedFlag = false;

                        }
                        else { //anything else should be pushing meaing openers

                            s->push(expr[i]);

                        }
                        break;



                    case '{'://if the value is {

                        if (expr[i] == '}') {//check if the new expr is } if so pop the top value


                            s->pop();

                        }
                        else if (expr[i] == ')' || expr[i] == ']') {//if wrong closing break out of loop and make balance false
                            brakePad = 1;
                            balancedFlag = false;

                        }
                        else {//anything else should be pushing meaing openers

                            s->push(expr[i]);

                        }
                        break;



                    case '['://if the value is {

                        if (expr[i] == ']') {//check if the new expr is ] if so pop the top value


                            s->pop();

                        }
                        else if (expr[i] == ')' || expr[i] == '}') { //if wrong closing break out of loop and make balance false
                            brakePad = 1;
                            balancedFlag = false;

                        }
                        else {//anything else should be pushing meaing openers

                            s->push(expr[i]);

                        }
                        break;



                    default://anything else should be pushing meaing openers
                        s->push(expr[i]);
                        break;

                    }

                }
                if (brakePad == 1) {//used to break out of loop
                    break;
                }
            }
        }






        if (balancedFlag && s->isEmpty()) //used to give feedback to user if system is balanced or not

            cout << "Expression is balanced! \n";

        else

            cout << "Expression is not Balanced! \n";





        cout << "stack is ";
        s->display();//displays the stack even if it is empty
        cout << endl;
        s->clear(); //clears the stack completely

        cout << "Enter an expression(* to terminate): "; //asks for a new input to check if balanced or not
        cin >> expr;

    }

    cout << "End. \n";

    return 0;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
