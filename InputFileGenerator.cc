// Copyright 2025 Jerard A

#include <iostream>
#include <random> // For Random numbers
#include <string> // For ASCII
#include <fstream> // Handles files
#include <sstream> // Reads/writes string for memory


using namespace std;


int main(){

    const int sizes[] = {10, 100, 1000};
    const int Num_files_per_size = 25;
    const float MinR = -100.0f;
    const float MaxR = 100.0f;

    // Initializes the random number generation process
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<float> distrib(MinR, MaxR);

    cout << "Generating input files now!...." << endl;

    // Loop for the array sizes
    for (int n : sizes){
        
        // Loop to create 25 files for the current size
        for (int i =1; i <= Num_files_per_size; ++i) {

            // Generates the file name
            ostringstream filename_ss;
            filename_ss << "input_" << n << "_" << setfill('0') << setw(2) << i << ".txt" ;

            string filename = filename_ss.str();

            ofstream outfile(filename);

            if (!outfile.is_open()) {

                cerr << "Error: Couldn't open the file " << filename << endl;
                continue;

            }

            // Writes n random numbers to the file
            for (int j = 0; j < n ; ++j) {
                float num = distrib(gen);

                outfile << num;

                if (j < n - 1) {
                    outfile << " "
                }
            }

            outfile.close()
        }

        cout << "Successfully generated 25 files for the size of " << n << "!" << endl;
    }

    cout << "All 75 input files have been created! " << endl;
    return 0;
}
