// Copyright 2025 Jerard Austin

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;


const string input_filename = "Austin_Jerard_executionTime.txt";

const string output_filename = "Austin_Jerard_averageExecutionTime.txt";

const vector<int> SIZES = {10, 100, 1000};

int main() {

    // Maps to store size: Total_Time, Count
    // Had to get help from YouTube
    map<int, pair<long long, int>> time_data;

    // Initializes map entries for each sizes
    for (int size : SIZES) {
        time_data[size] = {0, 0}; 
    }

    cout << "Starting average time calculation!" << endl;
    cout << "Reading data from " << input_filename << "..." << endl;

    // For Input
    ifstream infile(input_filename);
    if (!infile.is_open()) {
        cerr << "Error: Failed opening input file: " << input_filename
             << endl;
        return 1;
    }

    string line;
    // Read the files line by line
    while (getline(infile, line)) {
        stringstream ss(line);
        int size;
        long long time_in_micro;

        // The format is: size / time_in_microseconds
        if (ss >> size >> time_in_micro) {
            if (time_data.count(size)) {
                time_data[size].first += time_in_micro;
                time_data[size].second++;
            }
        }
    }
    infile.close();


	// For Output
    ofstream outfile(output_filename);
    if (!outfile.is_open()) {
        cerr << "Error: Failed opening output file: " << output_filename << endl;
        return 1;
    }


    outfile << left << setw(15) << "Input Size" << "Average Execution Time " << endl;
    outfile << "------------------------------------------" << endl;

    for (int size : SIZES) {
        if (time_data[size].second > 0) {
            long long total_time = time_data[size].first;
            int count = time_data[size].second;
            
            double average_time = (double)total_time / count;

            // Write the calculated average to the output
            outfile << left << setw(15) << size << fixed << setprecision(2) << average_time << endl;
            cout << "Successfully calculated average for  " << size << " based on " << count << " runs." << endl;
        } else {
             cerr << "Warning: No data found for input  " << size << ". Check raw data file." << endl;
        }
    }

    outfile.close();
    cout << "Success! Average execution times calculated and saved to: " << output_filename << endl;
    return 0;
}
