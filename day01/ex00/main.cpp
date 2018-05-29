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
    Pony    *pony = new Pony("Found", "Heap", "Ryan Moore", 3);
    draw();
    delete pony;
}

void    ponyOnTheStack(void) {
    Pony    pony("Nashwan", "Stack", "Willie Carson", 5);
    draw();
}

int     main(void) {

    std::cout << "Calling ponyOnTheHeap()" << std::endl;
	ponyOnTheHeap();
	std::cout << "Returned from ponyOnTheHeap()" << std::endl;
    std::cout << "Calling ponyOnTheStack()" << std::endl;
	ponyOnTheStack();
    std::cout << "Returned from ponyOnTheStack()" << std::endl;
    return 0;
}