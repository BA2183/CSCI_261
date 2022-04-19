#include "obj_functions.h"

/**
 * @brief print options and asked for input, also check for valid input
 * 
 * @param minValue the minimum value allowed
 * @param maxValue the maximum value allowed
 * @return int for the user choice within range of min and max value
 */
int operation_input(int minValue, int maxValue) {
    int userInput;
    do {
        // get input
        cout << "what do you wish to do?\n(1) Print comments\n(2) Print vertices\n(3) Print faces\n(4) Quit\nChoice: ";
        cin >> userInput;

        // check for valid input
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr << "Invalid input." << endl;
        } else if ((userInput < minValue) || (userInput > maxValue)) {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr << "Invalid input." << endl;
        }
    } while ((userInput < minValue) || (userInput > maxValue));
    
    // return input value
    return userInput;
}

/**
 * @brief Open the input file stream for the corresponding filename. Check that the file opened correctly. 
 * 
 * @param fileIn the ifstream object keeping the the input file
 * @param fileName the input file name
 * @return true file opened successfully
 * @return false file failed to open
 */
bool open_file(ifstream& fileIn, const string fileName) {
    // open file
    fileIn.open(fileName);
    cout << "Opening file \"" << fileName << "\"\n";

    // check if file open
    if (fileIn.fail()) {
        fileIn.close();
        return false;
    } else {
        return true;
    }
}

/**
 * @brief read everything in the obj file, and classify item into specific linked lists
 * 
 * @param fileIn the ifstream object of the input file
 * @param commentList linked list of string of comment
 * @param vertexList linked list of vertex
 * @param faceList linked list of face
 */
void read_file(ifstream& fileIn, LinkedList<string>& commentList, LinkedList<Vertex>& vertexList, LinkedList<Face>& faceList) {
    // thing to chack and add to linked lists
    char headerChar;
    string sentence = "";
    Vertex coordPoint;
    Face vertexNum;

    // read file
    do
    {
        // check the header character to get according items
        fileIn >> headerChar;
        switch (headerChar) {
            // case of vertex points to put them into vertex list
            case 'v':
                fileIn >> coordPoint.x;
                fileIn >> coordPoint.y;
                fileIn >> coordPoint.z;
                // incase of at white spaces, the program will not mistakenly at in an extra duplicate
                if (!fileIn.fail()) {
                    vertexList.pushBack(coordPoint);
                }
                break;

            // case of face vertices to put them into face list
            case 'f':
                fileIn >> vertexNum.p;
                fileIn >> vertexNum.q;
                fileIn >> vertexNum.r;
                // incase of at white spaces, the program will not mistakenly at in an extra duplicate
                if (!fileIn.fail()) {
                    faceList.pushBack(vertexNum);
                }
                break;

            // case of comment to put sentence into list
            case '#':
                getline(fileIn, sentence);
                // incase of at white spaces, the program will not mistakenly at in an extra duplicate
                if (!fileIn.fail()) {
                    commentList.pushBack(sentence);
                }
                break;

        }
    } while (!fileIn.eof());
}

/**
 * @brief check for invalid faces, and at the same print out error
 * 
 * @param vertexList linked list of vertex
 * @param faceList linked list of face
 * @return true if all faces are valid
 * @return false if other wise
 */
bool valid_face(const LinkedList<Vertex>& vertexList, const LinkedList<Face>& faceList) {
    bool caseCheck = false;
    int errorCount = 0;
    cout << "Validating faces. . . \n";

    // get individual face in the list for comparison
    Face temptFace;
    for (int i = 0; i < faceList.size(); i++) {
        // i think this is how it suppose to work
        temptFace = faceList.at(i);

        // check for duplicate vertices
        if (temptFace.p == temptFace.q || temptFace.q == temptFace.r || temptFace.p == temptFace.r) {
            cerr << "Face " << i + 1 << " has duplicate indices\n";
            errorCount++;

        // check for out of bound
        } else if (temptFace.p < 1 || temptFace.p > vertexList.size()) {
            cerr << "Face " << i + 1 << " contains vertices out of range\n";
            errorCount++;
        } else if (temptFace.q < 1 || temptFace.p > vertexList.size()) {
            cerr << "Face " << i + 1 << " contains vertices out of range\n";
            errorCount++;
        } else if (temptFace.r < 1 || temptFace.r > vertexList.size()) {
            cerr << "Face " << i + 1 << " contains vertices out of range\n";
            errorCount++;
        }
    }
    
    // if all case clear
    if (errorCount == 0) {
        caseCheck = true;
    }

    // return value for error or not
    return caseCheck;
}

/**
 * @brief from user input, print out according thing, if not i dont know
 * 
 * @param userChoice the interger stand for choice from previous part
 * @param commentList list of strings of comment
 * @param vertexList list of vertex points
 * @param faceList list of face contain number of vertex
 * @return 1 for continue asking for user input
 * @return 0 for stopping
 */
int print_output(const int userChoice, const LinkedList<string>& commentList, const LinkedList<Vertex>& vertexList, const LinkedList<Face>& faceList) {
    // controlling the loop that might be looping this
    int loopCtrl = 1;

    // variable for loops in cases
    int a, b, c;

    // print out stuff according to user choice
    switch(userChoice) {
        // comments
        case 1:
            for (a = 0; a < commentList.size(); a++) {
                cout << "Comment #" << a + 1 << ": " << commentList.at(a) << "\n";
            }
            break;
        
        // vertices
        case 2:
            for (b = 0; b < vertexList.size(); b++) {
                cout << "Vertex #" << b + 1 << ": " << (vertexList.at(b)).x << " " << (vertexList.at(b)).y << " " << (vertexList.at(b)).z << "\n";
            }
            break;
        
        // faces, what there is a grid of point, "-1" to get q as an index
        /**
         * (xq, yq, zq)
         * (xp, yp, zp)
         * (xr, yr, zr)
         */
        case 3:
            for (c = 0; c < faceList.size(); c++) {
                cout << "Face #" << c + 1 << ": " 
                << "(" << (vertexList.at((faceList.at(c)).p - 1)).x << ", " << (vertexList.at((faceList.at(c)).p - 1)).y << ", " << (vertexList.at((faceList.at(c)).p - 1)).z << ") "
                << "(" << (vertexList.at((faceList.at(c)).q - 1)).x << ", " << (vertexList.at((faceList.at(c)).q - 1)).y << ", " << (vertexList.at((faceList.at(c)).q - 1)).z << ") "
                << "(" << (vertexList.at((faceList.at(c)).r - 1)).x << ", " << (vertexList.at((faceList.at(c)).r - 1)).y << ", " << (vertexList.at((faceList.at(c)).r - 1)).z << ")\n";
            }
            break;

        // user decide to quit the program
        case 4:
            cout << "Goodbye!\n";
            loopCtrl = 0;
            break;
    }

    return loopCtrl;
}