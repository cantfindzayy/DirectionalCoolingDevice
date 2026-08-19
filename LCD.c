
TemperatureReadingFan.elf:     file format elf32-littlearm

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .isr_vector   0000018c  08000000  08000000  00001000  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  1 .text         00001790  08000190  08000190  00001190  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  2 .rodata       00000080  08001920  08001920  00002920  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  3 .ARM.extab    00000000  080019a0  080019a0  00003050  2**0
                  CONTENTS, READONLY
  4 .ARM          00000008  080019a0  080019a0  000029a0  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  5 .preinit_array 00000000  080019a8  080019a8  00003050  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  6 .init_array   00000004  080019a8  080019a8  000029a8  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  7 .fini_array   00000004  080019ac  080019ac  000029ac  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  8 .data         00000050  20000000  080019b0  00003000  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  9 .sram2        00000000  10000000  10000000  00003050  2**0
                  CONTENTS
 10 .bss          00000188  20000050  20000050  00003050  2**2
                  ALLOC
 11 ._user_heap_stack 00000600  200001d8  200001d8  00003050  2**0
                  ALLOC
 12 .ARM.attributes 00000030  00000000  00000000  00003050  2**0
                  CONTENTS, READONLY
 13 .debug_info   00001b94  00000000  00000000  00003080  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 14 .debug_abbrev 00000789  00000000  00000000  00004c14  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 15 .debug_aranges 000001b8  00000000  00000000  000053a0  2**3
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 16 .debug_rnglists 00000138  00000000  00000000  00005558  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 17 .debug_macro  0001d511  00000000  00000000  00005690  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 18 .debug_line   00001ef0  00000000  00000000  00022ba1  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 19 .debug_str    000a2b94  00000000  00000000  00024a91  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 20 .comment      00000043  00000000  00000000  000c7625  2**0
                  CONTENTS, READONLY
 21 .debug_frame  00000ab0  00000000  00000000  000c7668  2**2
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 22 .debug_line_str 00000067  00000000  00000000  000c8118  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS

Disassembly of section .text:

08000190 <__do_global_dtors_aux>:
 8000190:	b510      	push	{r4, lr}
 8000192:	4c05      	ldr	r4, [pc, #20]	@ (80001a8 <__do_global_dtors_aux+0x18>)
 8000194:	7823      	ldrb	r3, [r4, #0]
 8000196:	b933      	cbnz	r3, 80001a6 <__do_global_dtors_aux+0x16>
 8000198:	4b04      	ldr	r3, [pc, #16]	@ (80001ac <__do_global_dtors_aux+0x1c>)
 800019a:	b113      	cbz	r3, 80001a2 <__do_global_dtors_aux+0x12>
 800019c:	4804      	ldr	r0, [pc, #16]	@ (80001b0 <__do_global_dtors_aux+0x20>)
 800019e:	f3af 8000 	nop.w
 80001a2:	2301      	movs	r3, #1
 80001a4:	7023      	strb	r3, [r4, #0]
 80001a6:	bd10      	pop	{r4, pc}
 80001a8:	20000050 	.word	0x20000050
 80001ac:	00000000 	.word	0x00000000
 80001b0:	08001908 	.word	0x08001908

080001b4 <frame_dummy>:
 80001b4:	b508      	push	{r3, lr}
 80001b6:	4b03      	ldr	r3, [pc, #12]	@ (80001c4 <frame_dummy+0x10>)
 80001b8:	b11b      	cbz	r3, 80001c2 <frame_dummy+0xe>
 80001ba:	4903      	ldr	r1, [pc, #12]	@ (80001c8 <frame_dummy+0x14>)
 80001bc:	4803      	ldr	r0, [pc, #12]	@ (80001cc <frame_dummy+0x18>)
 80001be:	f3af 8000 	nop.w
 80001c2:	bd08      	pop	{r3, pc}
 80001c4:	00000000 	.word	0x00000000
 80001c8:	20000054 	.word	0x20000054
 80001cc:	08001908 	.word	0x08001908

080001d0 <memchr>:
 80001d0:	f001 01ff 	and.w	r1, r1, #255	@ 0xff
 80001d4:	2a10      	cmp	r2, #16
 80001d6:	db2b      	blt.n	8000230 <memchr+0x60>
 80001d8:	f010 0f07 	tst.w	r0, #7
 80001dc:	d008      	beq.n	80001f0 <memchr+0x20>
 80001de:	f810 3b01 	ldrb.w	r3, [r0], #1
 80001e2:	3a01      	subs	r2, #1
 80001e4:	428b      	cmp	r3, r1
 80001e6:	d02d      	beq.n	8000244 <memchr+0x74>
 80001e8:	f010 0f07 	tst.w	r0, #7
 80001ec:	b342      	cbz	r2, 8000240 <memchr+0x70>
 80001ee:	d1f6      	bne.n	80001de <memchr+0xe>
 80001f0:	b4f0      	push	{r4, r5, r6, r7}
 80001f2:	ea41 2101 	orr.w	r1, r1, r1, lsl #8
 80001f6:	ea41 4101 	orr.w	r1, r1, r1, lsl #16
 80001fa:	f022 0407 	bic.w	r4, r2, #7
 80001fe:	f07f 0700 	mvns.w	r7, #0
 8000202:	2300      	movs	r3, #0
 8000204:	e8f0 5602 	ldrd	r5, r6, [r0], #8
 8000208:	3c08      	subs	r4, #8
 800020a:	ea85 0501 	eor.w	r5, r5, r1
 800020e:	ea86 0601 	eor.w	r6, r6, r1
 8000212:	fa85 f547 	uadd8	r5, r5, r7
 8000216:	faa3 f587 	sel	r5, r3, r7
 800021a:	fa86 f647 	uadd8	r6, r6, r7
 800021e:	faa5 f687 	sel	r6, r5, r7
 8000222:	b98e      	cbnz	r6, 8000248 <memchr+0x78>
 8000224:	d1ee      	bne.n	8000204 <memchr+0x34>
 8000226:	bcf0      	pop	{r4, r5, r6, r7}
 8000228:	f001 01ff 	and.w	r1, r1, #255	@ 0xff
 800022c:	f002 0207 	and.w	r2, r2, #7
 8000230:	b132      	cbz	r2, 8000240 <memchr+0x70>
 8000232:	f810 3b01 	ldrb.w	r3, [r0], #1
 8000236:	3a01      	subs	r2, #1
 8000238:	ea83 0301 	eor.w	r3, r3, r1
 800023c:	b113      	cbz	r3, 8000244 <memchr+0x74>
 800023e:	d1f8      	bne.n	8000232 <memchr+0x62>
 8000240:	2000      	movs	r0, #0
 8000242:	4770      	bx	lr
 8000244:	3801      	subs	r0, #1
 8000246:	4770      	bx	lr
 8000248:	2d00      	cmp	r5, #0
 800024a:	bf06      	itte	eq
 800024c:	4635      	moveq	r5, r6
 800024e:	3803      	subeq	r0, #3
 8000250:	3807      	subne	r0, #7
 8000252:	f015 0f01 	tst.w	r5, #1
 8000256:	d107      	bne.n	8000268 <memchr+0x98>
 8000258:	3001      	adds	r0, #1
 800025a:	f415 7f80 	tst.w	r5, #256	@ 0x100
 800025e:	bf02      	ittt	eq
 8000260:	3001      	addeq	r0, #1
 8000262:	f415 3fc0 	tsteq.w	r5, #98304	@ 0x18000
 8000266:	3001      	addeq	r0, #1
 8000268:	bcf0      	pop	{r4, r5, r6, r7}
 800026a:	3801      	subs	r0, #1
 800026c:	4770      	bx	lr
 800026e:	bf00      	nop

08000270 <DWT_Delay_Init>:
 *
 * Enables the Cortex-M4 DWT cycle counter.
 * This lets us create accurate microsecond delays.
 * ---------------------------------------------------- */
void DWT_Delay_Init(void)
{
 8000270:	b480      	push	{r7}
 8000272:	af00      	add	r7, sp, #0
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
 8000274:	4b09      	ldr	r3, [pc, #36]	@ (800029c <DWT_Delay_Init+0x2c>)
 8000276:	68db      	ldr	r3, [r3, #12]
 8000278:	4a08      	ldr	r2, [pc, #32]	@ (800029c <DWT_Delay_Init+0x2c>)
 800027a:	f043 7380 	orr.w	r3, r3, #16777216	@ 0x1000000
 800027e:	60d3      	str	r3, [r2, #12]

    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
 8000280:	4b07      	ldr	r3, [pc, #28]	@ (80002a0 <DWT_Delay_Init+0x30>)
 8000282:	681b      	ldr	r3, [r3, #0]
 8000284:	4a06      	ldr	r2, [pc, #24]	@ (80002a0 <DWT_Delay_Init+0x30>)
 8000286:	f043 0301 	orr.w	r3, r3, #1
 800028a:	6013      	str	r3, [r2, #0]
    DWT->CYCCNT = 0;
 800028c:	4b04      	ldr	r3, [pc, #16]	@ (80002a0 <DWT_Delay_Init+0x30>)
 800028e:	2200      	movs	r2, #0
 8000290:	605a      	str	r2, [r3, #4]
}
 8000292:	bf00      	nop
 8000294:	46bd      	mov	sp, r7
 8000296:	f85d 7b04 	ldr.w	r7, [sp], #4
 800029a:	4770      	bx	lr
 800029c:	e000edf0 	.word	0xe000edf0
 80002a0:	e0001000 	.word	0xe0001000

080002a4 <delay_us>:
 * This version assumes system clock = HSI 16 MHz.
 * At 16 MHz:
 *   1 microsecond = 16 CPU cycles
 * ---------------------------------------------------- */
void delay_us(uint32_t us)
{
 80002a4:	b580      	push	{r7, lr}
 80002a6:	b084      	sub	sp, #16
 80002a8:	af00      	add	r7, sp, #0
 80002aa:	6078      	str	r0, [r7, #4]
    uint32_t ticks;

    /*
     * Safety: make sure cycle counter is enabled.
     */
    if ((DWT->CTRL & DWT_CTRL_CYCCNTENA_Msk) == 0)
 80002ac:	4b0d      	ldr	r3, [pc, #52]	@ (80002e4 <delay_us+0x40>)
 80002ae:	681b      	ldr	r3, [r3, #0]
 80002b0:	f003 0301 	and.w	r3, r3, #1
 80002b4:	2b00      	cmp	r3, #0
 80002b6:	d101      	bne.n	80002bc <delay_us+0x18>
    {
        DWT_Delay_Init();
 80002b8:	f7ff ffda 	bl	8000270 <DWT_Delay_Init>
    }

    start = DWT->CYCCNT;
 80002bc:	4b09      	ldr	r3, [pc, #36]	@ (80002e4 <delay_us+0x40>)
 80002be:	685b      	ldr	r3, [r3, #4]
 80002c0:	60fb      	str	r3, [r7, #12]
    ticks = us * 16U;
 80002c2:	687b      	ldr	r3, [r7, #4]
 80002c4:	011b      	lsls	r3, r3, #4
 80002c6:	60bb      	str	r3, [r7, #8]

    while ((DWT->CYCCNT - start) < ticks)
 80002c8:	bf00      	nop
 80002ca:	4b06      	ldr	r3, [pc, #24]	@ (80002e4 <delay_us+0x40>)
 80002cc:	685a      	ldr	r2, [r3, #4]
 80002ce:	68fb      	ldr	r3, [r7, #12]
 80002d0:	1ad3      	subs	r3, r2, r3
 80002d2:	68ba      	ldr	r2, [r7, #8]
 80002d4:	429a      	cmp	r2, r3
 80002d6:	d8f8      	bhi.n	80002ca <delay_us+0x26>
    {
        /*
         * wait
         */
    }
}
 80002d8:	bf00      	nop
 80002da:	bf00      	nop
 80002dc:	3710      	adds	r7, #16
 80002de:	46bd      	mov	sp, r7
 80002e0:	bd80      	pop	{r7, pc}
 80002e2:	bf00      	nop
 80002e4:	e0001000 	.word	0xe0001000

080002e8 <DHT_SetPinOutput>:
 * Configure D7 / PA8 as output open-drain.
 *
 * Used when STM32 pulls DHT22 DATA line LOW.
 * ---------------------------------------------------- */
static void DHT_SetPinOutput(void)
{
 80002e8:	b480      	push	{r7}
 80002ea:	af00      	add	r7, sp, #0
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
 80002ec:	4b1a      	ldr	r3, [pc, #104]	@ (8000358 <DHT_SetPinOutput+0x70>)
 80002ee:	6cdb      	ldr	r3, [r3, #76]	@ 0x4c
 80002f0:	4a19      	ldr	r2, [pc, #100]	@ (8000358 <DHT_SetPinOutput+0x70>)
 80002f2:	f043 0304 	orr.w	r3, r3, #4
 80002f6:	64d3      	str	r3, [r2, #76]	@ 0x4c

    DHT_PORT->MODER &= ~(0b11 << (2 * DHT_PIN));
 80002f8:	4b18      	ldr	r3, [pc, #96]	@ (800035c <DHT_SetPinOutput+0x74>)
 80002fa:	681b      	ldr	r3, [r3, #0]
 80002fc:	4a17      	ldr	r2, [pc, #92]	@ (800035c <DHT_SetPinOutput+0x74>)
 80002fe:	f023 0303 	bic.w	r3, r3, #3
 8000302:	6013      	str	r3, [r2, #0]
    DHT_PORT->MODER |=  (0b01 << (2 * DHT_PIN));
 8000304:	4b15      	ldr	r3, [pc, #84]	@ (800035c <DHT_SetPinOutput+0x74>)
 8000306:	681b      	ldr	r3, [r3, #0]
 8000308:	4a14      	ldr	r2, [pc, #80]	@ (800035c <DHT_SetPinOutput+0x74>)
 800030a:	f043 0301 	orr.w	r3, r3, #1
 800030e:	6013      	str	r3, [r2, #0]

    DHT_PORT->OTYPER |= (1 << DHT_PIN);          // open-drain
 8000310:	4b12      	ldr	r3, [pc, #72]	@ (800035c <DHT_SetPinOutput+0x74>)
 8000312:	685b      	ldr	r3, [r3, #4]
 8000314:	4a11      	ldr	r2, [pc, #68]	@ (800035c <DHT_SetPinOutput+0x74>)
 8000316:	f043 0301 	orr.w	r3, r3, #1
 800031a:	6053      	str	r3, [r2, #4]
    DHT_PORT->PUPDR &= ~(0b11 << (2 * DHT_PIN)); // no pull
 800031c:	4b0f      	ldr	r3, [pc, #60]	@ (800035c <DHT_SetPinOutput+0x74>)
 800031e:	68db      	ldr	r3, [r3, #12]
 8000320:	4a0e      	ldr	r2, [pc, #56]	@ (800035c <DHT_SetPinOutput+0x74>)
 8000322:	f023 0303 	bic.w	r3, r3, #3
 8000326:	60d3      	str	r3, [r2, #12]

    DHT_PORT->OSPEEDR &= ~(0b11 << (2 * DHT_PIN));
 8000328:	4b0c      	ldr	r3, [pc, #48]	@ (800035c <DHT_SetPinOutput+0x74>)
 800032a:	689b      	ldr	r3, [r3, #8]
 800032c:	4a0b      	ldr	r2, [pc, #44]	@ (800035c <DHT_SetPinOutput+0x74>)
 800032e:	f023 0303 	bic.w	r3, r3, #3
 8000332:	6093      	str	r3, [r2, #8]
    DHT_PORT->OSPEEDR |=  (0b10 << (2 * DHT_PIN));
 8000334:	4b09      	ldr	r3, [pc, #36]	@ (800035c <DHT_SetPinOutput+0x74>)
 8000336:	689b      	ldr	r3, [r3, #8]
 8000338:	4a08      	ldr	r2, [pc, #32]	@ (800035c <DHT_SetPinOutput+0x74>)
 800033a:	f043 0302 	orr.w	r3, r3, #2
 800033e:	6093      	str	r3, [r2, #8]

    DHT_PORT->ODR &= ~(1 << DHT_PIN);            // drive low when output
 8000340:	4b06      	ldr	r3, [pc, #24]	@ (800035c <DHT_SetPinOutput+0x74>)
 8000342:	695b      	ldr	r3, [r3, #20]
 8000344:	4a05      	ldr	r2, [pc, #20]	@ (800035c <DHT_SetPinOutput+0x74>)
 8000346:	f023 0301 	bic.w	r3, r3, #1
 800034a:	6153      	str	r3, [r2, #20]
}
 800034c:	bf00      	nop
 800034e:	46bd      	mov	sp, r7
 8000350:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000354:	4770      	bx	lr
 8000356:	bf00      	nop
 8000358:	40021000 	.word	0x40021000
 800035c:	48000800 	.word	0x48000800

08000360 <DHT_SetPinInput>:
 * Configure D7 / PA8 as input with pull-up.
 *
 * This is the idle/listening state.
 * ---------------------------------------------------- */
void DHT_SetPinInput(void)
{
 8000360:	b480      	push	{r7}
 8000362:	af00      	add	r7, sp, #0
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
 8000364:	4b0b      	ldr	r3, [pc, #44]	@ (8000394 <DHT_SetPinInput+0x34>)
 8000366:	6cdb      	ldr	r3, [r3, #76]	@ 0x4c
 8000368:	4a0a      	ldr	r2, [pc, #40]	@ (8000394 <DHT_SetPinInput+0x34>)
 800036a:	f043 0304 	orr.w	r3, r3, #4
 800036e:	64d3      	str	r3, [r2, #76]	@ 0x4c

    DHT_PORT->MODER &= ~(0b11 << (2 * DHT_PIN));
 8000370:	4b09      	ldr	r3, [pc, #36]	@ (8000398 <DHT_SetPinInput+0x38>)
 8000372:	681b      	ldr	r3, [r3, #0]
 8000374:	4a08      	ldr	r2, [pc, #32]	@ (8000398 <DHT_SetPinInput+0x38>)
 8000376:	f023 0303 	bic.w	r3, r3, #3
 800037a:	6013      	str	r3, [r2, #0]

    /* No internal pull-up/pull-down */
    DHT_PORT->PUPDR &= ~(0b11 << (2 * DHT_PIN));
 800037c:	4b06      	ldr	r3, [pc, #24]	@ (8000398 <DHT_SetPinInput+0x38>)
 800037e:	68db      	ldr	r3, [r3, #12]
 8000380:	4a05      	ldr	r2, [pc, #20]	@ (8000398 <DHT_SetPinInput+0x38>)
 8000382:	f023 0303 	bic.w	r3, r3, #3
 8000386:	60d3      	str	r3, [r2, #12]
}
 8000388:	bf00      	nop
 800038a:	46bd      	mov	sp, r7
 800038c:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000390:	4770      	bx	lr
 8000392:	bf00      	nop
 8000394:	40021000 	.word	0x40021000
 8000398:	48000800 	.word	0x48000800

0800039c <DHT_PinLow>:
/* Drive PA8 LOW */
static void DHT_PinLow(void)
{
 800039c:	b480      	push	{r7}
 800039e:	af00      	add	r7, sp, #0
    DHT_PORT->ODR &= ~(1 << DHT_PIN);
 80003a0:	4b05      	ldr	r3, [pc, #20]	@ (80003b8 <DHT_PinLow+0x1c>)
 80003a2:	695b      	ldr	r3, [r3, #20]
 80003a4:	4a04      	ldr	r2, [pc, #16]	@ (80003b8 <DHT_PinLow+0x1c>)
 80003a6:	f023 0301 	bic.w	r3, r3, #1
 80003aa:	6153      	str	r3, [r2, #20]
}
 80003ac:	bf00      	nop
 80003ae:	46bd      	mov	sp, r7
 80003b0:	f85d 7b04 	ldr.w	r7, [sp], #4
 80003b4:	4770      	bx	lr
 80003b6:	bf00      	nop
 80003b8:	48000800 	.word	0x48000800

080003bc <DHT_ReadPin>:
    DHT_PORT->ODR |= (1 << DHT_PIN);
}

/* Read PA8 input state */
static uint8_t DHT_ReadPin(void)
{
 80003bc:	b480      	push	{r7}
 80003be:	af00      	add	r7, sp, #0
    if (DHT_PORT->IDR & (1 << DHT_PIN))
 80003c0:	4b06      	ldr	r3, [pc, #24]	@ (80003dc <DHT_ReadPin+0x20>)
 80003c2:	691b      	ldr	r3, [r3, #16]
 80003c4:	f003 0301 	and.w	r3, r3, #1
 80003c8:	2b00      	cmp	r3, #0
 80003ca:	d001      	beq.n	80003d0 <DHT_ReadPin+0x14>
        return 1;
 80003cc:	2301      	movs	r3, #1
 80003ce:	e000      	b.n	80003d2 <DHT_ReadPin+0x16>
    else
        return 0;
 80003d0:	2300      	movs	r3, #0
}
 80003d2:	4618      	mov	r0, r3
 80003d4:	46bd      	mov	sp, r7
 80003d6:	f85d 7b04 	ldr.w	r7, [sp], #4
 80003da:	4770      	bx	lr
 80003dc:	48000800 	.word	0x48000800

080003e0 <DHT_Start>:
 * DHT22:
 *   DATA LOW for > 1 ms
 *   DATA HIGH for 20-40 us
 * ---------------------------------------------------- */
static void DHT_Start(void)
{
 80003e0:	b580      	push	{r7, lr}
 80003e2:	af00      	add	r7, sp, #0
    DHT_SetPinOutput();
 80003e4:	f7ff ff80 	bl	80002e8 <DHT_SetPinOutput>

    DHT_PinLow();
 80003e8:	f7ff ffd8 	bl	800039c <DHT_PinLow>
    delay_us(2000);   // 2 ms for DHT22
 80003ec:	f44f 60fa 	mov.w	r0, #2000	@ 0x7d0
 80003f0:	f7ff ff58 	bl	80002a4 <delay_us>

    DHT_SetPinInput();
 80003f4:	f7ff ffb4 	bl	8000360 <DHT_SetPinInput>

    delay_us(40);
 80003f8:	2028      	movs	r0, #40	@ 0x28
 80003fa:	f7ff ff53 	bl	80002a4 <delay_us>
}
 80003fe:	bf00      	nop
 8000400:	bd80      	pop	{r7, pc}

08000402 <wait_for_pin>:
 * Returns:
 *   1 = response received
 *   0 = no response
 * ---------------------------------------------------- */
static uint8_t wait_for_pin(uint8_t state, uint32_t timeout_us)
{
 8000402:	b580      	push	{r7, lr}
 8000404:	b082      	sub	sp, #8
 8000406:	af00      	add	r7, sp, #0
 8000408:	4603      	mov	r3, r0
 800040a:	6039      	str	r1, [r7, #0]
 800040c:	71fb      	strb	r3, [r7, #7]
    while (timeout_us--)
 800040e:	e00b      	b.n	8000428 <wait_for_pin+0x26>
    {
        if (DHT_ReadPin() == state)
 8000410:	f7ff ffd4 	bl	80003bc <DHT_ReadPin>
 8000414:	4603      	mov	r3, r0
 8000416:	461a      	mov	r2, r3
 8000418:	79fb      	ldrb	r3, [r7, #7]
 800041a:	4293      	cmp	r3, r2
 800041c:	d101      	bne.n	8000422 <wait_for_pin+0x20>
        {
            return 1;
 800041e:	2301      	movs	r3, #1
 8000420:	e008      	b.n	8000434 <wait_for_pin+0x32>
        }

        delay_us(1);
 8000422:	2001      	movs	r0, #1
 8000424:	f7ff ff3e 	bl	80002a4 <delay_us>
    while (timeout_us--)
 8000428:	683b      	ldr	r3, [r7, #0]
 800042a:	1e5a      	subs	r2, r3, #1
 800042c:	603a      	str	r2, [r7, #0]
 800042e:	2b00      	cmp	r3, #0
 8000430:	d1ee      	bne.n	8000410 <wait_for_pin+0xe>
    }

    return 0;
 8000432:	2300      	movs	r3, #0
}
 8000434:	4618      	mov	r0, r3
 8000436:	3708      	adds	r7, #8
 8000438:	46bd      	mov	sp, r7
 800043a:	bd80      	pop	{r7, pc}

0800043c <delay_ms_simple>:
/* ----------------------------------------------------
 * Simple millisecond delay.
 * Used only for LCD screen timing.
 * ---------------------------------------------------- */
static void delay_ms_simple(uint32_t ms)
{
 800043c:	b580      	push	{r7, lr}
 800043e:	b084      	sub	sp, #16
 8000440:	af00      	add	r7, sp, #0
 8000442:	6078      	str	r0, [r7, #4]
    for (uint32_t i = 0; i < ms; i++)
 8000444:	2300      	movs	r3, #0
 8000446:	60fb      	str	r3, [r7, #12]
 8000448:	e006      	b.n	8000458 <delay_ms_simple+0x1c>
    {
        delay_us(1000);
 800044a:	f44f 707a 	mov.w	r0, #1000	@ 0x3e8
 800044e:	f7ff ff29 	bl	80002a4 <delay_us>
    for (uint32_t i = 0; i < ms; i++)
 8000452:	68fb      	ldr	r3, [r7, #12]
 8000454:	3301      	adds	r3, #1
 8000456:	60fb      	str	r3, [r7, #12]
 8000458:	68fa      	ldr	r2, [r7, #12]
 800045a:	687b      	ldr	r3, [r7, #4]
 800045c:	429a      	cmp	r2, r3
 800045e:	d3f4      	bcc.n	800044a <delay_ms_simple+0xe>
    }
}
 8000460:	bf00      	nop
 8000462:	bf00      	nop
 8000464:	3710      	adds	r7, #16
 8000466:	46bd      	mov	sp, r7
 8000468:	bd80      	pop	{r7, pc}

0800046a <DHT_Check_Response>:

static uint8_t DHT_Check_Response(void)
{
 800046a:	b580      	push	{r7, lr}
 800046c:	af00      	add	r7, sp, #0
    /* DHT22 should pull line LOW after host releases it */
    if (!wait_for_pin(0, 500))
 800046e:	f44f 71fa 	mov.w	r1, #500	@ 0x1f4
 8000472:	2000      	movs	r0, #0
 8000474:	f7ff ffc5 	bl	8000402 <wait_for_pin>
 8000478:	4603      	mov	r3, r0
 800047a:	2b00      	cmp	r3, #0
 800047c:	d101      	bne.n	8000482 <DHT_Check_Response+0x18>
    {
        return 0;
 800047e:	2300      	movs	r3, #0
 8000480:	e014      	b.n	80004ac <DHT_Check_Response+0x42>
    }

    /* DHT22 then pulls line HIGH */
    if (!wait_for_pin(1, 500))
 8000482:	f44f 71fa 	mov.w	r1, #500	@ 0x1f4
 8000486:	2001      	movs	r0, #1
 8000488:	f7ff ffbb 	bl	8000402 <wait_for_pin>
 800048c:	4603      	mov	r3, r0
 800048e:	2b00      	cmp	r3, #0
 8000490:	d101      	bne.n	8000496 <DHT_Check_Response+0x2c>
    {
        return 0;
 8000492:	2300      	movs	r3, #0
 8000494:	e00a      	b.n	80004ac <DHT_Check_Response+0x42>
    }

    /* DHT22 then pulls line LOW again before sending data bits */
    if (!wait_for_pin(0, 500))
 8000496:	f44f 71fa 	mov.w	r1, #500	@ 0x1f4
 800049a:	2000      	movs	r0, #0
 800049c:	f7ff ffb1 	bl	8000402 <wait_for_pin>
 80004a0:	4603      	mov	r3, r0
 80004a2:	2b00      	cmp	r3, #0
 80004a4:	d101      	bne.n	80004aa <DHT_Check_Response+0x40>
    {
        return 0;
 80004a6:	2300      	movs	r3, #0
 80004a8:	e000      	b.n	80004ac <DHT_Check_Response+0x42>
    }

    return 1;
 80004aa:	2301      	movs	r3, #1
}
 80004ac:	4618      	mov	r0, r3
 80004ae:	bd80      	pop	{r7, pc}

080004b0 <DHT_Read>:
 *
 * Short HIGH pulse = 0
 * Long HIGH pulse  = 1
 * ---------------------------------------------------- */
static uint8_t DHT_Read(void)
{
 80004b0:	b580      	push	{r7, lr}
 80004b2:	b082      	sub	sp, #8
 80004b4:	af00      	add	r7, sp, #0
    uint8_t data = 0;
 80004b6:	2300      	movs	r3, #0
 80004b8:	71fb      	strb	r3, [r7, #7]

    for (uint8_t i = 0; i < 8; i++)
 80004ba:	2300      	movs	r3, #0
 80004bc:	71bb      	strb	r3, [r7, #6]
 80004be:	e028      	b.n	8000512 <DHT_Read+0x62>
    {
        if (!wait_for_pin(1, 200))
 80004c0:	21c8      	movs	r1, #200	@ 0xc8
 80004c2:	2001      	movs	r0, #1
 80004c4:	f7ff ff9d 	bl	8000402 <wait_for_pin>
 80004c8:	4603      	mov	r3, r0
 80004ca:	2b00      	cmp	r3, #0
 80004cc:	d101      	bne.n	80004d2 <DHT_Read+0x22>
        {
            return 0;
 80004ce:	2300      	movs	r3, #0
 80004d0:	e023      	b.n	800051a <DHT_Read+0x6a>
        }

        delay_us(40);
 80004d2:	2028      	movs	r0, #40	@ 0x28
 80004d4:	f7ff fee6 	bl	80002a4 <delay_us>

        if (DHT_ReadPin() == 1)
 80004d8:	f7ff ff70 	bl	80003bc <DHT_ReadPin>
 80004dc:	4603      	mov	r3, r0
 80004de:	2b01      	cmp	r3, #1
 80004e0:	d10b      	bne.n	80004fa <DHT_Read+0x4a>
        {
            data |= (1 << (7 - i));
 80004e2:	79bb      	ldrb	r3, [r7, #6]
 80004e4:	f1c3 0307 	rsb	r3, r3, #7
 80004e8:	2201      	movs	r2, #1
 80004ea:	fa02 f303 	lsl.w	r3, r2, r3
 80004ee:	b25a      	sxtb	r2, r3
 80004f0:	f997 3007 	ldrsb.w	r3, [r7, #7]
 80004f4:	4313      	orrs	r3, r2
 80004f6:	b25b      	sxtb	r3, r3
 80004f8:	71fb      	strb	r3, [r7, #7]
        }

        if (!wait_for_pin(0, 200))
 80004fa:	21c8      	movs	r1, #200	@ 0xc8
 80004fc:	2000      	movs	r0, #0
 80004fe:	f7ff ff80 	bl	8000402 <wait_for_pin>
 8000502:	4603      	mov	r3, r0
 8000504:	2b00      	cmp	r3, #0
 8000506:	d101      	bne.n	800050c <DHT_Read+0x5c>
        {
            return 0;
 8000508:	2300      	movs	r3, #0
 800050a:	e006      	b.n	800051a <DHT_Read+0x6a>
    for (uint8_t i = 0; i < 8; i++)
 800050c:	79bb      	ldrb	r3, [r7, #6]
 800050e:	3301      	adds	r3, #1
 8000510:	71bb      	strb	r3, [r7, #6]
 8000512:	79bb      	ldrb	r3, [r7, #6]
 8000514:	2b07      	cmp	r3, #7
 8000516:	d9d3      	bls.n	80004c0 <DHT_Read+0x10>
        }
    }

    return data;
 8000518:	79fb      	ldrb	r3, [r7, #7]
}
 800051a:	4618      	mov	r0, r3
 800051c:	3708      	adds	r7, #8
 800051e:	46bd      	mov	sp, r7
 8000520:	bd80      	pop	{r7, pc}
	...

08000524 <DHT_Display>:
 *   - Simple LCD bar graphs
 *
 * This avoids %f printing.
 * ---------------------------------------------------- */
void DHT_Display(void)
{
 8000524:	b580      	push	{r7, lr}
 8000526:	b086      	sub	sp, #24
 8000528:	af00      	add	r7, sp, #0
    uint8_t checksum;
    uint8_t calculated;
    uint8_t Humidity;
	uint8_t temperature;

    lcd_clear();
 800052a:	f000 fa52 	bl	80009d2 <lcd_clear>
    lcd_put_cur(0, 0);
 800052e:	2100      	movs	r1, #0
 8000530:	2000      	movs	r0, #0
 8000532:	f000 fa58 	bl	80009e6 <lcd_put_cur>
    lcd_send_string("Reading DHT");
 8000536:	4847      	ldr	r0, [pc, #284]	@ (8000654 <DHT_Display+0x130>)
 8000538:	f000 fa6f 	bl	8000a1a <lcd_send_string>

    DHT_Start();
 800053c:	f7ff ff50 	bl	80003e0 <DHT_Start>

    if (DHT_Check_Response())
 8000540:	f7ff ff93 	bl	800046a <DHT_Check_Response>
 8000544:	4603      	mov	r3, r0
 8000546:	2b00      	cmp	r3, #0
 8000548:	d072      	beq.n	8000630 <DHT_Display+0x10c>
    {
        /*
         * Read all 5 bytes immediately.
         * Do not put LCD prints or delays between these.
         */
        Rh_byte1   = DHT_Read();
 800054a:	f7ff ffb1 	bl	80004b0 <DHT_Read>
 800054e:	4603      	mov	r3, r0
 8000550:	461a      	mov	r2, r3
 8000552:	4b41      	ldr	r3, [pc, #260]	@ (8000658 <DHT_Display+0x134>)
 8000554:	701a      	strb	r2, [r3, #0]
        Rh_byte2   = DHT_Read();
 8000556:	f7ff ffab 	bl	80004b0 <DHT_Read>
 800055a:	4603      	mov	r3, r0
 800055c:	461a      	mov	r2, r3
 800055e:	4b3f      	ldr	r3, [pc, #252]	@ (800065c <DHT_Display+0x138>)
 8000560:	701a      	strb	r2, [r3, #0]
        Temp_byte1 = DHT_Read();
 8000562:	f7ff ffa5 	bl	80004b0 <DHT_Read>
 8000566:	4603      	mov	r3, r0
 8000568:	461a      	mov	r2, r3
 800056a:	4b3d      	ldr	r3, [pc, #244]	@ (8000660 <DHT_Display+0x13c>)
 800056c:	701a      	strb	r2, [r3, #0]
        Temp_byte2 = DHT_Read();
 800056e:	f7ff ff9f 	bl	80004b0 <DHT_Read>
 8000572:	4603      	mov	r3, r0
 8000574:	461a      	mov	r2, r3
 8000576:	4b3b      	ldr	r3, [pc, #236]	@ (8000664 <DHT_Display+0x140>)
 8000578:	701a      	strb	r2, [r3, #0]
        checksum   = DHT_Read();
 800057a:	f7ff ff99 	bl	80004b0 <DHT_Read>
 800057e:	4603      	mov	r3, r0
 8000580:	75fb      	strb	r3, [r7, #23]

        RH = ((uint16_t)Rh_byte1 << 8) | Rh_byte2;
 8000582:	4b35      	ldr	r3, [pc, #212]	@ (8000658 <DHT_Display+0x134>)
 8000584:	781b      	ldrb	r3, [r3, #0]
 8000586:	b21b      	sxth	r3, r3
 8000588:	021b      	lsls	r3, r3, #8
 800058a:	b21a      	sxth	r2, r3
 800058c:	4b33      	ldr	r3, [pc, #204]	@ (800065c <DHT_Display+0x138>)
 800058e:	781b      	ldrb	r3, [r3, #0]
 8000590:	b21b      	sxth	r3, r3
 8000592:	4313      	orrs	r3, r2
 8000594:	b21b      	sxth	r3, r3
 8000596:	b29a      	uxth	r2, r3
 8000598:	4b33      	ldr	r3, [pc, #204]	@ (8000668 <DHT_Display+0x144>)
 800059a:	801a      	strh	r2, [r3, #0]
        TEMP = ((uint16_t)Temp_byte1 << 8) | Temp_byte2;
 800059c:	4b30      	ldr	r3, [pc, #192]	@ (8000660 <DHT_Display+0x13c>)
 800059e:	781b      	ldrb	r3, [r3, #0]
 80005a0:	b21b      	sxth	r3, r3
 80005a2:	021b      	lsls	r3, r3, #8
 80005a4:	b21a      	sxth	r2, r3
 80005a6:	4b2f      	ldr	r3, [pc, #188]	@ (8000664 <DHT_Display+0x140>)
 80005a8:	781b      	ldrb	r3, [r3, #0]
 80005aa:	b21b      	sxth	r3, r3
 80005ac:	4313      	orrs	r3, r2
 80005ae:	b21b      	sxth	r3, r3
 80005b0:	b29a      	uxth	r2, r3
 80005b2:	4b2e      	ldr	r3, [pc, #184]	@ (800066c <DHT_Display+0x148>)
 80005b4:	801a      	strh	r2, [r3, #0]

        temperature = RH / 10;
 80005b6:	4b2c      	ldr	r3, [pc, #176]	@ (8000668 <DHT_Display+0x144>)
 80005b8:	881b      	ldrh	r3, [r3, #0]
 80005ba:	4a2d      	ldr	r2, [pc, #180]	@ (8000670 <DHT_Display+0x14c>)
 80005bc:	fba2 2303 	umull	r2, r3, r2, r3
 80005c0:	08db      	lsrs	r3, r3, #3
 80005c2:	b29b      	uxth	r3, r3
 80005c4:	75bb      	strb	r3, [r7, #22]
        Humidity = TEMP / 10;
 80005c6:	4b29      	ldr	r3, [pc, #164]	@ (800066c <DHT_Display+0x148>)
 80005c8:	881b      	ldrh	r3, [r3, #0]
 80005ca:	4a29      	ldr	r2, [pc, #164]	@ (8000670 <DHT_Display+0x14c>)
 80005cc:	fba2 2303 	umull	r2, r3, r2, r3
 80005d0:	08db      	lsrs	r3, r3, #3
 80005d2:	b29b      	uxth	r3, r3
 80005d4:	757b      	strb	r3, [r7, #21]

        calculated = (uint8_t)(Rh_byte1 + Rh_byte2 + Temp_byte1 + Temp_byte2);
 80005d6:	4b20      	ldr	r3, [pc, #128]	@ (8000658 <DHT_Display+0x134>)
 80005d8:	781a      	ldrb	r2, [r3, #0]
 80005da:	4b20      	ldr	r3, [pc, #128]	@ (800065c <DHT_Display+0x138>)
 80005dc:	781b      	ldrb	r3, [r3, #0]
 80005de:	4413      	add	r3, r2
 80005e0:	b2da      	uxtb	r2, r3
 80005e2:	4b1f      	ldr	r3, [pc, #124]	@ (8000660 <DHT_Display+0x13c>)
 80005e4:	781b      	ldrb	r3, [r3, #0]
 80005e6:	4413      	add	r3, r2
 80005e8:	b2da      	uxtb	r2, r3
 80005ea:	4b1e      	ldr	r3, [pc, #120]	@ (8000664 <DHT_Display+0x140>)
 80005ec:	781b      	ldrb	r3, [r3, #0]
 80005ee:	4413      	add	r3, r2
 80005f0:	753b      	strb	r3, [r7, #20]

        lcd_clear();
 80005f2:	f000 f9ee 	bl	80009d2 <lcd_clear>

        lcd_put_cur(0, 0);
 80005f6:	2100      	movs	r1, #0
 80005f8:	2000      	movs	r0, #0
 80005fa:	f000 f9f4 	bl	80009e6 <lcd_put_cur>
        snprintf(buffer,
 80005fe:	7d7b      	ldrb	r3, [r7, #21]
 8000600:	4638      	mov	r0, r7
 8000602:	4a1c      	ldr	r2, [pc, #112]	@ (8000674 <DHT_Display+0x150>)
 8000604:	2111      	movs	r1, #17
 8000606:	f000 fcd3 	bl	8000fb0 <sniprintf>
                 sizeof(buffer),
                 "Humidity:%3d",
                 Humidity);
        lcd_send_string(buffer);
 800060a:	463b      	mov	r3, r7
 800060c:	4618      	mov	r0, r3
 800060e:	f000 fa04 	bl	8000a1a <lcd_send_string>

        lcd_put_cur(1, 0);
 8000612:	2100      	movs	r1, #0
 8000614:	2001      	movs	r0, #1
 8000616:	f000 f9e6 	bl	80009e6 <lcd_put_cur>
        snprintf(buffer,
 800061a:	7dbb      	ldrb	r3, [r7, #22]
 800061c:	4638      	mov	r0, r7
 800061e:	4a16      	ldr	r2, [pc, #88]	@ (8000678 <DHT_Display+0x154>)
 8000620:	2111      	movs	r1, #17
 8000622:	f000 fcc5 	bl	8000fb0 <sniprintf>
                 sizeof(buffer),
                 "Temperature:%2d",
                 temperature);
        lcd_send_string(buffer);
 8000626:	463b      	mov	r3, r7
 8000628:	4618      	mov	r0, r3
 800062a:	f000 f9f6 	bl	8000a1a <lcd_send_string>
 800062e:	e008      	b.n	8000642 <DHT_Display+0x11e>
    }
    else
    {
        lcd_clear();
 8000630:	f000 f9cf 	bl	80009d2 <lcd_clear>
        lcd_put_cur(0, 0);
 8000634:	2100      	movs	r1, #0
 8000636:	2000      	movs	r0, #0
 8000638:	f000 f9d5 	bl	80009e6 <lcd_put_cur>
        lcd_send_string("No Response");
 800063c:	480f      	ldr	r0, [pc, #60]	@ (800067c <DHT_Display+0x158>)
 800063e:	f000 f9ec 	bl	8000a1a <lcd_send_string>
    }

    delay_ms_simple(3000);
 8000642:	f640 30b8 	movw	r0, #3000	@ 0xbb8
 8000646:	f7ff fef9 	bl	800043c <delay_ms_simple>
}
 800064a:	bf00      	nop
 800064c:	3718      	adds	r7, #24
 800064e:	46bd      	mov	sp, r7
 8000650:	bd80      	pop	{r7, pc}
 8000652:	bf00      	nop
 8000654:	08001928 	.word	0x08001928
 8000658:	2000006c 	.word	0x2000006c
 800065c:	2000006d 	.word	0x2000006d
 8000660:	2000006e 	.word	0x2000006e
 8000664:	2000006f 	.word	0x2000006f
 8000668:	20000070 	.word	0x20000070
 800066c:	20000072 	.word	0x20000072
 8000670:	cccccccd 	.word	0xcccccccd
 8000674:	08001934 	.word	0x08001934
 8000678:	08001944 	.word	0x08001944
 800067c:	08001954 	.word	0x08001954

08000680 <LCD_Delay>:
 *
 * These are simple blocking delays.
 * They are good enough for LCD timing.
 * ---------------------------------------------------- */
static void LCD_Delay(volatile uint32_t delay)
{
 8000680:	b480      	push	{r7}
 8000682:	b083      	sub	sp, #12
 8000684:	af00      	add	r7, sp, #0
 8000686:	6078      	str	r0, [r7, #4]
    while (delay--);
 8000688:	bf00      	nop
 800068a:	687b      	ldr	r3, [r7, #4]
 800068c:	1e5a      	subs	r2, r3, #1
 800068e:	607a      	str	r2, [r7, #4]
 8000690:	2b00      	cmp	r3, #0
 8000692:	d1fa      	bne.n	800068a <LCD_Delay+0xa>
}
 8000694:	bf00      	nop
 8000696:	bf00      	nop
 8000698:	370c      	adds	r7, #12
 800069a:	46bd      	mov	sp, r7
 800069c:	f85d 7b04 	ldr.w	r7, [sp], #4
 80006a0:	4770      	bx	lr

080006a2 <LCD_Delay_ms>:

static void LCD_Delay_ms(uint32_t ms)
{
 80006a2:	b580      	push	{r7, lr}
 80006a4:	b084      	sub	sp, #16
 80006a6:	af00      	add	r7, sp, #0
 80006a8:	6078      	str	r0, [r7, #4]
    for (uint32_t i = 0; i < ms; i++)
 80006aa:	2300      	movs	r3, #0
 80006ac:	60fb      	str	r3, [r7, #12]
 80006ae:	e006      	b.n	80006be <LCD_Delay_ms+0x1c>
    {
        LCD_Delay(4000);
 80006b0:	f44f 607a 	mov.w	r0, #4000	@ 0xfa0
 80006b4:	f7ff ffe4 	bl	8000680 <LCD_Delay>
    for (uint32_t i = 0; i < ms; i++)
 80006b8:	68fb      	ldr	r3, [r7, #12]
 80006ba:	3301      	adds	r3, #1
 80006bc:	60fb      	str	r3, [r7, #12]
 80006be:	68fa      	ldr	r2, [r7, #12]
 80006c0:	687b      	ldr	r3, [r7, #4]
 80006c2:	429a      	cmp	r2, r3
 80006c4:	d3f4      	bcc.n	80006b0 <LCD_Delay_ms+0xe>
    }
}
 80006c6:	bf00      	nop
 80006c8:	bf00      	nop
 80006ca:	3710      	adds	r7, #16
 80006cc:	46bd      	mov	sp, r7
 80006ce:	bd80      	pop	{r7, pc}

080006d0 <LCD_GPIO_Init>:
 * LCD_GPIO_Init()
 *
 * Configures LCD pins as GPIO outputs.
 * ---------------------------------------------------- */
static void LCD_GPIO_Init(void)
{
 80006d0:	b480      	push	{r7}
 80006d2:	af00      	add	r7, sp, #0
    /* Enable GPIOA clock */
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
 80006d4:	4b4d      	ldr	r3, [pc, #308]	@ (800080c <LCD_GPIO_Init+0x13c>)
 80006d6:	6cdb      	ldr	r3, [r3, #76]	@ 0x4c
 80006d8:	4a4c      	ldr	r2, [pc, #304]	@ (800080c <LCD_GPIO_Init+0x13c>)
 80006da:	f043 0302 	orr.w	r3, r3, #2
 80006de:	64d3      	str	r3, [r2, #76]	@ 0x4c

    /* Set RS, EN, D4, D5, D6, D7 as output */
    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_RS));
 80006e0:	4b4b      	ldr	r3, [pc, #300]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80006e2:	681b      	ldr	r3, [r3, #0]
 80006e4:	4a4a      	ldr	r2, [pc, #296]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80006e6:	f023 0303 	bic.w	r3, r3, #3
 80006ea:	6013      	str	r3, [r2, #0]
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_RS));
 80006ec:	4b48      	ldr	r3, [pc, #288]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80006ee:	681b      	ldr	r3, [r3, #0]
 80006f0:	4a47      	ldr	r2, [pc, #284]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80006f2:	f043 0301 	orr.w	r3, r3, #1
 80006f6:	6013      	str	r3, [r2, #0]

    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_EN));
 80006f8:	4b45      	ldr	r3, [pc, #276]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80006fa:	681b      	ldr	r3, [r3, #0]
 80006fc:	4a44      	ldr	r2, [pc, #272]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80006fe:	f023 030c 	bic.w	r3, r3, #12
 8000702:	6013      	str	r3, [r2, #0]
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_EN));
 8000704:	4b42      	ldr	r3, [pc, #264]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000706:	681b      	ldr	r3, [r3, #0]
 8000708:	4a41      	ldr	r2, [pc, #260]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800070a:	f043 0304 	orr.w	r3, r3, #4
 800070e:	6013      	str	r3, [r2, #0]

    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_D4));
 8000710:	4b3f      	ldr	r3, [pc, #252]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000712:	681b      	ldr	r3, [r3, #0]
 8000714:	4a3e      	ldr	r2, [pc, #248]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000716:	f423 7340 	bic.w	r3, r3, #768	@ 0x300
 800071a:	6013      	str	r3, [r2, #0]
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_D4));
 800071c:	4b3c      	ldr	r3, [pc, #240]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800071e:	681b      	ldr	r3, [r3, #0]
 8000720:	4a3b      	ldr	r2, [pc, #236]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000722:	f443 7380 	orr.w	r3, r3, #256	@ 0x100
 8000726:	6013      	str	r3, [r2, #0]

    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_D5));
 8000728:	4b39      	ldr	r3, [pc, #228]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800072a:	681b      	ldr	r3, [r3, #0]
 800072c:	4a38      	ldr	r2, [pc, #224]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800072e:	f423 6340 	bic.w	r3, r3, #3072	@ 0xc00
 8000732:	6013      	str	r3, [r2, #0]
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_D5));
 8000734:	4b36      	ldr	r3, [pc, #216]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000736:	681b      	ldr	r3, [r3, #0]
 8000738:	4a35      	ldr	r2, [pc, #212]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800073a:	f443 6380 	orr.w	r3, r3, #1024	@ 0x400
 800073e:	6013      	str	r3, [r2, #0]

    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_D6));
 8000740:	4b33      	ldr	r3, [pc, #204]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000742:	681b      	ldr	r3, [r3, #0]
 8000744:	4a32      	ldr	r2, [pc, #200]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000746:	f423 3340 	bic.w	r3, r3, #196608	@ 0x30000
 800074a:	6013      	str	r3, [r2, #0]
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_D6));
 800074c:	4b30      	ldr	r3, [pc, #192]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800074e:	681b      	ldr	r3, [r3, #0]
 8000750:	4a2f      	ldr	r2, [pc, #188]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000752:	f443 3380 	orr.w	r3, r3, #65536	@ 0x10000
 8000756:	6013      	str	r3, [r2, #0]

    LCD_PORT->MODER &= ~(0b11 << (2 * LCD_D7));
 8000758:	4b2d      	ldr	r3, [pc, #180]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800075a:	681b      	ldr	r3, [r3, #0]
 800075c:	4a2c      	ldr	r2, [pc, #176]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800075e:	f423 4340 	bic.w	r3, r3, #49152	@ 0xc000
 8000762:	6013      	str	r3, [r2, #0]
    LCD_PORT->MODER |=  (0b01 << (2 * LCD_D7));
 8000764:	4b2a      	ldr	r3, [pc, #168]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000766:	681b      	ldr	r3, [r3, #0]
 8000768:	4a29      	ldr	r2, [pc, #164]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800076a:	f443 4380 	orr.w	r3, r3, #16384	@ 0x4000
 800076e:	6013      	str	r3, [r2, #0]

    /* Push-pull output */
    LCD_PORT->OTYPER &= ~(1 << LCD_RS);
 8000770:	4b27      	ldr	r3, [pc, #156]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000772:	685b      	ldr	r3, [r3, #4]
 8000774:	4a26      	ldr	r2, [pc, #152]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000776:	f023 0301 	bic.w	r3, r3, #1
 800077a:	6053      	str	r3, [r2, #4]
    LCD_PORT->OTYPER &= ~(1 << LCD_EN);
 800077c:	4b24      	ldr	r3, [pc, #144]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800077e:	685b      	ldr	r3, [r3, #4]
 8000780:	4a23      	ldr	r2, [pc, #140]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000782:	f023 0302 	bic.w	r3, r3, #2
 8000786:	6053      	str	r3, [r2, #4]
    LCD_PORT->OTYPER &= ~(1 << LCD_D4);
 8000788:	4b21      	ldr	r3, [pc, #132]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800078a:	685b      	ldr	r3, [r3, #4]
 800078c:	4a20      	ldr	r2, [pc, #128]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800078e:	f023 0310 	bic.w	r3, r3, #16
 8000792:	6053      	str	r3, [r2, #4]
    LCD_PORT->OTYPER &= ~(1 << LCD_D5);
 8000794:	4b1e      	ldr	r3, [pc, #120]	@ (8000810 <LCD_GPIO_Init+0x140>)
 8000796:	685b      	ldr	r3, [r3, #4]
 8000798:	4a1d      	ldr	r2, [pc, #116]	@ (8000810 <LCD_GPIO_Init+0x140>)
 800079a:	f023 0320 	bic.w	r3, r3, #32
 800079e:	6053      	str	r3, [r2, #4]
    LCD_PORT->OTYPER &= ~(1 << LCD_D6);
 80007a0:	4b1b      	ldr	r3, [pc, #108]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007a2:	685b      	ldr	r3, [r3, #4]
 80007a4:	4a1a      	ldr	r2, [pc, #104]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007a6:	f423 7380 	bic.w	r3, r3, #256	@ 0x100
 80007aa:	6053      	str	r3, [r2, #4]
    LCD_PORT->OTYPER &= ~(1 << LCD_D7);
 80007ac:	4b18      	ldr	r3, [pc, #96]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007ae:	685b      	ldr	r3, [r3, #4]
 80007b0:	4a17      	ldr	r2, [pc, #92]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007b2:	f023 0380 	bic.w	r3, r3, #128	@ 0x80
 80007b6:	6053      	str	r3, [r2, #4]

    /* No pull-up / pull-down */
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_RS));
 80007b8:	4b15      	ldr	r3, [pc, #84]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007ba:	68db      	ldr	r3, [r3, #12]
 80007bc:	4a14      	ldr	r2, [pc, #80]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007be:	f023 0303 	bic.w	r3, r3, #3
 80007c2:	60d3      	str	r3, [r2, #12]
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_EN));
 80007c4:	4b12      	ldr	r3, [pc, #72]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007c6:	68db      	ldr	r3, [r3, #12]
 80007c8:	4a11      	ldr	r2, [pc, #68]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007ca:	f023 030c 	bic.w	r3, r3, #12
 80007ce:	60d3      	str	r3, [r2, #12]
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_D4));
 80007d0:	4b0f      	ldr	r3, [pc, #60]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007d2:	68db      	ldr	r3, [r3, #12]
 80007d4:	4a0e      	ldr	r2, [pc, #56]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007d6:	f423 7340 	bic.w	r3, r3, #768	@ 0x300
 80007da:	60d3      	str	r3, [r2, #12]
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_D5));
 80007dc:	4b0c      	ldr	r3, [pc, #48]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007de:	68db      	ldr	r3, [r3, #12]
 80007e0:	4a0b      	ldr	r2, [pc, #44]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007e2:	f423 6340 	bic.w	r3, r3, #3072	@ 0xc00
 80007e6:	60d3      	str	r3, [r2, #12]
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_D6));
 80007e8:	4b09      	ldr	r3, [pc, #36]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007ea:	68db      	ldr	r3, [r3, #12]
 80007ec:	4a08      	ldr	r2, [pc, #32]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007ee:	f423 3340 	bic.w	r3, r3, #196608	@ 0x30000
 80007f2:	60d3      	str	r3, [r2, #12]
    LCD_PORT->PUPDR &= ~(0b11 << (2 * LCD_D7));
 80007f4:	4b06      	ldr	r3, [pc, #24]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007f6:	68db      	ldr	r3, [r3, #12]
 80007f8:	4a05      	ldr	r2, [pc, #20]	@ (8000810 <LCD_GPIO_Init+0x140>)
 80007fa:	f423 4340 	bic.w	r3, r3, #49152	@ 0xc000
 80007fe:	60d3      	str	r3, [r2, #12]
}
 8000800:	bf00      	nop
 8000802:	46bd      	mov	sp, r7
 8000804:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000808:	4770      	bx	lr
 800080a:	bf00      	nop
 800080c:	40021000 	.word	0x40021000
 8000810:	48000400 	.word	0x48000400

08000814 <LCD_Write_Pin>:
 * LCD_Write_Pin()
 *
 * Writes HIGH or LOW to one LCD pin.
 * ---------------------------------------------------- */
static void LCD_Write_Pin(uint8_t pin, uint8_t value)
{
 8000814:	b480      	push	{r7}
 8000816:	b083      	sub	sp, #12
 8000818:	af00      	add	r7, sp, #0
 800081a:	4603      	mov	r3, r0
 800081c:	460a      	mov	r2, r1
 800081e:	71fb      	strb	r3, [r7, #7]
 8000820:	4613      	mov	r3, r2
 8000822:	71bb      	strb	r3, [r7, #6]
    if (value)
 8000824:	79bb      	ldrb	r3, [r7, #6]
 8000826:	2b00      	cmp	r3, #0
 8000828:	d00a      	beq.n	8000840 <LCD_Write_Pin+0x2c>
    {
        LCD_PORT->ODR |= (1 << pin);
 800082a:	4b0e      	ldr	r3, [pc, #56]	@ (8000864 <LCD_Write_Pin+0x50>)
 800082c:	695b      	ldr	r3, [r3, #20]
 800082e:	79fa      	ldrb	r2, [r7, #7]
 8000830:	2101      	movs	r1, #1
 8000832:	fa01 f202 	lsl.w	r2, r1, r2
 8000836:	4611      	mov	r1, r2
 8000838:	4a0a      	ldr	r2, [pc, #40]	@ (8000864 <LCD_Write_Pin+0x50>)
 800083a:	430b      	orrs	r3, r1
 800083c:	6153      	str	r3, [r2, #20]
    }
    else
    {
        LCD_PORT->ODR &= ~(1 << pin);
    }
}
 800083e:	e00a      	b.n	8000856 <LCD_Write_Pin+0x42>
        LCD_PORT->ODR &= ~(1 << pin);
 8000840:	4b08      	ldr	r3, [pc, #32]	@ (8000864 <LCD_Write_Pin+0x50>)
 8000842:	695b      	ldr	r3, [r3, #20]
 8000844:	79fa      	ldrb	r2, [r7, #7]
 8000846:	2101      	movs	r1, #1
 8000848:	fa01 f202 	lsl.w	r2, r1, r2
 800084c:	43d2      	mvns	r2, r2
 800084e:	4611      	mov	r1, r2
 8000850:	4a04      	ldr	r2, [pc, #16]	@ (8000864 <LCD_Write_Pin+0x50>)
 8000852:	400b      	ands	r3, r1
 8000854:	6153      	str	r3, [r2, #20]
}
 8000856:	bf00      	nop
 8000858:	370c      	adds	r7, #12
 800085a:	46bd      	mov	sp, r7
 800085c:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000860:	4770      	bx	lr
 8000862:	bf00      	nop
 8000864:	48000400 	.word	0x48000400

08000868 <LCD_Enable_Pulse>:
 *
 * Sends enable pulse to LCD.
 * LCD reads data on EN transition.
 * ---------------------------------------------------- */
static void LCD_Enable_Pulse(void)
{
 8000868:	b580      	push	{r7, lr}
 800086a:	af00      	add	r7, sp, #0
    LCD_Write_Pin(LCD_EN, 1);
 800086c:	2101      	movs	r1, #1
 800086e:	2001      	movs	r0, #1
 8000870:	f7ff ffd0 	bl	8000814 <LCD_Write_Pin>
    LCD_Delay(100);
 8000874:	2064      	movs	r0, #100	@ 0x64
 8000876:	f7ff ff03 	bl	8000680 <LCD_Delay>
    LCD_Write_Pin(LCD_EN, 0);
 800087a:	2100      	movs	r1, #0
 800087c:	2001      	movs	r0, #1
 800087e:	f7ff ffc9 	bl	8000814 <LCD_Write_Pin>
    LCD_Delay(100);
 8000882:	2064      	movs	r0, #100	@ 0x64
 8000884:	f7ff fefc 	bl	8000680 <LCD_Delay>
}
 8000888:	bf00      	nop
 800088a:	bd80      	pop	{r7, pc}

0800088c <LCD_Send_4Bits>:
 * LCD_Send_4Bits()
 *
 * Sends 4 bits to LCD data pins D4-D7.
 * ---------------------------------------------------- */
static void LCD_Send_4Bits(uint8_t data)
{
 800088c:	b580      	push	{r7, lr}
 800088e:	b082      	sub	sp, #8
 8000890:	af00      	add	r7, sp, #0
 8000892:	4603      	mov	r3, r0
 8000894:	71fb      	strb	r3, [r7, #7]
    LCD_Write_Pin(LCD_D4, (data >> 0) & 0x01);
 8000896:	79fb      	ldrb	r3, [r7, #7]
 8000898:	f003 0301 	and.w	r3, r3, #1
 800089c:	b2db      	uxtb	r3, r3
 800089e:	4619      	mov	r1, r3
 80008a0:	2004      	movs	r0, #4
 80008a2:	f7ff ffb7 	bl	8000814 <LCD_Write_Pin>
    LCD_Write_Pin(LCD_D5, (data >> 1) & 0x01);
 80008a6:	79fb      	ldrb	r3, [r7, #7]
 80008a8:	085b      	lsrs	r3, r3, #1
 80008aa:	b2db      	uxtb	r3, r3
 80008ac:	f003 0301 	and.w	r3, r3, #1
 80008b0:	b2db      	uxtb	r3, r3
 80008b2:	4619      	mov	r1, r3
 80008b4:	2005      	movs	r0, #5
 80008b6:	f7ff ffad 	bl	8000814 <LCD_Write_Pin>
    LCD_Write_Pin(LCD_D6, (data >> 2) & 0x01);
 80008ba:	79fb      	ldrb	r3, [r7, #7]
 80008bc:	089b      	lsrs	r3, r3, #2
 80008be:	b2db      	uxtb	r3, r3
 80008c0:	f003 0301 	and.w	r3, r3, #1
 80008c4:	b2db      	uxtb	r3, r3
 80008c6:	4619      	mov	r1, r3
 80008c8:	2008      	movs	r0, #8
 80008ca:	f7ff ffa3 	bl	8000814 <LCD_Write_Pin>
    LCD_Write_Pin(LCD_D7, (data >> 3) & 0x01);
 80008ce:	79fb      	ldrb	r3, [r7, #7]
 80008d0:	08db      	lsrs	r3, r3, #3
 80008d2:	b2db      	uxtb	r3, r3
 80008d4:	f003 0301 	and.w	r3, r3, #1
 80008d8:	b2db      	uxtb	r3, r3
 80008da:	4619      	mov	r1, r3
 80008dc:	2007      	movs	r0, #7
 80008de:	f7ff ff99 	bl	8000814 <LCD_Write_Pin>

    LCD_Enable_Pulse();
 80008e2:	f7ff ffc1 	bl	8000868 <LCD_Enable_Pulse>
}
 80008e6:	bf00      	nop
 80008e8:	3708      	adds	r7, #8
 80008ea:	46bd      	mov	sp, r7
 80008ec:	bd80      	pop	{r7, pc}

080008ee <LCD_Send_Command>:
 *
 * Sends command byte to LCD.
 * RS = 0 means command mode.
 * ---------------------------------------------------- */
static void LCD_Send_Command(uint8_t cmd)
{
 80008ee:	b580      	push	{r7, lr}
 80008f0:	b082      	sub	sp, #8
 80008f2:	af00      	add	r7, sp, #0
 80008f4:	4603      	mov	r3, r0
 80008f6:	71fb      	strb	r3, [r7, #7]
    LCD_Write_Pin(LCD_RS, 0);
 80008f8:	2100      	movs	r1, #0
 80008fa:	2000      	movs	r0, #0
 80008fc:	f7ff ff8a 	bl	8000814 <LCD_Write_Pin>

    LCD_Send_4Bits(cmd >> 4);
 8000900:	79fb      	ldrb	r3, [r7, #7]
 8000902:	091b      	lsrs	r3, r3, #4
 8000904:	b2db      	uxtb	r3, r3
 8000906:	4618      	mov	r0, r3
 8000908:	f7ff ffc0 	bl	800088c <LCD_Send_4Bits>
    LCD_Send_4Bits(cmd & 0x0F);
 800090c:	79fb      	ldrb	r3, [r7, #7]
 800090e:	f003 030f 	and.w	r3, r3, #15
 8000912:	b2db      	uxtb	r3, r3
 8000914:	4618      	mov	r0, r3
 8000916:	f7ff ffb9 	bl	800088c <LCD_Send_4Bits>

    LCD_Delay_ms(2);
 800091a:	2002      	movs	r0, #2
 800091c:	f7ff fec1 	bl	80006a2 <LCD_Delay_ms>
}
 8000920:	bf00      	nop
 8000922:	3708      	adds	r7, #8
 8000924:	46bd      	mov	sp, r7
 8000926:	bd80      	pop	{r7, pc}

08000928 <LCD_Send_Data>:
 *
 * Sends character data to LCD.
 * RS = 1 means data mode.
 * ---------------------------------------------------- */
static void LCD_Send_Data(uint8_t data)
{
 8000928:	b580      	push	{r7, lr}
 800092a:	b082      	sub	sp, #8
 800092c:	af00      	add	r7, sp, #0
 800092e:	4603      	mov	r3, r0
 8000930:	71fb      	strb	r3, [r7, #7]
    LCD_Write_Pin(LCD_RS, 1);
 8000932:	2101      	movs	r1, #1
 8000934:	2000      	movs	r0, #0
 8000936:	f7ff ff6d 	bl	8000814 <LCD_Write_Pin>

    LCD_Send_4Bits(data >> 4);
 800093a:	79fb      	ldrb	r3, [r7, #7]
 800093c:	091b      	lsrs	r3, r3, #4
 800093e:	b2db      	uxtb	r3, r3
 8000940:	4618      	mov	r0, r3
 8000942:	f7ff ffa3 	bl	800088c <LCD_Send_4Bits>
    LCD_Send_4Bits(data & 0x0F);
 8000946:	79fb      	ldrb	r3, [r7, #7]
 8000948:	f003 030f 	and.w	r3, r3, #15
 800094c:	b2db      	uxtb	r3, r3
 800094e:	4618      	mov	r0, r3
 8000950:	f7ff ff9c 	bl	800088c <LCD_Send_4Bits>

    LCD_Delay_ms(1);
 8000954:	2001      	movs	r0, #1
 8000956:	f7ff fea4 	bl	80006a2 <LCD_Delay_ms>
}
 800095a:	bf00      	nop
 800095c:	3708      	adds	r7, #8
 800095e:	46bd      	mov	sp, r7
 8000960:	bd80      	pop	{r7, pc}

08000962 <LCD_Init>:
 * LCD_Init()
 *
 * Initializes LCD in 4-bit mode.
 * ---------------------------------------------------- */
void LCD_Init(void)
{
 8000962:	b580      	push	{r7, lr}
 8000964:	af00      	add	r7, sp, #0
    LCD_GPIO_Init();
 8000966:	f7ff feb3 	bl	80006d0 <LCD_GPIO_Init>

    LCD_Delay_ms(50);
 800096a:	2032      	movs	r0, #50	@ 0x32
 800096c:	f7ff fe99 	bl	80006a2 <LCD_Delay_ms>

    LCD_Write_Pin(LCD_RS, 0);
 8000970:	2100      	movs	r1, #0
 8000972:	2000      	movs	r0, #0
 8000974:	f7ff ff4e 	bl	8000814 <LCD_Write_Pin>
    LCD_Write_Pin(LCD_EN, 0);
 8000978:	2100      	movs	r1, #0
 800097a:	2001      	movs	r0, #1
 800097c:	f7ff ff4a 	bl	8000814 <LCD_Write_Pin>

    /* 4-bit initialization sequence */
    LCD_Send_4Bits(0x03);
 8000980:	2003      	movs	r0, #3
 8000982:	f7ff ff83 	bl	800088c <LCD_Send_4Bits>
    LCD_Delay_ms(5);
 8000986:	2005      	movs	r0, #5
 8000988:	f7ff fe8b 	bl	80006a2 <LCD_Delay_ms>

    LCD_Send_4Bits(0x03);
 800098c:	2003      	movs	r0, #3
 800098e:	f7ff ff7d 	bl	800088c <LCD_Send_4Bits>
    LCD_Delay_ms(5);
 8000992:	2005      	movs	r0, #5
 8000994:	f7ff fe85 	bl	80006a2 <LCD_Delay_ms>

    LCD_Send_4Bits(0x03);
 8000998:	2003      	movs	r0, #3
 800099a:	f7ff ff77 	bl	800088c <LCD_Send_4Bits>
    LCD_Delay_ms(1);
 800099e:	2001      	movs	r0, #1
 80009a0:	f7ff fe7f 	bl	80006a2 <LCD_Delay_ms>

    LCD_Send_4Bits(0x02);
 80009a4:	2002      	movs	r0, #2
 80009a6:	f7ff ff71 	bl	800088c <LCD_Send_4Bits>
    LCD_Delay_ms(1);
 80009aa:	2001      	movs	r0, #1
 80009ac:	f7ff fe79 	bl	80006a2 <LCD_Delay_ms>

    /* 4-bit mode, 2 lines, 5x8 font */
    LCD_Send_Command(0x28);
 80009b0:	2028      	movs	r0, #40	@ 0x28
 80009b2:	f7ff ff9c 	bl	80008ee <LCD_Send_Command>

    /* Display ON, cursor OFF */
    LCD_Send_Command(0x0C);
 80009b6:	200c      	movs	r0, #12
 80009b8:	f7ff ff99 	bl	80008ee <LCD_Send_Command>

    /* Entry mode: cursor moves right */
    LCD_Send_Command(0x06);
 80009bc:	2006      	movs	r0, #6
 80009be:	f7ff ff96 	bl	80008ee <LCD_Send_Command>

    /* Clear display */
    LCD_Send_Command(0x01);
 80009c2:	2001      	movs	r0, #1
 80009c4:	f7ff ff93 	bl	80008ee <LCD_Send_Command>
    LCD_Delay_ms(2);
 80009c8:	2002      	movs	r0, #2
 80009ca:	f7ff fe6a 	bl	80006a2 <LCD_Delay_ms>
}
 80009ce:	bf00      	nop
 80009d0:	bd80      	pop	{r7, pc}

080009d2 <lcd_clear>:
 * lcd_clear()
 *
 * Clears LCD screen.
 * ---------------------------------------------------- */
void lcd_clear(void)
{
 80009d2:	b580      	push	{r7, lr}
 80009d4:	af00      	add	r7, sp, #0
    LCD_Send_Command(0x01);
 80009d6:	2001      	movs	r0, #1
 80009d8:	f7ff ff89 	bl	80008ee <LCD_Send_Command>
    LCD_Delay_ms(2);
 80009dc:	2002      	movs	r0, #2
 80009de:	f7ff fe60 	bl	80006a2 <LCD_Delay_ms>
}
 80009e2:	bf00      	nop
 80009e4:	bd80      	pop	{r7, pc}

080009e6 <lcd_put_cur>:
 * For 16x2 LCD:
 *   row 0 = first line
 *   row 1 = second line
 * ---------------------------------------------------- */
void lcd_put_cur(uint8_t row, uint8_t col)
{
 80009e6:	b580      	push	{r7, lr}
 80009e8:	b084      	sub	sp, #16
 80009ea:	af00      	add	r7, sp, #0
 80009ec:	4603      	mov	r3, r0
 80009ee:	460a      	mov	r2, r1
 80009f0:	71fb      	strb	r3, [r7, #7]
 80009f2:	4613      	mov	r3, r2
 80009f4:	71bb      	strb	r3, [r7, #6]
    uint8_t address;

    if (row == 0)
 80009f6:	79fb      	ldrb	r3, [r7, #7]
 80009f8:	2b00      	cmp	r3, #0
 80009fa:	d103      	bne.n	8000a04 <lcd_put_cur+0x1e>
    {
        address = 0x80 + col;
 80009fc:	79bb      	ldrb	r3, [r7, #6]
 80009fe:	3b80      	subs	r3, #128	@ 0x80
 8000a00:	73fb      	strb	r3, [r7, #15]
 8000a02:	e002      	b.n	8000a0a <lcd_put_cur+0x24>
    }
    else
    {
        address = 0xC0 + col;
 8000a04:	79bb      	ldrb	r3, [r7, #6]
 8000a06:	3b40      	subs	r3, #64	@ 0x40
 8000a08:	73fb      	strb	r3, [r7, #15]
    }

    LCD_Send_Command(address);
 8000a0a:	7bfb      	ldrb	r3, [r7, #15]
 8000a0c:	4618      	mov	r0, r3
 8000a0e:	f7ff ff6e 	bl	80008ee <LCD_Send_Command>
}
 8000a12:	bf00      	nop
 8000a14:	3710      	adds	r7, #16
 8000a16:	46bd      	mov	sp, r7
 8000a18:	bd80      	pop	{r7, pc}

08000a1a <lcd_send_string>:
 * lcd_send_string()
 *
 * Sends string to LCD.
 * ---------------------------------------------------- */
void lcd_send_string(char *str)
{
 8000a1a:	b580      	push	{r7, lr}
 8000a1c:	b082      	sub	sp, #8
 8000a1e:	af00      	add	r7, sp, #0
 8000a20:	6078      	str	r0, [r7, #4]
    while (*str)
 8000a22:	e007      	b.n	8000a34 <lcd_send_string+0x1a>
    {
        LCD_Send_Data((uint8_t)(*str));
 8000a24:	687b      	ldr	r3, [r7, #4]
 8000a26:	781b      	ldrb	r3, [r3, #0]
 8000a28:	4618      	mov	r0, r3
 8000a2a:	f7ff ff7d 	bl	8000928 <LCD_Send_Data>
        str++;
 8000a2e:	687b      	ldr	r3, [r7, #4]
 8000a30:	3301      	adds	r3, #1
 8000a32:	607b      	str	r3, [r7, #4]
    while (*str)
 8000a34:	687b      	ldr	r3, [r7, #4]
 8000a36:	781b      	ldrb	r3, [r3, #0]
 8000a38:	2b00      	cmp	r3, #0
 8000a3a:	d1f3      	bne.n	8000a24 <lcd_send_string+0xa>
    }
}
 8000a3c:	bf00      	nop
 8000a3e:	bf00      	nop
 8000a40:	3708      	adds	r7, #8
 8000a42:	46bd      	mov	sp, r7
 8000a44:	bd80      	pop	{r7, pc}
	...

08000a48 <__NVIC_EnableIRQ>:
  \details Enables a device specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
 8000a48:	b480      	push	{r7}
 8000a4a:	b083      	sub	sp, #12
 8000a4c:	af00      	add	r7, sp, #0
 8000a4e:	4603      	mov	r3, r0
 8000a50:	71fb      	strb	r3, [r7, #7]
  if ((int32_t)(IRQn) >= 0)
 8000a52:	f997 3007 	ldrsb.w	r3, [r7, #7]
 8000a56:	2b00      	cmp	r3, #0
 8000a58:	db0b      	blt.n	8000a72 <__NVIC_EnableIRQ+0x2a>
  {
    __COMPILER_BARRIER();
    NVIC->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
 8000a5a:	79fb      	ldrb	r3, [r7, #7]
 8000a5c:	f003 021f 	and.w	r2, r3, #31
 8000a60:	4907      	ldr	r1, [pc, #28]	@ (8000a80 <__NVIC_EnableIRQ+0x38>)
 8000a62:	f997 3007 	ldrsb.w	r3, [r7, #7]
 8000a66:	095b      	lsrs	r3, r3, #5
 8000a68:	2001      	movs	r0, #1
 8000a6a:	fa00 f202 	lsl.w	r2, r0, r2
 8000a6e:	f841 2023 	str.w	r2, [r1, r3, lsl #2]
    __COMPILER_BARRIER();
  }
}
 8000a72:	bf00      	nop
 8000a74:	370c      	adds	r7, #12
 8000a76:	46bd      	mov	sp, r7
 8000a78:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000a7c:	4770      	bx	lr
 8000a7e:	bf00      	nop
 8000a80:	e000e100 	.word	0xe000e100

08000a84 <FPU_Enable>:
void LCD_Init(void);
void lcd_clear(void);
void lcd_put_cur(uint8_t row, uint8_t col);
void lcd_send_string(char *str);

void FPU_Enable(){
 8000a84:	b480      	push	{r7}
 8000a86:	af00      	add	r7, sp, #0

    SCB->CPACR |= ((3UL << 20U) | (3UL << 22U));
 8000a88:	4b06      	ldr	r3, [pc, #24]	@ (8000aa4 <FPU_Enable+0x20>)
 8000a8a:	f8d3 3088 	ldr.w	r3, [r3, #136]	@ 0x88
 8000a8e:	4a05      	ldr	r2, [pc, #20]	@ (8000aa4 <FPU_Enable+0x20>)
 8000a90:	f443 0370 	orr.w	r3, r3, #15728640	@ 0xf00000
 8000a94:	f8c2 3088 	str.w	r3, [r2, #136]	@ 0x88
}
 8000a98:	bf00      	nop
 8000a9a:	46bd      	mov	sp, r7
 8000a9c:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000aa0:	4770      	bx	lr
 8000aa2:	bf00      	nop
 8000aa4:	e000ed00 	.word	0xe000ed00

08000aa8 <configure_PB6>:


void configure_PB6(){
 8000aa8:	b480      	push	{r7}
 8000aaa:	af00      	add	r7, sp, #0
  // 1. Enable the clock to GPIO Port B
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
 8000aac:	4b11      	ldr	r3, [pc, #68]	@ (8000af4 <configure_PB6+0x4c>)
 8000aae:	6cdb      	ldr	r3, [r3, #76]	@ 0x4c
 8000ab0:	4a10      	ldr	r2, [pc, #64]	@ (8000af4 <configure_PB6+0x4c>)
 8000ab2:	f043 0302 	orr.w	r3, r3, #2
 8000ab6:	64d3      	str	r3, [r2, #76]	@ 0x4c

	// 2. Configure GPIO Mode to 'Alternative Function' mode: Input(00), Output(01), Alternative Function(10), Analog(11)
	GPIOB->MODER &= ~(0b11<<(2*PB6));
 8000ab8:	4b0f      	ldr	r3, [pc, #60]	@ (8000af8 <configure_PB6+0x50>)
 8000aba:	681b      	ldr	r3, [r3, #0]
 8000abc:	4a0e      	ldr	r2, [pc, #56]	@ (8000af8 <configure_PB6+0x50>)
 8000abe:	f423 5340 	bic.w	r3, r3, #12288	@ 0x3000
 8000ac2:	6013      	str	r3, [r2, #0]
	GPIOB->MODER |=   0b10<<(2*PB6);
 8000ac4:	4b0c      	ldr	r3, [pc, #48]	@ (8000af8 <configure_PB6+0x50>)
 8000ac6:	681b      	ldr	r3, [r3, #0]
 8000ac8:	4a0b      	ldr	r2, [pc, #44]	@ (8000af8 <configure_PB6+0x50>)
 8000aca:	f443 5300 	orr.w	r3, r3, #8192	@ 0x2000
 8000ace:	6013      	str	r3, [r2, #0]

	// 3. Select PA1's alternative function as TIM4_CH1, which is 'AF2', by configuring the GPIOA_AFRL register
	GPIOB->AFR[0] &= ~(0b1111 << (4*PB6));
 8000ad0:	4b09      	ldr	r3, [pc, #36]	@ (8000af8 <configure_PB6+0x50>)
 8000ad2:	6a1b      	ldr	r3, [r3, #32]
 8000ad4:	4a08      	ldr	r2, [pc, #32]	@ (8000af8 <configure_PB6+0x50>)
 8000ad6:	f023 6370 	bic.w	r3, r3, #251658240	@ 0xf000000
 8000ada:	6213      	str	r3, [r2, #32]
	GPIOB->AFR[0] |= (0b0010 << (4*PB6));
 8000adc:	4b06      	ldr	r3, [pc, #24]	@ (8000af8 <configure_PB6+0x50>)
 8000ade:	6a1b      	ldr	r3, [r3, #32]
 8000ae0:	4a05      	ldr	r2, [pc, #20]	@ (8000af8 <configure_PB6+0x50>)
 8000ae2:	f043 7300 	orr.w	r3, r3, #33554432	@ 0x2000000
 8000ae6:	6213      	str	r3, [r2, #32]

}
 8000ae8:	bf00      	nop
 8000aea:	46bd      	mov	sp, r7
 8000aec:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000af0:	4770      	bx	lr
 8000af2:	bf00      	nop
 8000af4:	40021000 	.word	0x40021000
 8000af8:	48000400 	.word	0x48000400

08000afc <configure_PB10>:

void configure_PB10(){
 8000afc:	b480      	push	{r7}
 8000afe:	af00      	add	r7, sp, #0
  // 1. Enable the clock to GPIO Port B
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
 8000b00:	4b17      	ldr	r3, [pc, #92]	@ (8000b60 <configure_PB10+0x64>)
 8000b02:	6cdb      	ldr	r3, [r3, #76]	@ 0x4c
 8000b04:	4a16      	ldr	r2, [pc, #88]	@ (8000b60 <configure_PB10+0x64>)
 8000b06:	f043 0302 	orr.w	r3, r3, #2
 8000b0a:	64d3      	str	r3, [r2, #76]	@ 0x4c

	// 2. Configure GPIO Mode to 'Alternative Function' mode: Input(00), Output(01), Alternative Function(10), Analog(11)
	GPIOB->MODER &= ~(0b11<<(2*PB10));
 8000b0c:	4b15      	ldr	r3, [pc, #84]	@ (8000b64 <configure_PB10+0x68>)
 8000b0e:	681b      	ldr	r3, [r3, #0]
 8000b10:	4a14      	ldr	r2, [pc, #80]	@ (8000b64 <configure_PB10+0x68>)
 8000b12:	f423 1340 	bic.w	r3, r3, #3145728	@ 0x300000
 8000b16:	6013      	str	r3, [r2, #0]
	GPIOB->MODER |=   0b10<<(2*PB10);
 8000b18:	4b12      	ldr	r3, [pc, #72]	@ (8000b64 <configure_PB10+0x68>)
 8000b1a:	681b      	ldr	r3, [r3, #0]
 8000b1c:	4a11      	ldr	r2, [pc, #68]	@ (8000b64 <configure_PB10+0x68>)
 8000b1e:	f443 1300 	orr.w	r3, r3, #2097152	@ 0x200000
 8000b22:	6013      	str	r3, [r2, #0]

	// 3. Select PA1's alternative function as TIM2_CH3, which is 'AF1', by configuring the GPIOA_AFRH register
	GPIOB->AFR[1] &= ~(0b1111 << (4*(PB10-8)));
 8000b24:	4b0f      	ldr	r3, [pc, #60]	@ (8000b64 <configure_PB10+0x68>)
 8000b26:	6a5b      	ldr	r3, [r3, #36]	@ 0x24
 8000b28:	4a0e      	ldr	r2, [pc, #56]	@ (8000b64 <configure_PB10+0x68>)
 8000b2a:	f423 6370 	bic.w	r3, r3, #3840	@ 0xf00
 8000b2e:	6253      	str	r3, [r2, #36]	@ 0x24
	GPIOB->AFR[1] |= (0b0001 << (4*(PB10-8)));
 8000b30:	4b0c      	ldr	r3, [pc, #48]	@ (8000b64 <configure_PB10+0x68>)
 8000b32:	6a5b      	ldr	r3, [r3, #36]	@ 0x24
 8000b34:	4a0b      	ldr	r2, [pc, #44]	@ (8000b64 <configure_PB10+0x68>)
 8000b36:	f443 7380 	orr.w	r3, r3, #256	@ 0x100
 8000b3a:	6253      	str	r3, [r2, #36]	@ 0x24

	// 4. Configure GPIO Output Type to 'Push-Pull': Output push-pull (0), Output open drain (1)
	GPIOB->OTYPER &= ~(1<<PB10);      // Push-pull
 8000b3c:	4b09      	ldr	r3, [pc, #36]	@ (8000b64 <configure_PB10+0x68>)
 8000b3e:	685b      	ldr	r3, [r3, #4]
 8000b40:	4a08      	ldr	r2, [pc, #32]	@ (8000b64 <configure_PB10+0x68>)
 8000b42:	f423 6380 	bic.w	r3, r3, #1024	@ 0x400
 8000b46:	6053      	str	r3, [r2, #4]

	// 5. Configure GPIO Push-Pull to 'No Pull-up or Pull-down': No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOB->PUPDR  &= ~(0b11<<(2*PB10));  // No pull-up, no pull-down
 8000b48:	4b06      	ldr	r3, [pc, #24]	@ (8000b64 <configure_PB10+0x68>)
 8000b4a:	68db      	ldr	r3, [r3, #12]
 8000b4c:	4a05      	ldr	r2, [pc, #20]	@ (8000b64 <configure_PB10+0x68>)
 8000b4e:	f423 1340 	bic.w	r3, r3, #3145728	@ 0x300000
 8000b52:	60d3      	str	r3, [r2, #12]
}
 8000b54:	bf00      	nop
 8000b56:	46bd      	mov	sp, r7
 8000b58:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000b5c:	4770      	bx	lr
 8000b5e:	bf00      	nop
 8000b60:	40021000 	.word	0x40021000
 8000b64:	48000400 	.word	0x48000400

08000b68 <TIM2_CH3_Init>:
void TIM2_CH3_Init(){//pb10 trigger PmW
 8000b68:	b480      	push	{r7}
 8000b6a:	af00      	add	r7, sp, #0

		//1. Enable the clock to TIM2 by configuring RCC_APB1ENR1 register
    RCC->APB1ENR1	|= RCC_APB1ENR1_TIM2EN;
 8000b6c:	4b24      	ldr	r3, [pc, #144]	@ (8000c00 <TIM2_CH3_Init+0x98>)
 8000b6e:	6d9b      	ldr	r3, [r3, #88]	@ 0x58
 8000b70:	4a23      	ldr	r2, [pc, #140]	@ (8000c00 <TIM2_CH3_Init+0x98>)
 8000b72:	f043 0301 	orr.w	r3, r3, #1
 8000b76:	6593      	str	r3, [r2, #88]	@ 0x58

		//2. Configure TIM2 counting mode to upcounting (TIMx_CR1)
		TIM2->CR1 &= ~TIM_CR1_DIR;
 8000b78:	f04f 4380 	mov.w	r3, #1073741824	@ 0x40000000
 8000b7c:	681b      	ldr	r3, [r3, #0]
 8000b7e:	f04f 4280 	mov.w	r2, #1073741824	@ 0x40000000
 8000b82:	f023 0310 	bic.w	r3, r3, #16
 8000b86:	6013      	str	r3, [r2, #0]

		//3. Configure TIM5 Prescalar (TIMx_PSC) and ARR (TIMx_ARR) to generate a counter period of 100 ms
    TIM2->PSC = CNT_PSC-1;       // Prescaler
 8000b88:	f04f 4380 	mov.w	r3, #1073741824	@ 0x40000000
 8000b8c:	220f      	movs	r2, #15
 8000b8e:	629a      	str	r2, [r3, #40]	@ 0x28
	  TIM2->ARR = 10000-1;   // Note: there are many possible combinations of PSC and ARR. This is just one solution
 8000b90:	f04f 4380 	mov.w	r3, #1073741824	@ 0x40000000
 8000b94:	f242 720f 	movw	r2, #9999	@ 0x270f
 8000b98:	62da      	str	r2, [r3, #44]	@ 0x2c

		//4. Configure TIMx_CCMR2 CC3S[1:0] bits to output mode for TIM2 Channel 3
		TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;
 8000b9a:	f04f 4380 	mov.w	r3, #1073741824	@ 0x40000000
 8000b9e:	69db      	ldr	r3, [r3, #28]
 8000ba0:	f04f 4280 	mov.w	r2, #1073741824	@ 0x40000000
 8000ba4:	f023 0303 	bic.w	r3, r3, #3
 8000ba8:	61d3      	str	r3, [r2, #28]

		//5. Configure TIMx_CCMR2 OC3M[3:0] bits to PWM mode 1 ('0110') for TIM2 Channel 3
		TIM2->CCMR2 &= ~TIM_CCMR2_OC3M;  // Clear ouput compare mode bits for channel 3
 8000baa:	f04f 4380 	mov.w	r3, #1073741824	@ 0x40000000
 8000bae:	69db      	ldr	r3, [r3, #28]
 8000bb0:	f04f 4280 	mov.w	r2, #1073741824	@ 0x40000000
 8000bb4:	f423 3380 	bic.w	r3, r3, #65536	@ 0x10000
 8000bb8:	f023 0370 	bic.w	r3, r3, #112	@ 0x70
 8000bbc:	61d3      	str	r3, [r2, #28]
    TIM2->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1; // OC2M = 0110 for PWM Mode 1 output on ch3
 8000bbe:	f04f 4380 	mov.w	r3, #1073741824	@ 0x40000000
 8000bc2:	69db      	ldr	r3, [r3, #28]
 8000bc4:	f04f 4280 	mov.w	r2, #1073741824	@ 0x40000000
 8000bc8:	f043 0360 	orr.w	r3, r3, #96	@ 0x60
 8000bcc:	61d3      	str	r3, [r2, #28]


    //6. Set TIMx_CCER CC3E bit to enable output signal on Channel 3
		TIM2->CCER |= TIM_CCER_CC3E;
 8000bce:	f04f 4380 	mov.w	r3, #1073741824	@ 0x40000000
 8000bd2:	6a1b      	ldr	r3, [r3, #32]
 8000bd4:	f04f 4280 	mov.w	r2, #1073741824	@ 0x40000000
 8000bd8:	f443 7380 	orr.w	r3, r3, #256	@ 0x100
 8000bdc:	6213      	str	r3, [r2, #32]

		TIM2->CCR3  = 10;  // 10 us
 8000bde:	f04f 4380 	mov.w	r3, #1073741824	@ 0x40000000
 8000be2:	220a      	movs	r2, #10
 8000be4:	63da      	str	r2, [r3, #60]	@ 0x3c

		//7. Set TIMx_CR1 CEN bit to enable the TIM2 counter
		TIM2->CR1  |= TIM_CR1_CEN; // Enable counter
 8000be6:	f04f 4380 	mov.w	r3, #1073741824	@ 0x40000000
 8000bea:	681b      	ldr	r3, [r3, #0]
 8000bec:	f04f 4280 	mov.w	r2, #1073741824	@ 0x40000000
 8000bf0:	f043 0301 	orr.w	r3, r3, #1
 8000bf4:	6013      	str	r3, [r2, #0]
}
 8000bf6:	bf00      	nop
 8000bf8:	46bd      	mov	sp, r7
 8000bfa:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000bfe:	4770      	bx	lr
 8000c00:	40021000 	.word	0x40021000

08000c04 <TIM4_CH1_Init>:

void TIM4_CH1_Init(void) {//pb6 echo
 8000c04:	b580      	push	{r7, lr}
 8000c06:	af00      	add	r7, sp, #0

	//1. Enable the clock to TIM4 by configuring RCC_APB1ENR1 register
	RCC->APB1ENR1 |= RCC_APB1ENR1_TIM4EN;
 8000c08:	4b26      	ldr	r3, [pc, #152]	@ (8000ca4 <TIM4_CH1_Init+0xa0>)
 8000c0a:	6d9b      	ldr	r3, [r3, #88]	@ 0x58
 8000c0c:	4a25      	ldr	r2, [pc, #148]	@ (8000ca4 <TIM4_CH1_Init+0xa0>)
 8000c0e:	f043 0304 	orr.w	r3, r3, #4
 8000c12:	6593      	str	r3, [r2, #88]	@ 0x58

	//2. Configure TIM4 counting mode to upcounting (TIMx_CR1)
	TIM4->CR1 &= ~TIM_CR1_DIR;
 8000c14:	4b24      	ldr	r3, [pc, #144]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c16:	681b      	ldr	r3, [r3, #0]
 8000c18:	4a23      	ldr	r2, [pc, #140]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c1a:	f023 0310 	bic.w	r3, r3, #16
 8000c1e:	6013      	str	r3, [r2, #0]

	//3. Configure TIM4 Prescalar (TIMx_PSC) and ARR (TIMx_ARR) to generate a desired counter period
	TIM4->PSC = CNT_PSC-1;		// Set up an appropriate prescaler to slow down the clock or timer counter
 8000c20:	4b21      	ldr	r3, [pc, #132]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c22:	220f      	movs	r2, #15
 8000c24:	629a      	str	r2, [r3, #40]	@ 0x28
	TIM4->ARR = 10000-1;
 8000c26:	4b20      	ldr	r3, [pc, #128]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c28:	f242 720f 	movw	r2, #9999	@ 0x270f
 8000c2c:	62da      	str	r2, [r3, #44]	@ 0x2c
	//   and input channel (CC1) is mapped on Timer Input 1 (TI1)
	//   00 = output
	//   01 = input, CC1 is mapped on timer Input 1 (TI1)
	//   10 = input, CC1 is mapped on timer Input 2 (TI2)
	//   11 = input, CC1 is mapped on slave timer
	TIM4->CCMR1 &= ~TIM_CCMR1_CC1S;
 8000c2e:	4b1e      	ldr	r3, [pc, #120]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c30:	699b      	ldr	r3, [r3, #24]
 8000c32:	4a1d      	ldr	r2, [pc, #116]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c34:	f023 0303 	bic.w	r3, r3, #3
 8000c38:	6193      	str	r3, [r2, #24]
	TIM4->CCMR1 |= TIM_CCMR1_CC1S_0;
 8000c3a:	4b1b      	ldr	r3, [pc, #108]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c3c:	699b      	ldr	r3, [r3, #24]
 8000c3e:	4a1a      	ldr	r2, [pc, #104]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c40:	f043 0301 	orr.w	r3, r3, #1
 8000c44:	6193      	str	r3, [r2, #24]

	// 5. Disable digital filtering by configuring TIMx_CCMR1 IC1F[3:0] bits
	//    because we want to capture every event
	TIM4->CCMR1 &= ~TIM_CCMR1_IC1F;
 8000c46:	4b18      	ldr	r3, [pc, #96]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c48:	699b      	ldr	r3, [r3, #24]
 8000c4a:	4a17      	ldr	r2, [pc, #92]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c4c:	f023 03f0 	bic.w	r3, r3, #240	@ 0xf0
 8000c50:	6193      	str	r3, [r2, #24]

	// 6. Program the input prescaler by configuring TIMx_CCMR1 IC1PSC[1:0] bits
	// To capture each valid transition, set the input prescaler to zero;
	TIM4->CCMR1 &= ~(TIM_CCMR1_IC1PSC); // Clear filtering because we need to capture every event
 8000c52:	4b15      	ldr	r3, [pc, #84]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c54:	699b      	ldr	r3, [r3, #24]
 8000c56:	4a14      	ldr	r2, [pc, #80]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c58:	f023 030c 	bic.w	r3, r3, #12
 8000c5c:	6193      	str	r3, [r2, #24]
	//    by configuring TIMx_CCER CC1NP and CC1P bits
	// CC1NP=0, CC1P=0: rising edge,
	// CC1NP=0, CC1P=1: falling edge,
	// CC1NP=1, CC1P=0: reserved,
	// CC1NP=1, CC1P=1: both edges
	TIM4->CCER |= (TIM_CCER_CC1NP | TIM_CCER_CC1P);		// Both rising and falling edges.
 8000c5e:	4b12      	ldr	r3, [pc, #72]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c60:	6a1b      	ldr	r3, [r3, #32]
 8000c62:	4a11      	ldr	r2, [pc, #68]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c64:	f043 030a 	orr.w	r3, r3, #10
 8000c68:	6213      	str	r3, [r2, #32]

	// 8. Enable Input Capture mode by setting TIMx_CCER CC1E bit
	TIM4->CCER |= TIM_CCER_CC1E;
 8000c6a:	4b0f      	ldr	r3, [pc, #60]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c6c:	6a1b      	ldr	r3, [r3, #32]
 8000c6e:	4a0e      	ldr	r2, [pc, #56]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c70:	f043 0301 	orr.w	r3, r3, #1
 8000c74:	6213      	str	r3, [r2, #32]

	// 9. Enable related interrupts by
	//		i. configuring TIMx_DIER register
	TIM4->DIER |= TIM_DIER_CC1IE;		// Enable Capture/Compare interrupts for channel 1
 8000c76:	4b0c      	ldr	r3, [pc, #48]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c78:	68db      	ldr	r3, [r3, #12]
 8000c7a:	4a0b      	ldr	r2, [pc, #44]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c7c:	f043 0302 	orr.w	r3, r3, #2
 8000c80:	60d3      	str	r3, [r2, #12]
	TIM4->DIER |= TIM_DIER_UIE;			// Enable update interrupts
 8000c82:	4b09      	ldr	r3, [pc, #36]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c84:	68db      	ldr	r3, [r3, #12]
 8000c86:	4a08      	ldr	r2, [pc, #32]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c88:	f043 0301 	orr.w	r3, r3, #1
 8000c8c:	60d3      	str	r3, [r2, #12]

	//    ii. enable TIM4 interrupt source in NVIC
	NVIC_EnableIRQ(TIM4_IRQn);      // Enable TIM4 interrupt in NVIC
 8000c8e:	201e      	movs	r0, #30
 8000c90:	f7ff feda 	bl	8000a48 <__NVIC_EnableIRQ>

	//10. Set TIMx_CR1 CEN bit to enable the TIM4 counter
	TIM4->CR1 |= TIM_CR1_CEN;				// Enable the counter
 8000c94:	4b04      	ldr	r3, [pc, #16]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c96:	681b      	ldr	r3, [r3, #0]
 8000c98:	4a03      	ldr	r2, [pc, #12]	@ (8000ca8 <TIM4_CH1_Init+0xa4>)
 8000c9a:	f043 0301 	orr.w	r3, r3, #1
 8000c9e:	6013      	str	r3, [r2, #0]
}
 8000ca0:	bf00      	nop
 8000ca2:	bd80      	pop	{r7, pc}
 8000ca4:	40021000 	.word	0x40021000
 8000ca8:	40000800 	.word	0x40000800

08000cac <TIM4_IRQHandler>:

//TIM4 ISR
void TIM4_IRQHandler(void) {
 8000cac:	b480      	push	{r7}
 8000cae:	af00      	add	r7, sp, #0

    if (TIM4->SR & TIM_SR_UIF) {
 8000cb0:	4b1f      	ldr	r3, [pc, #124]	@ (8000d30 <TIM4_IRQHandler+0x84>)
 8000cb2:	691b      	ldr	r3, [r3, #16]
 8000cb4:	f003 0301 	and.w	r3, r3, #1
 8000cb8:	2b00      	cmp	r3, #0
 8000cba:	d00a      	beq.n	8000cd2 <TIM4_IRQHandler+0x26>
        TIM4->SR &= ~TIM_SR_UIF;
 8000cbc:	4b1c      	ldr	r3, [pc, #112]	@ (8000d30 <TIM4_IRQHandler+0x84>)
 8000cbe:	691b      	ldr	r3, [r3, #16]
 8000cc0:	4a1b      	ldr	r2, [pc, #108]	@ (8000d30 <TIM4_IRQHandler+0x84>)
 8000cc2:	f023 0301 	bic.w	r3, r3, #1
 8000cc6:	6113      	str	r3, [r2, #16]
        overflow++;
 8000cc8:	4b1a      	ldr	r3, [pc, #104]	@ (8000d34 <TIM4_IRQHandler+0x88>)
 8000cca:	681b      	ldr	r3, [r3, #0]
 8000ccc:	3301      	adds	r3, #1
 8000cce:	4a19      	ldr	r2, [pc, #100]	@ (8000d34 <TIM4_IRQHandler+0x88>)
 8000cd0:	6013      	str	r3, [r2, #0]
    }

    if (TIM4->SR & TIM_SR_CC1IF) {
 8000cd2:	4b17      	ldr	r3, [pc, #92]	@ (8000d30 <TIM4_IRQHandler+0x84>)
 8000cd4:	691b      	ldr	r3, [r3, #16]
 8000cd6:	f003 0302 	and.w	r3, r3, #2
 8000cda:	2b00      	cmp	r3, #0
 8000cdc:	d022      	beq.n	8000d24 <TIM4_IRQHandler+0x78>
        current_CCR = TIM4->CCR1;
 8000cde:	4b14      	ldr	r3, [pc, #80]	@ (8000d30 <TIM4_IRQHandler+0x84>)
 8000ce0:	6b5b      	ldr	r3, [r3, #52]	@ 0x34
 8000ce2:	461a      	mov	r2, r3
 8000ce4:	4b14      	ldr	r3, [pc, #80]	@ (8000d38 <TIM4_IRQHandler+0x8c>)
 8000ce6:	601a      	str	r2, [r3, #0]
        TIM4->SR &= ~TIM_SR_CC1IF;
 8000ce8:	4b11      	ldr	r3, [pc, #68]	@ (8000d30 <TIM4_IRQHandler+0x84>)
 8000cea:	691b      	ldr	r3, [r3, #16]
 8000cec:	4a10      	ldr	r2, [pc, #64]	@ (8000d30 <TIM4_IRQHandler+0x84>)
 8000cee:	f023 0302 	bic.w	r3, r3, #2
 8000cf2:	6113      	str	r3, [r2, #16]

        time_span = ((current_CCR - previous_CCR) + (overflow * 10000)) * CNT_CLK_PERIOD_IN_MICRO_SECOND;
 8000cf4:	4b10      	ldr	r3, [pc, #64]	@ (8000d38 <TIM4_IRQHandler+0x8c>)
 8000cf6:	681a      	ldr	r2, [r3, #0]
 8000cf8:	4b10      	ldr	r3, [pc, #64]	@ (8000d3c <TIM4_IRQHandler+0x90>)
 8000cfa:	681b      	ldr	r3, [r3, #0]
 8000cfc:	1ad2      	subs	r2, r2, r3
 8000cfe:	4b0d      	ldr	r3, [pc, #52]	@ (8000d34 <TIM4_IRQHandler+0x88>)
 8000d00:	681b      	ldr	r3, [r3, #0]
 8000d02:	f242 7110 	movw	r1, #10000	@ 0x2710
 8000d06:	fb01 f303 	mul.w	r3, r1, r3
 8000d0a:	4413      	add	r3, r2
 8000d0c:	4a0c      	ldr	r2, [pc, #48]	@ (8000d40 <TIM4_IRQHandler+0x94>)
 8000d0e:	6013      	str	r3, [r2, #0]
        previous_CCR = current_CCR;
 8000d10:	4b09      	ldr	r3, [pc, #36]	@ (8000d38 <TIM4_IRQHandler+0x8c>)
 8000d12:	681b      	ldr	r3, [r3, #0]
 8000d14:	4a09      	ldr	r2, [pc, #36]	@ (8000d3c <TIM4_IRQHandler+0x90>)
 8000d16:	6013      	str	r3, [r2, #0]
        overflow = 0;
 8000d18:	4b06      	ldr	r3, [pc, #24]	@ (8000d34 <TIM4_IRQHandler+0x88>)
 8000d1a:	2200      	movs	r2, #0
 8000d1c:	601a      	str	r2, [r3, #0]
        new_measurement = 1;
 8000d1e:	4b09      	ldr	r3, [pc, #36]	@ (8000d44 <TIM4_IRQHandler+0x98>)
 8000d20:	2201      	movs	r2, #1
 8000d22:	601a      	str	r2, [r3, #0]
    }
}
 8000d24:	bf00      	nop
 8000d26:	46bd      	mov	sp, r7
 8000d28:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000d2c:	4770      	bx	lr
 8000d2e:	bf00      	nop
 8000d30:	40000800 	.word	0x40000800
 8000d34:	20000074 	.word	0x20000074
 8000d38:	20000078 	.word	0x20000078
 8000d3c:	2000007c 	.word	0x2000007c
 8000d40:	20000080 	.word	0x20000080
 8000d44:	20000088 	.word	0x20000088

08000d48 <init_hardware>:


// Global state variable
volatile uint8_t fan_state = 0;

void init_hardware(void) {
 8000d48:	b480      	push	{r7}
 8000d4a:	af00      	add	r7, sp, #0
    /* 1. Enable Clocks for GPIOA (Fan) and GPIOC (Button) */
    RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOAEN);
 8000d4c:	4b0d      	ldr	r3, [pc, #52]	@ (8000d84 <init_hardware+0x3c>)
 8000d4e:	6cdb      	ldr	r3, [r3, #76]	@ 0x4c
 8000d50:	4a0c      	ldr	r2, [pc, #48]	@ (8000d84 <init_hardware+0x3c>)
 8000d52:	f043 0301 	orr.w	r3, r3, #1
 8000d56:	64d3      	str	r3, [r2, #76]	@ 0x4c

    /* 2. Configure PA5 as Output (Fan) */
    GPIOA->MODER &= ~(3U << (5 * 2));
 8000d58:	f04f 4390 	mov.w	r3, #1207959552	@ 0x48000000
 8000d5c:	681b      	ldr	r3, [r3, #0]
 8000d5e:	f04f 4290 	mov.w	r2, #1207959552	@ 0x48000000
 8000d62:	f423 6340 	bic.w	r3, r3, #3072	@ 0xc00
 8000d66:	6013      	str	r3, [r2, #0]
    GPIOA->MODER |=  (1U << (5 * 2));
 8000d68:	f04f 4390 	mov.w	r3, #1207959552	@ 0x48000000
 8000d6c:	681b      	ldr	r3, [r3, #0]
 8000d6e:	f04f 4290 	mov.w	r2, #1207959552	@ 0x48000000
 8000d72:	f443 6380 	orr.w	r3, r3, #1024	@ 0x400
 8000d76:	6013      	str	r3, [r2, #0]
}
 8000d78:	bf00      	nop
 8000d7a:	46bd      	mov	sp, r7
 8000d7c:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000d80:	4770      	bx	lr
 8000d82:	bf00      	nop
 8000d84:	40021000 	.word	0x40021000

08000d88 <SystemClock_Config>:

void SystemClock_Config(void)
{
 8000d88:	b480      	push	{r7}
 8000d8a:	af00      	add	r7, sp, #0
    RCC->CR |= RCC_CR_HSION;
 8000d8c:	4b12      	ldr	r3, [pc, #72]	@ (8000dd8 <SystemClock_Config+0x50>)
 8000d8e:	681b      	ldr	r3, [r3, #0]
 8000d90:	4a11      	ldr	r2, [pc, #68]	@ (8000dd8 <SystemClock_Config+0x50>)
 8000d92:	f443 7380 	orr.w	r3, r3, #256	@ 0x100
 8000d96:	6013      	str	r3, [r2, #0]
    while (!(RCC->CR & RCC_CR_HSIRDY));
 8000d98:	bf00      	nop
 8000d9a:	4b0f      	ldr	r3, [pc, #60]	@ (8000dd8 <SystemClock_Config+0x50>)
 8000d9c:	681b      	ldr	r3, [r3, #0]
 8000d9e:	f403 6380 	and.w	r3, r3, #1024	@ 0x400
 8000da2:	2b00      	cmp	r3, #0
 8000da4:	d0f9      	beq.n	8000d9a <SystemClock_Config+0x12>

    RCC->CFGR &= ~RCC_CFGR_SW;
 8000da6:	4b0c      	ldr	r3, [pc, #48]	@ (8000dd8 <SystemClock_Config+0x50>)
 8000da8:	689b      	ldr	r3, [r3, #8]
 8000daa:	4a0b      	ldr	r2, [pc, #44]	@ (8000dd8 <SystemClock_Config+0x50>)
 8000dac:	f023 0303 	bic.w	r3, r3, #3
 8000db0:	6093      	str	r3, [r2, #8]
    RCC->CFGR |= RCC_CFGR_SW_HSI;
 8000db2:	4b09      	ldr	r3, [pc, #36]	@ (8000dd8 <SystemClock_Config+0x50>)
 8000db4:	689b      	ldr	r3, [r3, #8]
 8000db6:	4a08      	ldr	r2, [pc, #32]	@ (8000dd8 <SystemClock_Config+0x50>)
 8000db8:	f043 0301 	orr.w	r3, r3, #1
 8000dbc:	6093      	str	r3, [r2, #8]

    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);
 8000dbe:	bf00      	nop
 8000dc0:	4b05      	ldr	r3, [pc, #20]	@ (8000dd8 <SystemClock_Config+0x50>)
 8000dc2:	689b      	ldr	r3, [r3, #8]
 8000dc4:	f003 030c 	and.w	r3, r3, #12
 8000dc8:	2b04      	cmp	r3, #4
 8000dca:	d1f9      	bne.n	8000dc0 <SystemClock_Config+0x38>
}
 8000dcc:	bf00      	nop
 8000dce:	bf00      	nop
 8000dd0:	46bd      	mov	sp, r7
 8000dd2:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000dd6:	4770      	bx	lr
 8000dd8:	40021000 	.word	0x40021000

08000ddc <delay_ms>:

Simple delay*
Rough delay for visible servo movement.
---------------------------------------------------- */
void delay_ms(uint32_t ms)
{
 8000ddc:	b480      	push	{r7}
 8000dde:	b085      	sub	sp, #20
 8000de0:	af00      	add	r7, sp, #0
 8000de2:	6078      	str	r0, [r7, #4]
    for (uint32_t i = 0; i < ms; i++)
 8000de4:	2300      	movs	r3, #0
 8000de6:	60fb      	str	r3, [r7, #12]
 8000de8:	e00c      	b.n	8000e04 <delay_ms+0x28>
    {
        for (volatile uint32_t j = 0; j < 4000; j++);
 8000dea:	2300      	movs	r3, #0
 8000dec:	60bb      	str	r3, [r7, #8]
 8000dee:	e002      	b.n	8000df6 <delay_ms+0x1a>
 8000df0:	68bb      	ldr	r3, [r7, #8]
 8000df2:	3301      	adds	r3, #1
 8000df4:	60bb      	str	r3, [r7, #8]
 8000df6:	68bb      	ldr	r3, [r7, #8]
 8000df8:	f5b3 6f7a 	cmp.w	r3, #4000	@ 0xfa0
 8000dfc:	d3f8      	bcc.n	8000df0 <delay_ms+0x14>
    for (uint32_t i = 0; i < ms; i++)
 8000dfe:	68fb      	ldr	r3, [r7, #12]
 8000e00:	3301      	adds	r3, #1
 8000e02:	60fb      	str	r3, [r7, #12]
 8000e04:	68fa      	ldr	r2, [r7, #12]
 8000e06:	687b      	ldr	r3, [r7, #4]
 8000e08:	429a      	cmp	r2, r3
 8000e0a:	d3ee      	bcc.n	8000dea <delay_ms+0xe>
    }
}
 8000e0c:	bf00      	nop
 8000e0e:	bf00      	nop
 8000e10:	3714      	adds	r7, #20
 8000e12:	46bd      	mov	sp, r7
 8000e14:	f85d 7b04 	ldr.w	r7, [sp], #4
 8000e18:	4770      	bx	lr
	...

08000e1c <main>:

main()
---------------------------------------------------- */

int main(void)
{
 8000e1c:	b580      	push	{r7, lr}
 8000e1e:	af00      	add	r7, sp, #0

    SystemClock_Config();
 8000e20:	f7ff ffb2 	bl	8000d88 <SystemClock_Config>
    FPU_Enable();
 8000e24:	f7ff fe2e 	bl	8000a84 <FPU_Enable>

    init_hardware();
 8000e28:	f7ff ff8e 	bl	8000d48 <init_hardware>

    configure_PB6();       // Echo
 8000e2c:	f7ff fe3c 	bl	8000aa8 <configure_PB6>
    configure_PB10();      // Trigger
 8000e30:	f7ff fe64 	bl	8000afc <configure_PB10>

    TIM4_CH1_Init();       // Echo input capture
 8000e34:	f7ff fee6 	bl	8000c04 <TIM4_CH1_Init>
    TIM2_CH3_Init();       // Trigger pulse
 8000e38:	f7ff fe96 	bl	8000b68 <TIM2_CH3_Init>

    DWT_Delay_Init();
 8000e3c:	f7ff fa18 	bl	8000270 <DWT_Delay_Init>

    LCD_Init();
 8000e40:	f7ff fd8f 	bl	8000962 <LCD_Init>
    DHT_SetPinInput();
 8000e44:	f7ff fa8c 	bl	8000360 <DHT_SetPinInput>

    delay_us(3000000);
 8000e48:	4823      	ldr	r0, [pc, #140]	@ (8000ed8 <main+0xbc>)
 8000e4a:	f7ff fa2b 	bl	80002a4 <delay_us>


	while (1)
	{
	    if (new_measurement)
 8000e4e:	4b23      	ldr	r3, [pc, #140]	@ (8000edc <main+0xc0>)
 8000e50:	681b      	ldr	r3, [r3, #0]
 8000e52:	2b00      	cmp	r3, #0
 8000e54:	d03c      	beq.n	8000ed0 <main+0xb4>
	    {
	        new_measurement = 0;
 8000e56:	4b21      	ldr	r3, [pc, #132]	@ (8000edc <main+0xc0>)
 8000e58:	2200      	movs	r2, #0
 8000e5a:	601a      	str	r2, [r3, #0]

	        distance = ((float)time_span * 0.0343f) / 2.0f;
 8000e5c:	4b20      	ldr	r3, [pc, #128]	@ (8000ee0 <main+0xc4>)
 8000e5e:	681b      	ldr	r3, [r3, #0]
 8000e60:	ee07 3a90 	vmov	s15, r3
 8000e64:	eef8 7ae7 	vcvt.f32.s32	s15, s15
 8000e68:	ed9f 7a1e 	vldr	s14, [pc, #120]	@ 8000ee4 <main+0xc8>
 8000e6c:	ee27 7a87 	vmul.f32	s14, s15, s14
 8000e70:	eef0 6a00 	vmov.f32	s13, #0	@ 0x40000000  2.0
 8000e74:	eec7 7a26 	vdiv.f32	s15, s14, s13
 8000e78:	4b1b      	ldr	r3, [pc, #108]	@ (8000ee8 <main+0xcc>)
 8000e7a:	edc3 7a00 	vstr	s15, [r3]

	        if (distance > 2.0f && distance <= 10.0f)
 8000e7e:	4b1a      	ldr	r3, [pc, #104]	@ (8000ee8 <main+0xcc>)
 8000e80:	edd3 7a00 	vldr	s15, [r3]
 8000e84:	eeb0 7a00 	vmov.f32	s14, #0	@ 0x40000000  2.0
 8000e88:	eef4 7ac7 	vcmpe.f32	s15, s14
 8000e8c:	eef1 fa10 	vmrs	APSR_nzcv, fpscr
 8000e90:	dd10      	ble.n	8000eb4 <main+0x98>
 8000e92:	4b15      	ldr	r3, [pc, #84]	@ (8000ee8 <main+0xcc>)
 8000e94:	edd3 7a00 	vldr	s15, [r3]
 8000e98:	eeb2 7a04 	vmov.f32	s14, #36	@ 0x41200000  10.0
 8000e9c:	eef4 7ac7 	vcmpe.f32	s15, s14
 8000ea0:	eef1 fa10 	vmrs	APSR_nzcv, fpscr
 8000ea4:	d806      	bhi.n	8000eb4 <main+0x98>
	        {
	            // Object detected: show DHT reading
	            DHT_Display();
 8000ea6:	f7ff fb3d 	bl	8000524 <DHT_Display>
	            GPIOA->BSRR = (1U << 5);
 8000eaa:	f04f 4390 	mov.w	r3, #1207959552	@ 0x48000000
 8000eae:	2220      	movs	r2, #32
 8000eb0:	619a      	str	r2, [r3, #24]
 8000eb2:	e00d      	b.n	8000ed0 <main+0xb4>
	        }
	        else
	        {
	            // Nothing detected: clear LCD
	            lcd_clear();
 8000eb4:	f7ff fd8d 	bl	80009d2 <lcd_clear>
	            lcd_put_cur(0, 0);
 8000eb8:	2100      	movs	r1, #0
 8000eba:	2000      	movs	r0, #0
 8000ebc:	f7ff fd93 	bl	80009e6 <lcd_put_cur>
	            lcd_send_string("No object");
 8000ec0:	480a      	ldr	r0, [pc, #40]	@ (8000eec <main+0xd0>)
 8000ec2:	f7ff fdaa 	bl	8000a1a <lcd_send_string>
	            GPIOA->BSRR = (1u << 21);
 8000ec6:	f04f 4390 	mov.w	r3, #1207959552	@ 0x48000000
 8000eca:	f44f 1200 	mov.w	r2, #2097152	@ 0x200000
 8000ece:	619a      	str	r2, [r3, #24]
	        }
	    }

	    delay_ms(200);
 8000ed0:	20c8      	movs	r0, #200	@ 0xc8
 8000ed2:	f7ff ff83 	bl	8000ddc <delay_ms>
	    if (new_measurement)
 8000ed6:	e7ba      	b.n	8000e4e <main+0x32>
 8000ed8:	002dc6c0 	.word	0x002dc6c0
 8000edc:	20000088 	.word	0x20000088
 8000ee0:	20000080 	.word	0x20000080
 8000ee4:	3d0c7e28 	.word	0x3d0c7e28
 8000ee8:	20000084 	.word	0x20000084
 8000eec:	08001960 	.word	0x08001960

08000ef0 <_sbrk>:
 *
 * @param incr Memory size
 * @return Pointer to allocated memory
 */
void *_sbrk(ptrdiff_t incr)
{
 8000ef0:	b580      	push	{r7, lr}
 8000ef2:	b086      	sub	sp, #24
 8000ef4:	af00      	add	r7, sp, #0
 8000ef6:	6078      	str	r0, [r7, #4]
  extern uint8_t _end; /* Symbol defined in the linker script */
  extern uint8_t _estack; /* Symbol defined in the linker script */
  extern uint32_t _Min_Stack_Size; /* Symbol defined in the linker script */
  const uint32_t stack_limit = (uint32_t)&_estack - (uint32_t)&_Min_Stack_Size;
 8000ef8:	4a14      	ldr	r2, [pc, #80]	@ (8000f4c <_sbrk+0x5c>)
 8000efa:	4b15      	ldr	r3, [pc, #84]	@ (8000f50 <_sbrk+0x60>)
 8000efc:	1ad3      	subs	r3, r2, r3
 8000efe:	617b      	str	r3, [r7, #20]
  const uint8_t *max_heap = (uint8_t *)stack_limit;
 8000f00:	697b      	ldr	r3, [r7, #20]
 8000f02:	613b      	str	r3, [r7, #16]
  uint8_t *prev_heap_end;

  /* Initialize heap end at first call */
  if (NULL == __sbrk_heap_end)
 8000f04:	4b13      	ldr	r3, [pc, #76]	@ (8000f54 <_sbrk+0x64>)
 8000f06:	681b      	ldr	r3, [r3, #0]
 8000f08:	2b00      	cmp	r3, #0
 8000f0a:	d102      	bne.n	8000f12 <_sbrk+0x22>
  {
    __sbrk_heap_end = &_end;
 8000f0c:	4b11      	ldr	r3, [pc, #68]	@ (8000f54 <_sbrk+0x64>)
 8000f0e:	4a12      	ldr	r2, [pc, #72]	@ (8000f58 <_sbrk+0x68>)
 8000f10:	601a      	str	r2, [r3, #0]
  }

  /* Protect heap from growing into the reserved MSP stack */
  if (__sbrk_heap_end + incr > max_heap)
 8000f12:	4b10      	ldr	r3, [pc, #64]	@ (8000f54 <_sbrk+0x64>)
 8000f14:	681a      	ldr	r2, [r3, #0]
 8000f16:	687b      	ldr	r3, [r7, #4]
 8000f18:	4413      	add	r3, r2
 8000f1a:	693a      	ldr	r2, [r7, #16]
 8000f1c:	429a      	cmp	r2, r3
 8000f1e:	d207      	bcs.n	8000f30 <_sbrk+0x40>
  {
    errno = ENOMEM;
 8000f20:	f000 f87c 	bl	800101c <__errno>
 8000f24:	4603      	mov	r3, r0
 8000f26:	220c      	movs	r2, #12
 8000f28:	601a      	str	r2, [r3, #0]
    return (void *)-1;
 8000f2a:	f04f 33ff 	mov.w	r3, #4294967295
 8000f2e:	e009      	b.n	8000f44 <_sbrk+0x54>
  }

  prev_heap_end = __sbrk_heap_end;
 8000f30:	4b08      	ldr	r3, [pc, #32]	@ (8000f54 <_sbrk+0x64>)
 8000f32:	681b      	ldr	r3, [r3, #0]
 8000f34:	60fb      	str	r3, [r7, #12]
  __sbrk_heap_end += incr;
 8000f36:	4b07      	ldr	r3, [pc, #28]	@ (8000f54 <_sbrk+0x64>)
 8000f38:	681a      	ldr	r2, [r3, #0]
 8000f3a:	687b      	ldr	r3, [r7, #4]
 8000f3c:	4413      	add	r3, r2
 8000f3e:	4a05      	ldr	r2, [pc, #20]	@ (8000f54 <_sbrk+0x64>)
 8000f40:	6013      	str	r3, [r2, #0]

  return (void *)prev_heap_end;
 8000f42:	68fb      	ldr	r3, [r7, #12]
}
 8000f44:	4618      	mov	r0, r3
 8000f46:	3718      	adds	r7, #24
 8000f48:	46bd      	mov	sp, r7
 8000f4a:	bd80      	pop	{r7, pc}
 8000f4c:	20018000 	.word	0x20018000
 8000f50:	00000400 	.word	0x00000400
 8000f54:	2000008c 	.word	0x2000008c
 8000f58:	200001d8 	.word	0x200001d8

08000f5c <Reset_Handler>:

  .section .text.Reset_Handler
  .weak Reset_Handler
  .type Reset_Handler, %function
Reset_Handler:
  ldr   r0, =_estack
 8000f5c:	480d      	ldr	r0, [pc, #52]	@ (8000f94 <LoopForever+0x2>)
  mov   sp, r0          /* set stack pointer */
 8000f5e:	4685      	mov	sp, r0
/* Call the clock system initialization function.*/
  bl  SystemInit
 8000f60:	f3af 8000 	nop.w

/* Copy the data segment initializers from flash to SRAM */
  ldr r0, =_sdata
 8000f64:	480c      	ldr	r0, [pc, #48]	@ (8000f98 <LoopForever+0x6>)
  ldr r1, =_edata
 8000f66:	490d      	ldr	r1, [pc, #52]	@ (8000f9c <LoopForever+0xa>)
  ldr r2, =_sidata
 8000f68:	4a0d      	ldr	r2, [pc, #52]	@ (8000fa0 <LoopForever+0xe>)
  movs r3, #0
 8000f6a:	2300      	movs	r3, #0
  b LoopCopyDataInit
 8000f6c:	e002      	b.n	8000f74 <LoopCopyDataInit>

08000f6e <CopyDataInit>:

CopyDataInit:
  ldr r4, [r2, r3]
 8000f6e:	58d4      	ldr	r4, [r2, r3]
  str r4, [r0, r3]
 8000f70:	50c4      	str	r4, [r0, r3]
  adds r3, r3, #4
 8000f72:	3304      	adds	r3, #4

08000f74 <LoopCopyDataInit>:

LoopCopyDataInit:
  adds r4, r0, r3
 8000f74:	18c4      	adds	r4, r0, r3
  cmp r4, r1
 8000f76:	428c      	cmp	r4, r1
  bcc CopyDataInit
 8000f78:	d3f9      	bcc.n	8000f6e <CopyDataInit>

/* Zero fill the bss segment. */
  ldr r2, =_sbss
 8000f7a:	4a0a      	ldr	r2, [pc, #40]	@ (8000fa4 <LoopForever+0x12>)
  ldr r4, =_ebss
 8000f7c:	4c0a      	ldr	r4, [pc, #40]	@ (8000fa8 <LoopForever+0x16>)
  movs r3, #0
 8000f7e:	2300      	movs	r3, #0
  b LoopFillZerobss
 8000f80:	e001      	b.n	8000f86 <LoopFillZerobss>

08000f82 <FillZerobss>:

FillZerobss:
  str  r3, [r2]
 8000f82:	6013      	str	r3, [r2, #0]
  adds r2, r2, #4
 8000f84:	3204      	adds	r2, #4

08000f86 <LoopFillZerobss>:

LoopFillZerobss:
  cmp r2, r4
 8000f86:	42a2      	cmp	r2, r4
  bcc FillZerobss
 8000f88:	d3fb      	bcc.n	8000f82 <FillZerobss>


/* Call static constructors */
  bl __libc_init_array
 8000f8a:	f000 f84d 	bl	8001028 <__libc_init_array>
/* Call the application's entry point.*/

  bl main
 8000f8e:	f7ff ff45 	bl	8000e1c <main>

08000f92 <LoopForever>:

LoopForever:
  b LoopForever
 8000f92:	e7fe      	b.n	8000f92 <LoopForever>
  ldr   r0, =_estack
 8000f94:	20018000 	.word	0x20018000
  ldr r0, =_sdata
 8000f98:	20000000 	.word	0x20000000
  ldr r1, =_edata
 8000f9c:	20000050 	.word	0x20000050
  ldr r2, =_sidata
 8000fa0:	080019b0 	.word	0x080019b0
  ldr r2, =_sbss
 8000fa4:	20000050 	.word	0x20000050
  ldr r4, =_ebss
 8000fa8:	200001d8 	.word	0x200001d8

08000fac <ADC1_2_IRQHandler>:
 * @retval : None
*/
  .section .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
  b Infinite_Loop
 8000fac:	e7fe      	b.n	8000fac <ADC1_2_IRQHandler>
	...

08000fb0 <sniprintf>:
 8000fb0:	b40c      	push	{r2, r3}
 8000fb2:	b530      	push	{r4, r5, lr}
 8000fb4:	4b18      	ldr	r3, [pc, #96]	@ (8001018 <sniprintf+0x68>)
 8000fb6:	1e0c      	subs	r4, r1, #0
 8000fb8:	681d      	ldr	r5, [r3, #0]
 8000fba:	b09d      	sub	sp, #116	@ 0x74
 8000fbc:	da08      	bge.n	8000fd0 <sniprintf+0x20>
 8000fbe:	238b      	movs	r3, #139	@ 0x8b
 8000fc0:	602b      	str	r3, [r5, #0]
 8000fc2:	f04f 30ff 	mov.w	r0, #4294967295
 8000fc6:	b01d      	add	sp, #116	@ 0x74
 8000fc8:	e8bd 4030 	ldmia.w	sp!, {r4, r5, lr}
 8000fcc:	b002      	add	sp, #8
 8000fce:	4770      	bx	lr
 8000fd0:	f44f 7302 	mov.w	r3, #520	@ 0x208
 8000fd4:	f8ad 3014 	strh.w	r3, [sp, #20]
 8000fd8:	f04f 0300 	mov.w	r3, #0
 8000fdc:	931b      	str	r3, [sp, #108]	@ 0x6c
 8000fde:	bf14      	ite	ne
 8000fe0:	f104 33ff 	addne.w	r3, r4, #4294967295
 8000fe4:	4623      	moveq	r3, r4
 8000fe6:	9304      	str	r3, [sp, #16]
 8000fe8:	9307      	str	r3, [sp, #28]
 8000fea:	f64f 73ff 	movw	r3, #65535	@ 0xffff
 8000fee:	9002      	str	r0, [sp, #8]
 8000ff0:	9006      	str	r0, [sp, #24]
 8000ff2:	f8ad 3016 	strh.w	r3, [sp, #22]
 8000ff6:	9a20      	ldr	r2, [sp, #128]	@ 0x80
 8000ff8:	ab21      	add	r3, sp, #132	@ 0x84
 8000ffa:	a902      	add	r1, sp, #8
 8000ffc:	4628      	mov	r0, r5
 8000ffe:	9301      	str	r3, [sp, #4]
 8001000:	f000 f98c 	bl	800131c <_svfiprintf_r>
 8001004:	1c43      	adds	r3, r0, #1
 8001006:	bfbc      	itt	lt
 8001008:	238b      	movlt	r3, #139	@ 0x8b
 800100a:	602b      	strlt	r3, [r5, #0]
 800100c:	2c00      	cmp	r4, #0
 800100e:	d0da      	beq.n	8000fc6 <sniprintf+0x16>
 8001010:	9b02      	ldr	r3, [sp, #8]
 8001012:	2200      	movs	r2, #0
 8001014:	701a      	strb	r2, [r3, #0]
 8001016:	e7d6      	b.n	8000fc6 <sniprintf+0x16>
 8001018:	20000000 	.word	0x20000000

0800101c <__errno>:
 800101c:	4b01      	ldr	r3, [pc, #4]	@ (8001024 <__errno+0x8>)
 800101e:	6818      	ldr	r0, [r3, #0]
 8001020:	4770      	bx	lr
 8001022:	bf00      	nop
 8001024:	20000000 	.word	0x20000000

08001028 <__libc_init_array>:
 8001028:	b570      	push	{r4, r5, r6, lr}
 800102a:	4d0d      	ldr	r5, [pc, #52]	@ (8001060 <__libc_init_array+0x38>)
 800102c:	4c0d      	ldr	r4, [pc, #52]	@ (8001064 <__libc_init_array+0x3c>)
 800102e:	1b64      	subs	r4, r4, r5
 8001030:	10a4      	asrs	r4, r4, #2
 8001032:	2600      	movs	r6, #0
 8001034:	42a6      	cmp	r6, r4
 8001036:	d109      	bne.n	800104c <__libc_init_array+0x24>
 8001038:	4d0b      	ldr	r5, [pc, #44]	@ (8001068 <__libc_init_array+0x40>)
 800103a:	4c0c      	ldr	r4, [pc, #48]	@ (800106c <__libc_init_array+0x44>)
 800103c:	f000 fc64 	bl	8001908 <_init>
 8001040:	1b64      	subs	r4, r4, r5
 8001042:	10a4      	asrs	r4, r4, #2
 8001044:	2600      	movs	r6, #0
 8001046:	42a6      	cmp	r6, r4
 8001048:	d105      	bne.n	8001056 <__libc_init_array+0x2e>
 800104a:	bd70      	pop	{r4, r5, r6, pc}
 800104c:	f855 3b04 	ldr.w	r3, [r5], #4
 8001050:	4798      	blx	r3
 8001052:	3601      	adds	r6, #1
 8001054:	e7ee      	b.n	8001034 <__libc_init_array+0xc>
 8001056:	f855 3b04 	ldr.w	r3, [r5], #4
 800105a:	4798      	blx	r3
 800105c:	3601      	adds	r6, #1
 800105e:	e7f2      	b.n	8001046 <__libc_init_array+0x1e>
 8001060:	080019a8 	.word	0x080019a8
 8001064:	080019a8 	.word	0x080019a8
 8001068:	080019a8 	.word	0x080019a8
 800106c:	080019ac 	.word	0x080019ac

08001070 <__retarget_lock_acquire_recursive>:
 8001070:	4770      	bx	lr

08001072 <__retarget_lock_release_recursive>:
 8001072:	4770      	bx	lr

08001074 <_free_r>:
 8001074:	b538      	push	{r3, r4, r5, lr}
 8001076:	4605      	mov	r5, r0
 8001078:	2900      	cmp	r1, #0
 800107a:	d041      	beq.n	8001100 <_free_r+0x8c>
 800107c:	f851 3c04 	ldr.w	r3, [r1, #-4]
 8001080:	1f0c      	subs	r4, r1, #4
 8001082:	2b00      	cmp	r3, #0
 8001084:	bfb8      	it	lt
 8001086:	18e4      	addlt	r4, r4, r3
 8001088:	f000 f8e0 	bl	800124c <__malloc_lock>
 800108c:	4a1d      	ldr	r2, [pc, #116]	@ (8001104 <_free_r+0x90>)
 800108e:	6813      	ldr	r3, [r2, #0]
 8001090:	b933      	cbnz	r3, 80010a0 <_free_r+0x2c>
 8001092:	6063      	str	r3, [r4, #4]
 8001094:	6014      	str	r4, [r2, #0]
 8001096:	4628      	mov	r0, r5
 8001098:	e8bd 4038 	ldmia.w	sp!, {r3, r4, r5, lr}
 800109c:	f000 b8dc 	b.w	8001258 <__malloc_unlock>
 80010a0:	42a3      	cmp	r3, r4
 80010a2:	d908      	bls.n	80010b6 <_free_r+0x42>
 80010a4:	6820      	ldr	r0, [r4, #0]
 80010a6:	1821      	adds	r1, r4, r0
 80010a8:	428b      	cmp	r3, r1
 80010aa:	bf01      	itttt	eq
 80010ac:	6819      	ldreq	r1, [r3, #0]
 80010ae:	685b      	ldreq	r3, [r3, #4]
 80010b0:	1809      	addeq	r1, r1, r0
 80010b2:	6021      	streq	r1, [r4, #0]
 80010b4:	e7ed      	b.n	8001092 <_free_r+0x1e>
 80010b6:	461a      	mov	r2, r3
 80010b8:	685b      	ldr	r3, [r3, #4]
 80010ba:	b10b      	cbz	r3, 80010c0 <_free_r+0x4c>
 80010bc:	42a3      	cmp	r3, r4
 80010be:	d9fa      	bls.n	80010b6 <_free_r+0x42>
 80010c0:	6811      	ldr	r1, [r2, #0]
 80010c2:	1850      	adds	r0, r2, r1
 80010c4:	42a0      	cmp	r0, r4
 80010c6:	d10b      	bne.n	80010e0 <_free_r+0x6c>
 80010c8:	6820      	ldr	r0, [r4, #0]
 80010ca:	4401      	add	r1, r0
 80010cc:	1850      	adds	r0, r2, r1
 80010ce:	4283      	cmp	r3, r0
 80010d0:	6011      	str	r1, [r2, #0]
 80010d2:	d1e0      	bne.n	8001096 <_free_r+0x22>
 80010d4:	6818      	ldr	r0, [r3, #0]
 80010d6:	685b      	ldr	r3, [r3, #4]
 80010d8:	6053      	str	r3, [r2, #4]
 80010da:	4408      	add	r0, r1
 80010dc:	6010      	str	r0, [r2, #0]
 80010de:	e7da      	b.n	8001096 <_free_r+0x22>
 80010e0:	d902      	bls.n	80010e8 <_free_r+0x74>
 80010e2:	230c      	movs	r3, #12
 80010e4:	602b      	str	r3, [r5, #0]
 80010e6:	e7d6      	b.n	8001096 <_free_r+0x22>
 80010e8:	6820      	ldr	r0, [r4, #0]
 80010ea:	1821      	adds	r1, r4, r0
 80010ec:	428b      	cmp	r3, r1
 80010ee:	bf04      	itt	eq
 80010f0:	6819      	ldreq	r1, [r3, #0]
 80010f2:	685b      	ldreq	r3, [r3, #4]
 80010f4:	6063      	str	r3, [r4, #4]
 80010f6:	bf04      	itt	eq
 80010f8:	1809      	addeq	r1, r1, r0
 80010fa:	6021      	streq	r1, [r4, #0]
 80010fc:	6054      	str	r4, [r2, #4]
 80010fe:	e7ca      	b.n	8001096 <_free_r+0x22>
 8001100:	bd38      	pop	{r3, r4, r5, pc}
 8001102:	bf00      	nop
 8001104:	200001d4 	.word	0x200001d4

08001108 <sbrk_aligned>:
 8001108:	b570      	push	{r4, r5, r6, lr}
 800110a:	4e0f      	ldr	r6, [pc, #60]	@ (8001148 <sbrk_aligned+0x40>)
 800110c:	460c      	mov	r4, r1
 800110e:	6831      	ldr	r1, [r6, #0]
 8001110:	4605      	mov	r5, r0
 8001112:	b911      	cbnz	r1, 800111a <sbrk_aligned+0x12>
 8001114:	f000 fba4 	bl	8001860 <_sbrk_r>
 8001118:	6030      	str	r0, [r6, #0]
 800111a:	4621      	mov	r1, r4
 800111c:	4628      	mov	r0, r5
 800111e:	f000 fb9f 	bl	8001860 <_sbrk_r>
 8001122:	1c43      	adds	r3, r0, #1
 8001124:	d103      	bne.n	800112e <sbrk_aligned+0x26>
 8001126:	f04f 34ff 	mov.w	r4, #4294967295
 800112a:	4620      	mov	r0, r4
 800112c:	bd70      	pop	{r4, r5, r6, pc}
 800112e:	1cc4      	adds	r4, r0, #3
 8001130:	f024 0403 	bic.w	r4, r4, #3
 8001134:	42a0      	cmp	r0, r4
 8001136:	d0f8      	beq.n	800112a <sbrk_aligned+0x22>
 8001138:	1a21      	subs	r1, r4, r0
 800113a:	4628      	mov	r0, r5
 800113c:	f000 fb90 	bl	8001860 <_sbrk_r>
 8001140:	3001      	adds	r0, #1
 8001142:	d1f2      	bne.n	800112a <sbrk_aligned+0x22>
 8001144:	e7ef      	b.n	8001126 <sbrk_aligned+0x1e>
 8001146:	bf00      	nop
 8001148:	200001d0 	.word	0x200001d0

0800114c <_malloc_r>:
 800114c:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
 8001150:	1ccd      	adds	r5, r1, #3
 8001152:	f025 0503 	bic.w	r5, r5, #3
 8001156:	3508      	adds	r5, #8
 8001158:	2d0c      	cmp	r5, #12
 800115a:	bf38      	it	cc
 800115c:	250c      	movcc	r5, #12
 800115e:	2d00      	cmp	r5, #0
 8001160:	4606      	mov	r6, r0
 8001162:	db01      	blt.n	8001168 <_malloc_r+0x1c>
 8001164:	42a9      	cmp	r1, r5
 8001166:	d904      	bls.n	8001172 <_malloc_r+0x26>
 8001168:	230c      	movs	r3, #12
 800116a:	6033      	str	r3, [r6, #0]
 800116c:	2000      	movs	r0, #0
 800116e:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
 8001172:	f8df 80d4 	ldr.w	r8, [pc, #212]	@ 8001248 <_malloc_r+0xfc>
 8001176:	f000 f869 	bl	800124c <__malloc_lock>
 800117a:	f8d8 3000 	ldr.w	r3, [r8]
 800117e:	461c      	mov	r4, r3
 8001180:	bb44      	cbnz	r4, 80011d4 <_malloc_r+0x88>
 8001182:	4629      	mov	r1, r5
 8001184:	4630      	mov	r0, r6
 8001186:	f7ff ffbf 	bl	8001108 <sbrk_aligned>
 800118a:	1c43      	adds	r3, r0, #1
 800118c:	4604      	mov	r4, r0
 800118e:	d158      	bne.n	8001242 <_malloc_r+0xf6>
 8001190:	f8d8 4000 	ldr.w	r4, [r8]
 8001194:	4627      	mov	r7, r4
 8001196:	2f00      	cmp	r7, #0
 8001198:	d143      	bne.n	8001222 <_malloc_r+0xd6>
 800119a:	2c00      	cmp	r4, #0
 800119c:	d04b      	beq.n	8001236 <_malloc_r+0xea>
 800119e:	6823      	ldr	r3, [r4, #0]
 80011a0:	4639      	mov	r1, r7
 80011a2:	4630      	mov	r0, r6
 80011a4:	eb04 0903 	add.w	r9, r4, r3
 80011a8:	f000 fb5a 	bl	8001860 <_sbrk_r>
 80011ac:	4581      	cmp	r9, r0
 80011ae:	d142      	bne.n	8001236 <_malloc_r+0xea>
 80011b0:	6821      	ldr	r1, [r4, #0]
 80011b2:	1a6d      	subs	r5, r5, r1
 80011b4:	4629      	mov	r1, r5
 80011b6:	4630      	mov	r0, r6
 80011b8:	f7ff ffa6 	bl	8001108 <sbrk_aligned>
 80011bc:	3001      	adds	r0, #1
 80011be:	d03a      	beq.n	8001236 <_malloc_r+0xea>
 80011c0:	6823      	ldr	r3, [r4, #0]
 80011c2:	442b      	add	r3, r5
 80011c4:	6023      	str	r3, [r4, #0]
 80011c6:	f8d8 3000 	ldr.w	r3, [r8]
 80011ca:	685a      	ldr	r2, [r3, #4]
 80011cc:	bb62      	cbnz	r2, 8001228 <_malloc_r+0xdc>
 80011ce:	f8c8 7000 	str.w	r7, [r8]
 80011d2:	e00f      	b.n	80011f4 <_malloc_r+0xa8>
 80011d4:	6822      	ldr	r2, [r4, #0]
 80011d6:	1b52      	subs	r2, r2, r5
 80011d8:	d420      	bmi.n	800121c <_malloc_r+0xd0>
 80011da:	2a0b      	cmp	r2, #11
 80011dc:	d917      	bls.n	800120e <_malloc_r+0xc2>
 80011de:	1961      	adds	r1, r4, r5
 80011e0:	42a3      	cmp	r3, r4
 80011e2:	6025      	str	r5, [r4, #0]
 80011e4:	bf18      	it	ne
 80011e6:	6059      	strne	r1, [r3, #4]
 80011e8:	6863      	ldr	r3, [r4, #4]
 80011ea:	bf08      	it	eq
 80011ec:	f8c8 1000 	streq.w	r1, [r8]
 80011f0:	5162      	str	r2, [r4, r5]
 80011f2:	604b      	str	r3, [r1, #4]
 80011f4:	4630      	mov	r0, r6
 80011f6:	f000 f82f 	bl	8001258 <__malloc_unlock>
 80011fa:	f104 000b 	add.w	r0, r4, #11
 80011fe:	1d23      	adds	r3, r4, #4
 8001200:	f020 0007 	bic.w	r0, r0, #7
 8001204:	1ac2      	subs	r2, r0, r3
 8001206:	bf1c      	itt	ne
 8001208:	1a1b      	subne	r3, r3, r0
 800120a:	50a3      	strne	r3, [r4, r2]
 800120c:	e7af      	b.n	800116e <_malloc_r+0x22>
 800120e:	6862      	ldr	r2, [r4, #4]
 8001210:	42a3      	cmp	r3, r4
 8001212:	bf0c      	ite	eq
 8001214:	f8c8 2000 	streq.w	r2, [r8]
 8001218:	605a      	strne	r2, [r3, #4]
 800121a:	e7eb      	b.n	80011f4 <_malloc_r+0xa8>
 800121c:	4623      	mov	r3, r4
 800121e:	6864      	ldr	r4, [r4, #4]
 8001220:	e7ae      	b.n	8001180 <_malloc_r+0x34>
 8001222:	463c      	mov	r4, r7
 8001224:	687f      	ldr	r7, [r7, #4]
 8001226:	e7b6      	b.n	8001196 <_malloc_r+0x4a>
 8001228:	461a      	mov	r2, r3
 800122a:	685b      	ldr	r3, [r3, #4]
 800122c:	42a3      	cmp	r3, r4
 800122e:	d1fb      	bne.n	8001228 <_malloc_r+0xdc>
 8001230:	2300      	movs	r3, #0
 8001232:	6053      	str	r3, [r2, #4]
 8001234:	e7de      	b.n	80011f4 <_malloc_r+0xa8>
 8001236:	230c      	movs	r3, #12
 8001238:	6033      	str	r3, [r6, #0]
 800123a:	4630      	mov	r0, r6
 800123c:	f000 f80c 	bl	8001258 <__malloc_unlock>
 8001240:	e794      	b.n	800116c <_malloc_r+0x20>
 8001242:	6005      	str	r5, [r0, #0]
 8001244:	e7d6      	b.n	80011f4 <_malloc_r+0xa8>
 8001246:	bf00      	nop
 8001248:	200001d4 	.word	0x200001d4

0800124c <__malloc_lock>:
 800124c:	4801      	ldr	r0, [pc, #4]	@ (8001254 <__malloc_lock+0x8>)
 800124e:	f7ff bf0f 	b.w	8001070 <__retarget_lock_acquire_recursive>
 8001252:	bf00      	nop
 8001254:	200001cc 	.word	0x200001cc

08001258 <__malloc_unlock>:
 8001258:	4801      	ldr	r0, [pc, #4]	@ (8001260 <__malloc_unlock+0x8>)
 800125a:	f7ff bf0a 	b.w	8001072 <__retarget_lock_release_recursive>
 800125e:	bf00      	nop
 8001260:	200001cc 	.word	0x200001cc

08001264 <__ssputs_r>:
 8001264:	e92d 47f0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, sl, lr}
 8001268:	688e      	ldr	r6, [r1, #8]
 800126a:	461f      	mov	r7, r3
 800126c:	42be      	cmp	r6, r7
 800126e:	680b      	ldr	r3, [r1, #0]
 8001270:	4682      	mov	sl, r0
 8001272:	460c      	mov	r4, r1
 8001274:	4690      	mov	r8, r2
 8001276:	d82d      	bhi.n	80012d4 <__ssputs_r+0x70>
 8001278:	f9b1 200c 	ldrsh.w	r2, [r1, #12]
 800127c:	f412 6f90 	tst.w	r2, #1152	@ 0x480
 8001280:	d026      	beq.n	80012d0 <__ssputs_r+0x6c>
 8001282:	6965      	ldr	r5, [r4, #20]
 8001284:	6909      	ldr	r1, [r1, #16]
 8001286:	eb05 0545 	add.w	r5, r5, r5, lsl #1
 800128a:	eba3 0901 	sub.w	r9, r3, r1
 800128e:	eb05 75d5 	add.w	r5, r5, r5, lsr #31
 8001292:	1c7b      	adds	r3, r7, #1
 8001294:	444b      	add	r3, r9
 8001296:	106d      	asrs	r5, r5, #1
 8001298:	429d      	cmp	r5, r3
 800129a:	bf38      	it	cc
 800129c:	461d      	movcc	r5, r3
 800129e:	0553      	lsls	r3, r2, #21
 80012a0:	d527      	bpl.n	80012f2 <__ssputs_r+0x8e>
 80012a2:	4629      	mov	r1, r5
 80012a4:	f7ff ff52 	bl	800114c <_malloc_r>
 80012a8:	4606      	mov	r6, r0
 80012aa:	b360      	cbz	r0, 8001306 <__ssputs_r+0xa2>
 80012ac:	6921      	ldr	r1, [r4, #16]
 80012ae:	464a      	mov	r2, r9
 80012b0:	f000 fae6 	bl	8001880 <memcpy>
 80012b4:	89a3      	ldrh	r3, [r4, #12]
 80012b6:	f423 6390 	bic.w	r3, r3, #1152	@ 0x480
 80012ba:	f043 0380 	orr.w	r3, r3, #128	@ 0x80
 80012be:	81a3      	strh	r3, [r4, #12]
 80012c0:	6126      	str	r6, [r4, #16]
 80012c2:	6165      	str	r5, [r4, #20]
 80012c4:	444e      	add	r6, r9
 80012c6:	eba5 0509 	sub.w	r5, r5, r9
 80012ca:	6026      	str	r6, [r4, #0]
 80012cc:	60a5      	str	r5, [r4, #8]
 80012ce:	463e      	mov	r6, r7
 80012d0:	42be      	cmp	r6, r7
 80012d2:	d900      	bls.n	80012d6 <__ssputs_r+0x72>
 80012d4:	463e      	mov	r6, r7
 80012d6:	6820      	ldr	r0, [r4, #0]
 80012d8:	4632      	mov	r2, r6
 80012da:	4641      	mov	r1, r8
 80012dc:	f000 faa6 	bl	800182c <memmove>
 80012e0:	68a3      	ldr	r3, [r4, #8]
 80012e2:	1b9b      	subs	r3, r3, r6
 80012e4:	60a3      	str	r3, [r4, #8]
 80012e6:	6823      	ldr	r3, [r4, #0]
 80012e8:	4433      	add	r3, r6
 80012ea:	6023      	str	r3, [r4, #0]
 80012ec:	2000      	movs	r0, #0
 80012ee:	e8bd 87f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, sl, pc}
 80012f2:	462a      	mov	r2, r5
 80012f4:	f000 fad2 	bl	800189c <_realloc_r>
 80012f8:	4606      	mov	r6, r0
 80012fa:	2800      	cmp	r0, #0
 80012fc:	d1e0      	bne.n	80012c0 <__ssputs_r+0x5c>
 80012fe:	6921      	ldr	r1, [r4, #16]
 8001300:	4650      	mov	r0, sl
 8001302:	f7ff feb7 	bl	8001074 <_free_r>
 8001306:	230c      	movs	r3, #12
 8001308:	f8ca 3000 	str.w	r3, [sl]
 800130c:	89a3      	ldrh	r3, [r4, #12]
 800130e:	f043 0340 	orr.w	r3, r3, #64	@ 0x40
 8001312:	81a3      	strh	r3, [r4, #12]
 8001314:	f04f 30ff 	mov.w	r0, #4294967295
 8001318:	e7e9      	b.n	80012ee <__ssputs_r+0x8a>
	...

0800131c <_svfiprintf_r>:
 800131c:	e92d 4ff0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
 8001320:	4698      	mov	r8, r3
 8001322:	898b      	ldrh	r3, [r1, #12]
 8001324:	061b      	lsls	r3, r3, #24
 8001326:	b09d      	sub	sp, #116	@ 0x74
 8001328:	4607      	mov	r7, r0
 800132a:	460d      	mov	r5, r1
 800132c:	4614      	mov	r4, r2
 800132e:	d510      	bpl.n	8001352 <_svfiprintf_r+0x36>
 8001330:	690b      	ldr	r3, [r1, #16]
 8001332:	b973      	cbnz	r3, 8001352 <_svfiprintf_r+0x36>
 8001334:	2140      	movs	r1, #64	@ 0x40
 8001336:	f7ff ff09 	bl	800114c <_malloc_r>
 800133a:	6028      	str	r0, [r5, #0]
 800133c:	6128      	str	r0, [r5, #16]
 800133e:	b930      	cbnz	r0, 800134e <_svfiprintf_r+0x32>
 8001340:	230c      	movs	r3, #12
 8001342:	603b      	str	r3, [r7, #0]
 8001344:	f04f 30ff 	mov.w	r0, #4294967295
 8001348:	b01d      	add	sp, #116	@ 0x74
 800134a:	e8bd 8ff0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, pc}
 800134e:	2340      	movs	r3, #64	@ 0x40
 8001350:	616b      	str	r3, [r5, #20]
 8001352:	2300      	movs	r3, #0
 8001354:	9309      	str	r3, [sp, #36]	@ 0x24
 8001356:	2320      	movs	r3, #32
 8001358:	f88d 3029 	strb.w	r3, [sp, #41]	@ 0x29
 800135c:	f8cd 800c 	str.w	r8, [sp, #12]
 8001360:	2330      	movs	r3, #48	@ 0x30
 8001362:	f8df 819c 	ldr.w	r8, [pc, #412]	@ 8001500 <_svfiprintf_r+0x1e4>
 8001366:	f88d 302a 	strb.w	r3, [sp, #42]	@ 0x2a
 800136a:	f04f 0901 	mov.w	r9, #1
 800136e:	4623      	mov	r3, r4
 8001370:	469a      	mov	sl, r3
 8001372:	f813 2b01 	ldrb.w	r2, [r3], #1
 8001376:	b10a      	cbz	r2, 800137c <_svfiprintf_r+0x60>
 8001378:	2a25      	cmp	r2, #37	@ 0x25
 800137a:	d1f9      	bne.n	8001370 <_svfiprintf_r+0x54>
 800137c:	ebba 0b04 	subs.w	fp, sl, r4
 8001380:	d00b      	beq.n	800139a <_svfiprintf_r+0x7e>
 8001382:	465b      	mov	r3, fp
 8001384:	4622      	mov	r2, r4
 8001386:	4629      	mov	r1, r5
 8001388:	4638      	mov	r0, r7
 800138a:	f7ff ff6b 	bl	8001264 <__ssputs_r>
 800138e:	3001      	adds	r0, #1
 8001390:	f000 80a7 	beq.w	80014e2 <_svfiprintf_r+0x1c6>
 8001394:	9a09      	ldr	r2, [sp, #36]	@ 0x24
 8001396:	445a      	add	r2, fp
 8001398:	9209      	str	r2, [sp, #36]	@ 0x24
 800139a:	f89a 3000 	ldrb.w	r3, [sl]
 800139e:	2b00      	cmp	r3, #0
 80013a0:	f000 809f 	beq.w	80014e2 <_svfiprintf_r+0x1c6>
 80013a4:	2300      	movs	r3, #0
 80013a6:	f04f 32ff 	mov.w	r2, #4294967295
 80013aa:	e9cd 2305 	strd	r2, r3, [sp, #20]
 80013ae:	f10a 0a01 	add.w	sl, sl, #1
 80013b2:	9304      	str	r3, [sp, #16]
 80013b4:	9307      	str	r3, [sp, #28]
 80013b6:	f88d 3053 	strb.w	r3, [sp, #83]	@ 0x53
 80013ba:	931a      	str	r3, [sp, #104]	@ 0x68
 80013bc:	4654      	mov	r4, sl
 80013be:	2205      	movs	r2, #5
 80013c0:	f814 1b01 	ldrb.w	r1, [r4], #1
 80013c4:	484e      	ldr	r0, [pc, #312]	@ (8001500 <_svfiprintf_r+0x1e4>)
 80013c6:	f7fe ff03 	bl	80001d0 <memchr>
 80013ca:	9a04      	ldr	r2, [sp, #16]
 80013cc:	b9d8      	cbnz	r0, 8001406 <_svfiprintf_r+0xea>
 80013ce:	06d0      	lsls	r0, r2, #27
 80013d0:	bf44      	itt	mi
 80013d2:	2320      	movmi	r3, #32
 80013d4:	f88d 3053 	strbmi.w	r3, [sp, #83]	@ 0x53
 80013d8:	0711      	lsls	r1, r2, #28
 80013da:	bf44      	itt	mi
 80013dc:	232b      	movmi	r3, #43	@ 0x2b
 80013de:	f88d 3053 	strbmi.w	r3, [sp, #83]	@ 0x53
 80013e2:	f89a 3000 	ldrb.w	r3, [sl]
 80013e6:	2b2a      	cmp	r3, #42	@ 0x2a
 80013e8:	d015      	beq.n	8001416 <_svfiprintf_r+0xfa>
 80013ea:	9a07      	ldr	r2, [sp, #28]
 80013ec:	4654      	mov	r4, sl
 80013ee:	2000      	movs	r0, #0
 80013f0:	f04f 0c0a 	mov.w	ip, #10
 80013f4:	4621      	mov	r1, r4
 80013f6:	f811 3b01 	ldrb.w	r3, [r1], #1
 80013fa:	3b30      	subs	r3, #48	@ 0x30
 80013fc:	2b09      	cmp	r3, #9
 80013fe:	d94b      	bls.n	8001498 <_svfiprintf_r+0x17c>
 8001400:	b1b0      	cbz	r0, 8001430 <_svfiprintf_r+0x114>
 8001402:	9207      	str	r2, [sp, #28]
 8001404:	e014      	b.n	8001430 <_svfiprintf_r+0x114>
 8001406:	eba0 0308 	sub.w	r3, r0, r8
 800140a:	fa09 f303 	lsl.w	r3, r9, r3
 800140e:	4313      	orrs	r3, r2
 8001410:	9304      	str	r3, [sp, #16]
 8001412:	46a2      	mov	sl, r4
 8001414:	e7d2      	b.n	80013bc <_svfiprintf_r+0xa0>
 8001416:	9b03      	ldr	r3, [sp, #12]
 8001418:	1d19      	adds	r1, r3, #4
 800141a:	681b      	ldr	r3, [r3, #0]
 800141c:	9103      	str	r1, [sp, #12]
 800141e:	2b00      	cmp	r3, #0
 8001420:	bfbb      	ittet	lt
 8001422:	425b      	neglt	r3, r3
 8001424:	f042 0202 	orrlt.w	r2, r2, #2
 8001428:	9307      	strge	r3, [sp, #28]
 800142a:	9307      	strlt	r3, [sp, #28]
 800142c:	bfb8      	it	lt
 800142e:	9204      	strlt	r2, [sp, #16]
 8001430:	7823      	ldrb	r3, [r4, #0]
 8001432:	2b2e      	cmp	r3, #46	@ 0x2e
 8001434:	d10a      	bne.n	800144c <_svfiprintf_r+0x130>
 8001436:	7863      	ldrb	r3, [r4, #1]
 8001438:	2b2a      	cmp	r3, #42	@ 0x2a
 800143a:	d132      	bne.n	80014a2 <_svfiprintf_r+0x186>
 800143c:	9b03      	ldr	r3, [sp, #12]
 800143e:	1d1a      	adds	r2, r3, #4
 8001440:	681b      	ldr	r3, [r3, #0]
 8001442:	9203      	str	r2, [sp, #12]
 8001444:	ea43 73e3 	orr.w	r3, r3, r3, asr #31
 8001448:	3402      	adds	r4, #2
 800144a:	9305      	str	r3, [sp, #20]
 800144c:	f8df a0c0 	ldr.w	sl, [pc, #192]	@ 8001510 <_svfiprintf_r+0x1f4>
 8001450:	7821      	ldrb	r1, [r4, #0]
 8001452:	2203      	movs	r2, #3
 8001454:	4650      	mov	r0, sl
 8001456:	f7fe febb 	bl	80001d0 <memchr>
 800145a:	b138      	cbz	r0, 800146c <_svfiprintf_r+0x150>
 800145c:	9b04      	ldr	r3, [sp, #16]
 800145e:	eba0 000a 	sub.w	r0, r0, sl
 8001462:	2240      	movs	r2, #64	@ 0x40
 8001464:	4082      	lsls	r2, r0
 8001466:	4313      	orrs	r3, r2
 8001468:	3401      	adds	r4, #1
 800146a:	9304      	str	r3, [sp, #16]
 800146c:	f814 1b01 	ldrb.w	r1, [r4], #1
 8001470:	4824      	ldr	r0, [pc, #144]	@ (8001504 <_svfiprintf_r+0x1e8>)
 8001472:	f88d 1028 	strb.w	r1, [sp, #40]	@ 0x28
 8001476:	2206      	movs	r2, #6
 8001478:	f7fe feaa 	bl	80001d0 <memchr>
 800147c:	2800      	cmp	r0, #0
 800147e:	d036      	beq.n	80014ee <_svfiprintf_r+0x1d2>
 8001480:	4b21      	ldr	r3, [pc, #132]	@ (8001508 <_svfiprintf_r+0x1ec>)
 8001482:	bb1b      	cbnz	r3, 80014cc <_svfiprintf_r+0x1b0>
 8001484:	9b03      	ldr	r3, [sp, #12]
 8001486:	3307      	adds	r3, #7
 8001488:	f023 0307 	bic.w	r3, r3, #7
 800148c:	3308      	adds	r3, #8
 800148e:	9303      	str	r3, [sp, #12]
 8001490:	9b09      	ldr	r3, [sp, #36]	@ 0x24
 8001492:	4433      	add	r3, r6
 8001494:	9309      	str	r3, [sp, #36]	@ 0x24
 8001496:	e76a      	b.n	800136e <_svfiprintf_r+0x52>
 8001498:	fb0c 3202 	mla	r2, ip, r2, r3
 800149c:	460c      	mov	r4, r1
 800149e:	2001      	movs	r0, #1
 80014a0:	e7a8      	b.n	80013f4 <_svfiprintf_r+0xd8>
 80014a2:	2300      	movs	r3, #0
 80014a4:	3401      	adds	r4, #1
 80014a6:	9305      	str	r3, [sp, #20]
 80014a8:	4619      	mov	r1, r3
 80014aa:	f04f 0c0a 	mov.w	ip, #10
 80014ae:	4620      	mov	r0, r4
 80014b0:	f810 2b01 	ldrb.w	r2, [r0], #1
 80014b4:	3a30      	subs	r2, #48	@ 0x30
 80014b6:	2a09      	cmp	r2, #9
 80014b8:	d903      	bls.n	80014c2 <_svfiprintf_r+0x1a6>
 80014ba:	2b00      	cmp	r3, #0
 80014bc:	d0c6      	beq.n	800144c <_svfiprintf_r+0x130>
 80014be:	9105      	str	r1, [sp, #20]
 80014c0:	e7c4      	b.n	800144c <_svfiprintf_r+0x130>
 80014c2:	fb0c 2101 	mla	r1, ip, r1, r2
 80014c6:	4604      	mov	r4, r0
 80014c8:	2301      	movs	r3, #1
 80014ca:	e7f0      	b.n	80014ae <_svfiprintf_r+0x192>
 80014cc:	ab03      	add	r3, sp, #12
 80014ce:	9300      	str	r3, [sp, #0]
 80014d0:	462a      	mov	r2, r5
 80014d2:	4b0e      	ldr	r3, [pc, #56]	@ (800150c <_svfiprintf_r+0x1f0>)
 80014d4:	a904      	add	r1, sp, #16
 80014d6:	4638      	mov	r0, r7
 80014d8:	f3af 8000 	nop.w
 80014dc:	1c42      	adds	r2, r0, #1
 80014de:	4606      	mov	r6, r0
 80014e0:	d1d6      	bne.n	8001490 <_svfiprintf_r+0x174>
 80014e2:	89ab      	ldrh	r3, [r5, #12]
 80014e4:	065b      	lsls	r3, r3, #25
 80014e6:	f53f af2d 	bmi.w	8001344 <_svfiprintf_r+0x28>
 80014ea:	9809      	ldr	r0, [sp, #36]	@ 0x24
 80014ec:	e72c      	b.n	8001348 <_svfiprintf_r+0x2c>
 80014ee:	ab03      	add	r3, sp, #12
 80014f0:	9300      	str	r3, [sp, #0]
 80014f2:	462a      	mov	r2, r5
 80014f4:	4b05      	ldr	r3, [pc, #20]	@ (800150c <_svfiprintf_r+0x1f0>)
 80014f6:	a904      	add	r1, sp, #16
 80014f8:	4638      	mov	r0, r7
 80014fa:	f000 f879 	bl	80015f0 <_printf_i>
 80014fe:	e7ed      	b.n	80014dc <_svfiprintf_r+0x1c0>
 8001500:	0800196a 	.word	0x0800196a
 8001504:	08001974 	.word	0x08001974
 8001508:	00000000 	.word	0x00000000
 800150c:	08001265 	.word	0x08001265
 8001510:	08001970 	.word	0x08001970

08001514 <_printf_common>:
 8001514:	e92d 47f0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, sl, lr}
 8001518:	4616      	mov	r6, r2
 800151a:	4698      	mov	r8, r3
 800151c:	688a      	ldr	r2, [r1, #8]
 800151e:	690b      	ldr	r3, [r1, #16]
 8001520:	f8dd 9020 	ldr.w	r9, [sp, #32]
 8001524:	4293      	cmp	r3, r2
 8001526:	bfb8      	it	lt
 8001528:	4613      	movlt	r3, r2
 800152a:	6033      	str	r3, [r6, #0]
 800152c:	f891 2043 	ldrb.w	r2, [r1, #67]	@ 0x43
 8001530:	4607      	mov	r7, r0
 8001532:	460c      	mov	r4, r1
 8001534:	b10a      	cbz	r2, 800153a <_printf_common+0x26>
 8001536:	3301      	adds	r3, #1
 8001538:	6033      	str	r3, [r6, #0]
 800153a:	6823      	ldr	r3, [r4, #0]
 800153c:	0699      	lsls	r1, r3, #26
 800153e:	bf42      	ittt	mi
 8001540:	6833      	ldrmi	r3, [r6, #0]
 8001542:	3302      	addmi	r3, #2
 8001544:	6033      	strmi	r3, [r6, #0]
 8001546:	6825      	ldr	r5, [r4, #0]
 8001548:	f015 0506 	ands.w	r5, r5, #6
 800154c:	d106      	bne.n	800155c <_printf_common+0x48>
 800154e:	f104 0a19 	add.w	sl, r4, #25
 8001552:	68e3      	ldr	r3, [r4, #12]
 8001554:	6832      	ldr	r2, [r6, #0]
 8001556:	1a9b      	subs	r3, r3, r2
 8001558:	42ab      	cmp	r3, r5
 800155a:	dc26      	bgt.n	80015aa <_printf_common+0x96>
 800155c:	f894 3043 	ldrb.w	r3, [r4, #67]	@ 0x43
 8001560:	6822      	ldr	r2, [r4, #0]
 8001562:	3b00      	subs	r3, #0
 8001564:	bf18      	it	ne
 8001566:	2301      	movne	r3, #1
 8001568:	0692      	lsls	r2, r2, #26
 800156a:	d42b      	bmi.n	80015c4 <_printf_common+0xb0>
 800156c:	f104 0243 	add.w	r2, r4, #67	@ 0x43
 8001570:	4641      	mov	r1, r8
 8001572:	4638      	mov	r0, r7
 8001574:	47c8      	blx	r9
 8001576:	3001      	adds	r0, #1
 8001578:	d01e      	beq.n	80015b8 <_printf_common+0xa4>
 800157a:	6823      	ldr	r3, [r4, #0]
 800157c:	6922      	ldr	r2, [r4, #16]
 800157e:	f003 0306 	and.w	r3, r3, #6
 8001582:	2b04      	cmp	r3, #4
 8001584:	bf02      	ittt	eq
 8001586:	68e5      	ldreq	r5, [r4, #12]
 8001588:	6833      	ldreq	r3, [r6, #0]
 800158a:	1aed      	subeq	r5, r5, r3
 800158c:	68a3      	ldr	r3, [r4, #8]
 800158e:	bf0c      	ite	eq
 8001590:	ea25 75e5 	biceq.w	r5, r5, r5, asr #31
 8001594:	2500      	movne	r5, #0
 8001596:	4293      	cmp	r3, r2
 8001598:	bfc4      	itt	gt
 800159a:	1a9b      	subgt	r3, r3, r2
 800159c:	18ed      	addgt	r5, r5, r3
 800159e:	2600      	movs	r6, #0
 80015a0:	341a      	adds	r4, #26
 80015a2:	42b5      	cmp	r5, r6
 80015a4:	d11a      	bne.n	80015dc <_printf_common+0xc8>
 80015a6:	2000      	movs	r0, #0
 80015a8:	e008      	b.n	80015bc <_printf_common+0xa8>
 80015aa:	2301      	movs	r3, #1
 80015ac:	4652      	mov	r2, sl
 80015ae:	4641      	mov	r1, r8
 80015b0:	4638      	mov	r0, r7
 80015b2:	47c8      	blx	r9
 80015b4:	3001      	adds	r0, #1
 80015b6:	d103      	bne.n	80015c0 <_printf_common+0xac>
 80015b8:	f04f 30ff 	mov.w	r0, #4294967295
 80015bc:	e8bd 87f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, sl, pc}
 80015c0:	3501      	adds	r5, #1
 80015c2:	e7c6      	b.n	8001552 <_printf_common+0x3e>
 80015c4:	18e1      	adds	r1, r4, r3
 80015c6:	1c5a      	adds	r2, r3, #1
 80015c8:	2030      	movs	r0, #48	@ 0x30
 80015ca:	f881 0043 	strb.w	r0, [r1, #67]	@ 0x43
 80015ce:	4422      	add	r2, r4
 80015d0:	f894 1045 	ldrb.w	r1, [r4, #69]	@ 0x45
 80015d4:	f882 1043 	strb.w	r1, [r2, #67]	@ 0x43
 80015d8:	3302      	adds	r3, #2
 80015da:	e7c7      	b.n	800156c <_printf_common+0x58>
 80015dc:	2301      	movs	r3, #1
 80015de:	4622      	mov	r2, r4
 80015e0:	4641      	mov	r1, r8
 80015e2:	4638      	mov	r0, r7
 80015e4:	47c8      	blx	r9
 80015e6:	3001      	adds	r0, #1
 80015e8:	d0e6      	beq.n	80015b8 <_printf_common+0xa4>
 80015ea:	3601      	adds	r6, #1
 80015ec:	e7d9      	b.n	80015a2 <_printf_common+0x8e>
	...

080015f0 <_printf_i>:
 80015f0:	e92d 47ff 	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, lr}
 80015f4:	7e0f      	ldrb	r7, [r1, #24]
 80015f6:	9e0c      	ldr	r6, [sp, #48]	@ 0x30
 80015f8:	2f78      	cmp	r7, #120	@ 0x78
 80015fa:	4691      	mov	r9, r2
 80015fc:	4680      	mov	r8, r0
 80015fe:	460c      	mov	r4, r1
 8001600:	469a      	mov	sl, r3
 8001602:	f101 0243 	add.w	r2, r1, #67	@ 0x43
 8001606:	d807      	bhi.n	8001618 <_printf_i+0x28>
 8001608:	2f62      	cmp	r7, #98	@ 0x62
 800160a:	d80a      	bhi.n	8001622 <_printf_i+0x32>
 800160c:	2f00      	cmp	r7, #0
 800160e:	f000 80d1 	beq.w	80017b4 <_printf_i+0x1c4>
 8001612:	2f58      	cmp	r7, #88	@ 0x58
 8001614:	f000 80b8 	beq.w	8001788 <_printf_i+0x198>
 8001618:	f104 0642 	add.w	r6, r4, #66	@ 0x42
 800161c:	f884 7042 	strb.w	r7, [r4, #66]	@ 0x42
 8001620:	e03a      	b.n	8001698 <_printf_i+0xa8>
 8001622:	f1a7 0363 	sub.w	r3, r7, #99	@ 0x63
 8001626:	2b15      	cmp	r3, #21
 8001628:	d8f6      	bhi.n	8001618 <_printf_i+0x28>
 800162a:	a101      	add	r1, pc, #4	@ (adr r1, 8001630 <_printf_i+0x40>)
 800162c:	f851 f023 	ldr.w	pc, [r1, r3, lsl #2]
 8001630:	08001689 	.word	0x08001689
 8001634:	0800169d 	.word	0x0800169d
 8001638:	08001619 	.word	0x08001619
 800163c:	08001619 	.word	0x08001619
 8001640:	08001619 	.word	0x08001619
 8001644:	08001619 	.word	0x08001619
 8001648:	0800169d 	.word	0x0800169d
 800164c:	08001619 	.word	0x08001619
 8001650:	08001619 	.word	0x08001619
 8001654:	08001619 	.word	0x08001619
 8001658:	08001619 	.word	0x08001619
 800165c:	0800179b 	.word	0x0800179b
 8001660:	080016c7 	.word	0x080016c7
 8001664:	08001755 	.word	0x08001755
 8001668:	08001619 	.word	0x08001619
 800166c:	08001619 	.word	0x08001619
 8001670:	080017bd 	.word	0x080017bd
 8001674:	08001619 	.word	0x08001619
 8001678:	080016c7 	.word	0x080016c7
 800167c:	08001619 	.word	0x08001619
 8001680:	08001619 	.word	0x08001619
 8001684:	0800175d 	.word	0x0800175d
 8001688:	6833      	ldr	r3, [r6, #0]
 800168a:	1d1a      	adds	r2, r3, #4
 800168c:	681b      	ldr	r3, [r3, #0]
 800168e:	6032      	str	r2, [r6, #0]
 8001690:	f104 0642 	add.w	r6, r4, #66	@ 0x42
 8001694:	f884 3042 	strb.w	r3, [r4, #66]	@ 0x42
 8001698:	2301      	movs	r3, #1
 800169a:	e09c      	b.n	80017d6 <_printf_i+0x1e6>
 800169c:	6833      	ldr	r3, [r6, #0]
 800169e:	6820      	ldr	r0, [r4, #0]
 80016a0:	1d19      	adds	r1, r3, #4
 80016a2:	6031      	str	r1, [r6, #0]
 80016a4:	0606      	lsls	r6, r0, #24
 80016a6:	d501      	bpl.n	80016ac <_printf_i+0xbc>
 80016a8:	681d      	ldr	r5, [r3, #0]
 80016aa:	e003      	b.n	80016b4 <_printf_i+0xc4>
 80016ac:	0645      	lsls	r5, r0, #25
 80016ae:	d5fb      	bpl.n	80016a8 <_printf_i+0xb8>
 80016b0:	f9b3 5000 	ldrsh.w	r5, [r3]
 80016b4:	2d00      	cmp	r5, #0
 80016b6:	da03      	bge.n	80016c0 <_printf_i+0xd0>
 80016b8:	232d      	movs	r3, #45	@ 0x2d
 80016ba:	426d      	negs	r5, r5
 80016bc:	f884 3043 	strb.w	r3, [r4, #67]	@ 0x43
 80016c0:	4858      	ldr	r0, [pc, #352]	@ (8001824 <_printf_i+0x234>)
 80016c2:	230a      	movs	r3, #10
 80016c4:	e011      	b.n	80016ea <_printf_i+0xfa>
 80016c6:	6821      	ldr	r1, [r4, #0]
 80016c8:	6833      	ldr	r3, [r6, #0]
 80016ca:	0608      	lsls	r0, r1, #24
 80016cc:	f853 5b04 	ldr.w	r5, [r3], #4
 80016d0:	d402      	bmi.n	80016d8 <_printf_i+0xe8>
 80016d2:	0649      	lsls	r1, r1, #25
 80016d4:	bf48      	it	mi
 80016d6:	b2ad      	uxthmi	r5, r5
 80016d8:	2f6f      	cmp	r7, #111	@ 0x6f
 80016da:	4852      	ldr	r0, [pc, #328]	@ (8001824 <_printf_i+0x234>)
 80016dc:	6033      	str	r3, [r6, #0]
 80016de:	bf14      	ite	ne
 80016e0:	230a      	movne	r3, #10
 80016e2:	2308      	moveq	r3, #8
 80016e4:	2100      	movs	r1, #0
 80016e6:	f884 1043 	strb.w	r1, [r4, #67]	@ 0x43
 80016ea:	6866      	ldr	r6, [r4, #4]
 80016ec:	60a6      	str	r6, [r4, #8]
 80016ee:	2e00      	cmp	r6, #0
 80016f0:	db05      	blt.n	80016fe <_printf_i+0x10e>
 80016f2:	6821      	ldr	r1, [r4, #0]
 80016f4:	432e      	orrs	r6, r5
 80016f6:	f021 0104 	bic.w	r1, r1, #4
 80016fa:	6021      	str	r1, [r4, #0]
 80016fc:	d04b      	beq.n	8001796 <_printf_i+0x1a6>
 80016fe:	4616      	mov	r6, r2
 8001700:	fbb5 f1f3 	udiv	r1, r5, r3
 8001704:	fb03 5711 	mls	r7, r3, r1, r5
 8001708:	5dc7      	ldrb	r7, [r0, r7]
 800170a:	f806 7d01 	strb.w	r7, [r6, #-1]!
 800170e:	462f      	mov	r7, r5
 8001710:	42bb      	cmp	r3, r7
 8001712:	460d      	mov	r5, r1
 8001714:	d9f4      	bls.n	8001700 <_printf_i+0x110>
 8001716:	2b08      	cmp	r3, #8
 8001718:	d10b      	bne.n	8001732 <_printf_i+0x142>
 800171a:	6823      	ldr	r3, [r4, #0]
 800171c:	07df      	lsls	r7, r3, #31
 800171e:	d508      	bpl.n	8001732 <_printf_i+0x142>
 8001720:	6923      	ldr	r3, [r4, #16]
 8001722:	6861      	ldr	r1, [r4, #4]
 8001724:	4299      	cmp	r1, r3
 8001726:	bfde      	ittt	le
 8001728:	2330      	movle	r3, #48	@ 0x30
 800172a:	f806 3c01 	strble.w	r3, [r6, #-1]
 800172e:	f106 36ff 	addle.w	r6, r6, #4294967295
 8001732:	1b92      	subs	r2, r2, r6
 8001734:	6122      	str	r2, [r4, #16]
 8001736:	f8cd a000 	str.w	sl, [sp]
 800173a:	464b      	mov	r3, r9
 800173c:	aa03      	add	r2, sp, #12
 800173e:	4621      	mov	r1, r4
 8001740:	4640      	mov	r0, r8
 8001742:	f7ff fee7 	bl	8001514 <_printf_common>
 8001746:	3001      	adds	r0, #1
 8001748:	d14a      	bne.n	80017e0 <_printf_i+0x1f0>
 800174a:	f04f 30ff 	mov.w	r0, #4294967295
 800174e:	b004      	add	sp, #16
 8001750:	e8bd 87f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, sl, pc}
 8001754:	6823      	ldr	r3, [r4, #0]
 8001756:	f043 0320 	orr.w	r3, r3, #32
 800175a:	6023      	str	r3, [r4, #0]
 800175c:	4832      	ldr	r0, [pc, #200]	@ (8001828 <_printf_i+0x238>)
 800175e:	2778      	movs	r7, #120	@ 0x78
 8001760:	f884 7045 	strb.w	r7, [r4, #69]	@ 0x45
 8001764:	6823      	ldr	r3, [r4, #0]
 8001766:	6831      	ldr	r1, [r6, #0]
 8001768:	061f      	lsls	r7, r3, #24
 800176a:	f851 5b04 	ldr.w	r5, [r1], #4
 800176e:	d402      	bmi.n	8001776 <_printf_i+0x186>
 8001770:	065f      	lsls	r7, r3, #25
 8001772:	bf48      	it	mi
 8001774:	b2ad      	uxthmi	r5, r5
 8001776:	6031      	str	r1, [r6, #0]
 8001778:	07d9      	lsls	r1, r3, #31
 800177a:	bf44      	itt	mi
 800177c:	f043 0320 	orrmi.w	r3, r3, #32
 8001780:	6023      	strmi	r3, [r4, #0]
 8001782:	b11d      	cbz	r5, 800178c <_printf_i+0x19c>
 8001784:	2310      	movs	r3, #16
 8001786:	e7ad      	b.n	80016e4 <_printf_i+0xf4>
 8001788:	4826      	ldr	r0, [pc, #152]	@ (8001824 <_printf_i+0x234>)
 800178a:	e7e9      	b.n	8001760 <_printf_i+0x170>
 800178c:	6823      	ldr	r3, [r4, #0]
 800178e:	f023 0320 	bic.w	r3, r3, #32
 8001792:	6023      	str	r3, [r4, #0]
 8001794:	e7f6      	b.n	8001784 <_printf_i+0x194>
 8001796:	4616      	mov	r6, r2
 8001798:	e7bd      	b.n	8001716 <_printf_i+0x126>
 800179a:	6833      	ldr	r3, [r6, #0]
 800179c:	6825      	ldr	r5, [r4, #0]
 800179e:	6961      	ldr	r1, [r4, #20]
 80017a0:	1d18      	adds	r0, r3, #4
 80017a2:	6030      	str	r0, [r6, #0]
 80017a4:	062e      	lsls	r6, r5, #24
 80017a6:	681b      	ldr	r3, [r3, #0]
 80017a8:	d501      	bpl.n	80017ae <_printf_i+0x1be>
 80017aa:	6019      	str	r1, [r3, #0]
 80017ac:	e002      	b.n	80017b4 <_printf_i+0x1c4>
 80017ae:	0668      	lsls	r0, r5, #25
 80017b0:	d5fb      	bpl.n	80017aa <_printf_i+0x1ba>
 80017b2:	8019      	strh	r1, [r3, #0]
 80017b4:	2300      	movs	r3, #0
 80017b6:	6123      	str	r3, [r4, #16]
 80017b8:	4616      	mov	r6, r2
 80017ba:	e7bc      	b.n	8001736 <_printf_i+0x146>
 80017bc:	6833      	ldr	r3, [r6, #0]
 80017be:	1d1a      	adds	r2, r3, #4
 80017c0:	6032      	str	r2, [r6, #0]
 80017c2:	681e      	ldr	r6, [r3, #0]
 80017c4:	6862      	ldr	r2, [r4, #4]
 80017c6:	2100      	movs	r1, #0
 80017c8:	4630      	mov	r0, r6
 80017ca:	f7fe fd01 	bl	80001d0 <memchr>
 80017ce:	b108      	cbz	r0, 80017d4 <_printf_i+0x1e4>
 80017d0:	1b80      	subs	r0, r0, r6
 80017d2:	6060      	str	r0, [r4, #4]
 80017d4:	6863      	ldr	r3, [r4, #4]
 80017d6:	6123      	str	r3, [r4, #16]
 80017d8:	2300      	movs	r3, #0
 80017da:	f884 3043 	strb.w	r3, [r4, #67]	@ 0x43
 80017de:	e7aa      	b.n	8001736 <_printf_i+0x146>
 80017e0:	6923      	ldr	r3, [r4, #16]
 80017e2:	4632      	mov	r2, r6
 80017e4:	4649      	mov	r1, r9
 80017e6:	4640      	mov	r0, r8
 80017e8:	47d0      	blx	sl
 80017ea:	3001      	adds	r0, #1
 80017ec:	d0ad      	beq.n	800174a <_printf_i+0x15a>
 80017ee:	6823      	ldr	r3, [r4, #0]
 80017f0:	079b      	lsls	r3, r3, #30
 80017f2:	d413      	bmi.n	800181c <_printf_i+0x22c>
 80017f4:	68e0      	ldr	r0, [r4, #12]
 80017f6:	9b03      	ldr	r3, [sp, #12]
 80017f8:	4298      	cmp	r0, r3
 80017fa:	bfb8      	it	lt
 80017fc:	4618      	movlt	r0, r3
 80017fe:	e7a6      	b.n	800174e <_printf_i+0x15e>
 8001800:	2301      	movs	r3, #1
 8001802:	4632      	mov	r2, r6
 8001804:	4649      	mov	r1, r9
 8001806:	4640      	mov	r0, r8
 8001808:	47d0      	blx	sl
 800180a:	3001      	adds	r0, #1
 800180c:	d09d      	beq.n	800174a <_printf_i+0x15a>
 800180e:	3501      	adds	r5, #1
 8001810:	68e3      	ldr	r3, [r4, #12]
 8001812:	9903      	ldr	r1, [sp, #12]
 8001814:	1a5b      	subs	r3, r3, r1
 8001816:	42ab      	cmp	r3, r5
 8001818:	dcf2      	bgt.n	8001800 <_printf_i+0x210>
 800181a:	e7eb      	b.n	80017f4 <_printf_i+0x204>
 800181c:	2500      	movs	r5, #0
 800181e:	f104 0619 	add.w	r6, r4, #25
 8001822:	e7f5      	b.n	8001810 <_printf_i+0x220>
 8001824:	0800197b 	.word	0x0800197b
 8001828:	0800198c 	.word	0x0800198c

0800182c <memmove>:
 800182c:	4288      	cmp	r0, r1
 800182e:	b510      	push	{r4, lr}
 8001830:	eb01 0402 	add.w	r4, r1, r2
 8001834:	d902      	bls.n	800183c <memmove+0x10>
 8001836:	4284      	cmp	r4, r0
 8001838:	4623      	mov	r3, r4
 800183a:	d807      	bhi.n	800184c <memmove+0x20>
 800183c:	1e43      	subs	r3, r0, #1
 800183e:	42a1      	cmp	r1, r4
 8001840:	d008      	beq.n	8001854 <memmove+0x28>
 8001842:	f811 2b01 	ldrb.w	r2, [r1], #1
 8001846:	f803 2f01 	strb.w	r2, [r3, #1]!
 800184a:	e7f8      	b.n	800183e <memmove+0x12>
 800184c:	4402      	add	r2, r0
 800184e:	4601      	mov	r1, r0
 8001850:	428a      	cmp	r2, r1
 8001852:	d100      	bne.n	8001856 <memmove+0x2a>
 8001854:	bd10      	pop	{r4, pc}
 8001856:	f813 4d01 	ldrb.w	r4, [r3, #-1]!
 800185a:	f802 4d01 	strb.w	r4, [r2, #-1]!
 800185e:	e7f7      	b.n	8001850 <memmove+0x24>

08001860 <_sbrk_r>:
 8001860:	b538      	push	{r3, r4, r5, lr}
 8001862:	4d06      	ldr	r5, [pc, #24]	@ (800187c <_sbrk_r+0x1c>)
 8001864:	2300      	movs	r3, #0
 8001866:	4604      	mov	r4, r0
 8001868:	4608      	mov	r0, r1
 800186a:	602b      	str	r3, [r5, #0]
 800186c:	f7ff fb40 	bl	8000ef0 <_sbrk>
 8001870:	1c43      	adds	r3, r0, #1
 8001872:	d102      	bne.n	800187a <_sbrk_r+0x1a>
 8001874:	682b      	ldr	r3, [r5, #0]
 8001876:	b103      	cbz	r3, 800187a <_sbrk_r+0x1a>
 8001878:	6023      	str	r3, [r4, #0]
 800187a:	bd38      	pop	{r3, r4, r5, pc}
 800187c:	200001c8 	.word	0x200001c8

08001880 <memcpy>:
 8001880:	440a      	add	r2, r1
 8001882:	4291      	cmp	r1, r2
 8001884:	f100 33ff 	add.w	r3, r0, #4294967295
 8001888:	d100      	bne.n	800188c <memcpy+0xc>
 800188a:	4770      	bx	lr
 800188c:	b510      	push	{r4, lr}
 800188e:	f811 4b01 	ldrb.w	r4, [r1], #1
 8001892:	f803 4f01 	strb.w	r4, [r3, #1]!
 8001896:	4291      	cmp	r1, r2
 8001898:	d1f9      	bne.n	800188e <memcpy+0xe>
 800189a:	bd10      	pop	{r4, pc}

0800189c <_realloc_r>:
 800189c:	e92d 41f0 	stmdb	sp!, {r4, r5, r6, r7, r8, lr}
 80018a0:	4607      	mov	r7, r0
 80018a2:	4614      	mov	r4, r2
 80018a4:	460d      	mov	r5, r1
 80018a6:	b921      	cbnz	r1, 80018b2 <_realloc_r+0x16>
 80018a8:	e8bd 41f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, lr}
 80018ac:	4611      	mov	r1, r2
 80018ae:	f7ff bc4d 	b.w	800114c <_malloc_r>
 80018b2:	b92a      	cbnz	r2, 80018c0 <_realloc_r+0x24>
 80018b4:	f7ff fbde 	bl	8001074 <_free_r>
 80018b8:	4625      	mov	r5, r4
 80018ba:	4628      	mov	r0, r5
 80018bc:	e8bd 81f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, pc}
 80018c0:	f000 f81a 	bl	80018f8 <_malloc_usable_size_r>
 80018c4:	4284      	cmp	r4, r0
 80018c6:	4606      	mov	r6, r0
 80018c8:	d802      	bhi.n	80018d0 <_realloc_r+0x34>
 80018ca:	ebb4 0f50 	cmp.w	r4, r0, lsr #1
 80018ce:	d8f4      	bhi.n	80018ba <_realloc_r+0x1e>
 80018d0:	4621      	mov	r1, r4
 80018d2:	4638      	mov	r0, r7
 80018d4:	f7ff fc3a 	bl	800114c <_malloc_r>
 80018d8:	4680      	mov	r8, r0
 80018da:	b908      	cbnz	r0, 80018e0 <_realloc_r+0x44>
 80018dc:	4645      	mov	r5, r8
 80018de:	e7ec      	b.n	80018ba <_realloc_r+0x1e>
 80018e0:	42b4      	cmp	r4, r6
 80018e2:	4622      	mov	r2, r4
 80018e4:	4629      	mov	r1, r5
 80018e6:	bf28      	it	cs
 80018e8:	4632      	movcs	r2, r6
 80018ea:	f7ff ffc9 	bl	8001880 <memcpy>
 80018ee:	4629      	mov	r1, r5
 80018f0:	4638      	mov	r0, r7
 80018f2:	f7ff fbbf 	bl	8001074 <_free_r>
 80018f6:	e7f1      	b.n	80018dc <_realloc_r+0x40>

080018f8 <_malloc_usable_size_r>:
 80018f8:	f851 3c04 	ldr.w	r3, [r1, #-4]
 80018fc:	1f18      	subs	r0, r3, #4
 80018fe:	2b00      	cmp	r3, #0
 8001900:	bfbc      	itt	lt
 8001902:	580b      	ldrlt	r3, [r1, r0]
 8001904:	18c0      	addlt	r0, r0, r3
 8001906:	4770      	bx	lr

08001908 <_init>:
 8001908:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 800190a:	bf00      	nop
 800190c:	bcf8      	pop	{r3, r4, r5, r6, r7}
 800190e:	bc08      	pop	{r3}
 8001910:	469e      	mov	lr, r3
 8001912:	4770      	bx	lr

08001914 <_fini>:
 8001914:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8001916:	bf00      	nop
 8001918:	bcf8      	pop	{r3, r4, r5, r6, r7}
 800191a:	bc08      	pop	{r3}
 800191c:	469e      	mov	lr, r3
 800191e:	4770      	bx	lr
