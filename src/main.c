#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <graphx.h>
#include <keypadc.h>
#include <fileioc.h>

#include "gfx/gfx.h"

void begin(void);
void end(void);
bool step(void);
void draw(void);

void raceMenu(){
	gfx_FillScreen(0x2);
	gfx_BlitBuffer();
}

bool startRace(){

}
void displayCredits(char color){
	gfx_SetTextFGColor(color);
	gfx_SetTextScale(1, 1);
	gfx_PrintStringXY("Cr: ", 225, 0);


}

bool mainMenu(){

		uint8_t selected_option = 0;
		bool key = false;
		gfx_ZeroScreen();
		gfx_SetTextFGColor(0x0A);
		gfx_PrintStringXY("HOME", 0, 0);
		displayCredits(0xDF);
		gfx_SetTextScale(1, 1);
		gfx_PrintStringXY("Go Race", 20, 50);
		gfx_PrintStringXY("Change Car", 20, 70);
		gfx_PrintStringXY("Tuning", 20, 90);
		gfx_PrintStringXY("Buy Cars", 20, 110);
		gfx_PrintStringXY("Options", 20, 130);
		gfx_PrintStringXY("About", 20, 150);
		gfx_PrintStringXY("Quit Game", 20, 170);
		gfx_SetColor(0);
		while(!key) {
			kb_Scan();
			key = (kb_Data[1] == kb_2nd);
			gfx_FillRectangle(10, 50 + selected_option*20, 10, 10);
			
			if(kb_Data[7] & kb_Up) {
				selected_option--;
				if(selected_option == 255) selected_option = 6;
			}
			if(kb_Data[7] & kb_Down) {
				selected_option++;
				if(selected_option == 7) selected_option = 0;
			}
			
			gfx_PrintStringXY(">", 10, 50 + selected_option*20);
			gfx_BlitBuffer();
			delay(100);
		}
			bool noloop = false;
			switch(selected_option)
			{
				case 0:
					raceMenu();
					break;
				case 1:
					break;
			
				case 2:
					break;

				case 3:
					
					break;

				case 4:
					
					break;
				
				case 5:
					key = false;
					gfx_ZeroScreen();
					gfx_SetTextFGColor(0x0A);
					gfx_PrintStringXY("ABOUT", 0, 0);
					gfx_SetTextFGColor(0xDF);
					gfx_PrintStringXY("Calculator Street Racing III", 0, 40);
					gfx_PrintStringXY("Game by oxiti8. Pre-Alpha 10/17/23", 0, 50);
					gfx_PrintStringXY("Controls:", 20, 70);
					gfx_PrintStringXY("2nd = Rev engine/Select", 20, 80);
					gfx_PrintStringXY("Alpha = Use Nitrous", 20, 90);
					gfx_PrintStringXY("Up = Shift up", 20, 100);
					gfx_PrintStringXY("Down = Shift down", 20, 110);
					gfx_BlitBuffer();
					delay(300);
					while(!key) {
						kb_Scan();
						key = (kb_Data[1] == kb_2nd);
					}
					break;
			
				case 6:
					noloop = true;
					break;
				}
				return noloop;
			}

int main(void)
{
    bool partial_redraw = false;
	bool exit = false;
	gfx_Begin(gfx_8bpp);
	gfx_Blit(gfx_screen);
	gfx_FillScreen(0xFF);
    gfx_SetDrawBuffer();
	gfx_SetColor(0xE0);
	gfx_SetTextFGColor(0);
	gfx_SetTextScale(1, 1);
	gfx_PrintStringXY("Calculator Street Racing III", 60, 20);
	gfx_PrintStringXY("Press any key", 100, 150);
	gfx_PrintStringXY("oxiti8", 280, 220);
	gfx_BlitBuffer();
	while(!kb_AnyKey());
	while(!exit){
	exit = mainMenu();
	}
    gfx_SetDrawBuffer();

    gfx_End();

    return 0;
}

