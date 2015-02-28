#include "chapter_11.h"

using namespace std;

int& function_11_4 (int& i) {
    i++;
    return i;
}

Class_11_5::Class_11_5 () {}

void Class_11_5::function_1() {}

void Class_11_5::function_2() const {}

void function_11_5(Class_11_5& clPtr) {
    // passing 'const Class_11_5' as 'this' argument of 'void Class_11_5::function_1()' discards qualifiers
    clPtr.function_1();
    clPtr.function_2();
}

void function_11_6(int*& iRef) {
    iRef++;
}

void function_11_7(int**& iRef) {
    iRef++;
}

void function_11_8(char& cRef) {
    cRef++;
}

Class_11_9::Class_11_9() {}

void Class_11_9::function_1() {}

void Class_11_9::function_2() const {}

void function_11_9_1(Class_11_9 cl) {
    cl.function_1();
    cl.function_2();
}

void function_11_9_2(Class_11_9& cl) {
    cl.function_1();
    cl.function_2();
}

void function_11_9_3(const Class_11_9& cl) {
    // passing 'const Class_11_9' as 'this' argument of 'void Class_11_9::function_1()' discards qualifiers
    // cl.function_1();
    cl.function_2();
}

int function_11_10(int i) {
    /*
 295              	_Z14function_11_10i:
 296              	.LFB18:
 297              		.cfi_startproc
 298 012a 55       		pushq	%rbp
 299              		.cfi_def_cfa_offset 16
 300              		.cfi_offset 6, -16
 301 012b 4889E5   		movq	%rsp, %rbp
 302              		.cfi_def_cfa_register 6
 303 012e 897DFC   		movl	%edi, -4(%rbp)
 304 0131 8345FC01 		addl	$1, -4(%rbp)
 305 0135 8B45FC   		movl	-4(%rbp), %eax
 306 0138 5D       		popq	%rbp
 307              		.cfi_def_cfa 7, 8
 308 0139 C3       		ret
 309              		.cfi_endproc
 */
    i++;
    return i;
}

void function_11_11(char c, int i, float f, double d) {
    c++;
    i++;
    f++;
    d++;
}

// Code from chapter_11() function, call this function.
/*
10843 6f1c C6856BFF 		movb	$97, -149(%rbp)
10843      FFFF61
10844 6f23 C7458001 		movl	$1, -128(%rbp)
10844      000000
10845 6f2a 8B050000 		movl	.LC206(%rip), %eax
10845      0000
10846 6f30 894584   		movl	%eax, -124(%rbp)
10847 6f33 B8000000 		movl	$0, %eax
10847      00
10848 6f38 488945C8 		movq	%rax, -56(%rbp)
10849 6f3c 0FBE8D6B 		movsbl	-149(%rbp), %ecx
10849      FFFFFF
10850 6f43 488B55C8 		movq	-56(%rbp), %rdx
10851 6f47 8B4584   		movl	-124(%rbp), %eax
10852 6f4a 8B7580   		movl	-128(%rbp), %esi
10853 6f4d 48899558 		movq	%rdx, -168(%rbp)
10853      FFFFFF
10854 6f54 F20F108D 		movsd	-168(%rbp), %xmm1
10854      58FFFFFF
10855 6f5c 898558FF 		movl	%eax, -168(%rbp)
10855      FFFF
10856 6f62 F30F1085 		movss	-168(%rbp), %xmm0
10856      58FFFFFF
10857 6f6a 89CF     		movl	%ecx, %edi
10858 6f6c E8000000 		call	_Z14function_11_11cifd
*/

double function_11_12(double d) {
    d++;
    return d;
}

// Code function_11_12.
/*
 347              	_Z14function_11_12d:
 348              	.LFB20:
 349              		.cfi_startproc
 350 018c 55       		pushq	%rbp
 351              		.cfi_def_cfa_offset 16
 352              		.cfi_offset 6, -16
 353 018d 4889E5   		movq	%rsp, %rbp
 354              		.cfi_def_cfa_register 6
 355 0190 F20F1145 		movsd	%xmm0, -8(%rbp)
 355      F8
 356 0195 F20F104D 		movsd	-8(%rbp), %xmm1
 356      F8
 357 019a F20F1005 		movsd	.LC1(%rip), %xmm0
 357      00000000
 358 01a2 F20F58C1 		addsd	%xmm1, %xmm0
 359 01a6 F20F1145 		movsd	%xmm0, -8(%rbp)
 359      F8
 360 01ab 488B45F8 		movq	-8(%rbp), %rax
 361 01af 488945F0 		movq	%rax, -16(%rbp)
 362 01b3 F20F1045 		movsd	-16(%rbp), %xmm0
 362      F0
 363 01b8 5D       		popq	%rbp
 364              		.cfi_def_cfa 7, 8
 365 01b9 C3       		ret
 366              		.cfi_endproc
 367              	.LFE20:
 368              		.size	_Z14function_11_12d, .-_Z14function_11_12d
*/

Structure_13 function_11_13(Structure_13 st) {
    st.i++;
    st.l--;
    return st;
}

// Calling function_11_13, code. Char seems loaded as effective address 'lea' instruction.
/*
 10862 6fc5 488D85F0 		leaq	-272(%rbp), %rax
 10862      FEFFFF
 10863 6fcc 488B55B0 		movq	-80(%rbp), %rdx
 10864 6fd0 48891424 		movq	%rdx, (%rsp)
 10865 6fd4 488B55B8 		movq	-72(%rbp), %rdx
 10866 6fd8 48895424 		movq	%rdx, 8(%rsp)
 10866      08
 10867 6fdd 488B55C0 		movq	-64(%rbp), %rdx
 10868 6fe1 48895424 		movq	%rdx, 16(%rsp)
 10868      10
 10869 6fe6 488B55C8 		movq	-56(%rbp), %rdx
 10870 6fea 48895424 		movq	%rdx, 24(%rsp)
 10870      18
 10871 6fef 488B55D0 		movq	-48(%rbp), %rdx
 10872 6ff3 48895424 		movq	%rdx, 32(%rsp)
 10872      20
 10873 6ff8 488B55D8 		movq	-40(%rbp), %rdx
 10874 6ffc 48895424 		movq	%rdx, 40(%rsp)
 10874      28
 10875 7001 4889C7   		movq	%rax, %rdi
 10876 7004 E8000000 		call	_Z14function_11_1312Structure_13
 */

// Function_11_13 assembly code.
/*
 371              	_Z14function_11_1312Structure_13:
 372              	.LFB21:
 373              		.cfi_startproc
 374 01ba 55       		pushq	%rbp
 375              		.cfi_def_cfa_offset 16
 376              		.cfi_offset 6, -16
 377 01bb 4889E5   		movq	%rsp, %rbp
 378              		.cfi_def_cfa_register 6
 379 01be 48897DF8 		movq	%rdi, -8(%rbp)
GAS LISTING /tmp/ccVxllSK.s 			page 8


 380 01c2 8B4530   		movl	48(%rbp), %eax
 381 01c5 83C001   		addl	$1, %eax
 382 01c8 894530   		movl	%eax, 48(%rbp)
 383 01cb 488B4538 		movq	56(%rbp), %rax
 384 01cf 4883E801 		subq	$1, %rax
 385 01d3 48894538 		movq	%rax, 56(%rbp)
 386 01d7 488B45F8 		movq	-8(%rbp), %rax
 387 01db 488B5510 		movq	16(%rbp), %rdx
 388 01df 488910   		movq	%rdx, (%rax)
 389 01e2 488B5518 		movq	24(%rbp), %rdx
 390 01e6 48895008 		movq	%rdx, 8(%rax)
 391 01ea 488B5520 		movq	32(%rbp), %rdx
 392 01ee 48895010 		movq	%rdx, 16(%rax)
 393 01f2 488B5528 		movq	40(%rbp), %rdx
 394 01f6 48895018 		movq	%rdx, 24(%rax)
 395 01fa 488B5530 		movq	48(%rbp), %rdx
 396 01fe 48895020 		movq	%rdx, 32(%rax)
 397 0202 488B5538 		movq	56(%rbp), %rdx
 398 0206 48895028 		movq	%rdx, 40(%rax)
 399 020a 488B45F8 		movq	-8(%rbp), %rax
 400 020e 5D       		popq	%rbp
 401              		.cfi_def_cfa 7, 8
 402 020f C3       		ret
 403              		.cfi_endproc
*/

void function_11_14(int r) {
    cout << "Function_11_14 has called." << endl;
    if (--r) function_11_14(r);
}

// Function_11_14 code.
/*
.text
 412              		.globl	_Z14function_11_14i
 413              		.type	_Z14function_11_14i, @function
 414              	_Z14function_11_14i:
 415              	.LFB993:
 416              		.cfi_startproc
 417 0210 55       		pushq	%rbp
 418              		.cfi_def_cfa_offset 16
 419              		.cfi_offset 6, -16
 420 0211 4889E5   		movq	%rsp, %rbp
 421              		.cfi_def_cfa_register 6
 422 0214 4883EC10 		subq	$16, %rsp
 423 0218 897DFC   		movl	%edi, -4(%rbp)
 424 021b BE000000 		movl	$.LC2, %esi
 424      00
 425 0220 BF000000 		movl	$_ZSt4cout, %edi
 425      00
 426 0225 E8000000 		call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
 426      00
 427 022a BE000000 		movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
 427      00
 428 022f 4889C7   		movq	%rax, %rdi
GAS LISTING /tmp/ccvgcuT1.s 			page 9


 429 0232 E8000000 		call	_ZNSolsEPFRSoS_E
 429      00
 430 0237 836DFC01 		subl	$1, -4(%rbp)
 431 023b 837DFC00 		cmpl	$0, -4(%rbp)
 432 023f 0F95C0   		setne	%al
 433 0242 84C0     		testb	%al, %al
 434 0244 740A     		je	.L23
 435 0246 8B45FC   		movl	-4(%rbp), %eax
 436 0249 89C7     		movl	%eax, %edi
 437 024b E8000000 		call	_Z14function_11_14i
 437      00
 438              	.L23:
 439 0250 C9       		leave
 440              		.cfi_def_cfa 7, 8
 441 0251 C3       		ret
 442              		.cfi_endproc
*/

void function_11_15(int i, Class_11_15_2 cl) {
    i++;
    cout << "Class_11_15_2 integer = " << cl.s << endl;
    cout << "Class_11_15_1 integer = " << cl.clP.t << endl;
}

Class_11_16::Class_11_16 () {
    cout << "Class_11_16 constructor." << endl;
}

Class_11_16::Class_11_16(const Class_11_16& r) {
    cout << "Class_11_16 copy constructor." << endl;
    str = r.str;
}

void function_11_16_1(Class_11_16 cl) {}

Class_11_16 function_11_16_2() {
    Class_11_16 local;
    local.str = "new";
    return local;
}

Class_11_17::Class_11_17(double i) {
    dPtr = new double(i);
    cout << "Class_11_17 constructor, double =  " << *dPtr << endl;
}

Class_11_17::~Class_11_17() {
    cout << "Class_11_17 destructor, double = " << *dPtr << endl;
    *dPtr = -1;
    delete dPtr;
    dPtr = 0;
}

Class_11_17::Class_11_17(const Class_11_17 &l) {
    cout << "Class_11_17, copy constructor." << endl;
    dPtr = new double(*l.dPtr);
}

void function_11_17(Class_11_17 value) {
    cout << "Function_11_17, double = " << *value.dPtr << endl;
}

Class_11_18::Class_11_18() {
    cout << "Class_11_18 constructor." << endl;
}

Class_11_18::Class_11_18(const Class_11_18 &l, int i) {
    cout << "Class_11_18 copy constructor." << endl;
    i++;
}

void function_11_18(Class_11_18 value) {
    cout << "In function_11_18." << endl;
}

Class_11_19_1::Class_11_19_1() {
    cout << "Class_11_19_1 constructor." << endl;
}

Class_11_19_1::Class_11_19_1(const Class_11_19_1&) {
    cout << "Class_11_19_1 copy constructor." << endl;
}

Class_11_19_2::Class_11_19_2() {
    cout << "Class_11_19_2 constructor." << endl;
}

void Class_11_19_2::function_1(Class_11_19_2 clV) {
    cout << "In Class_11_19_2::function_1." << endl;
}

Class_11_20::Class_11_20() {}

Class_11_20 function_11_20_1() {
    Class_11_20 local;
    return local;
}

void function_11_20_2(const Class_11_20 &value) {
    cout << "Function_11_20_2." << endl;
}

Class_11_21::Class_11_21() {}

void function_11_21(Class_11_21 cl) {}

Class_11_22::Class_11_22() {}

Class_11_22* Class_11_22::clone() const {
    Class_11_22* newObject = new Class_11_22;
    return newObject;
}

void function_11_22(const Class_11_22& value) {
    Class_11_22* cl = value.clone();
}

Class_11_24::Class_11_24(double di) : d(di) {}

void Class_11_24::print() {
    cout << "Class_11_24 double = " << d << endl;
}
