/*  CSCI 261: A4 - Abstract Lists: Wavefront OBJ File Validator
 *
 * Author: Duan Nguyen
 * Reference: class slide, previous code, the code snipet from A3, Hong Amy's help in debugging
 * 
 * The program will ask for user input of obj file name.
 * Then it will try to open the file, and exist accordingly if the file failed to open
 * The program will then read the obj file to find comments, vertices, and faces.
 * Put all of it's content in to their according linked list of according datatype; string, Vertex, and Face. Afterward, it also print the count of each elements.
 * The program will then check if the faces of the obj is valid; not out of range, or no duplicate. If the file is invilad, the program will alert the errors, clean up, and exit.
 * Then the program will continue to promt the user for number input according to printing action; comments, vertices, faces, or quit.
 * Failed to input will result in error message, and promt the user for input again.
 * From the correct input, the program will print out each item accordingly, but for faces, it will print out coordinate.
 * If the user wish to exist the program, they can enter 4, and the program will clean up and exit.
 */
#include "obj_functions.h"

// code snipet at A3
int main(int argc, char* argv[]) {
    // get file name
    string fileName;
    ifstream fileIn;
    if(argc == 1) {
        cout << "Enter the name of the file to open: ";
        cin >> fileName;
    } else if(argc == 2) {
        fileName = argv[1];
    } else {
        cerr << "Usage: " << argv[0] << " [filename]" << endl;
        cerr << "  filename   - optional file to open upon start" << endl;
        return -2;
    }
    
    // opening file
    bool fileOpen = open_file(fileIn, fileName);
    if (!fileOpen) {
        cerr << "Could not open file, shutting down. . .\n";
        return -1;
    } else {
        cout << "File successfully opened!\n\n";
    }

    // read content
    LinkedList<string> (*commentList) = new LinkedList<string>;
    LinkedList<Vertex> (*vertexList) = new LinkedList<Vertex>;
    LinkedList<Face> (*faceList) = new LinkedList<Face>;
    read_file(fileIn, (*commentList), (*vertexList), (*faceList));
    cout << "Read in:\n" << (*commentList).size() << " comments\n" << (*vertexList).size() << " vertices\n" << (*faceList).size() << " faces\n\n";

    // validating faces
    bool allValid = valid_face((*vertexList), (*faceList));
    if (!allValid) {
        cerr << ". . .File is invalid.\n";

        // clean up and close the program
        delete commentList;
        delete vertexList;
        delete faceList;
        fileIn.close();
        return -1;
    } else {
        cout << ". . .File is valid.\n\n";
    }

    // ask for print option
    int loopCtrl = 0;
    int userInput;
    do
    {
        userInput = operation_input(1, 4);
        loopCtrl = print_output(userInput, (*commentList), (*vertexList), (*faceList));
    } while (loopCtrl != 0);

    // end of progame
    cout << "delete and close . . .";
    delete commentList;
    delete vertexList;
    delete faceList;
    fileIn.close();
    cout << "sucess!";
    return 0;
}