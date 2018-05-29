#include "Pony.hpp"

void    draw(void) {
std::cout << "                                                 #    #" << std::endl;
std::cout << "                                            %%% ##   ##" << std::endl;
std::cout << "                                         %%%%% ###%%###" << std::endl;
std::cout << "                                        %%%%% ### %%% #" << std::endl;
std::cout << "                                       %%%% ## %% #######" << std::endl;
std::cout << "                                      %%%%% # %% #O#####" << std::endl;
std::cout << "                                    %%%%%% # % #########" << std::endl;
std::cout << "                                    %% ####### #########" << std::endl;
std::cout << "                %%% ############    ########### ########" << std::endl;
std::cout << "             %%%% ###############################  ######" << std::endl;
std::cout << "           %%%%% ##################################  #C###" << std::endl;
std::cout << "         %%%%%% ####################################  ###" << std::endl;
std::cout << "        %%%%%% #####################################" << std::endl;
std::cout << "        %%%%% #######################################" << std::endl;
std::cout << "       %%%%%% ########################################" << std::endl;
std::cout << "    %%%%%%%%%% ########################################" << std::endl;
std::cout << "   %%%%%%%%      ###### #################### ##########" << std::endl;
std::cout << "  %%%%%%%%        ####### ########### ###### ##########" << std::endl;
std::cout << "   %%%%%%%          ##### ###  ######### ####### ######" << std::endl;
std::cout << "   %%%%%%%%          #### ##               ####### ####" << std::endl;
std::cout << "    %%%%%%%%           ## #                  ##### ###" << std::endl;
std::cout << "      %% % %%         # ##                      ## ###" << std::endl;
std::cout << "        %    %        # ###                      # ###" << std::endl;
std::cout << "                       # ###                     ## ###" << std::endl;
std::cout << "                       # ###                     ## ###" << std::endl;
std::cout << "                      ### ###                  ##### ###" << std::endl;
std::cout << "                     ####  ###                 ####   ##" << std::endl;
std::cout << "                    #####   ###                 ##    ##" << std::endl;
std::cout << "                   #####    ####                      ###" << std::endl;
std::cout << "                    ##        ###                     ###" << std::endl;
std::cout << "                               ####                     ##" << std::endl;
std::cout << "                                                         ##" << std::endl;
}

void    ponyOnTheHeap(void) {
    std::cout << "Calling ponyOnTheHeap()" << std::endl;
    Pony    *pony = new Pony("Found", "Heap", "Ryan Moore", 3);
    draw();
    delete pony;
	std::cout << "Returned from ponyOnTheHeap()" << std::endl;
}

void    ponyOnTheStack(void) {
    std::cout << "Calling ponyOnTheStack()" << std::endl;
    Pony    pony("Nashwan", "Stack", "Willie Carson", 5);
    draw();
    std::cout << "Returned from ponyOnTheStack()" << std::endl;    
}

int     main(void) {
    
	ponyOnTheHeap();
	ponyOnTheStack();
    return 0;
}