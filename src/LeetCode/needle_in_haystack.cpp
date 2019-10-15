#include <iostream>
#include <string>


int strStr(std::string haystack, std::string needle) {
     
        if (needle == std::std::string("")) return 0;
        if (needle.size() == 1 && haystack.size() == 1){
            return (needle[0] == haystack[0]) ? 0 : -1;
        }
        for (int i = 0; i < haystack.size(); i++){

            if (i + needle.size() - 1 < haystack.size() && 
                haystack[i + needle.size() - 1] == needle[needle.size() - 1] &&
                haystack[i] == needle[0]){
                
            int count = (needle.size() == 1) ? 1 : 2;
            for (int j = 1; j < needle.size() - 1; j++){
                if (haystack[i + j] == needle[j]){
                    count++;    
                }
                else {
                 break;   
                }
            }
               if (count == needle.size())
                return i;
            }

        }
        return -1;
    }

int main(int argc, char *argv[])
{
  std::cout << strStr("aaa","a") << std::endl;
  return 0;
}
