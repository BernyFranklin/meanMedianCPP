/*
 * meanMedian.cpp Version#1.0
 * Frank Bernal
 * CIS 054 C/C++ Programming
 * Input: User input for file selection. File input stream for data
 * Output: Total records, mean, median
 * 05 May 2022
 */

#include <iostream>    // Used for I/O
#include <fstream>     // Used to open files
#include <cstdlib>     // Used for exit()
using namespace std;   // For cin cout

// Start int main
int main(int argc, char* argv[]) {
    // Variables to control the disk file
    ifstream infile;
    char filename[200];
    int recordCount = 0;
    int recordsToSkip = 0;

    // Variables for fields of each record in the file
    int acctNo = 0;
    char name[100] = "";
    double acctBal = 0.0;

    // Variables to determine Mean and Median
    double total = 0.0;
    double mean = 0.0;
    double median = 0.0;
    
    // Ask for file name
    cout << "Enter the name of the data file: ";
    cin.getline(filename, 200);

    // PART 1. Count the number of records in the file
    //         Determine the mean when you know the record count
    //         and the total of all balances

    // Open file
    infile.open(filename);

    // Check if file opened correctly
    if (infile.fail()) {
        // Alert User
        cerr << "Unable to open --" << filename << "--, first pass" << endl;
        // Abort mission
        exit(1);
    }   // End of fail

    // While not the end of file, iterate through data
    while (!infile.eof()) {
        name[0] = 0;                           // Test for empty record
        infile >> acctNo >> name >> acctBal;   // Store each data set
        if (name[0] != 0)                      // Ignore empty records
            total += acctBal;                  // Add acctBal to total for mean calc
            recordCount++;
    }   // End of while

    // Close file 
    infile.close();
    // Calculate mean
    mean = total/recordCount;
    // Display record count
    cout << "There are " << recordCount << " records in " << filename << endl;

    // PART 2. Determine number of records to skip and establish mean
    // Odd number of records
    if (recordCount %2 == 1)
        recordsToSkip = recordCount/2;
    // Even
    else
        recordsToSkip = recordCount/2 - 1;

    // Reopen file
    infile.open(filename);
    // Did it work
    if (infile.fail()) {
        // Alert User
        cerr << "Unable tp open --" << filename << "--, first pass" << endl;
        // Abort mission
        exit(1);
    }   // End of fail


    return 0;
}   // End of int main
 