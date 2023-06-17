/**
 * @file class_include.h
 * misc demo of cpp-fstring
 *
 * @ingroup examples
 *
 * @author Sandeep M
 * @copyright Copyright 2023 Sandeep M<deep@tensorfield.ag>
 * @license MIT License
*/

/**
 * from:
 * https://github.com/robotpy/robotpy-cppheaderparser/blob/main/test/TestSampleClass.h
 * Copyright (C) 2011, Jashua R. Cloutier
 * License: BSD
 */

#include <vector>
#include <string>
#include <map>

#include "fstr.h"

using std::string;
using std::vector;

class BaseSampleClass {
	enum Elephant
	{
		EL_ONE = 1,
		EL_TWO = 2,
		EL_NINE = 9,
		EL_TEN,
	};
  Elephant el_base = EL_TWO ;

  friend class SampleClass;
// Generated formatter for PRIVATE enum BaseSampleClass::Elephant of type UINT 
 friend constexpr auto format_as(const BaseSampleClass::Elephant obj) {
  fmt::string_view name = "<missing>";
  switch (obj) {
    case BaseSampleClass::EL_ONE : name = "EL_ONE" ; break;  // index=1
    case BaseSampleClass::EL_TWO : name = "EL_TWO" ; break;  // index=2
    case BaseSampleClass::EL_NINE: name = "EL_NINE"; break;  // index=9
    case BaseSampleClass::EL_TEN : name = "EL_TEN" ; break;  // index=10
  }
  return name;
}
// Generated to_string for PUBLIC CLASS_DECL BaseSampleClass
  public:
  auto to_string() const {
    return fstr::format(R"( BaseSampleClass:
    PRIVATE Eleph el_base: 1={} 2={} 3={} 
)", 1, 2, 3);
  }
};

class SampleClass: public BaseSampleClass
{
    string prop1;
    int prop2;
    bool prop3;     /*!< prop6 description */
    double prop4;   //!< prop7 description
                    //!< with two lines
    
    /// prop8 description
    int prop5;
    Elephant el_derived = EL_TEN;
// Generated to_string for PUBLIC CLASS_DECL SampleClass
  public:
  auto to_string() const {
    return fstr::format(R"( BaseSampleClass:
    PRIVATE Eleph el_base: 1={} 2={} 3={} EL_ONE={} EL_TWO={}
)", 1, 2, 3, EL_ONE, EL_TWO);
  }
};

namespace Alpha
{
    class AlphaClass
    {
    public:
    	AlphaClass();

    	void alphaMethod();

      string alphaString;
    protected:
    	typedef enum
    	{
    		Z_A,
    		Z_B = 0x2B,
    		Z_C = 'j',
			Z_D,
         Z_E = '9',
         Z_F = 9,
    	} Zebra;
    // Generated formatter for PROTECTED enum Alpha::AlphaClass::Zebra of type UINT 
 friend constexpr auto format_as(const Alpha::AlphaClass::Zebra obj) {
  fmt::string_view name = "<missing>";
  switch (obj) {
    case Alpha::AlphaClass::Z_A: name = "Z_A"; break;  // index=0
    case Alpha::AlphaClass::Z_B: name = "Z_B"; break;  // index=43
    case Alpha::AlphaClass::Z_C: name = "Z_C"; break;  // index=106
    case Alpha::AlphaClass::Z_D: name = "Z_D"; break;  // index=107
    case Alpha::AlphaClass::Z_E: name = "Z_E"; break;  // index=57
    case Alpha::AlphaClass::Z_F: name = "Z_F"; break;  // index=9
  }
  return name;
}
// Generated to_string for PUBLIC CLASS_DECL Alpha::AlphaClass
  public:
  auto to_string() const {
    return fstr::format(R"( Alpha::AlphaClass:
    PUBLIC int alphaString: {} 
)", alphaString);
  }
};

    namespace Omega
    {
		class OmegaClass
		{
		public:
			OmegaClass();

			string omegaString;
		protected:
			///
			/// @brief Rino Numbers, not that that means anything
			///
			typedef enum
			{
				RI_ZERO, /// item zero
				RI_ONE,  /** item one */
				RI_TWO,   //!< item two
				RI_THREE,
				/// item four
				RI_FOUR,
			} Rino;
		// Generated formatter for PROTECTED enum Alpha::Omega::OmegaClass::Rino of type UINT 
 friend constexpr auto format_as(const Alpha::Omega::OmegaClass::Rino obj) {
  fmt::string_view name = "<missing>";
  switch (obj) {
    case Alpha::Omega::OmegaClass::RI_ZERO : name = "RI_ZERO" ; break;  // index=0
    case Alpha::Omega::OmegaClass::RI_ONE  : name = "RI_ONE"  ; break;  // index=1
    case Alpha::Omega::OmegaClass::RI_TWO  : name = "RI_TWO"  ; break;  // index=2
    case Alpha::Omega::OmegaClass::RI_THREE: name = "RI_THREE"; break;  // index=3
    case Alpha::Omega::OmegaClass::RI_FOUR : name = "RI_FOUR" ; break;  // index=4
  }
  return name;
}
// Generated to_string for PUBLIC CLASS_DECL Alpha::Omega::OmegaClass
  public:
  auto to_string() const {
    return fstr::format(R"( Alpha::Omega::OmegaClass:
    PUBLIC int omegaString: {} 
)", omegaString);
  }
};
    } // end namespace Omega
} // end namespace Alpha

//Sample class for bug 3488053
class Bug_3488053
{
	public:
	class Bug_3488053_Nested
	{
	public:
		int x;
	// Generated to_string for PUBLIC CLASS_DECL Bug_3488053::Bug_3488053_Nested
  public:
  auto to_string() const {
    return fstr::format(R"( Bug_3488053::Bug_3488053_Nested:
    PUBLIC int x: {} 
)", x);
  }
} nest;
// Generated to_string for PUBLIC CLASS_DECL Bug_3488053
  public:
  auto to_string() const {
    return fstr::format(R"( Bug_3488053:
    PUBLIC class Bug_3488053_Nested nest: {} 
)", nest);
  }
};

// Bug 3488360
namespace Citrus
{
  class BloodOrange { 
    public:
      int bo=1;
  
  friend class ExcellentCake;
// Generated to_string for PUBLIC CLASS_DECL Citrus::BloodOrange
  public:
  auto to_string() const {
    return fstr::format(R"( Citrus::BloodOrange:
    PUBLIC int bo: {} 
)", bo);
  }
};
}

class Bananna: public Citrus::BloodOrange
{
// Generated to_string for PUBLIC CLASS_DECL Bananna
  public:
  auto to_string() const {
    return fstr::format(R"( Bananna:
     PUBLIC int bo: {} 
)", this->bo);
  }
};

class ExcellentCake: private Citrus::BloodOrange
{
// Generated to_string for PUBLIC CLASS_DECL ExcellentCake
  public:
  auto to_string() const {
    return fstr::format(R"( ExcellentCake:
     PRIVATE int bo: {} 
)", this->bo);
  }
};

// Bug 3487551
class Bug_3487551
{
public:
    virtual int method();
};


// Feature Request 3488051
struct SampleStruct
{
    unsigned int meth();
private:
    int prop;
// Generated to_string for PUBLIC STRUCT_DECL SampleStruct
  public:
  auto to_string() const {
    return fstr::format(R"( SampleStruct:
    PRIVATE int prop: {} 
)", prop);
  }
};

// Bug 3488049 & Feature Request 3488050
const int MAX_ITEM = 7;
class Bird
{
  public:
  int items[MAX_ITEM];
  int otherItems[7];
  int oneItem;
// Generated to_string for PUBLIC CLASS_DECL Bird
  public:
  auto to_string() const {
    return fstr::format(R"( Bird:
    PUBLIC int[7] items: {} 
    PUBLIC int[7] otherItems: {} 
    PUBLIC int oneItem: {} 
)", items, otherItems, oneItem);
  }
};

// Bug 3488054
class Monkey {
private:
static void Create();
};
inline void Monkey::Create() { }

// Bug 3488275
class Chicken
{
template <typename T> static T Get();
};
template <typename T> T Chicken::Get() { return T(); }

// Bug 3491240
class Lizzard {
Lizzard();
explicit Lizzard( int a );
};

// Bug 3491178
class Owl {
private:
template <typename T> int* tFunc( int count );
};

template <typename T> int* Owl::tFunc( int count ) {
if (count == 0) {
return NULL;
}
return NULL;
}

// Bug 3491232
class GrapeClass {
private:
struct GrapeStruct { };
int x;
void f();
// Generated to_string for PUBLIC CLASS_DECL GrapeClass
  public:
  auto to_string() const {
    return fstr::format(R"( GrapeClass:
    PRIVATE int x: {} 
)", x);
  }
};


// Bug 3491319
struct AnonHolderClass {
struct {
int x;
} a;
// Generated to_string for PUBLIC STRUCT_DECL AnonHolderClass
  public:
  auto to_string() const {
    return fstr::format(R"( AnonHolderClass:
     PUBLIC int a.x: {} 
)", this->a.x);
  }
};


// Feature Request 3491220
class CowClass {};
struct CowStruct {};

// Bug 3491334
class BaseMangoClass { };
class MangoClass: virtual public BaseMangoClass { };

// Bug 3492237
const long MAX_LEN = 7;
struct EagleClass {
int a[(int)MAX_LEN];
// Generated to_string for PUBLIC STRUCT_DECL EagleClass
  public:
  auto to_string() const {
    return fstr::format(R"( EagleClass:
    PUBLIC int[7] a: {} 
)", a);
  }
};

// Bug 3497164
struct FrogClass {

    struct {
        int a;
    } x;

    struct {
        int b;
    } y;

    struct {
        int c;
    } z;

// Generated to_string for PUBLIC STRUCT_DECL FrogClass
  public:
  auto to_string() const {
    return fstr::format(R"( FrogClass:
     PUBLIC int x.a: {} 
     PUBLIC int y.b: {} 
     PUBLIC int z.c: {} 
)", this->x.a, this->y.b, this->z.c);
  }
};

// Bug 3497160
class DogClass;
class CatClass {
    friend DogClass;
};

// Bug 3497155
extern "C" {
int FishA( const char* strA );
int FishB( const char* strB );
}

// Bug 3497168
class PandaClass {
static const int CONST_A = (1 << 7) - 1;
static const int CONST_B = sizeof(int);
// Generated to_string for PUBLIC CLASS_DECL PandaClass
  public:
  auto to_string() const {
    return fstr::format(R"( PandaClass:
    PRIVATE const int CONST_A: {} 
    PRIVATE const int CONST_B: {} 
)", CONST_A, CONST_B);
  }
};

// Bug 3497166
class PotatoClass {
    struct FwdStruct;
    FwdStruct* ptr;
    struct FwdStruct {
    	int a;
    // Generated to_string for PRIVATE STRUCT_DECL PotatoClass::FwdStruct
  public:
  auto to_string() const {
    return fstr::format(R"( PotatoClass::FwdStruct:
    PUBLIC int a: {} 
)", a);
  }
};
// Generated to_string for PUBLIC CLASS_DECL PotatoClass
  public:
  auto to_string() const {
    return fstr::format(R"( PotatoClass:
    PRIVATE FwdStruct * ptr: {} 
)", fmt::ptr(ptr));
  }
};

// Bug 3497162
class HogClass {
	union HogUnion {
		int a;
		float b;
	// Generated to_string for PRIVATE UNION_DECL HogClass::HogUnion
  public:
  auto to_string() const {
    return fstr::format(R"( HogClass::HogUnion:
    PUBLIC int a: {} 
    PUBLIC float b: {} 
)", a, b);
  }
} u;
// Generated to_string for PUBLIC CLASS_DECL HogClass
  public:
  auto to_string() const {
    return fstr::format(R"( HogClass:
    PRIVATE union HogUnion u: {} 
)", u);
  }
};

// Bug 3497158
template< int ID >
class CherryClass {
public:
	CherryClass ();
	struct NestStruct {
	    void FuncA();
	    int val;
	// Generated to_string for PUBLIC STRUCT_DECL CherryClass<ID>::NestStruct
  public:
  auto to_string() const {
    return fstr::format(R"( CherryClass<ID>::NestStruct:
    PUBLIC int val: {} 
)", val);
  }
};
// Generated to_string for PUBLIC CLASS_TEMPLATE CherryClass<ID>
  public:
  auto to_string() const {
    return fstr::format(R"( CherryClass<ID>:
)");
  }
};

// Bug 3517308
template<class T>
class GarlicClass
{
public:
	GarlicClass();
    int fun1(T);
    int fun2(T);
// Generated to_string for PUBLIC CLASS_TEMPLATE GarlicClass<T>
  public:
  auto to_string() const {
    return fstr::format(R"( GarlicClass<T>:
)");
  }
};

// Bug 3514728
class CarrotClass
{
int var1;
#define FIRSTLINE \
SECONDLINE
void fun1();
// Generated to_string for PUBLIC CLASS_DECL CarrotClass
  public:
  auto to_string() const {
    return fstr::format(R"( CarrotClass:
    PRIVATE int var1: {} 
)", var1);
  }
};

// Bug 3517289
extern "C" void f(int i, char c, float x);


// Bug 3514671
struct OliveStruct{
	struct other* a;
	void* b;
	bool c;
	int d;
// Generated to_string for PUBLIC STRUCT_DECL OliveStruct
  public:
  auto to_string() const {
    return fstr::format(R"( OliveStruct:
    PUBLIC struct other * a: {} 
    PUBLIC void * b: {} 
    PUBLIC bool c: {} 
    PUBLIC int d: {} 
)", fmt::ptr(a), fmt::ptr(b), c, d);
  }
};

// Bug 3515330
namespace RoosterNamespace
{
    class RoosterOuterClass
    {
    public:
        int member1;

        class RoosterSubClass1
        {
        public:
            int publicMember1;
        private:
            int privateMember1;
        // Generated to_string for PUBLIC CLASS_DECL RoosterNamespace::RoosterOuterClass::RoosterSubClass1
  public:
  auto to_string() const {
    return fstr::format(R"( RoosterNamespace::RoosterOuterClass::RoosterSubClass1:
    PUBLIC int publicMember1: {} 
    PRIVATE int privateMember1: {} 
)", publicMember1, privateMember1);
  }
};

    private:
        int member2;
        class RoosterSubClass2
        {
        public:
            int publicMember2;
        private:
            int privateMember2;
        // Generated to_string for PRIVATE CLASS_DECL RoosterNamespace::RoosterOuterClass::RoosterSubClass2
  public:
  auto to_string() const {
    return fstr::format(R"( RoosterNamespace::RoosterOuterClass::RoosterSubClass2:
    PUBLIC int publicMember2: {} 
    PRIVATE int privateMember2: {} 
)", publicMember2, privateMember2);
  }
};
    // Generated to_string for PUBLIC CLASS_DECL RoosterNamespace::RoosterOuterClass
  public:
  auto to_string() const {
    return fstr::format(R"( RoosterNamespace::RoosterOuterClass:
    PUBLIC int member1: {} 
    PRIVATE int member2: {} 
)", member1, member2);
  }
};
}


// Bug 3514672
class OperatorClass
{
public:
};

// Feature request 3519502 & 3523010
class CrowClass
{
public:
    int meth();

public:
    void testSlot(int i);
};

// Bug 3497170
struct DriverFuncs {
    void* (*init) ();
    void (*write) (void *buf, int buflen);
// Generated to_string for PUBLIC STRUCT_DECL DriverFuncs
  public:
  auto to_string() const {
    return fstr::format(R"( DriverFuncs:
    PUBLIC void *(*)() init: {} 
    PUBLIC void (*)(void *, int) write: {} 
)", fmt::ptr(init), fmt::ptr(write));
  }
};


// Feature Request 3523235
class RockClass
{
    int getNum() const;
    int getNum2();
};


// Bug 3524327
class StoneClass
{
    virtual int getNum2() const = 0;
    int getNum3();
};

// Bug 3531219
class Kangaroo
{
public:
    Kangaroo() {
    }
    class Joey
    {
    public:
        Joey();
    };
};





