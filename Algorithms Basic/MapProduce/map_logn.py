import tkinter as tk
from tkinter import filedialog
import matplotlib.pyplot as plt
import numpy as np
import os
from collections import defaultdict

def read_data(filename):
    # Read the txt file
    with open(filename, 'r') as file:
        data = file.readlines()

    # Extract x and y values
    xy_dict = defaultdict(list)
    for line in data:
        values = line.split()
        x_val = float(values[0])
        y_val = float(values[1])
        xy_dict[x_val].append(y_val)

    # Calculate average y values for each x
    x_values = []
    y_values = []
    for x_val, y_list in xy_dict.items():
        x_values.append(x_val)
        y_values.append(np.mean(y_list))

    # Sort by x values
    sorted_data = sorted(zip(x_values, y_values))
    x_values = [item[0] for item in sorted_data]
    y_values = [item[1] for item in sorted_data]

    return x_values, y_values

# Create tkinter window
root = tk.Tk()
root.withdraw()  # Hide the main window

# Open file dialog and get the filename
filename = filedialog.askopenfilename(title="Select data file", filetypes=(("Text files", "*.txt"), ("All files", "*.*")))

if filename:
    # Read the data
    title = os.path.basename(filename)
    x, y = read_data(filename)

    # Perform polynomial fit (degree 3 for O(n^3))
    coeffs = np.polyfit(x, y, 2)

    # Generate polynomial function using the coefficients
    poly_func = np.poly1d(coeffs)

    # Plot the data
    plt.plot(x, y, marker='o', linestyle='-', label="Actual Data")

    # Plot the fitted curve
    xfit = np.linspace(min(x), max(x), 100)
    plt.plot(xfit, poly_func(xfit), linestyle='--', label='Fitted Curve (O(n^2.7))')

    plt.xlabel('N')
    plt.ylabel('Time Cost')
    plt.title(title)
    plt.legend()
    plt.show()
else:
    print("No file selected.")
