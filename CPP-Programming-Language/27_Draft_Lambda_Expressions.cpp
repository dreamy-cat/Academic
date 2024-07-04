#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

/* Он точно нуждается в психиатрической помощи. :) Остается только напрямую по стандарту. Документ №4928 от 2022-12-18.

(7.5.5.1). 
A lambda-expression is a prvalue whose result object is called the closure object.
[Note 1: A closure object behaves like a function object (22.10). — end note].

Лямбда выражение это pr-значение, результатом которого является объект называемый объектом замыкания.
Примечание: Объект замыкания ведет себя как функциональный объект 22.10.

(22.10.1) A function object type is an object type (6.8.1) that can be the type of the postfix-expression in a function
call (7.6.1.3, 12.2.2.2).208 A function object is an object of a function object type. In the places where one
would expect to pass a pointer to a function to an algorithmic template (Clause 27), the interface is specified
to accept a function object.

Объект функционального типа это объект типа (6.8.1), который может быть постфиксным выражением ФУНКЦИОНАЛЬНОГО ВЫЗОВА(CALL)!!!(7.6.1.3., 12.2.2.2)... В местах где ожидается передача указателя на функцию в алгоритм по шаблону.

(7.6.1.3) Function call
A function call is a postfix expression followed by parentheses containing a possibly empty, comma-separated
list of initializer-clauses which constitute the arguments to the function.

(7.2) Категории значений
pr-value - это выражение которым инициализируется объект или вычисляется значение операнда заданного оператора, как это определено по контексту, в котором оно появляется или выражение имеющий тип cv-void(нет результирующего объекта).

(1.2)
A prvalue is an expression whose evaluation initializes an object or computes the value of an operand
of an operator, as specified by the context in which it appears, or an expression that has type cv void.

----
*/

using namespace std;

// Черновик для ответа на зачете по лямбда функциям. GCC-32 bits, 8.1.0.

/* Задание от Дани:
 *  Короче этот пёс заставил  меня примеры написать к моим ответам.
 * Функтор с перегрузкой оператора () я показал, а вот функтор с перегрузкой оператора
 * перевода/конверсии в функцию с нужной сигнатурой я не очень понимаю как сделать.
 * В пятницу к нему идти снова. (envy)
 *
 **/

/*

class Functor {                                             // Класс функтора с перегруженным оператором вызова: "operator()".
public:
    typedef char(*fPtrA)(char);                             // Вспомогательные типы сигнатур функций для вызова.
    typedef int(*fPtrB)(int);
    Functor()
    {
        cout << "Functor object constructor, addresses of static functions:\n";
        cout << "return char FuncA(char c) is " << (void*)&funcA << endl;
        cout << "return int FuncB(int i) is " << (void*)&funcB << endl;

    }
    virtual ~Functor() {};
    static char funcA(char c)
    {
        cout << "Static function called from pointer, last char value " << lastC
             << ", current char " << c << endl;
        return c;
    }
    static int funcB(int i)
    {
        cout << "Static function called from pointer, last int " << lastI
             << ", current integer " << i << endl;
        return lastI;
    }
    fPtrA operator()(char c)                                // Перегруженный оператор вызова функционального объекта.
    {
        cout << "Calling overloaded operator() using char " << c << "\n";
        lastC = c;
        return &funcA;                                      // Возвращаем.
    }
    fPtrB operator()(int i)
    {
        cout << "Calling overloaded operator() using integer " << i << "\n";
        // return &funcA; ошибка возвращаемой сигнатуры указателя на функцию.
        lastI = i;
        return &funcB;  // Верная сигнатура.
    }
    operator fPtrA()                                        // Оператор конвертации объетка Функтора в функциональный объект.
    {
        cout << "Conversion from Functor to function with char, returned " << (void*)funcA << endl;
        return &funcA;                                      // По аналогии просто возвращаем результат.
    }
    operator fPtrB()
    {
        cout << "Conversion from Functor to function with integer, return " << (void*)funcB << endl;
        return &funcB;
    }
    static char lastC;
    static int lastI;
};

char Functor::lastC;
int Functor::lastI;

void between(int a, int b, int c, std::function<bool(int,int)> cmp)
{
    cout << "Between " << a << " and " << b << ", value " << c << ", address " << &cmp << endl;
    if (cmp(c, a) && cmp(b, c))
        cout << "Yes, value in range.\n";
    else if (cmp(c, a) && !cmp(b, c))
        cout << "No, value is far right.\n";
    else if (!cmp(c, a) && cmp(b, c))
        cout << "No, value is far left.\n";
}

*/

void chapter_27()
{
    cout << "Quick functional examples.\n\n";
    /*
    // Лямбда выражение. Замыкание и захват переменных по значению.
    std::function<bool(int,int)> more = [](int lv, int rv) {
        cout << "In lambda, left " << lv << " more than right " << rv << ": " << (lv > rv) << endl;
        return (lv > rv);
    };
    cout << "Is functional object is more (1 than 0).\n";
    more(1, 0);
    between(1, 5, 3, more);
    cout << endl;
    between(1, 5, 7, more);
    cout << endl;
    between(1, 5, 0, more);
    */

    /*
C:/SDK/Qt/Tools/mingw810_32/lib/gcc/i686-w64-mingw32/8.1.0/include/c++/bits/std_function.h:687:       return _M_invoker(_M_functor, std::forward<_ArgTypes>(__args)...);
   lea	eax, [ebp-64]	 # tmp130,
   mov	DWORD PTR [esp+8], eax	 #, tmp130
   lea	eax, [ebp-68]	 # tmp131,
   mov	DWORD PTR [esp+4], eax	 #, tmp131
   lea	eax, [ebp-60]	 # tmp192,
   mov	DWORD PTR [esp], eax	 #, tmp192
   call	[DWORD PTR [ebp-48]]	 # more._M_invoker
# C:\Users\Alexander\Documents\Projects\Questions-CPP\main.cpp:48:     between(1, 5, 3, more);
   lea	eax, [ebp-60]	 # tmp193,
   lea	ecx, [ebp-44]	 # tmp194,
   mov	DWORD PTR [esp], eax	 #, tmp193
   call	__ZNSt8functionIFbiiEEC1ERKS1_	 #
   */

    // Замыкание без объявления.
    /*
    std::vector<int> data({ 1, 2, 3, 4, 5 });
    cout << "\nVectors using lambda expression without declaration:\n";
    for (auto e = data.begin(); e != data.end(); ++e)
        cout << *e << " ";
    cout << endl;
    sort(data.begin(), data.end(), [](int a, int b) { return a > b; });
    /*
    /*
 # C:/SDK/Qt/Tools/mingw810_32/lib/gcc/i686-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1968: 	  std::__introsort_loop(__first, __last,
    mov	esi, DWORD PTR [ebp-76]	 # _157, %sfp
    mov	BYTE PTR [esp], 0	 #,
    mov	edx, edi	 #, _198
    mov	ecx, 4	 #,
    mov	eax, esi	 #, _157
    call	__ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEEiNS0_5__ops15_Iter_comp_iterIZ4mainEUliiE0_EEEvT_SB_T0_T1_	 #
 # C:/SDK/Qt/Tools/mingw810_32/lib/gcc/i686-w64-mingw32/8.1.0/include/c++/bits/stl_algo.h:1890: 	std::__insertion_sort(__first, __last, __comp);
    mov	edx, edi	 #, _198
    mov	eax, esi	 #, _157
    call	__ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_comp_iterIZ4mainEUliiE0_EEEvT_SB_T0_.isra.66	 #
    */

    /*
    for (auto e = data.begin(); e != data.end(); ++e)
        cout << *e << " ";
    cout << "\n\n";
    */
    // Без захвата переменных.
    /*
    std::function<int(void)> rnd = [](void) { return rand(); };
    cout << "Lambda expression without args, random: " << rnd() << "\n\n";
    */
    /*
 # C:\Users\Alexander\Documents\Projects\Questions-CPP\main.cpp:65:     cout << "Lambda expression without args, random: " << rnd() << "\n\n";
    mov	DWORD PTR [esp], eax	 #, _72
    mov	ecx, OFFSET FLAT:__ZSt4cout	 #,
    call	__ZNSolsEi	 #
    sub	esp, 4	 #,
    mov	DWORD PTR [esp+4], OFFSET FLAT:LC14	 #,
    mov	DWORD PTR [esp], eax	 #, _39
    call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #    */

    // Указатель на функцию в стиле Си на лямбду.
    /*
    typedef void(*lambda_c)(void);
    lambda_c ptr = [](void) { cout << "Calling C-like pointer lambda function.\n"; };
    (*ptr)();
    std::cout << endl;
    */
/*
# C:\Users\Alexander\Documents\Projects\Questions-CPP\main.cpp:68:     lambda_c ptr = [](void) { cout << "Calling C-like pointer lambda function.\n"; };
   mov	DWORD PTR [esp+4], OFFSET FLAT:LC16	 #,
   mov	DWORD PTR [esp], OFFSET FLAT:__ZSt4cout	 #,
   call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
# C:/SDK/Qt/Tools/mingw810_32/lib/gcc/i686-w64-mingw32/8.1.0/include/c++/ostream:113: 	return __pf(*this);
   mov	DWORD PTR [esp], OFFSET FLAT:__ZSt4cout	 #,
   call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_	 #
*/
    // Автоматическое выведение типа из захваченного аргумента по ссылке.
    // char object = 'A';
    // Update C++14.
    // auto autoTypeLambda = [&]()->auto&& { return object; };
    // cout << "Auto type deduction from object, char is " << autoTypeLambda() << "\n\n";
    /*
# C:/SDK/Qt/Tools/mingw810_32/lib/gcc/i686-w64-mingw32/8.1.0/include/c++/ostream:509:     { return __ostream_insert(__out, &__c, 1); }
   lea	eax, [ebp-69]	 # tmp160,
   mov	DWORD PTR [esp+8], 1	 #,
   mov	DWORD PTR [esp+4], eax	 #, tmp160
   mov	DWORD PTR [esp], OFFSET FLAT:__ZSt4cout	 #,
   mov	BYTE PTR [ebp-69], 65	 # __c,
   call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i	 #
   */

    // Обобщенный вариант.
    // short word = 7;
    // Update standard.
    // auto tempTypeLambda = []<typename T>(T object) { cout << "Type " << object << "\n\n"; };
    // tempTypeLambda(word);
    /* # C:\Users\Alexander\Documents\Projects\Questions-CPP\main.cpp:77:     auto tempTypeLambda = []<typename T>(T object) { cout << "Type " << object << "\n\n"; };
    mov	DWORD PTR [esp], 7	 #,
    mov	ecx, OFFSET FLAT:__ZSt4cout	 #,
    call	__ZNSolsEs	 #
    sub	esp, 4	 #,
    mov	DWORD PTR [esp+4], OFFSET FLAT:LC14	 #,
    mov	DWORD PTR [esp], eax	 #, _211
    call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
     * */

    // Объект функтора c перегузкой оператора вызова.
    /*
    cout << "Trying functor object with overloading operator().\n";
    Functor fObj;
    auto ptrA = fObj.operator()('A');                       // Вызов перегруженного оператора оба варианта вызова равнозначны.
    auto ptrB = fObj(1);
    cout << "Verify calling functions from returned signatures.\n";
    ptrA('B');
    ptrB(2);
    // Дополнительно, получение сигнатуры через стандартный вызов и функциональный объект.
    cout << "Calling function object as returned auto signature from object as returned overloaded Functor::operator().\n";
    // Получаем сигнатуру после автоматического выведения функционального объекта из перегуженного оператора().
    auto ptrC = std::reference_wrapper<Functor::fPtrA>(ptrA);
    ptrC('C');                                              // Проверяем полученный функциональный объект через вызов.
    cout << "Converting object Functor to functional objects and verify by calling.\n";
    auto convA = Functor::fPtrA(fObj);                      // Методы конвертации.
    auto convB = Functor::fPtrB(fObj);
    convA('D');                                             // Проверяем.
    convB(3);
    cout << endl;
    */
}
