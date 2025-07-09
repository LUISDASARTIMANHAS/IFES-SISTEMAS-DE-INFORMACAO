;
; *********************************
; *                               *
; *                               *
; *********************************
;
.nolist
.include "m328pdef.inc" ; Define device ATmega328P
.list
;
; **********************************
;        H A R D W A R E
; **********************************
;
; **********************************
;  P O R T S   A N D   P I N S
; **********************************
;
.equ pOut = PORTB ; Define a output port
.equ pDir = DDRB ; Define a direction port
.equ pIn = PINB ; Define an input port
.equ bMyPinO = PORTB0 ; Define an output pin
.equ bDir0 = DDB0 ; Define a direction pin
.equ bMyIn = PINB0 ; Define an input pin
;
; **********************************
;   A D J U S T A B L E   C O N S T
; **********************************
;
.equ clock=1000000 ; Define clock frequency
;
; **********************************
;  F I X  &  D E R I V.  C O N S T
; **********************************
;
.equ cTc0Clk = clock / 256 ; Define from clock
;
; **********************************
;       R E G I S T E R S
; **********************************
;
; free: R0 to R14
.def rSreg = R15 ; Save/Restore status port
; free: R0 to R15
.def rmp = R16 ; Define multipurpose register
; free: R17 to R29
; used: R31:R30 = Z for ...
;
; **********************************
;           S R A M
; **********************************
;
.dseg
.org SRAM_START
sLabel1:
.byte 16 ; Reserve 16 bytes
;
; **********************************
;         C O D E
; **********************************
;
.cseg
.org 000000
;
; **********************************
; R E S E T  &  I N T - V E C T O R S
; **********************************
	rjmp Main ; Reset vector
	nop
	reti ; INT0
	nop
	reti ; INT1
	nop
	reti ; PCI0
	nop
	reti ; PCI1
	nop
	reti ; PCI2
	nop
	reti ; WDT
	nop
	reti ; OC2A
	nop
	reti ; OC2B
	nop
	reti ; OVF2
	nop
	reti ; ICP1
	nop
	reti ; OC1A
	nop
	reti ; OC1B
	nop
	reti ; OVF1
	nop
	reti ; OC0A
	nop
	reti ; OC0B
	nop
	reti ; OVF0
	nop
	reti ; SPI
	nop
	reti ; URXC
	nop
	reti ; UDRE
	nop
	reti ; UTXC
	nop
	reti ; ADCC
	nop
	reti ; ERDY
	nop
	reti ; ACI
	nop
	reti ; TWI
	nop
	reti ; SPMR
	nop
;
; **********************************
;  I N T - S E R V I C E   R O U T .
; **********************************
;
; Add all interrupt service routines
;
; **********************************
;  M A I N   P R O G R A M   I N I T
; **********************************
;
Main:
	ldi rmp,High(RAMEND)
	out SPH,rmp ; Init MSB stack pointer
	ldi rmp,Low(RAMEND)
	out SPL,rmp ; Init LSB stack pointer
; ...
	sei ; Enable interrupts
;
; **********************************
;    P R O G R A M   L O O P
; **********************************
;

    LDI R16, 0        ; Inicializa o registrador R16 com zero (acumulador)
LDI R17, 0        ; Inicializa o registrador R17 com zero (contador)
LDI R18, 200      ; Carrega a constante 200 em R18 (limite da soma)

LDI R27, $FF      ; Carrega o valor máximo na parte alta do registrador R27
LDI R26, $10      ; Carrega o endereço de memória em formato hexadecimal na parte baixa do registrador R26

my_loop:
    LD R20, Z       ; Carrega o valor da memória apontada por Z em R20
    ADD R16, R20    ; Soma o valor de R20 ao acumulador em R16 (sem considerar carry)
    INC R17         ; Incrementa o contador em R17

    CP R16, R18     ; Compara o valor do acumulador com o limite em R18
    BRSH end        ; Sai do loop se a soma for maior ou igual ao limite

    INC R26         ; Incrementa o endereço de memória para apontar para o próximo número
    jmp my_loop    ; Salta de volta para o início do loop se o resultado do salto não for zero

end:
    ; Aqui você pode adicionar o código para lidar com o resultado da soma
    ; O valor final da soma estará em R16


Loop:
	rjmp loop
;
; End of source code
