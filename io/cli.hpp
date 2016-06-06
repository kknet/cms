#ifndef cli_hpp
#define cli_hpp


#include "ioI.hpp"
#include <string>
#include <iostream>


namespace cms {

  class cli : public ioI {
  
    public:
      std::string getMessage(){
        std::string ret = "";
        std::cin >> ret;
        return ret;
      }

      void sendMessage(std::string s){
        std::cout << s;

      }


    private:

  };

}

#endif //cli_hpp



