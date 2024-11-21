
#include <string>
#include <filesystem>
#include "fs_global.h"

namespace fs = std::filesystem;
static  ssq::VM* PVM;
sq_api*  SQ_PTRS;

void directory_iterator(const ssq::Function& f, const std::string& dir)
{
    std::string path = dir, sss;
    if(path.empty())
        path="./";
    for (const auto & entry : std::filesystem::directory_iterator(path))
    {
        const auto p = entry.path();
        sss = entry.path().string().c_str();
        if(sss.find_first_of("./")==0)
        {
            sss.erase(0,1);
        }
        if(!f.isNull())
        {
            PVM->callFunc(f, *PVM, sss);
        }
    }
}

std::string current_path()
{
    static std::string path = std::filesystem::current_path().c_str();
    return path;
}

size_t file_size(const char* file)
{
    std::filesystem::file_status s=std::filesystem::status(file);
    if(std::filesystem::is_regular_file(s))
    {
        return std::filesystem::file_size(file);
    }
    return -1;
}

class BaseClass
{
public:
    BaseClass()
    {
        std::cout << __FUNCTION__ << "\n";
    }

    virtual ~BaseClass()
    {
        std::cout << __FUNCTION__ << "\n";
    }

    void functionbase()
    {
        std::cout << __FUNCTION__ << "\n";
    }

    int add(int g, int k)
    {
        return g+k;
    }

    std::string return_a_string()
    {
        return std::string("from c++\n");
    }
};

class DerivedClass : public BaseClass
{
public:
    DerivedClass()
    {
        std::cout << __FUNCTION__ << "\n";
    }

    ~DerivedClass()
    {
        std::cout << __FUNCTION__ << "\n";
    }

    void functionderived()
    {
        std::cout << __FUNCTION__ << "\n";
    }
};


void functionb(BaseClass* pcb)
{
    std::cout << __FUNCTION__ << "\n";
    pcb->functionbase();
}


void functiond(DerivedClass* pcb)
{
    std::cout << __FUNCTION__ << "\n";
    pcb->functionderived();
}

DerivedClass* new_derived()
{
    return new DerivedClass();
}

void release_derived(DerivedClass* p)
{
    delete p;
}


/**
 * @brief _init_apis
 * @param pvm   VM
 * @param ptrs  ptrs to SQ api's
 * @return true
 */
bool _init_apis(ssq::VM* pvm, sq_api* ptrs)
{
    PVM = pvm;
    SQ_PTRS = ptrs;
    /**
     * how to exports things to script
     */

    // functions
    pvm->addFunc("directory_iterator",directory_iterator);
    pvm->addFunc("current_path",current_path);
    pvm->addFunc("file_size",file_size);
    pvm->addFunc("new_derived",new_derived);
    pvm->addFunc("release_derived",release_derived);


    // classes
    auto clsb = pvm->addClass("BaseClass",ssq::Class::Ctor<BaseClass()>());
    clsb.addFunc("functionbase", &BaseClass::functionbase);
    clsb.addFunc("add", &BaseClass::add);
    clsb.addFunc("return_a_string", &BaseClass::return_a_string);

    auto clsb2 = pvm->addClass("DerivedClass",ssq::Class::Ctor<DerivedClass()>());
    clsb2.addFunc("functionbase", &BaseClass::functionbase);
    clsb2.addFunc("functionderived", &DerivedClass::functionderived);
    clsb2.addFunc("add", &BaseClass::add);
    clsb2.addFunc("return_a_string", &BaseClass::return_a_string);

    // functions
    pvm->addFunc("functionb", functionb);
    pvm->addFunc("functiond",  functiond);

    return false;
}



void _deinit_apis(ssq::VM* pvm, sq_api* ptrs)
{
}


