.syntax unified
.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.global  g_pfnVectors
.global  Reset_Handler

.section  .isr_vector,"a",%progbits
.type  g_pfnVectors, %object
.size  g_pfnVectors, .-g_pfnVectors

// 向量表
 g_pfnVectors:
  .word  _estack
  .word  Reset_Handler
  .word  0 // NMI_Handler
  .word  0 // HardFault_Handler
  .word  0 // MemManage_Handler
  .word  0 // BusFault_Handler
  .word  0 // UsageFault_Handler
  .word  0, 0, 0, 0 // Reserved
  .word  0 // SVC_Handler
  .word  0 // DebugMon_Handler
  .word  0 // Reserved
  .word  0 // PendSV_Handler
  .word  0 // SysTick_Handler
  // 其余中断向量可补充

.section  .text.Reset_Handler
.weak  Reset_Handler
.type  Reset_Handler, %function
Reset_Handler:
  ldr   sp, =_estack
  bl    main
  b     .

.size  Reset_Handler, .-Reset_Handler

// 堆栈顶
.section  .stack
_estack:
  .word  0x20020000 // 128K RAM 顶
