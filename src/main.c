#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <graphx.h>
#include <keypadc.h>
#include <fileioc.h>

void begin(void);
void end(void);
bool step(void);
void draw(void);

void raceMenu(){
	gfx_FillScreen(0x2);
	gfx_BlitBuffer();
}

void mainMenu(){

		uint8_t selected_option = 0;
		bool key = false;
		gfx_FillScreen(0);
		gfx_SetTextFGColor(0x0A);
		gfx_PrintStringXY("WELCOME TO CALCULATOR STREET RACING III", 0, 0);
		gfx_SetTextFGColor(0xDF);
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
					break;
			
				case 6:
					break;
			}	

			gfx_BlitBuffer();
			}

int main(void)
{
    bool partial_redraw = false;

	gfx_Begin(gfx_8bpp);
	gfx_Blit(gfx_screen);
	gfx_FillScreen(0x00);
    gfx_SetDrawBuffer();
	gfx_SetColor(0xE0);
	gfx_SetTextFGColor(0x00);
	gfx_SetTextScale(1, 1);
	gfx_PrintStringXY("Calculator Street Racing III:", 20, 20);
		gfx_SetTextFGColor(0x1E);
    gfx_PrintStringXY("Racing Redefined", 80, 40);
	gfx_SetTextScale(1, 1);
	gfx_PrintStringXY("Press any key", 100, 150);
	gfx_PrintStringXY("oxiti8", 200, 200);
	gfx_BlitBuffer();
	while(!kb_AnyKey());
	mainMenu();

    gfx_SetDrawBuffer();

    gfx_End();

    return 0;
}

