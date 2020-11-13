/* ------------------------------------------
 * Copyright (c) 2017, Synopsys, Inc. All rights reserved.

 * Redistribution and use in source and binary forms, with or without
modification,
 * are permitted provided that the following conditions are met:

 * 1) Redistributions of source code must retain the above copyright notice,
this
 * list of conditions and the following disclaimer.

 * 2) Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
and/or
 * other materials provided with the distribution.

 * 3) Neither the name of the Synopsys, Inc., nor the names of its contributors
may
 * be used to endorse or promote products derived from this software without
 * specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
--------------------------------------------- */
#include <stdio.h>

#include "embARC.h"
#include "embARC_debug.h"
#include "iic1602lcd.h"

/* Define Max Number for 32-bit Integer */
#define MAX_COUNT 0xffffffff

/**
 * 宣告或定義你喜歡的埠(port)與腳位(pin)供超音波測距模組使用
 * e.g.:
 * #define UltraSonicPort DFSS_GPIO_8B2_ID
 * {
 */


/**
 * }
 */

/**
 * 宣告 GPIO 物件
 * {
 */

/**
 * }
 */

/**
 * 宣告用來判斷是否有被中斷的變數
 * {
 */

/**
 * }
 */

/* 宣告Timer0_ISR的原型 */
void Timer0_ISR();

/* Declare LCD Object to control LCD */
pLCD_t lcd_obj;

int main(void)
{
  /**
   * 初始化lcd_obj物件
   * {
   */
  
  /**
   * }
   */

  /**
	 * 獲得signal腳位的GPIO物件
	 * 將signal腳位設為輸出腳位
	 * {
   */
  
  
  /**
	 * }
	 */

  while (1)
  {
    /**
		 * 將超音波signal腳位設為輸出
		 * {
		 */
    
    /**
		 * }
		 */

    /**
		 * 將TIMER_0停止
		 * 裝載(install) Timer0_ISR為TIMER0中斷的處理程序(handler)
		 * 開啟TIMER_0的interrupt
		 * 啟動TIMER_0，設定為啟動中斷(Interrupt Enabled)模式，並且在5us(5*10^-6s)時中斷
		 * {
		 */
    
    
    
    
    /**
		 * }
		 */

    /**
		 * 將超音波signal腳位設為高電位
		 * {
		 */
    
    /**
		 * }
		 */

    /**
		 * 設定用來判斷是否有中斷的變數
		 * 等待該變數在中斷改變
		 * 將signal pin腳設定為低電位
		 * {
		*/
    
    
    
    /**
		 * }
		 */

    /**
		 * 停止TIMER_0
		 * 將signal腳位設定為輸入腳位
		 * 宣告一個變數來儲存signal腳位的電位值
		 * 等待signal腳位變為高電位
		 * {
		 */
    
    
    
    
    /**
		 * }
		 */

    /**
		 * 利用timer_start開始計數，因為不需要interrupt所以可以將mode設為0或是TIMER_CTRL_NH，並且設定val為最大值
		 * 待signal腳位變為低電位
		 * {
		 */
    
    
    /**
		 * }
		 */

    /**
		 * 利用一個變數紀錄TIMER_0目前的計數，作為開始到結束經過的CPU cycle數
		 * 透過開始到結束經過的CPU Cycle數量除以CPU Cycle(CLK_CPU)得到秒數
		 * 再乘以 340(m/s)*100(cm/m)/2(來回) 得到公分數
		 * {
		 */
    
    
    
    /**
		 * }
		 */

    /**
		 * 判斷距離是否大於15公分
     * 如果大於15公分就將LCD背景設為綠色，反之LCD背景設為紅色
     * 清除上個迴圈LCD所顯示的距離
     * 將LCD游標設為0, 0
     * 將距離透過LCD印出，因為無法使用%f格式，所以要用%d.%d印出末兩位
		 * {
		 */
    
    
    
    
    
    /**
		 * }
		 */

    /* 等待200毫秒，讓LCD能夠有時間顯示上一段距離 */
    board_delay_ms(200, 0);
  }

  return E_SYS;
}

void Timer0_ISR()
{
  /**
	 * 先將TIMER_0的 interrupt 清除
	 * 設定該設定的變數
	 * {
	 */
  
  
  /**
	 * }
	 */
}
