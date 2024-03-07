#!/bin/bash

# Define the base directory where your Assignment folders are located
base_dir="C:/Users/danie/OneDrive/Documents/UT Arlington/Semesters/Spring 2024/Intermediate Programming"

# Define the directory where compressed files are stored
compressed_dir="$base_dir/Compressed"

# Log file path
log_file="$base_dir/compression_log.txt"

# Function to log messages
log_message() {
    echo "$(date +"%Y-%m-%d %T") - $1" >> "$log_file"
}

# Check if base directory exists
if [ ! -d "$base_dir" ]; then
    echo "Base directory does not exist: $base_dir"
    exit 1
fi

# Check if compressed directory exists, if not, create it
if [ ! -d "$compressed_dir" ]; then
    mkdir -p "$compressed_dir"
    if [ $? -ne 0 ]; then
        echo "Failed to create compressed directory: $compressed_dir"
        exit 1
    fi
fi

# Loop through each Assignment folder
find "$base_dir" -maxdepth 1 -type d -name "Assignment*" | while read -r assignment_dir; do
    # Extract the assignment number from the directory name
    assignment_number=$(basename "$assignment_dir" | sed 's/[^0-9]*//g')

    log_message "Processing $assignment_dir"

    # Check if the corresponding zip file exists
    zip_file="$compressed_dir/Medrano_Gomez_1001961644_A${assignment_number}.zip"
    if [ ! -f "$zip_file" ]; then
        # If zip file doesn't exist, compress the folder with heavy compression
        log_message "Compressing $assignment_dir..."
        7z a -tzip -mx=9 "$zip_file" "$assignment_dir" >> "$log_file" 2>&1
        if [ $? -ne 0 ]; then
            log_message "Failed to compress $assignment_dir"
        else
            log_message "Successfully compressed $assignment_dir"
        fi
    else
        log_message "Zip file already exists for $assignment_dir"
    fi
done
