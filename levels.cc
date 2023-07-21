//abstract base class that defines the command interface for selecting the next block
class Level{
    public:
        virtual Block* getNextBlock(); // returning next block

};

//read in blocks from from sequence files 
class level0: public Level{

    

};

//similar to level 2, except using 6 blocks instead of 7 and if it lands on block that 
//represents S or Z then we generate random number again to select from the two
class level1: public Level{


    
};


//all blocks selected equally (7 blocks, generate random number, mod by 7, gives us block )
class level2: public Level{

    
};


class level3: public Level{

    
};

class level4: public Level{
    
};