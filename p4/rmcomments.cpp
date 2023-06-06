/*
 * CSc103 Project 4: uncommenting C/C++
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 5-7 hours
 */

#include <cstdio>   // printf and friends
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>  // for setw

using namespace std;

enum State
{
  NORMAL,
  SLASH,
  STAR,
  LINE_COMMENT,
  BLOCK_COMMENT,
  DOUBLE_QUOTE,
  SINGLE_QUOTE
};

string remove_comments(string str) {
  string res;
  State state = NORMAL;
  for (int i = 0; i < str.length(); i++) {
    char c = str[i];
    switch (state) {
      case NORMAL:
        if (c == '/') {
          state = SLASH;
        } else if (c == '\"') {
          state = DOUBLE_QUOTE;
          res += c;
        } else if (c == '\'') {
          state = SINGLE_QUOTE;
          res += c;
        } else {
          res += c;
        }
        break;
      case SLASH:
        if (c == '/') {
          state = LINE_COMMENT;
        } else if (c == '*') {
          state = BLOCK_COMMENT;
        } else {
          res += '/';
          if (c == '\"') {
            state = DOUBLE_QUOTE;
            res += c;
          } else if (c == '\'') {
            state = SINGLE_QUOTE;
            res += c;
          } else {
            state = NORMAL;
            res += c;
          }
        }
        break;
      case STAR:
        if (c == '/') {
          state = NORMAL;
        } else if (c == '*') {
          // stay in the BLOCK_COMMENT state
        } else {
          state = BLOCK_COMMENT;
        }
        break;
      case LINE_COMMENT:
        if (c == '\n') {
          state = NORMAL;
          res += c;
        }
        break;
      case BLOCK_COMMENT:
        if (c == '*') {
          state = STAR;
        }
        break;
      case DOUBLE_QUOTE:
        if (c == '\"') {
          state = NORMAL;
        }
        res += c;
        break;
      case SINGLE_QUOTE:
        if (c == '\'') {
          state = NORMAL;
        }
        res += c;
        break;
    }
  }
  return res;
}


bool whitespace (char c)
{
  return c == ' ' || c == '\t';
}

void processLine (string s, unsigned &cctr, unsigned &wctr, unsigned &lctr)
{
  bool inword = false;

  for (size_t i = 0; i < s.size (); i++)
    {
      if (inword)
    {
      if (whitespace (s[i]))
        {
          inword = false;
        }
    }
      else
    {
      if (!whitespace (s[i]))
        {
          inword = true;
          wctr++;
        }
    }

      cctr++;
    }

  lctr++;
}

int processFile (string file)
{
  unsigned cctr = 0, wctr = 0, lctr = 0;

  ifstream input_file (file);
  if (input_file.is_open ())
    {
      string line;
      while (getline (input_file, line))
    {
      processLine (line, cctr, wctr, lctr);
    }
    }
  else
    {
      cerr << "Error opening file " << file << endl;
      return -1;
    }

  cout << setw (6) << lctr << setw (6) << wctr << setw (6) << cctr
       << " " << file << endl;

  return 0;
}

int main (int argc, char *argv[])
{
  for (int i = 1; i < argc; i++)
    {
      ifstream input_file (argv[i]);
      if (input_file.is_open ())
    {
      string file_contents ((istreambuf_iterator < char >(input_file)),
                istreambuf_iterator < char >());
      string no_comments = remove_comments (file_contents);
      cout << "Output: " << no_comments << endl;
      processFile (argv[i]);
    }
      else
    {
      cerr << "Error opening file " << argv[i] << endl;
    }
    }

  return 0;
}
