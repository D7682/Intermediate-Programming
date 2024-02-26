#!/bin/bash

# Define the base directory where your Assignment folders are located
base_dir="/path/to/your/folder_structure"

# Define the directory where compressed files are stored
compressed_dir="$base_dir/Compressed"

# Loop through each Assignment folder
for ((i=0; ; i++)); do
    assignment_dir="$base_dir/Assignment$i"
    
    # Check if the Assignment folder exists
    if [ -d "$assignment_dir" ]; then
        # Check if the corresponding zip file exists
        zip_file="$compressed_dir/Medrano_Gomez_1001961644_A$i.zip"
        if [ ! -f "$zip_file" ]; then
            # If zip file doesn't exist, compress the folder
            echo "Compressing $assignment_dir..."
            7z a "$zip_file" "$assignment_dir"
        else
            echo "Zip file already exists for $assignment_dir"
        fi
    else
        # Break the loop if the Assignment folder doesn't exist
        break
    fi
done
