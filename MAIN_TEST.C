////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//clang 6.0.0

#include <iostream>
#include <map>

struct SMacro
{
public:
    typedef std::multimap<unsigned, std::pair<std::string, std::string>, std::greater<unsigned>> MyMapType;
    MyMapType defs;
    std::pair<std::string, std::string> getDefFrom(std::string line) const
    {
        std::string def, val;
        line.erase(line.find_first_not_of(" \t")-1); // ltrim
        line.erase(line.find_last_not_of(" \t")+1); // rtrim
        /* **********
        if(0!=line.compare("#DEFINE", 0, 7))
        {
            line.erase(line.begin(), line.begin()+8);
            line.erase(line.find_first_not_of(" \t")-1); // ltrim again
            auto de = line.find_first_of(" \t");
            auto lend = de.begin() - line.begin() - 1;
            line.copy(def, 0, lend); // def is set
            line.copy(val, line.begin() + lend + 1); // val is set
            val.erase(val.find_first_not_of(" \t"); // val is set ltrimmed
        }
        ************** */
        return make_pair(def, val);
    }
    void addDef(std::string name, std::string value)
    {
        unsigned leni = name.length();
        defs.insert(std::make_pair(leni, std::make_pair(name, value)));
    }
    std::string solveDef(std::string code, MyMapType defs) const
    {
        for(auto&& it: defs)
        {
            code.replace(code.find(it.second.first), (int)it.first, it.second.second);
        }
        return code;
    }
};


int main()
{
    std::cout << "Hello, world!\n";
    return 0;
}

