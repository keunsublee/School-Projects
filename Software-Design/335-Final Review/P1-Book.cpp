 #include "Book.hpp"
 
    Book::Book()
    :                    
    title_{" "}, 
    author_{" "}, 
    ISBN_{0}, 
    icon_{nullptr},      
    price_{0.00}, 
    keywords_{}, 
    blurb_{" "}
    { }                 

    Book::~Book() {
        delete[] icon_;
        icon_ = nullptr;
    }                   

    Book::Book(const Book& rhs)             //copy ctor
    {
    title_ = rhs.title_;                    //copy members
    author_ = rhs.author_;
    ISBN_ = rhs.ISBN_;

    if (rhs.icon_ == nullptr)               //check rhs icon nullptr
        {   icon_ = nullptr;    }
    else 
        {   icon_ = new int[80];            //new dynamic memory allocation                  
            for (int i = 0; i < 80; ++i)    //copy rhs.icon_ to *this.icon_ w/ for loop         
            {  icon_[i] = rhs.icon_[i];     }}  

    price_ = rhs.price_;
    keywords_ = rhs.keywords_;
    blurb_ = rhs.blurb_;
    }


    Book& Book::operator=(const Book& rhs) //copy assignment operator
    { if (this != &rhs) 
    {   title_ = rhs.title_;                //copy members
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;

        delete[] icon_;                         //delete icon_ before any operations
        if (rhs.icon_){                         //if rhs icon !null
            {   icon_ = new int[80];            //new dynamic memory allocation
                for (int i = 0; i < 80; ++i)    //copy rhs.icon_ to *this.icon_ w/ for loop
                {   icon_[i] = rhs.icon_[i];   }
            }}
        else{
            {   icon_ = nullptr;}}              //rhs icon null, set *this.icon_ to nullptr
    }
    
    return *this;                               //return *this book object
}       

//Move ctor 
Book::Book(Book&& rhs)  // initializer list to move rhs members to *this book object members
    :   
        title_(std::move(rhs.title_)),      //move rhs members to *this members
        author_(std::move(rhs.author_)), 
        ISBN_(std::move(rhs.ISBN_)), 
        icon_ (std::move(rhs.icon_)),
        price_(std::move(rhs.price_)), 
        keywords_(std::move(rhs.keywords_)), 
        blurb_(std::move(rhs.blurb_))
        {   rhs.icon_ = nullptr;  }                      
                                                 //set rhs icon to nullptr after moving it to *this icon 
                                            //prevent memory leak        
               


    Book& Book::operator=(Book&& rhs)           //move assignment operator
    {    if (this != &rhs)                      //check if *this is not rhs
    {   title_ = std::move(rhs.title_);         //move members
        author_ = std::move(rhs.author_);
        ISBN_ = std::move(rhs.ISBN_);

        delete[] icon_;                         //delete icon_ before any operations
        if (rhs.icon_ != nullptr){              //if rhs icon !null
            {   icon_ = std::move(rhs.icon_);   //move rhs.icon_ to *this.icon_
                rhs.icon_ = nullptr;            //set rhs icon to nullptr after moving it to *this icon
            }}

        else{
            {   icon_ = nullptr;}}              //rhs icon null, set *this.icon_ to nullptr

        price_ = std::move(rhs.price_);
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);   
    }

    return *this;                               //return *this book object
}

    const std::string& Book::getTitle() const
    {   return title_;    }

    void Book::setTitle(const std::string& title)
    {   title_ = title;    }

    const std::string& Book::getAuthor() const
    {   return author_;    }

    void Book::setAuthor(const std::string& author)
    {   author_ = author;    }

    long long int Book::getISBN() const
    {   return ISBN_;    }

    void Book::setISBN(long long int ISBN)
    {   ISBN_ = ISBN;    }

    const int* Book::getIcon() const
    {   return icon_;    }

    void Book::setIcon(int* icon)
    {   if (icon)                               //check if icon is not null
            { if (icon_)                        //check if icon_ is not null
                {   delete[] icon_;    }        //delete icon_ before any operations
                icon_ = new int[80];            //new dynamic memory allocation
              for (int i = 0; i < 80; ++i)      //copy icon to icon_ w/ for loop to set icon_
                {  
                    icon_[i] = icon[i];     
                }}
        else
            { if (icon_)             
                delete[] icon_;     
                icon_ = nullptr;
            }
    }


    float Book::getPrice() const
    {   return price_;    }

    void Book::setPrice(float price)
    {   price_ = price;    }

    const std::vector<std::string>& Book::getKeywords() const
    {   return keywords_;    }

    void Book::setKeywords(const std::vector<std::string>& keywords)
    {   keywords_ = keywords;   }       

    const std::string& Book::getBlurb() const
    {   return blurb_;    }

    void Book::setBlurb(const std::string& blurb)
    {   blurb_ = blurb;    }

    void Book::print() const
    {   std::cout << "Title: " << title_ << std::endl;
        std::cout << "Author: " << author_ << std::endl;
        std::cout << "ISBN: " << ISBN_ << std::endl;
            
        std::cout << "Icon: ";
            if (icon_) 
                {   for (int i=0; i<80; i++)
                {     std::cout << icon_[i] << " ";   }
                }
            else //icon null
                {   std::cout << "";  }
            std::cout << std::endl;
        
        std::cout << "Price: $" << std::fixed << std::setprecision(2) << price_ +0.00<< std::endl; 
        // format for decimals
            
        std::cout << "Keywords: ";        
            for (int i = 0; i < keywords_.size(); i++) 
                {   if (i != keywords_.size() - 1) 
                    {       std::cout<<keywords_[i]<<", ";  }
                    else 
                    {       std::cout<<keywords_[i];  }
                }   
        std::cout<<std::endl;
        std::cout << "Blurb: " << blurb_ <<std::endl;       
    }

 