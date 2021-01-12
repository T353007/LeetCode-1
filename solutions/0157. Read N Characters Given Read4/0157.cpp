/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char* buf, int n) {
    char* buf4 = new char[4];
    int i4 = 0;  // buf4's pointer
    int n4 = 0;  // buf4's size
    int i = 0;   // buf's pointer

    while (i < n) {
      if (i4 == n4) {      // all characters in buf4 are consumed
        i4 = 0;            // reset buf4's pointer
        n4 = read4(buf4);  // read 4 (or less) chars from file to buf4
        if (n4 == 0)       // reach the EOF
          return i;
      }
      buf[i++] = buf4[i4++];
    }

    return i;
  }
};