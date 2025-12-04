# Created by Jerard Austin 2025

import matplotlib.pyplot as plt
import csv
import re

# Configuring my files 
analysis_file = "Austin_Jerard_averageExecutionTime.txt"
# For time in microseconds
time = "Microseconds (\u03BCs)" 

def data_from_analysis_file(filepath):
    
    # Reads the input size and average time from the analysis file.
    
    
    sizes = []
    average_times = []
    
    
    # Looks for the size (first num) and the average time (last num).
    
    
    
    try:
        with open(filepath, 'r') as f:
            content = f.read()
            
        # Attempts to parse the text output based on the structure
        
        # Looks for a pattern
        pattern = re.compile(r'calculated average for\s+(\d+)\s+based on \d+ runs\. Average Time:\s+([\d.]+)', re.IGNORECASE)
        
        matches = pattern.findall(content)

        if matches:
            print("--- Data Parsed Successfully ---")
            for size_str, time_str in matches:
                try:
                    sizes.append(int(size_str))
                    average_times.append(float(time_str))
                    print(f"Found: Size={size_str}, Avg Time={time_str}")
                except ValueError:
                    print(f"Skipping malformed data line: Size={size_str}, Time={time_str}")
            return sizes, average_times
        
        else:
            print(f"Warning: Could not find structured data in {filepath}. Attempting simple read...")
            
            # Tries reading the file in two columns (Size Time)
            with open(filepath, 'r') as f:
                 for line in f:
                    parts = line.split()
                    if len(parts) >= 2:
                        try:
                            sizes.append(int(parts[0]))
                            average_times.append(float(parts[1]))
                        except ValueError:
                            continue # Skips any non-numeric numbers

    except FileNotFoundError:
        print(f"Error: The analysis file '{filepath}' was not found. Did you run 'make average'?")
        return [], []
    except Exception as e:
        print(f"An error occurred while reading the file: {e}")
        return [], []
        
    return sizes, average_times

def plot_performance(sizes, average_times):
    """Generates and displays the performance plot."""
    if not sizes:
        print("No data available to plot.")
        return

    # Creates the display plot
    plt.figure(figsize=(10, 6))
    
    # Plots the points of data
    plt.plot(sizes, average_times, marker='o', linestyle='-', color='green', label= "QuickSort Average Time")
    
    # Add labels and title
    plt.title('QuickSort Performance', fontsize=16)
    plt.xlabel('Input Size (N)', fontsize=12)
    plt.ylabel(f'Average Execution Time (time)', fontsize=16)
    
    # Add grid for better readability
    plt.grid(True, linestyle='--', alpha=0.6)
    
    # Add labels to the data points
    for i in range(len(sizes)):
        plt.annotate(f'{average_times[i]:.2f}', (sizes[i], average_times[i]), 
                     textcoords="offset points", xytext=(0,10), ha='center')
        
    # Sets the x-axis as log since the sizes are 10, 100 and 1000
    plt.xscale('log')
    
   #Ensures that all sizes are visible on x-axis
    plt.xticks(sizes, labels=[str(s) for s in sizes])
    
    plt.legend()
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    
    sizes, times = data_from_analysis_file(analysis_file)
    
    if sizes:
        plot_performance(sizes, times)
    else:
        print("Plotting aborted due to missing or unreadable data.")
