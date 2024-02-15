#!/bin/bash

# Loop through each folder in the current directory
for folder in */; do
    folder="${folder%/}" # Remove trailing slash
    if [ -d "$folder" ]; then # Check if it's a directory
        echo "Entering folder: $folder"
        # Navigate into the folder
        if ! cd "$folder"; then
            echo "Failed to enter folder: $folder"
            continue
        fi

        # Loop through each C file in the folder
        for file in *.c; do
            echo "Compiling: $file"
            # Compile the C file without specifying an output executable
            if ! gcc -Wall "$file"; then
                echo "Failed to compile: $file"
                continue
            fi
            
            # Get the filename without extension
            filename="${file%.c}"

            # Compile the C file and specify an output executable
            if ! gcc -Wall "$file" -o "$filename.exe"; then
                echo "Failed to compile: $file to $filename.exe"
                continue
            fi
        done

        # Move back to the parent directory
        if ! cd ..; then
            echo "Failed to move back to parent directory"
            exit 1
        fi
    fi
done
