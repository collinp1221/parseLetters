#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

int main() {
    string inputPath = "Your Filepath Here";
    string outputPath = "Your Output Path Here";
    fstream inputFile;

    for(char letter = 'a'; letter <= 'z'; letter ++)
    {
        //Initialize relevant vars
        string words[50000];
        int arrayPos = 0;

        try
        {
            inputFile.open(inputPath);
            //Copy all words starting with target letter to array
            if(inputFile.is_open())
            {
                string line;
                while(getline(inputFile, line))
                {
                    //If line starts with the correct letter, add to array
                    if(line[0] == letter)
                    {
                        words[arrayPos] = line;
                        arrayPos ++;
                    }
                }
            inputFile.close();
            }

            //Open output file, and write array to it
            fstream outputFile;
            outputFile.open(outputPath + "\\" + letter + ".txt", ios::out);
            for(int i=0; i<arrayPos;i++)
            {
                outputFile<<words[i]<<endl;
            }
            outputFile.close();

        }
        catch(exception e){ }
    }
    return 0;
}