#include <iostream>
#include <cstdlib>
#include <fstream>
#include <regex> // For URL validation
#include <limits> // For input validation

using namespace std;

// Function to validate URL format
bool isValidUrl(const string& url) {
  regex url_pattern(R"(https?://www\.instagram\.com/reel/)");
  return regex_match(url, url_pattern);
}

// Function to get a valid URL from user
string getValidUrl(const string& prompt) {
  string url;
  while (true) {
    cout << prompt;
    getline(cin, url);
    if (url.empty()) {
      cerr << "Error: URL cannot be empty." << endl;
    } else if (url == "q" || url == "Q") {
      return url; // Quit signal
    } else if (isValidUrl(url)) {
      return url;
    } else {
      cerr << "Invalid URL format. Please enter a valid Instagram Reel URL." << endl;
    }
  }
}

// Function to get a non-empty string from user
string getNonEmptyString(const string& prompt) {
  string input;
  while (input.empty()) {
    cout << prompt;
    getline(cin, input);
    if (input.empty()) {
      cerr << "Error: Input cannot be empty." << endl;
    }
  }
  return input;
}

// Function to get a valid filename from user
string getValidFilename(const string& prompt) {
  string filename = getNonEmptyString(prompt);
  // Basic filename validation (replace with more robust checks if needed)
  if (filename.find_any_of("\\/:*?\"<>|") != string::npos) {
    cerr << "Error: Filename cannot contain invalid characters." << endl;
    return getValidFilename(prompt);
  }
  return filename;
}

// Function to download reels using yt-dlp
int downloadReel(const string& reel_url, const string& output_filename) {
  string command = "yt-dlp -f bestvideo+bestaudio -o \"" + output_filename + "\" " + reel_url;
  return system(command.c_str());
}

int main() {
  bool download_again = true;

  while (download_again) {
    cout << "\n** Instagram Reel Downloader **\n" << endl;

    // Get reel URL from user with quit option
    string reel_url = getValidUrl("Enter the Instagram Reel URL (or 'q' to quit): ");
    if (reel_url == "q" || reel_url == "Q") {
      break;
    }

    // Get output filename from user with validation
    string output_filename = getValidFilename("Enter desired output filename (without extension): ");
    output_filename += ".mp4";

    // Download the reel
    int result = downloadReel(reel_url, output_filename);

    if (result == 0) {
      cout << "Reel downloaded successfully to: " << output_filename << endl;
    } else {
      cerr << "Error downloading Reel. Check URL or yt-dlp installation." << endl;
    }

    // Prompt user to download another reel with input validation
    cout << "\nDownload another reel (y/n)? ";
    char choice;
    while (!(cin >> choice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cerr << "Error: Invalid input. Please enter 'y' or 'n'." << endl;
      cout << "Download another reel (y/n)? ";
    }
    cin.ignore(); // Consume newline character

    download_again = (choice == 'y' || choice == 'Y');
  }

  cout << "Exiting..." << endl;
  return 0;
}
