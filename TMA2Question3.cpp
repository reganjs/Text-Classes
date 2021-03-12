//Regan Setter
//Student ID 3505894
//Computer Science 206
//February 15th, 2021

//Write a program in which you create a Text class that contains a string object to hold the text of a file. Give it two constructors: a default constructor and a constructor that takes a string argument that is the name of the file to open. When the second constructor is used, open the file and read the contents of the file into the string member object. Add a member function contents() to return the string so that you can display it. In main(), open a file using Text and display the contents.

//Test: Created a file that contains sentences in it. Runs the program, created an object without any parameter. Object creation called default constructor and then created a second object that called parameterized constructor. Then displays the content of both objects by calling contents functions of the objects.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class text
{
  string text_content; //a string variable that holds all of the text contents available in the file

public:
  text() //default constructor
  {
    text_content = "";
  };

  text (string file) //parameterized constructor
  {
    string line; //a string variable to hold the line taken from the file
    ifstream myfile (file.c_str()); //opens a file
    if (myfile.is_open()) //if file opened successfully
    {
      while (getline (myfile, line)) //looping until it reads the line 
      {
        text_content += line + '\n'; //adding line into text content string variable with an end line
      }
      myfile.close(); //closes the file
    }
  };

  string contents() //function that returns the string in text content variable
  {
    return text_content; //return text_content string
  }
};

int main()
{
  text text1; //created an object of text that calls default constructor
  text text2 ("file1.txt"); //created an object of text that calls parameterized constructor as we passed the file name
  cout << "text1: " << text1.contents () << endl; //displaying text content of first object.
  cout << "text2: " << text2.contents () << endl;//displaying text content of second object.
}
