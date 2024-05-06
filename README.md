## Instagram Reel Downloader in C++ (README.md)

This project provides a C++ program to download Instagram Reels using the `yt-dlp` command-line tool on Ubuntu.

**Features:**

* User-friendly interface for entering URLs and filenames.
* URL validation (checks for basic format).
* Filename validation (prevents invalid characters).
* Option to quit the program.
* Informative error messages.

**Requirements:**

* C++ compiler (e.g., g++)
* `yt-dlp` tool installed on Ubuntu (follow instructions from [https://github.com/yt-dlp/yt-dlp](https://github.com/yt-dlp/yt-dlp))

**Instructions:**

1. Clone or download this repository.
2. Ensure you have `yt-dlp` installed on your Ubuntu system.
3. Compile the code using a C++ compiler (e.g., `g++ downloader.cpp -o downloader`).
4. Run the compiled executable (e.g., `./downloader`).

**Code Explanation:**

The code utilizes several components:

* **Headers:**
   - `<iostream>`: For input/output operations (cin, cout, cerr).
   - `<cstdlib>`: For system calls to execute `yt-dlp` (consider security implications).
   - `<fstream>`: For potential future file operations (not used in current version).
   - `<regex>`: For URL validation using regular expressions (optional).
   - `<limits>`: For input validation (checks for empty input).
* **Functions:**
   - `isValidUrl(const string& url)`: Validates the URL format (basic check for Instagram Reels).
   - `getValidUrl(const string& prompt)`: Prompts the user for a valid URL and handles quit signal ('q' or 'Q').
   - `getNonEmptyString(const string& prompt)`: Ensures the user enters a non-empty string for input.
   - `getValidFilename(const string& prompt)`: Prompts for a filename, performs basic validation (no special characters), and ensures non-empty input.
   - `downloadReel(const string& reel_url, const string& output_filename)`: Constructs the `yt-dlp` command with options and executes it using system calls.
* **Main Function:**
   - The `main` function drives the program flow.
   - It presents a user interface with menus for entering the URL and filename.
   - It validates user input using the defined functions.
   - It calls `downloadReel` to perform the download using `yt-dlp`.
   - It provides informative messages based on the download results.

**Security Considerations:**

* Using `system` calls can be a security risk. Consider alternative approaches for better security practices, especially in production environments.

**Disclaimer:**

This code is provided for educational purposes only. Downloading content may be subject to copyright restrictions. Please ensure you have the necessary rights before using this program.
