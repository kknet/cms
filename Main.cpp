//Library includes
#include <vector>


//Header file includes
#include "io/ioI.hpp"
#include "io/cli.hpp"
#include "io/FileReader.hpp"

#include "commands/Command.hpp"
#include "commands/Post.hpp"
#include "commands/List.hpp"

#include "market/Market.hpp"

//Namespaces
using namespace cms;
using namespace std;

//Function stubs
void displayCmsMenu();
string identifyCommandType(string &cIn);


int main(int argc, char** argv){

  //Initialize the communication layer of choice
  //ioI * commLayer = new cli(); 
  //for testing
  ioI * commLayer = new FileReader("test/testPost.txt");


  commLayer->sendMessage("Welcome to the Commodity Market System! (CMS)\n");
  commLayer->sendMessage("Ctrl + c, or simply \"e\" to exit.\n");
  commLayer->sendMessage("Please begin issuing commands.\n");
  string line = "", type = "";

  //And the market
  Market * m = new Market();


  //Loop to receive commands in
  while((line = commLayer->getMessage()) != "e"){

    Command * command;
    //Post * post;

    //Identify the command type and create an instance of it
    type = identifyCommandType(line);
    try{
      if(type == "POST"){
        command = new Post(line);
        command->validate();
        m->addOrder(dynamic_cast<Post *>(command));
      }else if(type == "LIST"){
        command = new List(line);


      }else if(type == "other commands here"){

      }else{
        commLayer->sendMessage("\t\nINVALID MESSAGE\n\n");

      }
    }catch(const ParseException& pe){

      commLayer->sendMessage(pe.what());
    }

    
  }
  //cleanup
  delete commLayer;
  delete m;
}

void displayCmsMenu(){

}

string identifyCommandType(string & cIn){
  //Grab the second string in the arg
  stringstream ss(cIn);
  string temp;
  ss >> temp;
  ss >> temp;
  return temp;
}

